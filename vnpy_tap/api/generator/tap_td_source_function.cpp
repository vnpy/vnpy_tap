int TdApi::qryTradingDate()
{
	TAPIUINT32 session;
	int i = this->api->QryTradingDate(&session);
	return i;
};

int TdApi::qryAccount(const dict &req)
{
	TAPIUINT32 session;
	TapAPIAccQryReq myreq = TapAPIAccQryReq();
	memset(&myreq, 0, sizeof(myreq));
	int i = this->api->QryAccount(&session, &myreq);
	return i;
};

int TdApi::qryFund(const dict &req)
{
	TAPIUINT32 session;
	TapAPIFundReq myreq = TapAPIFundReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "AccountNo", myreq.AccountNo);
	int i = this->api->QryFund(&session, &myreq);
	return i;
};

int TdApi::qryExchange()
{
	TAPIUINT32 session;
	int i = this->api->QryExchange(&session);
	return i;
};

int TdApi::qryCommodity()
{
	TAPIUINT32 session;
	int i = this->api->QryCommodity(&session);
	return i;
};

int TdApi::qryContract(const dict &req)
{
	TAPIUINT32 session;
	TapAPICommodity myreq = TapAPICommodity();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeNo", myreq.ExchangeNo);
	getChar(req, "CommodityType", &myreq.CommodityType);
	getString(req, "CommodityNo", myreq.CommodityNo);
	int i = this->api->QryContract(&session, &myreq);
	return i;
};

int TdApi::qryOrder(const dict &req)
{
	TAPIUINT32 session;
	TapAPIOrderQryReq myreq = TapAPIOrderQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "AccountNo", myreq.AccountNo);
	getString(req, "ExchangeNo", myreq.ExchangeNo);
	getChar(req, "CommodityType", &myreq.CommodityType);
	getString(req, "CommodityNo", myreq.CommodityNo);
	getChar(req, "OrderType", &myreq.OrderType);
	getChar(req, "OrderSource", &myreq.OrderSource);
	getChar(req, "TimeInForce", &myreq.TimeInForce);
	getString(req, "ExpireTime", myreq.ExpireTime);
	getChar(req, "IsRiskOrder", &myreq.IsRiskOrder);
	getChar(req, "ServerFlag", &myreq.ServerFlag);
	getString(req, "OrderNo", myreq.OrderNo);
	getChar(req, "IsBackInput", &myreq.IsBackInput);
	getChar(req, "IsDeleted", &myreq.IsDeleted);
	getChar(req, "IsAddOne", &myreq.IsAddOne);
	getChar(req, "OrderQryType", &myreq.OrderQryType);
	int i = this->api->QryOrder(&session, &myreq);
	return i;
};

int TdApi::qryOrderProcess(const dict &req)
{
	TAPIUINT32 session;
	TapAPIOrderProcessQryReq myreq = TapAPIOrderProcessQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ServerFlag", &myreq.ServerFlag);
	getString(req, "OrderNo", myreq.OrderNo);
	int i = this->api->QryOrderProcess(&session, &myreq);
	return i;
};

int TdApi::qryFill(const dict &req)
{
	TAPIUINT32 session;
	TapAPIFillQryReq myreq = TapAPIFillQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "AccountNo", myreq.AccountNo);
	getString(req, "ExchangeNo", myreq.ExchangeNo);
	getChar(req, "CommodityType", &myreq.CommodityType);
	getString(req, "CommodityNo", myreq.CommodityNo);
	getString(req, "ContractNo", myreq.ContractNo);
	getString(req, "StrikePrice", myreq.StrikePrice);
	getChar(req, "CallOrPutFlag", &myreq.CallOrPutFlag);
	getChar(req, "MatchSource", &myreq.MatchSource);
	getChar(req, "MatchSide", &myreq.MatchSide);
	getChar(req, "PositionEffect", &myreq.PositionEffect);
	getChar(req, "ServerFlag", &myreq.ServerFlag);
	getString(req, "OrderNo", myreq.OrderNo);
	getString(req, "UpperNo", myreq.UpperNo);
	getChar(req, "IsDeleted", &myreq.IsDeleted);
	getChar(req, "IsAddOne", &myreq.IsAddOne);
	int i = this->api->QryFill(&session, &myreq);
	return i;
};

int TdApi::qryPosition(const dict &req)
{
	TAPIUINT32 session;
	TapAPIPositionQryReq myreq = TapAPIPositionQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "AccountNo", myreq.AccountNo);
	int i = this->api->QryPosition(&session, &myreq);
	return i;
};

int TdApi::qryPositionSummary(const dict &req)
{
	TAPIUINT32 session;
	TapAPIPositionQryReq myreq = TapAPIPositionQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "AccountNo", myreq.AccountNo);
	int i = this->api->QryPositionSummary(&session, &myreq);
	return i;
};

int TdApi::qryCurrency()
{
	TAPIUINT32 session;
	int i = this->api->QryCurrency(&session);
	return i;
};

int TdApi::qryAccountCashAdjust(const dict &req)
{
	TAPIUINT32 session;
	TapAPIAccountCashAdjustQryReq myreq = TapAPIAccountCashAdjustQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getUnsigned int(req, "SerialID", &myreq.SerialID);
	getString(req, "AccountNo", myreq.AccountNo);
	getString(req, "BeginDate", myreq.BeginDate);
	getString(req, "EndDate", myreq.EndDate);
	int i = this->api->QryAccountCashAdjust(&session, &myreq);
	return i;
};

int TdApi::qryTradeMessage(const dict &req)
{
	TAPIUINT32 session;
	TapAPITradeMessageReq myreq = TapAPITradeMessageReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "AccountNo", myreq.AccountNo);
	getString(req, "BenginSendDateTime", myreq.BenginSendDateTime);
	getString(req, "EndSendDateTime", myreq.EndSendDateTime);
	int i = this->api->QryTradeMessage(&session, &myreq);
	return i;
};

int TdApi::qryBill(const dict &req)
{
	TAPIUINT32 session;
	TapAPIBillQryReq myreq = TapAPIBillQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "UserNo", myreq.UserNo);
	getChar(req, "BillType", &myreq.BillType);
	getString(req, "BillDate", myreq.BillDate);
	getChar(req, "BillFileType", &myreq.BillFileType);
	int i = this->api->QryBill(&session, &myreq);
	return i;
};

int TdApi::qryHisOrder(const dict &req)
{
	TAPIUINT32 session;
	TapAPIHisOrderQryReq myreq = TapAPIHisOrderQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "AccountNo", myreq.AccountNo);
	getString(req, "BeginDate", myreq.BeginDate);
	getString(req, "EndDate", myreq.EndDate);
	int i = this->api->QryHisOrder(&session, &myreq);
	return i;
};

int TdApi::qryHisOrderProcess(const dict &req)
{
	TAPIUINT32 session;
	TapAPIHisOrderProcessQryReq myreq = TapAPIHisOrderProcessQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "Date", myreq.Date);
	getString(req, "OrderNo", myreq.OrderNo);
	int i = this->api->QryHisOrderProcess(&session, &myreq);
	return i;
};

int TdApi::qryHisMatch(const dict &req)
{
	TAPIUINT32 session;
	TapAPIHisMatchQryReq myreq = TapAPIHisMatchQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "AccountNo", myreq.AccountNo);
	getString(req, "BeginDate", myreq.BeginDate);
	getString(req, "EndDate", myreq.EndDate);
	int i = this->api->QryHisMatch(&session, &myreq);
	return i;
};

int TdApi::qryHisPosition(const dict &req)
{
	TAPIUINT32 session;
	TapAPIHisPositionQryReq myreq = TapAPIHisPositionQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "AccountNo", myreq.AccountNo);
	getString(req, "Date", myreq.Date);
	getChar(req, "SettleFlag", &myreq.SettleFlag);
	int i = this->api->QryHisPosition(&session, &myreq);
	return i;
};

int TdApi::qryHisDelivery(const dict &req)
{
	TAPIUINT32 session;
	TapAPIHisDeliveryQryReq myreq = TapAPIHisDeliveryQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "AccountNo", myreq.AccountNo);
	getString(req, "BeginDate", myreq.BeginDate);
	getString(req, "EndDate", myreq.EndDate);
	getChar(req, "SettleFlag", &myreq.SettleFlag);
	int i = this->api->QryHisDelivery(&session, &myreq);
	return i;
};

int TdApi::qryAccountFeeRent(const dict &req)
{
	TAPIUINT32 session;
	TapAPIAccountFeeRentQryReq myreq = TapAPIAccountFeeRentQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "AccountNo", myreq.AccountNo);
	int i = this->api->QryAccountFeeRent(&session, &myreq);
	return i;
};

int TdApi::qryAccountMarginRent(const dict &req)
{
	TAPIUINT32 session;
	TapAPIAccountMarginRentQryReq myreq = TapAPIAccountMarginRentQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "AccountNo", myreq.AccountNo);
	getString(req, "ExchangeNo", myreq.ExchangeNo);
	getChar(req, "CommodityType", &myreq.CommodityType);
	getString(req, "CommodityNo", myreq.CommodityNo);
	int i = this->api->QryAccountMarginRent(&session, &myreq);
	return i;
};

