from dataclasses import dataclass
from datetime import datetime
from pathlib import Path
from typing import Any, Dict, Tuple, List
import pytz

from ..api import MdApi, TdApi
from vnpy.event import EventEngine
from vnpy.trader.utility import get_folder_path
from vnpy.trader.constant import (
    Exchange,
    Product,
    Direction,
    Status,
    OrderType
)
from vnpy.trader.gateway import BaseGateway
from vnpy.trader.object import (
    CancelRequest,
    OrderRequest,
    SubscribeRequest,
    TickData,
    ContractData,
    OrderData,
    TradeData,
    PositionData,
    AccountData
)

# 委托状态映射
STATUS_TAP2VT: Dict[str, Status] = {
    "0": Status.SUBMITTING,
    "1": Status.SUBMITTING,
    "4": Status.NOTTRADED,
    "5": Status.PARTTRADED,
    "6": Status.ALLTRADED,
    "9": Status.CANCELLED,
    "A": Status.CANCELLED,
    "B": Status.REJECTED,
}

# 多空方向映射
DIRECTION_TAP2VT: Dict[str, Direction] = {
    "N": Direction.NET,
    "B": Direction.LONG,
    "S": Direction.SHORT,
}
DIRECTION_VT2TAP: Dict[Direction, str] = {v: k for k, v in DIRECTION_TAP2VT.items()}

# 委托类型映射
ORDERTYPE_TAP2VT: Dict[str, OrderType] = {
    "1": OrderType.MARKET,
    "2": OrderType.LIMIT
}
ORDERTYPE_VT2TAP = {v: k for k, v in ORDERTYPE_TAP2VT.items()}

# 产品类型映射
PRODUCT_TYPE_TAP2VT: Dict[str, Product] = {
    "P": Product.SPOT,
    "F": Product.FUTURES,
    "O": Product.OPTION,
    "Z": Product.INDEX,
    "T": Product.EQUITY,
}

# 交易所映射
EXCHANGE_TAP2VT: Dict[str, Exchange] = {
    "SGX": Exchange.SGX,
    "INE": Exchange.INE,
    "APEX": Exchange.APEX,
    "NYMEX": Exchange.NYMEX,
    "LME": Exchange.LME,
    "COMEX": Exchange.COMEX,
    "CBOT": Exchange.CBOT,
    "HKEX": Exchange.HKFE,
    "CME": Exchange.CME,
    "ZCE": Exchange.CZCE,
    "DCE": Exchange.DCE,
    "TOCOM": Exchange.TOCOM,
    "KRX": Exchange.KRX,
    "ICUS": Exchange.ICE,
    "ICEU": Exchange.ICE
}
EXCHANGE_VT2TAP: Dict[Exchange, str] = {v: k for k, v in EXCHANGE_TAP2VT.items()}

# 错误类型映射
ERROR_VT2TAP: Dict[str, int] = {
    "TAPIERROR_SUCCEED": 0
}

# 日志级别映射
LOGLEVEL_VT2TAP: Dict[str, str] = {
    "APILOGLEVEL_NONE": "N",
    "APILOGLEVEL_ERROR": "E",
    "APILOGLEVEL_WARNING": "W",
    "APILOGLEVEL_DEBUG": "D"
}

# 标示类型映射
FLAG_VT2TAP: Dict[str, str] = {
    "APIYNFLAG_YES": "Y",
    "APIYNFLAG_NO": "N",
    "TAPI_CALLPUT_FLAG_CALL": "C",
    "TAPI_CALLPUT_FLAG_PUT": "P",
    "TAPI_CALLPUT_FLAG_NONE": "N"
}

# 其他常量
CHINA_TZ = pytz.timezone("Asia/Shanghai")

# 合约数据全局缓存字典
commodity_infos: Dict[str, "CommodityInfo"] = {}
contract_infos: Dict[Tuple[str, "Exchange"], "ContractInfo"] = {}

class TapGateway(BaseGateway):
    """
    vn.py用于对接易盛9.0外盘的交易接口。
    """

    default_setting: Dict[str, Any] = {
        "行情账号": "",
        "行情密码": "",
        "行情服务器": "",
        "行情端口": 0,
        "交易账号": "",
        "交易密码": "",
        "交易服务器": "",
        "交易端口": 0,
        "授权码": ""
    }

    exchanges: List[str] = list(EXCHANGE_VT2TAP.keys())

    def __init__(self, event_engine: EventEngine):
        """构造函数"""
        super().__init__(event_engine, "TAP")

        self.md_api: "QuoteApi" = QuoteApi(self)
        self.td_api: "TradeApi" = TradeApi(self)

    def connect(self, setting: dict) -> None:
        """连接交易接口"""
        quote_username: str = setting["行情账号"]
        quote_password: str = setting["行情密码"]
        quote_host: str = setting["行情服务器"]
        quote_port: int = setting["行情端口"]
        trade_username: str = setting["交易账号"]
        trade_password: str = setting["交易密码"]
        trade_host: str = setting["交易服务器"]
        trade_port: int = setting["交易端口"]
        auth_code: str = setting["授权码"]

        self.md_api.connect(
            quote_username,
            quote_password,
            quote_host,
            quote_port,
            auth_code
        )
        self.td_api.connect(
            trade_username,
            trade_password,
            trade_host,
            trade_port,
            auth_code
        )

    def close(self) -> None:
        """关闭接口"""
        pass

    def subscribe(self, req: SubscribeRequest) -> None:
        """订阅行情"""
        self.md_api.subscribe(req)

    def send_order(self, req: OrderRequest) -> str:
        """委托下单"""
        return self.td_api.send_order(req)

    def cancel_order(self, req: CancelRequest) -> None:
        """委托撤单"""
        self.td_api.cancel_order(req)

    def query_account(self) -> None:
        """查询资金"""
        pass

    def query_position(self) -> None:
        """查询持仓"""
        pass


class QuoteApi(MdApi):
    """行情API"""

    def __init__(self, gateway: TapGateway) -> None:
        """构造函数"""
        super().__init__()

        self.gateway: TapGateway = gateway
        self.gateway_name: str = gateway.gateway_name

    def onRspLogin(self, error: int, data: dict) -> None:
        """用户登陆请求回报"""
        if error != ERROR_VT2TAP["TAPIERROR_SUCCEED"]:
            self.gateway.write_log(f"行情服务器登录失败：{error}")
        else:
            self.gateway.write_log("行情服务器登录成功")

    def onAPIReady(self) -> None:
        """API状态通知回报"""
        pass

    def onDisconnect(self, reason: int) -> None:
        """服务器连接断开回报"""
        self.gateway.write_log(f"行情服务器连接断开，原因：{reason}")

    def onRspSubscribeQuote(
        self,
        session: int,
        error: int,
        last: str,
        data: dict
    ) -> None:
        """订阅行情回报"""
        if error != ERROR_VT2TAP["TAPIERROR_SUCCEED"]:
            self.gateway.write_log(f"订阅行情失败：{error}")
        else:
            self.update_tick(data)

    def onRtnQuote(self, data: dict) -> None:
        """行情数据推送"""
        self.update_tick(data)

    def onRspQryCommodity(
        self,
        session: int,
        error: int,
        last: str,
        data: dict,
    ) -> None:
        """交易品种查询回报"""
        if error != ERROR_VT2TAP["TAPIERROR_SUCCEED"]:
            self.gateway.write_log("查询交易品种信息失败")
            return

        commodity_info: CommodityInfo = CommodityInfo(
            name=data["CommodityEngName"],
            size=int(data["ContractSize"]),
            pricetick=data["CommodityTickSize"]
        )
        key: tuple = (data["ExchangeNo"], data["CommodityNo"], data["CommodityType"])
        commodity_infos[key] = commodity_info

        if last == "Y":
            self.gateway.write_log("查询交易品种信息成功")
            req = {}
            self.qryContract(req)

    def onRspQryContract(
        self,
        session: int,
        error: int,
        last: str,
        data: dict
    ) -> None:
        """交易合约查询回报"""
        if error != ERROR_VT2TAP["TAPIERROR_SUCCEED"]:
            self.gateway.write_log("查询交易合约信息失败")
            return

        exchange: Exchange = EXCHANGE_TAP2VT.get(data["ExchangeNo"], None)
        key: tuple = (data["ExchangeNo"], data["CommodityNo"], data["CommodityType"])
        commodity_info: CommodityInfo = commodity_infos.get(key, None)

        if not data or not exchange or not commodity_info:
            return

        if data["CommodityType"] == "F":
            symbol: str = data["CommodityNo"] + data["ContractNo1"]

            if commodity_info.name:
                name: str = f"{commodity_info.name} {data['ContractNo1']}"
            else:
                name: str = symbol

            contract: ContractData = ContractData(
                symbol=symbol,
                exchange=exchange,
                name=name,
                product=Product.FUTURES,
                size=commodity_info.size,
                pricetick=commodity_info.pricetick,
                net_position=True,
                gateway_name=self.gateway.gateway_name
            )
            self.gateway.on_contract(contract)

            contract_info: ContractInfo = ContractInfo(
                name=contract.name,
                exchange_no=data["ExchangeNo"],
                contract_no=data["ContractNo1"],
                commodity_type=data["CommodityType"],
                commodity_no=data["CommodityNo"],
            )
            contract_infos[(contract.symbol, contract.exchange)] = contract_info

        if last == "Y":
            self.gateway.write_log("查询交易合约信息成功")

    def update_tick(self, data: dict) -> None:
        """切片数据类型转换"""
        symbol: str = data["CommodityNo"] + data["ContractNo1"]
        exchange: Exchange = EXCHANGE_TAP2VT[data["ExchangeNo"]]

        contract_info: ContractInfo = contract_infos.get((symbol, exchange), None)
        if not contract_info:
            self.gateway.write_log(f"行情合约信息无法匹配：{symbol}和{exchange}")
            return

        tick: TickData = TickData(
            symbol=symbol,
            exchange=exchange,
            datetime=generate_datetime(data["DateTimeStamp"]),
            name=contract_info.name,
            volume=data["QTotalQty"],
            last_price=data["QLastPrice"],
            last_volume=data["QLastQty"],
            limit_up=data["QLimitUpPrice"],
            limit_down=data["QLimitDownPrice"],
            open_price=data["QOpeningPrice"],
            high_price=data["QHighPrice"],
            low_price=data["QLowPrice"],
            pre_close=data["QPreClosingPrice"],
            bid_price_1=data["QBidPrice"][0],
            bid_price_2=data["QBidPrice"][1],
            bid_price_3=data["QBidPrice"][2],
            bid_price_4=data["QBidPrice"][3],
            bid_price_5=data["QBidPrice"][4],
            ask_price_1=data["QAskPrice"][0],
            ask_price_2=data["QAskPrice"][1],
            ask_price_3=data["QAskPrice"][2],
            ask_price_4=data["QAskPrice"][3],
            ask_price_5=data["QAskPrice"][4],
            bid_volume_1=data["QBidQty"][0],
            bid_volume_2=data["QBidQty"][1],
            bid_volume_3=data["QBidQty"][2],
            bid_volume_4=data["QBidQty"][3],
            bid_volume_5=data["QBidQty"][4],
            ask_volume_1=data["QAskQty"][0],
            ask_volume_2=data["QAskQty"][1],
            ask_volume_3=data["QAskQty"][2],
            ask_volume_4=data["QAskQty"][3],
            ask_volume_5=data["QAskQty"][4],
            gateway_name=self.gateway_name,
        )
        self.gateway.on_tick(tick)

    def connect(
        self,
        username: str,
        password: str,
        host: str,
        port: int,
        auth_code: str
    ) -> None:
        """连接服务器"""
        self.init()

        # API基本设置
        path: Path = get_folder_path(self.gateway_name.lower())
        self.setTapQuoteAPIDataPath(str(path))
        self.setTapQuoteAPILogLevel(LOGLEVEL_VT2TAP["APILOGLEVEL_NONE"])

        # 创建API
        req: dict = {
            "AuthCode": auth_code,
            "KeyOperationLogPath": str(path)
        }
        self.createTapQuoteAPI(req, 0)

        # 设置服务器地址
        self.setHostAddress(host, port)

        # 登陆
        data: dict = {
            "UserNo": username,
            "Password": password,
            "ISModifyPassword": FLAG_VT2TAP["APIYNFLAG_NO"],
            "ISDDA": FLAG_VT2TAP["APIYNFLAG_NO"]
        }
        self.login(data)

    def subscribe(self, req: SubscribeRequest):
        """订阅行情"""
        contract_info: ContractInfo = contract_infos.get((req.symbol, req.exchange), None)
        if not contract_info:
            self.gateway.write_log(
                f"找不到匹配的合约：{req.symbol}和{req.exchange.value}")
            return

        tap_contract: dict = {
            "ExchangeNo": EXCHANGE_VT2TAP[req.exchange],
            "CommodityType": contract_info.commodity_type,
            "CommodityNo": contract_info.commodity_no,
            "ContractNo1": contract_info.contract_no,
            "CallOrPutFlag1": FLAG_VT2TAP["TAPI_CALLPUT_FLAG_NONE"],
            "CallOrPutFlag2": FLAG_VT2TAP["TAPI_CALLPUT_FLAG_NONE"]
        }

        self.subscribeQuote(tap_contract)


class TradeApi(TdApi):
    """交易API"""

    def __init__(self, gateway: TapGateway) -> None:
        """构造函数"""
        super().__init__()

        self.gateway: TapGateway = gateway
        self.gateway_name: str = gateway.gateway_name

        self.account_no: str = ""        # 委托下单时使用
        self.cancel_reqs: Dict[str, CancelRequest] = {}       # 存放未成交订单

        self.sys_local_map: Dict[str, str] = {}
        self.local_sys_map: Dict[str, str] = {}
        self.sys_server_map: Dict[str, str] = {}

    def onConnect(self) -> None:
        """服务器连接成功回报"""
        self.gateway.write_log("交易服务器连接成功")

    def onRspLogin(self, error: int, data: dict) -> None:
        """用户登陆请求回报"""
        if error != ERROR_VT2TAP["TAPIERROR_SUCCEED"]:
            self.gateway.write_log(f"交易服务器登录失败，错误码：{error}")
        else:
            self.gateway.write_log("交易服务器登录成功")

    def onAPIReady(self, code: int) -> None:
        """API状态通知回报"""
        self.query_account()

        self.qryCommodity()

    def onRspQryCommodity(
        self,
        session: int,
        error: int,
        last: str,
        data: dict,
    ) -> None:
        """交易品种查询回报"""
        if error != ERROR_VT2TAP["TAPIERROR_SUCCEED"]:
            self.gateway.write_log("查询交易品种信息失败")
            return

        commodity_info: CommodityInfo = CommodityInfo(
            name=data["CommodityEngName"],
            size=int(data["ContractSize"]),
            pricetick=data["CommodityTickSize"]
        )
        commodity_infos[data["CommodityNo"]] = commodity_info

        if last == "Y":
            self.gateway.write_log("查询交易品种信息成功")
            req = {}
            self.qryContract(req)

    def onRspQryContract(
        self,
        session: int,
        error: int,
        last: str,
        data: dict
    ) -> None:
        """交易合约查询回报"""
        if error != ERROR_VT2TAP["TAPIERROR_SUCCEED"]:
            self.gateway.write_log("查询交易合约信息失败")
            return

        exchange: Exchange = EXCHANGE_TAP2VT.get(data["ExchangeNo"], None)
        commodity_info: CommodityInfo = commodity_infos.get(data["CommodityNo"], None)

        if not data or not exchange or not commodity_info:
            return

        if data["CommodityType"] == "F":
            symbol: str = data["CommodityNo"] + data["ContractNo1"]

            if commodity_info.name:
                name: str = f"{commodity_info.name} {data['ContractNo1']}"
            else:
                name = symbol

            contract: ContractData = ContractData(
                symbol=symbol,
                exchange=exchange,
                name=name,
                product=Product.FUTURES,
                size=commodity_info.size,
                pricetick=commodity_info.pricetick,
                net_position=True,
                gateway_name=self.gateway.gateway_name
            )
            self.gateway.on_contract(contract)

            contract_info: ContractInfo = ContractInfo(
                name=contract.name,
                exchange_no=data["ExchangeNo"],
                contract_no=data["ContractNo1"],
                commodity_type=data["CommodityType"],
                commodity_no=data["CommodityNo"],
            )
            contract_infos[(contract.symbol, contract.exchange)] = contract_info

        if last == "Y":
            self.gateway.write_log("查询交易合约信息成功")
            self.query_account()

    def onRtnPositionProfit(self, data: dict) -> None:
        """持仓利润更新推送"""
        pass

    def onRspQryAccount(
        self,
        session: int,
        error: int,
        last: str,
        data: dict
    ) -> None:
        """账户查询回报"""
        if error != ERROR_VT2TAP["TAPIERROR_SUCCEED"]:
            self.gateway.write_log("查询账号信息失败")
            return

        req: dict = {
            "AccountNo": data["AccountNo"]
        }
        self.qryFund(req)

    def onRspQryFund(
        self,
        session: int,
        error: int,
        last: str,
        data: dict
    ) -> None:
        """账户资金查询回报"""
        if error != ERROR_VT2TAP["TAPIERROR_SUCCEED"]:
            self.gateway.write_log("查询资金信息失败")
            return

        self.update_account(data)

        if last == "Y":
            self.gateway.write_log("查询资金信息成功")
            self.query_position()

    def onRtnFund(self, data: dict) -> None:
        """账户资金推送"""
        self.update_account(data)

    def onRspQryPositionSummary(
        self,
        session: int,
        error: int,
        last: str,
        data: dict
    ) -> None:
        """持仓汇总查询回报"""
        if error != ERROR_VT2TAP["TAPIERROR_SUCCEED"]:
            self.gateway.write_log("查询持仓信息失败")
            return

        if data:
            self.update_position(data)

        if last == "Y":
            self.gateway.write_log("查询持仓信息成功")
            self.query_order()

    def onRtnPositionSummary(self, data: dict) -> None:
        """持仓汇总更新推送"""
        self.update_position(data)

    def onRspQryOrder(
        self,
        session: int,
        error: int,
        last: str,
        data: dict
    ) -> None:
        """当日委托查询回报"""
        if error != ERROR_VT2TAP["TAPIERROR_SUCCEED"]:
            self.gateway.write_log("查询委托信息失败")
            return

        if data:
            self.update_order(data)

        if last == "Y":
            self.gateway.write_log("查询委托信息成功")
            self.query_trade()

    def onRtnOrder(self, data: dict) -> None:
        """委托查询推送"""
        if data["ErrorCode"] != ERROR_VT2TAP["TAPIERROR_SUCCEED"]:
            self.gateway.write_log(f"委托下单失败，错误码: {data['ErrorCode']}")
            return

        self.update_order(data)

    def onRspQryFill(
        self,
        session: int,
        error: int,
        last: str,
        data: dict
    ) -> None:
        """当日成交查询回报"""
        if error != ERROR_VT2TAP["TAPIERROR_SUCCEED"]:
            self.gateway.write_log("查询成交信息失败")
            return

        if data:
            self.update_trade(data)

        if last == "Y":
            self.gateway.write_log("查询成交信息成功")

    def onRtnFill(self, data: dict) -> None:
        """成交更新推送"""
        self.update_trade(data)

    def onRspOrderAction(
        self,
        session: int,
        error: int,
        data: dict
    ) -> None:
        """撤单和修改委托回报"""
        if error != ERROR_VT2TAP["TAPIERROR_SUCCEED"]:
            self.gateway.write_log(f"委托操作失败：{error}")
            return

    def update_account(self, data: dict) -> None:
        """更新并推送资金"""
        self.account_no: str = data["AccountNo"]

        account: AccountData = AccountData(
            accountid=data["AccountNo"],
            balance=data["Balance"],
            frozen=data["Balance"] - data["Available"],
            gateway_name=self.gateway_name
        )
        self.gateway.on_account(account)

    def update_position(self, data: dict) -> None:
        """更新并推送持仓"""
        position: PositionData = PositionData(
            symbol=data["CommodityNo"] + data["ContractNo"],
            exchange=EXCHANGE_TAP2VT.get(data["ExchangeNo"], None),
            direction=DIRECTION_TAP2VT[data["MatchSide"]],
            volume=data["PositionQty"],
            price=data["PositionPrice"],
            gateway_name=self.gateway_name
        )
        self.gateway.on_position(position)

    def update_order(self, data: dict) -> None:
        """更新并推送委托"""
        # 过滤撤销和修改状态中的委托
        if data["OrderState"] in {"7", "8"}:
            return

        self.local_sys_map[data["ClientOrderNo"]] = data["OrderNo"]
        self.sys_local_map[data["OrderNo"]] = data["ClientOrderNo"]
        self.sys_server_map[data["OrderNo"]] = data["ServerFlag"]

        order: OrderData = OrderData(
            symbol=data["CommodityNo"] + data["ContractNo"],
            exchange=EXCHANGE_TAP2VT.get(data["ExchangeNo"], None),
            orderid=data["ClientOrderNo"],
            type=ORDERTYPE_TAP2VT.get(data["OrderType"], data["OrderType"]),
            direction=DIRECTION_TAP2VT[data["OrderSide"]],
            price=data["OrderPrice"],
            volume=data["OrderQty"],
            traded=data["OrderMatchQty"],
            status=STATUS_TAP2VT.get(data["OrderState"], Status.SUBMITTING),
            datetime=generate_datetime(data["OrderInsertTime"]),
            gateway_name=self.gateway_name
        )
        self.gateway.on_order(order)

        # 发送等待撤单请求
        if data["ClientOrderNo"] in self.cancel_reqs:
            req: str = self.cancel_reqs.pop(data["ClientOrderNo"])
            self.cancel_order(req)

    def update_trade(self, data: dict) -> None:
        """更新并推送成交"""
        orderid: str = self.sys_local_map[data["OrderNo"]]

        trade: TradeData = TradeData(
            symbol=data["CommodityNo"] + data["ContractNo"],
            exchange=EXCHANGE_TAP2VT.get(data["ExchangeNo"], None),
            orderid=orderid,
            tradeid=data["MatchNo"],
            direction=DIRECTION_TAP2VT[data["MatchSide"]],
            price=data["MatchPrice"],
            volume=data["MatchQty"],
            datetime=generate_datetime(data["MatchDateTime"]),
            gateway_name=self.gateway_name
        )
        self.gateway.on_trade(trade)

    def connect(
        self,
        username: str,
        password: str,
        host: str,
        port: int,
        auth_code: str
    ) -> None:
        """连接服务器"""
        self.init()

        # API基本设置
        path: Path = get_folder_path(self.gateway_name.lower())
        self.setITapTradeAPIDataPath(str(path))
        self.setITapTradeAPILogLevel(LOGLEVEL_VT2TAP["APILOGLEVEL_NONE"])

        # 创建API
        req: dict = {
            "AuthCode": auth_code,
            "KeyOperationLogPath": str(path)
        }
        self.createITapTradeAPI(req, 0)

        # 设置服务器地址
        self.setHostAddress(host, port)

        # 登陆
        data: dict = {
            "UserNo": username,
            "Password": password,
            "ISModifyPassword": FLAG_VT2TAP["APIYNFLAG_NO"],
            "NoticeIgnoreFlag": "TAPI_NOTICE_IGNORE_POSITIONPROFIT"
        }
        self.login(data)

    def send_order(self, req: OrderRequest) -> str:
        """委托下单"""
        contract_info: ContractInfo = contract_infos.get((req.symbol, req.exchange), None)
        if not contract_info:
            self.gateway.write_log(f"找不到匹配的合约：{req.symbol}和{req.exchange.value}")
            return ""

        if req.type not in ORDERTYPE_VT2TAP:
            self.gateway.write_log(f"不支持的委托类型: {req.type.value}")
            return ""

        order_req: dict = {
            "AccountNo": self.account_no,
            "ExchangeNo": contract_info.exchange_no,
            "CommodityType": contract_info.commodity_type,
            "CommodityNo": contract_info.commodity_no,
            "ContractNo": contract_info.contract_no,
            "OrderType": ORDERTYPE_VT2TAP[req.type],
            "OrderSide": DIRECTION_VT2TAP[req.direction],
            "OrderPrice": req.price,
            "OrderQty": int(req.volume),
        }

        error_id, sesion, order_id = self.insertOrder(order_req)
        order: OrderData = req.create_order_data(
            order_id,
            self.gateway_name
        )

        if error_id:
            self.gateway.write_log(f"委托请求失败，错误号：{error_id}")
            order.status = Status.REJECTED

        self.gateway.on_order(order)

        return order.vt_orderid

    def cancel_order(self, req: CancelRequest) -> None:
        """委托撤单"""
        order_no: str = self.local_sys_map.get(req.orderid, "")
        if not order_no:
            self.cancel_reqs[req.orderid] = req
            return

        server_flag: str = self.sys_server_map[order_no]

        cancel_req: dict = {
            "OrderNo": order_no,
            "ServerFlag": server_flag,
        }

        self.cancelOrder(cancel_req)

    def query_account(self) -> None:
        """资金查询"""
        self.qryAccount({})

    def query_position(self) -> None:
        """持仓查询"""
        self.qryPositionSummary({})

    def query_order(self) -> None:
        """当日委托查询"""
        self.qryOrder({})

    def query_trade(self) -> None:
        """当日成交查询"""
        self.qryFill({})


def generate_datetime(timestamp: str) -> datetime:
    """生成datetime格式时间"""
    if "-" in timestamp:
        if "." in timestamp:
            dt = datetime.strptime(timestamp, "%Y-%m-%d %H:%M:%S.%f")
        else:
            dt = datetime.strptime(timestamp, "%Y-%m-%d %H:%M:%S")
    else:
        dt = datetime.strptime(timestamp, "%y%m%d%H%M%S.%f")

    dt = CHINA_TZ.localize(dt)
    return dt


@dataclass
class ContractInfo:
    """存储合约信息"""
    name: str
    exchange_no: str
    commodity_type: int
    commodity_no: str
    contract_no: str


@dataclass
class CommodityInfo:
    """存储品种信息"""
    name: str
    size: int
    pricetick: float
