void TdApi::OnConnect(const ITapTrade::TAPISTR_40 HostAddress)
{
	Task task = Task();
	task.task_name = ONCONNECT;
	task.task_string = HostAddress;
	this->task_queue.push(task);
};

void TdApi::OnRspLogin(ITapTrade::TAPIINT32 errorCode, const ITapTrade::TapAPITradeLoginRspInfo *loginRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPLOGIN;
	task.task_int = errorCode;
	if (loginRspInfo)
	{
		TapAPITradeLoginRspInfo *task_data = new TapAPITradeLoginRspInfo();
		*task_data = *loginRspInfo;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnContactInfo(ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TAPISTR_40 ContactInfo)
{
	Task task = Task();
	task.task_name = ONRTNCONTACTINFO;
	task.task_int = errorCode;
	task.task_last = isLast;
	task.task_string = ContactInfo;
	this->task_queue.push(task);
};

void TdApi::OnRspRequestVertificateCode(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, const TapAPIRequestVertificateCodeRsp *rsp)
{
	Task task = Task();
	task.task_name = ONRSPREQUESTVERTIFICATECODE;
	task.task_id = sessionID;
	task.task_int = errorCode;
	if (rsp)
	{
		TapAPIRequestVertificateCodeRsp *task_data = new TapAPIRequestVertificateCodeRsp();
		*task_data = *rsp;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnExpriationDate(ITapTrade::TAPIDATE date, int days)
{
	Task task = Task();
	task.task_name = ONEXPRIATIONDATE;
	task.task_string = date;
	task.task_int = days;
	this->task_queue.push(task);
};

void TdApi::OnAPIReady(ITapTrade::TAPIINT32 errorCode)
{
	Task task = Task();
	task.task_name = ONAPIREADY;
	task.task_int = errorCode;
	this->task_queue.push(task);
};

void TdApi::OnDisconnect(ITapTrade::TAPIINT32 reasonCode)
{
	Task task = Task();
	task.task_name = ONDISCONNECT;
	task.task_int = reasonCode;
	this->task_queue.push(task);
};

void TdApi::OnRspChangePassword(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode)
{
	Task task = Task();
	task.task_name = ONRSPCHANGEPASSWORD;
	task.task_id = sessionID;
	task.task_int = errorCode;
	this->task_queue.push(task);
};

void TdApi::OnRspAuthPassword(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode)
{
	Task task = Task();
	task.task_name = ONRSPAUTHPASSWORD;
	task.task_id = sessionID;
	task.task_int = errorCode;
	this->task_queue.push(task);
};

void TdApi::OnRspQryTradingDate(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, const ITapTrade::TapAPITradingCalendarQryRsp *info)
{
	Task task = Task();
	task.task_name = ONRSPQRYTRADINGDATE;
	task.task_id = sessionID;
	task.task_int = errorCode;
	if (info)
	{
		TapAPITradingCalendarQryRsp *task_data = new TapAPITradingCalendarQryRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspSetReservedInfo(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, const ITapTrade::TAPISTR_50 info)
{
	Task task = Task();
	task.task_name = ONRSPSETRESERVEDINFO;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_string = info;
	this->task_queue.push(task);
};

void TdApi::OnRspQryAccount(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIUINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPIAccountInfo *info)
{
	Task task = Task();
	task.task_name = ONRSPQRYACCOUNT;
	task.task_id = sessionID;
	task.task_id = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIAccountInfo *task_data = new TapAPIAccountInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryFund(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPIFundData *info)
{
	Task task = Task();
	task.task_name = ONRSPQRYFUND;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIFundData *task_data = new TapAPIFundData();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnFund(const ITapTrade::TapAPIFundData *info)
{
	Task task = Task();
	task.task_name = ONRTNFUND;
	if (info)
	{
		TapAPIFundData *task_data = new TapAPIFundData();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryExchange(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPIExchangeInfo *info)
{
	Task task = Task();
	task.task_name = ONRSPQRYEXCHANGE;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIExchangeInfo *task_data = new TapAPIExchangeInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryCommodity(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPICommodityInfo *info)
{
	Task task = Task();
	task.task_name = ONRSPQRYCOMMODITY;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPICommodityInfo *task_data = new TapAPICommodityInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryContract(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPITradeContractInfo *info)
{
	Task task = Task();
	task.task_name = ONRSPQRYCONTRACT;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPITradeContractInfo *task_data = new TapAPITradeContractInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnContract(const ITapTrade::TapAPITradeContractInfo *info)
{
	Task task = Task();
	task.task_name = ONRTNCONTRACT;
	if (info)
	{
		TapAPITradeContractInfo *task_data = new TapAPITradeContractInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspOrderAction(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, const ITapTrade::TapAPIOrderActionRsp *info)
{
	Task task = Task();
	task.task_name = ONRSPORDERACTION;
	task.task_id = sessionID;
	task.task_int = errorCode;
	if (info)
	{
		TapAPIOrderActionRsp *task_data = new TapAPIOrderActionRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnOrder(const ITapTrade::TapAPIOrderInfoNotice *info)
{
	Task task = Task();
	task.task_name = ONRTNORDER;
	if (info)
	{
		TapAPIOrderInfoNotice *task_data = new TapAPIOrderInfoNotice();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryOrder(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPIOrderInfo *info)
{
	Task task = Task();
	task.task_name = ONRSPQRYORDER;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIOrderInfo *task_data = new TapAPIOrderInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryOrderProcess(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPIOrderInfo *info)
{
	Task task = Task();
	task.task_name = ONRSPQRYORDERPROCESS;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIOrderInfo *task_data = new TapAPIOrderInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryFill(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPIFillInfo *info)
{
	Task task = Task();
	task.task_name = ONRSPQRYFILL;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIFillInfo *task_data = new TapAPIFillInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnFill(const ITapTrade::TapAPIFillInfo *info)
{
	Task task = Task();
	task.task_name = ONRTNFILL;
	if (info)
	{
		TapAPIFillInfo *task_data = new TapAPIFillInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryPosition(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPIPositionInfo *info)
{
	Task task = Task();
	task.task_name = ONRSPQRYPOSITION;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIPositionInfo *task_data = new TapAPIPositionInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnPosition(const ITapTrade::TapAPIPositionInfo *info)
{
	Task task = Task();
	task.task_name = ONRTNPOSITION;
	if (info)
	{
		TapAPIPositionInfo *task_data = new TapAPIPositionInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryPositionSummary(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPIPositionSummary *info)
{
	Task task = Task();
	task.task_name = ONRSPQRYPOSITIONSUMMARY;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIPositionSummary *task_data = new TapAPIPositionSummary();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnPositionSummary(const TapAPIPositionSummary *info)
{
	Task task = Task();
	task.task_name = ONRTNPOSITIONSUMMARY;
	if (info)
	{
		TapAPIPositionSummary *task_data = new TapAPIPositionSummary();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnPositionProfit(const ITapTrade::TapAPIPositionProfitNotice *info)
{
	Task task = Task();
	task.task_name = ONRTNPOSITIONPROFIT;
	if (info)
	{
		TapAPIPositionProfitNotice *task_data = new TapAPIPositionProfitNotice();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryCurrency(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPICurrencyInfo *info)
{
	Task task = Task();
	task.task_name = ONRSPQRYCURRENCY;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPICurrencyInfo *task_data = new TapAPICurrencyInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryTradeMessage(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPITradeMessage *info) 
{
	Task task = Task();
	task.task_name = ONRSPQRYTRADEMESSAGE;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPITradeMessage *task_data = new TapAPITradeMessage();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnTradeMessage(const ITapTrade::TapAPITradeMessage *info) 
{
	Task task = Task();
	task.task_name = ONRTNTRADEMESSAGE;
	if (info)
	{
		TapAPITradeMessage *task_data = new TapAPITradeMessage();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryHisOrder(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPIHisOrderQryRsp *info) 
{
	Task task = Task();
	task.task_name = ONRSPQRYHISORDER;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIHisOrderQryRsp *task_data = new TapAPIHisOrderQryRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryHisOrderProcess(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPIHisOrderProcessQryRsp *info) 
{
	Task task = Task();
	task.task_name = ONRSPQRYHISORDERPROCESS;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIHisOrderProcessQryRsp *task_data = new TapAPIHisOrderProcessQryRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryHisMatch(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPIHisMatchQryRsp *info) 
{
	Task task = Task();
	task.task_name = ONRSPQRYHISMATCH;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIHisMatchQryRsp *task_data = new TapAPIHisMatchQryRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryHisPosition(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPIHisPositionQryRsp *info) 
{
	Task task = Task();
	task.task_name = ONRSPQRYHISPOSITION;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIHisPositionQryRsp *task_data = new TapAPIHisPositionQryRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryHisDelivery(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPIHisDeliveryQryRsp *info) 
{
	Task task = Task();
	task.task_name = ONRSPQRYHISDELIVERY;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIHisDeliveryQryRsp *task_data = new TapAPIHisDeliveryQryRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryAccountCashAdjust(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPIAccountCashAdjustQryRsp *info) 
{
	Task task = Task();
	task.task_name = ONRSPQRYACCOUNTCASHADJUST;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIAccountCashAdjustQryRsp *task_data = new TapAPIAccountCashAdjustQryRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryBill(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPIBillQryRsp *info) 
{
	Task task = Task();
	task.task_name = ONRSPQRYBILL;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIBillQryRsp *task_data = new TapAPIBillQryRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryAccountFeeRent(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPIAccountFeeRentQryRsp *info) 
{
	Task task = Task();
	task.task_name = ONRSPQRYACCOUNTFEERENT;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIAccountFeeRentQryRsp *task_data = new TapAPIAccountFeeRentQryRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryAccountMarginRent(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPIAccountMarginRentQryRsp *info) 
{
	Task task = Task();
	task.task_name = ONRSPQRYACCOUNTMARGINRENT;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIAccountMarginRentQryRsp *task_data = new TapAPIAccountMarginRentQryRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspHKMarketOrderInsert(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, const ITapTrade::TapAPIOrderMarketInsertRsp *info) 
{
	Task task = Task();
	task.task_name = ONRSPHKMARKETORDERINSERT;
	task.task_id = sessionID;
	task.task_int = errorCode;
	if (info)
	{
		TapAPIOrderMarketInsertRsp *task_data = new TapAPIOrderMarketInsertRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspHKMarketOrderDelete(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, const ITapTrade::TapAPIOrderMarketDeleteRsp *info) 
{
	Task task = Task();
	task.task_name = ONRSPHKMARKETORDERDELETE;
	task.task_id = sessionID;
	task.task_int = errorCode;
	if (info)
	{
		TapAPIOrderMarketDeleteRsp *task_data = new TapAPIOrderMarketDeleteRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnHKMarketQuoteNotice(const ITapTrade::TapAPIOrderQuoteMarketNotice *info) 
{
	Task task = Task();
	task.task_name = ONHKMARKETQUOTENOTICE;
	if (info)
	{
		TapAPIOrderQuoteMarketNotice *task_data = new TapAPIOrderQuoteMarketNotice();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspOrderLocalRemove(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, const ITapTrade::TapAPIOrderLocalRemoveRsp *info) 
{
	Task task = Task();
	task.task_name = ONRSPORDERLOCALREMOVE;
	task.task_id = sessionID;
	task.task_int = errorCode;
	if (info)
	{
		TapAPIOrderLocalRemoveRsp *task_data = new TapAPIOrderLocalRemoveRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspOrderLocalInput(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, const ITapTrade::TapAPIOrderLocalInputRsp *info) 
{
	Task task = Task();
	task.task_name = ONRSPORDERLOCALINPUT;
	task.task_id = sessionID;
	task.task_int = errorCode;
	if (info)
	{
		TapAPIOrderLocalInputRsp *task_data = new TapAPIOrderLocalInputRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspOrderLocalModify(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, const ITapTrade::TapAPIOrderLocalModifyRsp *info) 
{
	Task task = Task();
	task.task_name = ONRSPORDERLOCALMODIFY;
	task.task_id = sessionID;
	task.task_int = errorCode;
	if (info)
	{
		TapAPIOrderLocalModifyRsp *task_data = new TapAPIOrderLocalModifyRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspOrderLocalTransfer(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, const ITapTrade::TapAPIOrderLocalTransferRsp *info) 
{
	Task task = Task();
	task.task_name = ONRSPORDERLOCALTRANSFER;
	task.task_id = sessionID;
	task.task_int = errorCode;
	if (info)
	{
		TapAPIOrderLocalTransferRsp *task_data = new TapAPIOrderLocalTransferRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspFillLocalInput(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, const ITapTrade::TapAPIFillLocalInputRsp *info) 
{
	Task task = Task();
	task.task_name = ONRSPFILLLOCALINPUT;
	task.task_id = sessionID;
	task.task_int = errorCode;
	if (info)
	{
		TapAPIFillLocalInputRsp *task_data = new TapAPIFillLocalInputRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspFillLocalRemove(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, const ITapTrade::TapAPIFillLocalRemoveRsp *info) 
{
	Task task = Task();
	task.task_name = ONRSPFILLLOCALREMOVE;
	task.task_id = sessionID;
	task.task_int = errorCode;
	if (info)
	{
		TapAPIFillLocalRemoveRsp *task_data = new TapAPIFillLocalRemoveRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQrySpotLock(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPISpotLockDataRsp *info) 
{
	Task task = Task();
	task.task_name = ONRSPQRYSPOTLOCK;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPISpotLockDataRsp *task_data = new TapAPISpotLockDataRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnSpotLock(const ITapTrade::TapAPISpotLockDataRsp *info) 
{
	Task task = Task();
	task.task_name = ONRTNSPOTLOCK;
	if (info)
	{
		TapAPISpotLockDataRsp *task_data = new TapAPISpotLockDataRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspSubmitUserLoginInfo(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPISubmitUserLoginRspInfo * info) 
{
	Task task = Task();
	task.task_name = ONRSPSUBMITUSERLOGININFO;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPISubmitUserLoginRspInfo *task_data = new TapAPISubmitUserLoginRspInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspSpecialOrderAction(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, const ITapTrade::TapAPISpecialOrderInfo *info) 
{
	Task task = Task();
	task.task_name = ONRSPSPECIALORDERACTION;
	task.task_id = sessionID;
	task.task_int = errorCode;
	if (info)
	{
		TapAPISpecialOrderInfo *task_data = new TapAPISpecialOrderInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnSpecialOrder(const ITapTrade::TapAPISpecialOrderInfo *info) 
{
	Task task = Task();
	task.task_name = ONRTNSPECIALORDER;
	if (info)
	{
		TapAPISpecialOrderInfo *task_data = new TapAPISpecialOrderInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQrySpecialOrder(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPISpecialOrderInfo *info) 
{
	Task task = Task();
	task.task_name = ONRSPQRYSPECIALORDER;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPISpecialOrderInfo *task_data = new TapAPISpecialOrderInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryCombinePosition(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const  ITapTrade::TapAPICombinePositionInfo *info) 
{
	Task task = Task();
	task.task_name = ONRSPQRYCOMBINEPOSITION;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPICombinePositionInfo *task_data = new TapAPICombinePositionInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnCombinePosition(const ITapTrade::TapAPICombinePositionInfo *info) 
{
	Task task = Task();
	task.task_name = ONRTNCOMBINEPOSITION;
	if (info)
	{
		TapAPICombinePositionInfo *task_data = new TapAPICombinePositionInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryUserTrustDevice(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const  ITapTrade::TapAPIUserTrustDeviceQryRsp *info) 
{
	Task task = Task();
	task.task_name = ONRSPQRYUSERTRUSTDEVICE;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIUserTrustDeviceQryRsp *task_data = new TapAPIUserTrustDeviceQryRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspAddUserTrustDevice(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, const ITapTrade::TapAPIUserTrustDeviceAddRsp *info) 
{
	Task task = Task();
	task.task_name = ONRSPADDUSERTRUSTDEVICE;
	task.task_id = sessionID;
	task.task_int = errorCode;
	if (info)
	{
		TapAPIUserTrustDeviceAddRsp *task_data = new TapAPIUserTrustDeviceAddRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspDelUserTrustDevice(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, const ITapTrade::TapAPIUserTrustDeviceDelRsp *info) 
{
	Task task = Task();
	task.task_name = ONRSPDELUSERTRUSTDEVICE;
	task.task_id = sessionID;
	task.task_int = errorCode;
	if (info)
	{
		TapAPIUserTrustDeviceDelRsp *task_data = new TapAPIUserTrustDeviceDelRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnAddUserTrustDevice(const ITapTrade::TapAPIUserTrustDeviceAddRsp *info) 
{
	Task task = Task();
	task.task_name = ONRTNADDUSERTRUSTDEVICE;
	if (info)
	{
		TapAPIUserTrustDeviceAddRsp *task_data = new TapAPIUserTrustDeviceAddRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnDelUserTrustDevice(const ITapTrade::TapAPIUserTrustDeviceDelRsp *info) 
{
	Task task = Task();
	task.task_name = ONRTNDELUSERTRUSTDEVICE;
	if (info)
	{
		TapAPIUserTrustDeviceDelRsp *task_data = new TapAPIUserTrustDeviceDelRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryIPOInfo(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPIIPOInfoQryRsp *info) 
{
	Task task = Task();
	task.task_name = ONRSPQRYIPOINFO;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIIPOInfoQryRsp *task_data = new TapAPIIPOInfoQryRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryIPOStockQty(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPIAvailableApplyQryRsp *info) 
{
	Task task = Task();
	task.task_name = ONRSPQRYIPOSTOCKQTY;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIAvailableApplyQryRsp *task_data = new TapAPIAvailableApplyQryRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryAccountIPO(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPIAccountIPOQryRsp *info) 
{
	Task task = Task();
	task.task_name = ONRSPQRYACCOUNTIPO;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIAccountIPOQryRsp *task_data = new TapAPIAccountIPOQryRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspAddAccountIPO(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, const ITapTrade::TapAPIAccountIPOAddRsp *info) 
{
	Task task = Task();
	task.task_name = ONRSPADDACCOUNTIPO;
	task.task_id = sessionID;
	task.task_int = errorCode;
	if (info)
	{
		TapAPIAccountIPOAddRsp *task_data = new TapAPIAccountIPOAddRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspCancelAccountIPO(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, const ITapTrade::TapAPIAccountIPOCancelRsp *info) 
{
	Task task = Task();
	task.task_name = ONRSPCANCELACCOUNTIPO;
	task.task_id = sessionID;
	task.task_int = errorCode;
	if (info)
	{
		TapAPIAccountIPOCancelRsp *task_data = new TapAPIAccountIPOCancelRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnAddAccountIPO(const ITapTrade::TapAPIAccountIPOAddNotice *info) 
{
	Task task = Task();
	task.task_name = ONRTNADDACCOUNTIPO;
	if (info)
	{
		TapAPIAccountIPOAddNotice *task_data = new TapAPIAccountIPOAddNotice();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnCancelAccountIPO(const ITapTrade::TapAPIAccountIPOCancelNotice *info) 
{
	Task task = Task();
	task.task_name = ONRTNCANCELACCOUNTIPO;
	if (info)
	{
		TapAPIAccountIPOCancelNotice *task_data = new TapAPIAccountIPOCancelNotice();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspUnFreezeVerificate(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode) 
{
	Task task = Task();
	task.task_name = ONRSPUNFREEZEVERIFICATE;
	task.task_id = sessionID;
	task.task_int = errorCode;
	this->task_queue.push(task);
};

