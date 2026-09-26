from collections.abc import Callable, Iterator
from datetime import datetime
from typing import Any

import pytest

pytest.importorskip("vnpy_tap.api", reason="缺少 Tap 原生扩展")

from vnpy.event import EventEngine  # noqa: E402
from vnpy.trader.constant import (  # noqa: E402
    Direction,
    Exchange,
    OptionType,
    OrderType,
    Product,
    Status,
)
from vnpy.trader.object import (  # noqa: E402
    AccountData,
    CancelRequest,
    ContractData,
    OrderData,
    OrderRequest,
    PositionData,
    SubscribeRequest,
    TickData,
    TradeData,
)

from vnpy_tap.gateway import tap_gateway  # noqa: E402
from vnpy_tap.gateway.tap_gateway import (  # noqa: E402
    CHINA_TZ,
    EXCHANGE_VT2TAP,
    CommodityInfo,
    ContractInfo,
    QuoteApi,
    TapGateway,
    TradeApi,
    generate_datetime,
)


class FakeGateway:
    def __init__(self) -> None:
        self.gateway_name: str = "TAP"
        self.logs: list[str] = []
        self.ticks: list[TickData] = []
        self.contracts: list[ContractData] = []
        self.orders: list[OrderData] = []
        self.trades: list[TradeData] = []
        self.positions: list[PositionData] = []
        self.accounts: list[AccountData] = []

    def write_log(self, msg: str) -> None:
        self.logs.append(msg)

    def on_tick(self, tick: TickData) -> None:
        self.ticks.append(tick)

    def on_contract(self, contract: ContractData) -> None:
        self.contracts.append(contract)

    def on_order(self, order: OrderData) -> None:
        self.orders.append(order)

    def on_trade(self, trade: TradeData) -> None:
        self.trades.append(trade)

    def on_position(self, position: PositionData) -> None:
        self.positions.append(position)

    def on_account(self, account: AccountData) -> None:
        self.accounts.append(account)


class CallRecorder:
    def __init__(self) -> None:
        self.calls: list[tuple[str, Any]] = []

    def patch(self, monkeypatch: pytest.MonkeyPatch, api: object, names: list[str]) -> None:
        for name in names:
            monkeypatch.setattr(api, name, self.make_stub(name))

    def make_stub(self, name: str) -> Callable[..., None]:
        def stub(*args: Any) -> None:
            self.calls.append((name, args[0] if args else None))
        return stub

    def names(self) -> list[str]:
        return [name for name, _ in self.calls]


TD_REQUEST_METHODS: list[str] = [
    "qryCommodity",
    "qryContract",
    "qryAccount",
    "qryFund",
    "qryPositionSummary",
    "qryOrder",
    "qryFill",
    "cancelOrder",
]


@pytest.fixture(autouse=True)
def clear_caches() -> Iterator[None]:
    tap_gateway.commodity_infos.clear()
    tap_gateway.contract_infos.clear()
    tap_gateway.option_contract_map.clear()
    yield
    tap_gateway.commodity_infos.clear()
    tap_gateway.contract_infos.clear()
    tap_gateway.option_contract_map.clear()


@pytest.fixture
def gateway() -> FakeGateway:
    return FakeGateway()


@pytest.fixture
def recorder() -> CallRecorder:
    return CallRecorder()


@pytest.fixture
def trade_api(gateway: FakeGateway, recorder: CallRecorder, monkeypatch: pytest.MonkeyPatch) -> TradeApi:
    api: TradeApi = TradeApi(gateway)  # type: ignore[arg-type]
    recorder.patch(monkeypatch, api, TD_REQUEST_METHODS)
    return api


@pytest.fixture
def quote_api(gateway: FakeGateway, recorder: CallRecorder, monkeypatch: pytest.MonkeyPatch) -> QuoteApi:
    api: QuoteApi = QuoteApi(gateway)  # type: ignore[arg-type]
    recorder.patch(monkeypatch, api, ["subscribeQuote"])
    return api


def add_futures_contract(symbol: str = "CL2512", exchange: Exchange = Exchange.NYMEX) -> None:
    tap_gateway.contract_infos[(symbol, exchange)] = ContractInfo(
        name="Crude Oil 2512",
        exchange_no=EXCHANGE_VT2TAP[exchange],
        commodity_type="F",
        commodity_no="CL",
        contract_no="2512",
    )


def add_option_contract() -> str:
    symbol: str = "CL2512C60"
    tap_gateway.contract_infos[(symbol, Exchange.NYMEX)] = ContractInfo(
        name="Crude Oil 2512 C60",
        exchange_no="NYMEX",
        commodity_type="O",
        commodity_no="CL",
        contract_no="2512",
    )
    tap_gateway.option_contract_map[symbol] = ContractData(
        symbol=symbol,
        exchange=Exchange.NYMEX,
        name="Crude Oil 2512 C60",
        product=Product.OPTION,
        size=1000,
        pricetick=0.01,
        option_type=OptionType.CALL,
        option_index="60",
        gateway_name="TAP",
    )
    return symbol


def contract_data(**overrides: str) -> dict[str, str]:
    data: dict[str, str] = {
        "ExchangeNo": "NYMEX",
        "CommodityNo": "CL",
        "CommodityType": "F",
        "ContractNo1": "2512",
        "ContractName": "",
        "CallOrPutFlag1": "N",
        "StrikePrice1": "",
        "ContractExpDate": "2025-11-20",
    }
    data.update(overrides)
    return data


def order_data(**overrides: Any) -> dict[str, Any]:
    data: dict[str, Any] = {
        "ClientOrderNo": "1001",
        "OrderNo": "SYS1",
        "ServerFlag": "C",
        "CommodityNo": "CL",
        "ContractNo": "2512",
        "ExchangeNo": "NYMEX",
        "OrderType": "2",
        "OrderSide": "B",
        "OrderPrice": 60.5,
        "OrderQty": 2,
        "OrderMatchQty": 0,
        "OrderState": "4",
        "OrderInsertTime": "2025-10-10 09:30:00.123",
        "ErrorCode": 0,
    }
    data.update(overrides)
    return data


def order_request(symbol: str = "CL2512", order_type: OrderType = OrderType.LIMIT) -> OrderRequest:
    return OrderRequest(
        symbol=symbol,
        exchange=Exchange.NYMEX,
        direction=Direction.LONG,
        type=order_type,
        volume=2,
        price=60.5,
    )


def tick_data() -> dict[str, Any]:
    return {
        "CommodityNo": "CL",
        "ContractNo1": "2512",
        "ExchangeNo": "NYMEX",
        "DateTimeStamp": "2025-10-10 09:30:00.500",
        "QTotalQty": 100,
        "QLastPrice": 60.5,
        "QLastQty": 1,
        "QLimitUpPrice": 70.0,
        "QLimitDownPrice": 50.0,
        "QOpeningPrice": 60.0,
        "QHighPrice": 61.0,
        "QLowPrice": 59.0,
        "QPreClosingPrice": 59.5,
        "QBidPrice": [60.4, 60.3, 60.2, 60.1, 60.0],
        "QAskPrice": [60.6, 60.7, 60.8, 60.9, 61.0],
        "QBidQty": [1, 2, 3, 4, 5],
        "QAskQty": [5, 4, 3, 2, 1],
    }


@pytest.mark.parametrize(
    ("timestamp", "expected"),
    [
        ("2025-10-10 09:30:00.123", datetime(2025, 10, 10, 9, 30, 0, 123000)),
        ("2025-10-10 09:30:00", datetime(2025, 10, 10, 9, 30, 0)),
        ("251010093000.123", datetime(2025, 10, 10, 9, 30, 0, 123000)),
    ],
)
def test_generate_datetime_formats(timestamp: str, expected: datetime) -> None:
    assert generate_datetime(timestamp) == expected.replace(tzinfo=CHINA_TZ)


def test_ice_reverse_mapping_keeps_iceu() -> None:
    assert EXCHANGE_VT2TAP[Exchange.ICE] == "ICEU"
    assert EXCHANGE_VT2TAP[Exchange.HKFE] == "HKEX"


def test_gateway_connect_skips_side_without_host(monkeypatch: pytest.MonkeyPatch) -> None:
    gateway: TapGateway = TapGateway(EventEngine(), "TAP")
    recorder: CallRecorder = CallRecorder()
    monkeypatch.setattr(gateway.md_api, "connect", recorder.make_stub("md_connect"))
    monkeypatch.setattr(gateway.td_api, "connect", recorder.make_stub("td_connect"))

    setting: dict[str, str | int | float | bool] = dict(TapGateway.default_setting)
    setting["交易服务器"] = "127.0.0.1"
    gateway.connect(setting)

    assert recorder.names() == ["td_connect"]


def test_commodity_empty_tail_continues_to_contract_query(trade_api: TradeApi, gateway: FakeGateway, recorder: CallRecorder) -> None:
    trade_api.onRspQryCommodity(0, 0, "Y", {})

    assert recorder.names() == ["qryContract"]
    assert tap_gateway.commodity_infos == {}
    assert gateway.logs == ["查询交易品种信息成功"]


def test_commodity_empty_packet_not_last_does_nothing(trade_api: TradeApi, recorder: CallRecorder) -> None:
    trade_api.onRspQryCommodity(0, 0, "N", {})

    assert recorder.calls == []


def test_commodity_cached_and_last_triggers_contract_query(trade_api: TradeApi, recorder: CallRecorder) -> None:
    data: dict[str, Any] = {
        "CommodityEngName": "Crude Oil",
        "ContractSize": "1000",
        "CommodityTickSize": 0.01,
        "ExchangeNo": "NYMEX",
        "CommodityNo": "CL",
        "CommodityType": "F",
    }
    trade_api.onRspQryCommodity(0, 0, "Y", data)

    assert tap_gateway.commodity_infos[("NYMEX", "CL", "F")] == CommodityInfo("Crude Oil", 1000, 0.01)
    assert recorder.names() == ["qryContract"]


def test_commodity_error_stops_chain(trade_api: TradeApi, gateway: FakeGateway, recorder: CallRecorder) -> None:
    trade_api.onRspQryCommodity(0, 1, "Y", {})

    assert recorder.calls == []
    assert gateway.logs == ["查询交易品种信息失败"]


def test_contract_empty_tail_continues_to_account_query(trade_api: TradeApi, gateway: FakeGateway, recorder: CallRecorder) -> None:
    trade_api.onRspQryContract(0, 0, "Y", {})

    assert recorder.names() == ["qryAccount"]
    assert gateway.contracts == []


def test_contract_futures_pushed_and_cached(trade_api: TradeApi, gateway: FakeGateway, recorder: CallRecorder) -> None:
    tap_gateway.commodity_infos[("NYMEX", "CL", "F")] = CommodityInfo("Crude Oil", 1000, 0.01)

    trade_api.onRspQryContract(0, 0, "Y", contract_data())

    assert recorder.names() == ["qryAccount"]
    contract: ContractData = gateway.contracts[0]
    assert contract.symbol == "CL2512"
    assert contract.exchange == Exchange.NYMEX
    assert contract.name == "Crude Oil 2512"
    assert contract.size == 1000
    assert contract.net_position is True
    assert tap_gateway.contract_infos[("CL2512", Exchange.NYMEX)].contract_no == "2512"


def test_contract_option_fields(trade_api: TradeApi, gateway: FakeGateway) -> None:
    tap_gateway.commodity_infos[("NYMEX", "CL", "O")] = CommodityInfo("Crude Oil Option", 1000, 0.01)

    data: dict[str, str] = contract_data(CommodityType="O", CallOrPutFlag1="C", StrikePrice1="60")
    trade_api.onRspQryContract(0, 0, "N", data)

    contract: ContractData = gateway.contracts[0]
    assert contract.symbol == "CL2512C60"
    assert contract.product == Product.OPTION
    assert contract.option_type == OptionType.CALL
    assert contract.option_strike == 60.0
    assert contract.option_index == "60"
    assert contract.option_underlying == "CL2512"
    assert contract.option_portfolio == "CL_O"
    assert tap_gateway.option_contract_map["CL2512C60"] is contract


def test_contract_without_commodity_is_skipped(trade_api: TradeApi, gateway: FakeGateway) -> None:
    trade_api.onRspQryContract(0, 0, "N", contract_data())

    assert gateway.contracts == []
    assert tap_gateway.contract_infos == {}


def test_account_empty_packet_skips_fund_query(trade_api: TradeApi, recorder: CallRecorder) -> None:
    trade_api.onRspQryAccount(0, 0, "Y", {})

    assert recorder.calls == []


def test_account_triggers_fund_query(trade_api: TradeApi, recorder: CallRecorder) -> None:
    trade_api.onRspQryAccount(0, 0, "Y", {"AccountNo": "A1"})

    assert recorder.calls == [("qryFund", {"AccountNo": "A1"})]


def test_fund_empty_tail_continues_to_position_query(trade_api: TradeApi, gateway: FakeGateway, recorder: CallRecorder) -> None:
    trade_api.onRspQryFund(0, 0, "Y", {})

    assert recorder.names() == ["qryPositionSummary"]
    assert gateway.accounts == []


def test_fund_pushes_account(trade_api: TradeApi, gateway: FakeGateway, recorder: CallRecorder) -> None:
    trade_api.onRspQryFund(0, 0, "Y", {"AccountNo": "A1", "Balance": 1000.0, "Available": 800.0})

    account: AccountData = gateway.accounts[0]
    assert account.accountid == "A1"
    assert account.balance == 1000.0
    assert account.frozen == 200.0
    assert trade_api.account_no == "A1"
    assert recorder.names() == ["qryPositionSummary"]


def test_startup_chain_queries_order_and_trade_once(trade_api: TradeApi, recorder: CallRecorder) -> None:
    trade_api.onRspQryPositionSummary(0, 0, "Y", {})
    trade_api.onRspQryOrder(0, 0, "Y", {})
    trade_api.onRspQryFill(0, 0, "Y", {})

    assert recorder.names() == ["qryOrder", "qryFill"]


def test_startup_chain_stops_after_position_without_init_query(trade_api: TradeApi, recorder: CallRecorder) -> None:
    trade_api.init_query = False

    trade_api.onRspQryPositionSummary(0, 0, "Y", {})

    assert recorder.calls == []


def test_position_direction_mapping(trade_api: TradeApi, gateway: FakeGateway) -> None:
    data: dict[str, Any] = {
        "CommodityNo": "CL",
        "ContractNo": "2512",
        "ExchangeNo": "NYMEX",
        "MatchSide": "S",
        "PositionQty": 3,
        "PositionPrice": 60.0,
    }
    trade_api.onRtnPositionSummary(data)

    position: PositionData = gateway.positions[0]
    assert position.vt_symbol == "CL2512.NYMEX"
    assert position.direction == Direction.SHORT
    assert position.volume == 3


def test_send_order_unknown_contract_returns_empty(trade_api: TradeApi, recorder: CallRecorder) -> None:
    assert trade_api.send_order(order_request()) == ""
    assert "insertOrder" not in recorder.names()


def test_send_order_unsupported_type_returns_empty(trade_api: TradeApi, gateway: FakeGateway) -> None:
    add_futures_contract()

    assert trade_api.send_order(order_request(order_type=OrderType.FAK)) == ""
    assert gateway.orders == []


def test_send_order_without_client_id(trade_api: TradeApi, gateway: FakeGateway, monkeypatch: pytest.MonkeyPatch) -> None:
    add_futures_contract()
    requests: list[dict[str, Any]] = []

    def insert_order(req: dict[str, Any]) -> tuple[int, int, bytes]:
        requests.append(req)
        return 0, 1, b"1001"

    monkeypatch.setattr(trade_api, "insertOrder", insert_order)
    trade_api.account_no = "A1"

    vt_orderid: str = trade_api.send_order(order_request())

    assert vt_orderid == "TAP.1001"
    assert requests[0]["AccountNo"] == "A1"
    assert requests[0]["ExchangeNo"] == "NYMEX"
    assert requests[0]["OrderType"] == "2"
    assert requests[0]["OrderSide"] == "B"
    assert requests[0]["OrderQty"] == 2
    assert "ClientID" not in requests[0]
    assert "StrikePrice" not in requests[0]
    assert gateway.orders[0].status == Status.SUBMITTING


def test_send_order_strips_client_prefix(trade_api: TradeApi, monkeypatch: pytest.MonkeyPatch) -> None:
    add_futures_contract()
    requests: list[dict[str, Any]] = []

    def insert_order(req: dict[str, Any]) -> tuple[int, int, bytes]:
        requests.append(req)
        return 0, 1, b"#SUB1#CN#1001"

    monkeypatch.setattr(trade_api, "insertOrder", insert_order)
    trade_api.client_id = "SUB1"
    trade_api.client_location = "CN"
    trade_api.byte_client_id = b"SUB1"
    trade_api.byte_client_location = b"CN"

    assert trade_api.send_order(order_request()) == "TAP.1001"
    assert requests[0]["ClientID"] == "SUB1"
    assert requests[0]["ClientLocationID"] == "CN"


def test_send_order_option_fields(trade_api: TradeApi, monkeypatch: pytest.MonkeyPatch) -> None:
    symbol: str = add_option_contract()
    requests: list[dict[str, Any]] = []

    def insert_order(req: dict[str, Any]) -> tuple[int, int, bytes]:
        requests.append(req)
        return 0, 1, b"1002"

    monkeypatch.setattr(trade_api, "insertOrder", insert_order)

    trade_api.send_order(order_request(symbol=symbol))

    assert requests[0]["CommodityType"] == "O"
    assert requests[0]["StrikePrice"] == "60"
    assert requests[0]["CallOrPutFlag"] == "C"


def test_send_order_error_marks_rejected(trade_api: TradeApi, gateway: FakeGateway, monkeypatch: pytest.MonkeyPatch) -> None:
    add_futures_contract()
    monkeypatch.setattr(trade_api, "insertOrder", lambda req: (-1, 1, b"1003"))

    assert trade_api.send_order(order_request()) == "TAP.1003"
    assert gateway.orders[0].status == Status.REJECTED


def test_update_order_maps_ids_and_status(trade_api: TradeApi, gateway: FakeGateway) -> None:
    trade_api.onRtnOrder(order_data(OrderState="5", OrderMatchQty=1))

    order: OrderData = gateway.orders[0]
    assert order.orderid == "1001"
    assert order.status == Status.PARTTRADED
    assert order.type == OrderType.LIMIT
    assert order.direction == Direction.LONG
    assert order.traded == 1
    assert trade_api.local_sys_map["1001"] == "SYS1"
    assert trade_api.sys_local_map["SYS1"] == "1001"
    assert trade_api.sys_server_map["SYS1"] == "C"


def test_rtn_order_with_error_code_is_ignored(trade_api: TradeApi, gateway: FakeGateway) -> None:
    trade_api.onRtnOrder(order_data(ErrorCode=10))

    assert gateway.orders == []
    assert trade_api.local_sys_map == {}


@pytest.mark.parametrize("state", ["7", "8"])
def test_pending_cancel_or_modify_state_is_skipped(trade_api: TradeApi, gateway: FakeGateway, state: str) -> None:
    trade_api.onRtnOrder(order_data(OrderState=state))

    assert gateway.orders == []
    assert trade_api.local_sys_map == {}


def test_cancel_before_order_return_is_sent_later(trade_api: TradeApi, recorder: CallRecorder) -> None:
    req: CancelRequest = CancelRequest(orderid="1001", symbol="CL2512", exchange=Exchange.NYMEX)

    trade_api.cancel_order(req)
    assert recorder.calls == []
    assert trade_api.cancel_reqs["1001"] is req

    trade_api.onRtnOrder(order_data())

    assert recorder.calls == [("cancelOrder", {"OrderNo": "SYS1", "ServerFlag": "C"})]
    assert trade_api.cancel_reqs == {}


def test_cancel_after_order_return_is_sent_directly(trade_api: TradeApi, recorder: CallRecorder) -> None:
    trade_api.onRtnOrder(order_data())

    trade_api.cancel_order(CancelRequest(orderid="1001", symbol="CL2512", exchange=Exchange.NYMEX))

    assert recorder.calls == [("cancelOrder", {"OrderNo": "SYS1", "ServerFlag": "C"})]


def test_trade_uses_local_order_id(trade_api: TradeApi, gateway: FakeGateway) -> None:
    trade_api.onRtnOrder(order_data())

    trade_api.onRtnFill({
        "OrderNo": "SYS1",
        "CommodityNo": "CL",
        "ContractNo": "2512",
        "ExchangeNo": "NYMEX",
        "MatchNo": "M1",
        "MatchSide": "B",
        "MatchPrice": 60.5,
        "MatchQty": 2,
        "MatchDateTime": "2025-10-10 09:30:01",
    })

    trade: TradeData = gateway.trades[0]
    assert trade.orderid == "1001"
    assert trade.tradeid == "M1"
    assert trade.direction == Direction.LONG
    assert trade.datetime == datetime(2025, 10, 10, 9, 30, 1, tzinfo=CHINA_TZ)


def test_update_tick_requires_contract(quote_api: QuoteApi, gateway: FakeGateway) -> None:
    quote_api.onRtnQuote(tick_data())

    assert gateway.ticks == []
    assert len(gateway.logs) == 1


def test_update_tick_pushes_depth(quote_api: QuoteApi, gateway: FakeGateway) -> None:
    add_futures_contract()

    quote_api.onRtnQuote(tick_data())

    tick: TickData = gateway.ticks[0]
    assert tick.vt_symbol == "CL2512.NYMEX"
    assert tick.name == "Crude Oil 2512"
    assert tick.last_price == 60.5
    assert tick.bid_price_1 == 60.4
    assert tick.ask_price_5 == 61.0
    assert tick.bid_volume_5 == 5
    assert tick.ask_volume_1 == 5


def test_subscribe_unknown_contract_is_skipped(quote_api: QuoteApi, recorder: CallRecorder) -> None:
    quote_api.subscribe(SubscribeRequest(symbol="CL2512", exchange=Exchange.NYMEX))

    assert recorder.calls == []


def test_subscribe_futures(quote_api: QuoteApi, recorder: CallRecorder) -> None:
    add_futures_contract()

    quote_api.subscribe(SubscribeRequest(symbol="CL2512", exchange=Exchange.NYMEX))

    assert recorder.calls == [(
        "subscribeQuote",
        {
            "ExchangeNo": "NYMEX",
            "CommodityType": "F",
            "CommodityNo": "CL",
            "ContractNo1": "2512",
            "CallOrPutFlag2": "N",
            "CallOrPutFlag1": "N",
        },
    )]


def test_subscribe_option(quote_api: QuoteApi, recorder: CallRecorder) -> None:
    symbol: str = add_option_contract()

    quote_api.subscribe(SubscribeRequest(symbol=symbol, exchange=Exchange.NYMEX))

    req: dict[str, Any] = recorder.calls[0][1]
    assert req["CommodityType"] == "O"
    assert req["StrikePrice1"] == "60"
    assert req["CallOrPutFlag1"] == "C"


def test_close_without_connection_does_not_exit(trade_api: TradeApi, quote_api: QuoteApi, recorder: CallRecorder, monkeypatch: pytest.MonkeyPatch) -> None:
    for api in (trade_api, quote_api):
        recorder.patch(monkeypatch, api, ["disconnect", "exit"])
        api.close()

    assert recorder.calls == []
