﻿
// vntaptd.cpp : 定义 DLL 应用程序的导出函数。
//

#include "vntaptd.h"



//test3

//用户名密码
#define DEFAULT_USERNAME	("Q779375914")
#define DEFAULT_PASSWORD	("123456")

//下单
#define DEFAULT_ACCOUNT_NO		(DEFAULT_USERNAME)
#define DEFAULT_EXCHANGE_NO		("NYMEX")
#define DEFAULT_COMMODITY_TYPE	(TAPI_COMMODITY_TYPE_FUTURES)
#define DEFAULT_COMMODITY_NO	("CL")
#define DEFAULT_CONTRACT_NO		("2001")
#define DEFAULT_ORDER_TYPE		(TAPI_ORDER_TYPE_MARKET)
#define DEFAULT_ORDER_SIDE		(TAPI_SIDE_BUY)
#define DEFAULT_ORDER_PRICE		(0)
#define DEFAULT_ORDER_QTY		(1)	


///-------------------------------------------------------------------------------------
///C++的回调函数将数据保存到队列中
///-------------------------------------------------------------------------------------

void TdApi::OnConnect(const ITapTrade::TAPISTR_40 HostAddress)
{
	Task task = Task();
	task.task_name = ONCONNECT;
	task.task_string = HostAddress;
	this->task_queue.push(task);
};

void TdApi::OnRspLogin(ITapTrade::TAPIINT32 errorCode, const ITapTrade::TapAPITradeLoginRspInfo* loginRspInfo)
{
	Task task = Task();
	task.task_name = ONRSPLOGIN;
	task.task_int = errorCode;
	if (loginRspInfo)
	{
		TapAPITradeLoginRspInfo* task_data = new TapAPITradeLoginRspInfo();
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

void TdApi::OnRspRequestVertificateCode(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, const TapAPIRequestVertificateCodeRsp* rsp)
{
	Task task = Task();
	task.task_name = ONRSPREQUESTVERTIFICATECODE;
	task.task_id = sessionID;
	task.task_int = errorCode;
	if (rsp)
	{
		TapAPIRequestVertificateCodeRsp* task_data = new TapAPIRequestVertificateCodeRsp();
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

void TdApi::OnRspQryTradingDate(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, const ITapTrade::TapAPITradingCalendarQryRsp* info)
{
	Task task = Task();
	task.task_name = ONRSPQRYTRADINGDATE;
	task.task_id = sessionID;
	task.task_int = errorCode;
	if (info)
	{
		TapAPITradingCalendarQryRsp* task_data = new TapAPITradingCalendarQryRsp();
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

void TdApi::OnRspQryAccount(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIUINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPIAccountInfo* info)
{
	Task task = Task();
	task.task_name = ONRSPQRYACCOUNT;
	task.task_id = sessionID;
	task.task_id = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIAccountInfo* task_data = new TapAPIAccountInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryFund(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPIFundData* info)
{
	Task task = Task();
	task.task_name = ONRSPQRYFUND;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIFundData* task_data = new TapAPIFundData();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnFund(const ITapTrade::TapAPIFundData* info)
{
	Task task = Task();
	task.task_name = ONRTNFUND;
	if (info)
	{
		TapAPIFundData* task_data = new TapAPIFundData();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryExchange(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPIExchangeInfo* info)
{
	Task task = Task();
	task.task_name = ONRSPQRYEXCHANGE;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIExchangeInfo* task_data = new TapAPIExchangeInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryCommodity(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPICommodityInfo* info)
{
	Task task = Task();
	task.task_name = ONRSPQRYCOMMODITY;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPICommodityInfo* task_data = new TapAPICommodityInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryContract(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPITradeContractInfo* info)
{
	Task task = Task();
	task.task_name = ONRSPQRYCONTRACT;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPITradeContractInfo* task_data = new TapAPITradeContractInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnContract(const ITapTrade::TapAPITradeContractInfo* info)
{
	Task task = Task();
	task.task_name = ONRTNCONTRACT;
	if (info)
	{
		TapAPITradeContractInfo* task_data = new TapAPITradeContractInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspOrderAction(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, const ITapTrade::TapAPIOrderActionRsp* info)
{
	Task task = Task();
	task.task_name = ONRSPORDERACTION;
	task.task_id = sessionID;
	task.task_int = errorCode;
	if (info)
	{
		TapAPIOrderActionRsp* task_data = new TapAPIOrderActionRsp();
		*task_data = *info;
		task.task_data = task_data;

		if (info->OrderInfo)
		{
			TapAPIOrderInfo* task_extra = new TapAPIOrderInfo();
			*task_extra = *info->OrderInfo; //1
			task.task_extra = task_extra; //4
		}
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnOrder(const ITapTrade::TapAPIOrderInfoNotice* info)
{
	Task task = Task();
	task.task_name = ONRTNORDER;
	if (info)
	{
		TapAPIOrderInfoNotice* task_data = new TapAPIOrderInfoNotice();
		*task_data = *info;
		task.task_data = task_data;

		if (info->OrderInfo)
		{
			TapAPIOrderInfo* task_extra = new TapAPIOrderInfo();
			*task_extra = *info->OrderInfo; //1
			task.task_extra = task_extra; //4
		}
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryOrder(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPIOrderInfo* info)
{
	Task task = Task();
	task.task_name = ONRSPQRYORDER;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIOrderInfo* task_data = new TapAPIOrderInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryOrderProcess(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPIOrderInfo* info)
{
	Task task = Task();
	task.task_name = ONRSPQRYORDERPROCESS;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIOrderInfo* task_data = new TapAPIOrderInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryFill(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPIFillInfo* info)
{
	Task task = Task();
	task.task_name = ONRSPQRYFILL;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIFillInfo* task_data = new TapAPIFillInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnFill(const ITapTrade::TapAPIFillInfo* info)
{
	Task task = Task();
	task.task_name = ONRTNFILL;
	if (info)
	{
		TapAPIFillInfo* task_data = new TapAPIFillInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryPosition(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPIPositionInfo* info)
{
	Task task = Task();
	task.task_name = ONRSPQRYPOSITION;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIPositionInfo* task_data = new TapAPIPositionInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnPosition(const ITapTrade::TapAPIPositionInfo* info)
{
	Task task = Task();
	task.task_name = ONRTNPOSITION;
	if (info)
	{
		TapAPIPositionInfo* task_data = new TapAPIPositionInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryPositionSummary(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPIPositionSummary* info)
{
	Task task = Task();
	task.task_name = ONRSPQRYPOSITIONSUMMARY;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIPositionSummary* task_data = new TapAPIPositionSummary();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnPositionSummary(const TapAPIPositionSummary* info)
{
	Task task = Task();
	task.task_name = ONRTNPOSITIONSUMMARY;
	if (info)
	{
		TapAPIPositionSummary* task_data = new TapAPIPositionSummary();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnPositionProfit(const ITapTrade::TapAPIPositionProfitNotice* info)
{
	Task task = Task();
	task.task_name = ONRTNPOSITIONPROFIT;
	if (info)
	{
		TapAPIPositionProfitNotice* task_data = new TapAPIPositionProfitNotice();
		*task_data = *info;
		task.task_data = task_data;

		if (info->Data)
		{
			TapAPIPositionProfit* task_extra = new TapAPIPositionProfit();
			*task_extra = *info->Data; //1
			task.task_extra = task_extra; //4
		}
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryCurrency(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPICurrencyInfo* info)
{
	Task task = Task();
	task.task_name = ONRSPQRYCURRENCY;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPICurrencyInfo* task_data = new TapAPICurrencyInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryTradeMessage(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPITradeMessage* info)
{
	Task task = Task();
	task.task_name = ONRSPQRYTRADEMESSAGE;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPITradeMessage* task_data = new TapAPITradeMessage();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnTradeMessage(const ITapTrade::TapAPITradeMessage* info)
{
	Task task = Task();
	task.task_name = ONRTNTRADEMESSAGE;
	if (info)
	{
		TapAPITradeMessage* task_data = new TapAPITradeMessage();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryHisOrder(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPIHisOrderQryRsp* info)
{
	Task task = Task();
	task.task_name = ONRSPQRYHISORDER;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIHisOrderQryRsp* task_data = new TapAPIHisOrderQryRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryHisOrderProcess(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPIHisOrderProcessQryRsp* info)
{
	Task task = Task();
	task.task_name = ONRSPQRYHISORDERPROCESS;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIHisOrderProcessQryRsp* task_data = new TapAPIHisOrderProcessQryRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryHisMatch(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPIHisMatchQryRsp* info)
{
	Task task = Task();
	task.task_name = ONRSPQRYHISMATCH;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIHisMatchQryRsp* task_data = new TapAPIHisMatchQryRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryHisPosition(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPIHisPositionQryRsp* info)
{
	Task task = Task();
	task.task_name = ONRSPQRYHISPOSITION;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIHisPositionQryRsp* task_data = new TapAPIHisPositionQryRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryHisDelivery(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPIHisDeliveryQryRsp* info)
{
	Task task = Task();
	task.task_name = ONRSPQRYHISDELIVERY;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIHisDeliveryQryRsp* task_data = new TapAPIHisDeliveryQryRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryAccountCashAdjust(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPIAccountCashAdjustQryRsp* info)
{
	Task task = Task();
	task.task_name = ONRSPQRYACCOUNTCASHADJUST;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIAccountCashAdjustQryRsp* task_data = new TapAPIAccountCashAdjustQryRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryBill(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPIBillQryRsp* info)
{
	Task task = Task();
	task.task_name = ONRSPQRYBILL;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIBillQryRsp* task_data = new TapAPIBillQryRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryAccountFeeRent(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPIAccountFeeRentQryRsp* info)
{
	Task task = Task();
	task.task_name = ONRSPQRYACCOUNTFEERENT;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIAccountFeeRentQryRsp* task_data = new TapAPIAccountFeeRentQryRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryAccountMarginRent(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPIAccountMarginRentQryRsp* info)
{
	Task task = Task();
	task.task_name = ONRSPQRYACCOUNTMARGINRENT;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIAccountMarginRentQryRsp* task_data = new TapAPIAccountMarginRentQryRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspHKMarketOrderInsert(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, const ITapTrade::TapAPIOrderMarketInsertRsp* info)
{
	Task task = Task();
	task.task_name = ONRSPHKMARKETORDERINSERT;
	task.task_id = sessionID;
	task.task_int = errorCode;
	if (info)
	{
		TapAPIOrderMarketInsertRsp* task_data = new TapAPIOrderMarketInsertRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspHKMarketOrderDelete(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, const ITapTrade::TapAPIOrderMarketDeleteRsp* info)
{
	Task task = Task();
	task.task_name = ONRSPHKMARKETORDERDELETE;
	task.task_id = sessionID;
	task.task_int = errorCode;
	if (info)
	{
		TapAPIOrderMarketDeleteRsp* task_data = new TapAPIOrderMarketDeleteRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnHKMarketQuoteNotice(const ITapTrade::TapAPIOrderQuoteMarketNotice* info)
{
	Task task = Task();
	task.task_name = ONHKMARKETQUOTENOTICE;
	if (info)
	{
		TapAPIOrderQuoteMarketNotice* task_data = new TapAPIOrderQuoteMarketNotice();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspOrderLocalRemove(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, const ITapTrade::TapAPIOrderLocalRemoveRsp* info)
{
	Task task = Task();
	task.task_name = ONRSPORDERLOCALREMOVE;
	task.task_id = sessionID;
	task.task_int = errorCode;
	if (info)
	{
		TapAPIOrderLocalRemoveRsp* task_data = new TapAPIOrderLocalRemoveRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspOrderLocalInput(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, const ITapTrade::TapAPIOrderLocalInputRsp* info)
{
	Task task = Task();
	task.task_name = ONRSPORDERLOCALINPUT;
	task.task_id = sessionID;
	task.task_int = errorCode;
	if (info)
	{
		TapAPIOrderLocalInputRsp* task_data = new TapAPIOrderLocalInputRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspOrderLocalModify(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, const ITapTrade::TapAPIOrderLocalModifyRsp* info)
{
	Task task = Task();
	task.task_name = ONRSPORDERLOCALMODIFY;
	task.task_id = sessionID;
	task.task_int = errorCode;
	if (info)
	{
		TapAPIOrderLocalModifyRsp* task_data = new TapAPIOrderLocalModifyRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspOrderLocalTransfer(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, const ITapTrade::TapAPIOrderLocalTransferRsp* info)
{
	Task task = Task();
	task.task_name = ONRSPORDERLOCALTRANSFER;
	task.task_id = sessionID;
	task.task_int = errorCode;
	if (info)
	{
		TapAPIOrderLocalTransferRsp* task_data = new TapAPIOrderLocalTransferRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspFillLocalInput(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, const ITapTrade::TapAPIFillLocalInputRsp* info)
{
	Task task = Task();
	task.task_name = ONRSPFILLLOCALINPUT;
	task.task_id = sessionID;
	task.task_int = errorCode;
	if (info)
	{
		TapAPIFillLocalInputRsp* task_data = new TapAPIFillLocalInputRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspFillLocalRemove(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, const ITapTrade::TapAPIFillLocalRemoveRsp* info)
{
	Task task = Task();
	task.task_name = ONRSPFILLLOCALREMOVE;
	task.task_id = sessionID;
	task.task_int = errorCode;
	if (info)
	{
		TapAPIFillLocalRemoveRsp* task_data = new TapAPIFillLocalRemoveRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQrySpotLock(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPISpotLockDataRsp* info)
{
	Task task = Task();
	task.task_name = ONRSPQRYSPOTLOCK;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPISpotLockDataRsp* task_data = new TapAPISpotLockDataRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnSpotLock(const ITapTrade::TapAPISpotLockDataRsp* info)
{
	Task task = Task();
	task.task_name = ONRTNSPOTLOCK;
	if (info)
	{
		TapAPISpotLockDataRsp* task_data = new TapAPISpotLockDataRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspSubmitUserLoginInfo(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPISubmitUserLoginRspInfo* info)
{
	Task task = Task();
	task.task_name = ONRSPSUBMITUSERLOGININFO;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPISubmitUserLoginRspInfo* task_data = new TapAPISubmitUserLoginRspInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspSpecialOrderAction(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, const ITapTrade::TapAPISpecialOrderInfo* info)
{
	Task task = Task();
	task.task_name = ONRSPSPECIALORDERACTION;
	task.task_id = sessionID;
	task.task_int = errorCode;
	if (info)
	{
		TapAPISpecialOrderInfo* task_data = new TapAPISpecialOrderInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnSpecialOrder(const ITapTrade::TapAPISpecialOrderInfo* info)
{
	Task task = Task();
	task.task_name = ONRTNSPECIALORDER;
	if (info)
	{
		TapAPISpecialOrderInfo* task_data = new TapAPISpecialOrderInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQrySpecialOrder(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPISpecialOrderInfo* info)
{
	Task task = Task();
	task.task_name = ONRSPQRYSPECIALORDER;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPISpecialOrderInfo* task_data = new TapAPISpecialOrderInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryCombinePosition(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const  ITapTrade::TapAPICombinePositionInfo* info)
{
	Task task = Task();
	task.task_name = ONRSPQRYCOMBINEPOSITION;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPICombinePositionInfo* task_data = new TapAPICombinePositionInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnCombinePosition(const ITapTrade::TapAPICombinePositionInfo* info)
{
	Task task = Task();
	task.task_name = ONRTNCOMBINEPOSITION;
	if (info)
	{
		TapAPICombinePositionInfo* task_data = new TapAPICombinePositionInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryUserTrustDevice(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const  ITapTrade::TapAPIUserTrustDeviceQryRsp* info)
{
	Task task = Task();
	task.task_name = ONRSPQRYUSERTRUSTDEVICE;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIUserTrustDeviceQryRsp* task_data = new TapAPIUserTrustDeviceQryRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspAddUserTrustDevice(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, const ITapTrade::TapAPIUserTrustDeviceAddRsp* info)
{
	Task task = Task();
	task.task_name = ONRSPADDUSERTRUSTDEVICE;
	task.task_id = sessionID;
	task.task_int = errorCode;
	if (info)
	{
		TapAPIUserTrustDeviceAddRsp* task_data = new TapAPIUserTrustDeviceAddRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspDelUserTrustDevice(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, const ITapTrade::TapAPIUserTrustDeviceDelRsp* info)
{
	Task task = Task();
	task.task_name = ONRSPDELUSERTRUSTDEVICE;
	task.task_id = sessionID;
	task.task_int = errorCode;
	if (info)
	{
		TapAPIUserTrustDeviceDelRsp* task_data = new TapAPIUserTrustDeviceDelRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnAddUserTrustDevice(const ITapTrade::TapAPIUserTrustDeviceAddRsp* info)
{
	Task task = Task();
	task.task_name = ONRTNADDUSERTRUSTDEVICE;
	if (info)
	{
		TapAPIUserTrustDeviceAddRsp* task_data = new TapAPIUserTrustDeviceAddRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnDelUserTrustDevice(const ITapTrade::TapAPIUserTrustDeviceDelRsp* info)
{
	Task task = Task();
	task.task_name = ONRTNDELUSERTRUSTDEVICE;
	if (info)
	{
		TapAPIUserTrustDeviceDelRsp* task_data = new TapAPIUserTrustDeviceDelRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryIPOInfo(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPIIPOInfoQryRsp* info)
{
	Task task = Task();
	task.task_name = ONRSPQRYIPOINFO;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIIPOInfoQryRsp* task_data = new TapAPIIPOInfoQryRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryIPOStockQty(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPIAvailableApplyQryRsp* info)
{
	Task task = Task();
	task.task_name = ONRSPQRYIPOSTOCKQTY;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIAvailableApplyQryRsp* task_data = new TapAPIAvailableApplyQryRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspQryAccountIPO(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, ITapTrade::TAPIYNFLAG isLast, const ITapTrade::TapAPIAccountIPOQryRsp* info)
{
	Task task = Task();
	task.task_name = ONRSPQRYACCOUNTIPO;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIAccountIPOQryRsp* task_data = new TapAPIAccountIPOQryRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspAddAccountIPO(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, const ITapTrade::TapAPIAccountIPOAddRsp* info)
{
	Task task = Task();
	task.task_name = ONRSPADDACCOUNTIPO;
	task.task_id = sessionID;
	task.task_int = errorCode;
	if (info)
	{
		TapAPIAccountIPOAddRsp* task_data = new TapAPIAccountIPOAddRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRspCancelAccountIPO(ITapTrade::TAPIUINT32 sessionID, ITapTrade::TAPIINT32 errorCode, const ITapTrade::TapAPIAccountIPOCancelRsp* info)
{
	Task task = Task();
	task.task_name = ONRSPCANCELACCOUNTIPO;
	task.task_id = sessionID;
	task.task_int = errorCode;
	if (info)
	{
		TapAPIAccountIPOCancelRsp* task_data = new TapAPIAccountIPOCancelRsp();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnAddAccountIPO(const ITapTrade::TapAPIAccountIPOAddNotice* info)
{
	Task task = Task();
	task.task_name = ONRTNADDACCOUNTIPO;
	if (info)
	{
		TapAPIAccountIPOAddNotice* task_data = new TapAPIAccountIPOAddNotice();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void TdApi::OnRtnCancelAccountIPO(const ITapTrade::TapAPIAccountIPOCancelNotice* info)
{
	Task task = Task();
	task.task_name = ONRTNCANCELACCOUNTIPO;
	if (info)
	{
		TapAPIAccountIPOCancelNotice* task_data = new TapAPIAccountIPOCancelNotice();
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

///-------------------------------------------------------------------------------------
///工作线程从队列中取出数据，转化为python对象后，进行推送
///-------------------------------------------------------------------------------------

void TdApi::processTask()
{
	try
	{
		while (this->active)
		{
			Task task = this->task_queue.pop();

			switch (task.task_name)
			{

			case ONCONNECT:
			{
				this->processConnect(&task);
				break;
			}

			case ONRSPLOGIN:
			{
				this->processRspLogin(&task);
				break;
			}

			case ONRTNCONTACTINFO:
			{
				this->processRtnContactInfo(&task);
				break;
			}

			case ONRSPREQUESTVERTIFICATECODE:
			{
				this->processRspRequestVertificateCode(&task);
				break;
			}

			case ONEXPRIATIONDATE:
			{
				this->processExpriationDate(&task);
				break;
			}

			case ONAPIREADY:
			{
				this->processAPIReady(&task);
				break;
			}

			case ONDISCONNECT:
			{
				this->processDisconnect(&task);
				break;
			}

			case ONRSPCHANGEPASSWORD:
			{
				this->processRspChangePassword(&task);
				break;
			}

			case ONRSPAUTHPASSWORD:
			{
				this->processRspAuthPassword(&task);
				break;
			}

			case ONRSPQRYTRADINGDATE:
			{
				this->processRspQryTradingDate(&task);
				break;
			}

			case ONRSPSETRESERVEDINFO:
			{
				this->processRspSetReservedInfo(&task);
				break;
			}

			case ONRSPQRYACCOUNT:
			{
				this->processRspQryAccount(&task);
				break;
			}

			case ONRSPQRYFUND:
			{
				this->processRspQryFund(&task);
				break;
			}

			case ONRTNFUND:
			{
				this->processRtnFund(&task);
				break;
			}

			case ONRSPQRYEXCHANGE:
			{
				this->processRspQryExchange(&task);
				break;
			}

			case ONRSPQRYCOMMODITY:
			{
				this->processRspQryCommodity(&task);
				break;
			}

			case ONRSPQRYCONTRACT:
			{
				this->processRspQryContract(&task);
				break;
			}

			case ONRTNCONTRACT:
			{
				this->processRtnContract(&task);
				break;
			}

			case ONRSPORDERACTION:
			{
				this->processRspOrderAction(&task);
				break;
			}

			case ONRTNORDER:
			{
				this->processRtnOrder(&task);
				break;
			}

			case ONRSPQRYORDER:
			{
				this->processRspQryOrder(&task);
				break;
			}

			case ONRSPQRYORDERPROCESS:
			{
				this->processRspQryOrderProcess(&task);
				break;
			}

			case ONRSPQRYFILL:
			{
				this->processRspQryFill(&task);
				break;
			}

			case ONRTNFILL:
			{
				this->processRtnFill(&task);
				break;
			}

			case ONRSPQRYPOSITION:
			{
				this->processRspQryPosition(&task);
				break;
			}

			case ONRTNPOSITION:
			{
				this->processRtnPosition(&task);
				break;
			}

			case ONRSPQRYPOSITIONSUMMARY:
			{
				this->processRspQryPositionSummary(&task);
				break;
			}

			case ONRTNPOSITIONSUMMARY:
			{
				this->processRtnPositionSummary(&task);
				break;
			}

			case ONRTNPOSITIONPROFIT:
			{
				this->processRtnPositionProfit(&task);
				break;
			}

			case ONRSPQRYCURRENCY:
			{
				this->processRspQryCurrency(&task);
				break;
			}

			case ONRSPQRYTRADEMESSAGE:
			{
				this->processRspQryTradeMessage(&task);
				break;
			}

			case ONRTNTRADEMESSAGE:
			{
				this->processRtnTradeMessage(&task);
				break;
			}

			case ONRSPQRYHISORDER:
			{
				this->processRspQryHisOrder(&task);
				break;
			}

			case ONRSPQRYHISORDERPROCESS:
			{
				this->processRspQryHisOrderProcess(&task);
				break;
			}

			case ONRSPQRYHISMATCH:
			{
				this->processRspQryHisMatch(&task);
				break;
			}

			case ONRSPQRYHISPOSITION:
			{
				this->processRspQryHisPosition(&task);
				break;
			}

			case ONRSPQRYHISDELIVERY:
			{
				this->processRspQryHisDelivery(&task);
				break;
			}

			case ONRSPQRYACCOUNTCASHADJUST:
			{
				this->processRspQryAccountCashAdjust(&task);
				break;
			}

			case ONRSPQRYBILL:
			{
				this->processRspQryBill(&task);
				break;
			}

			case ONRSPQRYACCOUNTFEERENT:
			{
				this->processRspQryAccountFeeRent(&task);
				break;
			}

			case ONRSPQRYACCOUNTMARGINRENT:
			{
				this->processRspQryAccountMarginRent(&task);
				break;
			}

			case ONRSPHKMARKETORDERINSERT:
			{
				this->processRspHKMarketOrderInsert(&task);
				break;
			}

			case ONRSPHKMARKETORDERDELETE:
			{
				this->processRspHKMarketOrderDelete(&task);
				break;
			}

			case ONHKMARKETQUOTENOTICE:
			{
				this->processHKMarketQuoteNotice(&task);
				break;
			}

			case ONRSPORDERLOCALREMOVE:
			{
				this->processRspOrderLocalRemove(&task);
				break;
			}

			case ONRSPORDERLOCALINPUT:
			{
				this->processRspOrderLocalInput(&task);
				break;
			}

			case ONRSPORDERLOCALMODIFY:
			{
				this->processRspOrderLocalModify(&task);
				break;
			}

			case ONRSPORDERLOCALTRANSFER:
			{
				this->processRspOrderLocalTransfer(&task);
				break;
			}

			case ONRSPFILLLOCALINPUT:
			{
				this->processRspFillLocalInput(&task);
				break;
			}

			case ONRSPFILLLOCALREMOVE:
			{
				this->processRspFillLocalRemove(&task);
				break;
			}

			case ONRSPQRYSPOTLOCK:
			{
				this->processRspQrySpotLock(&task);
				break;
			}

			case ONRTNSPOTLOCK:
			{
				this->processRtnSpotLock(&task);
				break;
			}

			case ONRSPSUBMITUSERLOGININFO:
			{
				this->processRspSubmitUserLoginInfo(&task);
				break;
			}

			case ONRSPSPECIALORDERACTION:
			{
				this->processRspSpecialOrderAction(&task);
				break;
			}

			case ONRTNSPECIALORDER:
			{
				this->processRtnSpecialOrder(&task);
				break;
			}

			case ONRSPQRYSPECIALORDER:
			{
				this->processRspQrySpecialOrder(&task);
				break;
			}

			case ONRSPQRYCOMBINEPOSITION:
			{
				this->processRspQryCombinePosition(&task);
				break;
			}

			case ONRTNCOMBINEPOSITION:
			{
				this->processRtnCombinePosition(&task);
				break;
			}

			case ONRSPQRYUSERTRUSTDEVICE:
			{
				this->processRspQryUserTrustDevice(&task);
				break;
			}

			case ONRSPADDUSERTRUSTDEVICE:
			{
				this->processRspAddUserTrustDevice(&task);
				break;
			}

			case ONRSPDELUSERTRUSTDEVICE:
			{
				this->processRspDelUserTrustDevice(&task);
				break;
			}

			case ONRTNADDUSERTRUSTDEVICE:
			{
				this->processRtnAddUserTrustDevice(&task);
				break;
			}

			case ONRTNDELUSERTRUSTDEVICE:
			{
				this->processRtnDelUserTrustDevice(&task);
				break;
			}

			case ONRSPQRYIPOINFO:
			{
				this->processRspQryIPOInfo(&task);
				break;
			}

			case ONRSPQRYIPOSTOCKQTY:
			{
				this->processRspQryIPOStockQty(&task);
				break;
			}

			case ONRSPQRYACCOUNTIPO:
			{
				this->processRspQryAccountIPO(&task);
				break;
			}

			case ONRSPADDACCOUNTIPO:
			{
				this->processRspAddAccountIPO(&task);
				break;
			}

			case ONRSPCANCELACCOUNTIPO:
			{
				this->processRspCancelAccountIPO(&task);
				break;
			}

			case ONRTNADDACCOUNTIPO:
			{
				this->processRtnAddAccountIPO(&task);
				break;
			}

			case ONRTNCANCELACCOUNTIPO:
			{
				this->processRtnCancelAccountIPO(&task);
				break;
			}

			case ONRSPUNFREEZEVERIFICATE:
			{
				this->processRspUnFreezeVerificate(&task);
				break;
			}

			};
		}
	}
	catch (const TerminatedError&)
	{
	}
};

void TdApi::processConnect(Task* task)
{
	gil_scoped_acquire acquire;
	this->onConnect(task->task_string);
};

void TdApi::processRspLogin(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPITradeLoginRspInfo* task_data = (TapAPITradeLoginRspInfo*)task->task_data;
		data["UserNo"] = toUtf(task_data->UserNo);
		data["UserType"] = task_data->UserType;
		data["UserName"] = toUtf(task_data->UserName);
		data["ReservedInfo"] = toUtf(task_data->ReservedInfo);
		data["LastLoginIP"] = toUtf(task_data->LastLoginIP);
		data["LastLoginProt"] = task_data->LastLoginProt;
		data["LastLoginTime"] = toUtf(task_data->LastLoginTime);
		data["LastLogoutTime"] = toUtf(task_data->LastLogoutTime);
		data["TradeDate"] = toUtf(task_data->TradeDate);
		data["LastSettleTime"] = toUtf(task_data->LastSettleTime);
		data["StartTime"] = toUtf(task_data->StartTime);
		data["NextSecondDate"] = toUtf(task_data->NextSecondDate);
		data["LastLoginInfo"] = toUtf(task_data->LastLoginInfo);
		delete task_data;
	}
	this->onRspLogin(task->task_int, data);
};

void TdApi::processRtnContactInfo(Task* task)
{
	gil_scoped_acquire acquire;
	this->onRtnContactInfo(task->task_int, task->task_last, task->task_string);
};

void TdApi::processRspRequestVertificateCode(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIRequestVertificateCodeRsp* task_data = (TapAPIRequestVertificateCodeRsp*)task->task_data;
		data["SecondSerialID"] = toUtf(task_data->SecondSerialID);
		data["Effective"] = task_data->Effective;
		delete task_data;
	}
	this->onRspRequestVertificateCode(task->task_id, task->task_int, data);
};

void TdApi::processExpriationDate(Task* task)
{
	gil_scoped_acquire acquire;
	this->onExpriationDate(task->task_string, task->task_int);
};

void TdApi::processAPIReady(Task* task)
{
	gil_scoped_acquire acquire;
	this->onAPIReady(task->task_int);
};

void TdApi::processDisconnect(Task* task)
{
	gil_scoped_acquire acquire;
	this->onDisconnect(task->task_int);
};

void TdApi::processRspChangePassword(Task* task)
{
	gil_scoped_acquire acquire;
	this->onRspChangePassword(task->task_id, task->task_int);
};

void TdApi::processRspAuthPassword(Task* task)
{
	gil_scoped_acquire acquire;
	this->onRspAuthPassword(task->task_id, task->task_int);
};

void TdApi::processRspQryTradingDate(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPITradingCalendarQryRsp* task_data = (TapAPITradingCalendarQryRsp*)task->task_data;
		data["CurrTradeDate"] = toUtf(task_data->CurrTradeDate);
		data["LastSettlementDate"] = toUtf(task_data->LastSettlementDate);
		data["PromptDate"] = toUtf(task_data->PromptDate);
		data["LastPromptDate"] = toUtf(task_data->LastPromptDate);
		delete task_data;
	}
	this->onRspQryTradingDate(task->task_id, task->task_int, data);
};

void TdApi::processRspSetReservedInfo(Task* task)
{
	gil_scoped_acquire acquire;
	this->onRspSetReservedInfo(task->task_id, task->task_int, task->task_string);
};

void TdApi::processRspQryAccount(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIAccountInfo* task_data = (TapAPIAccountInfo*)task->task_data;
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["AccountType"] = task_data->AccountType;
		data["AccountState"] = task_data->AccountState;
		data["AccountTradeRight"] = task_data->AccountTradeRight;
		data["CommodityGroupNo"] = toUtf(task_data->CommodityGroupNo);
		data["AccountShortName"] = toUtf(task_data->AccountShortName);
		data["AccountEnShortName"] = toUtf(task_data->AccountEnShortName);
		delete task_data;
	}
	this->onRspQryAccount(task->task_id, task->task_id, task->task_last, data);
};

void TdApi::processRspQryFund(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIFundData* task_data = (TapAPIFundData*)task->task_data;
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["CurrencyGroupNo"] = toUtf(task_data->CurrencyGroupNo);
		data["CurrencyNo"] = toUtf(task_data->CurrencyNo);
		data["TradeRate"] = task_data->TradeRate;
		data["FutureAlg"] = task_data->FutureAlg;
		data["OptionAlg"] = task_data->OptionAlg;
		data["PreBalance"] = task_data->PreBalance;
		data["PreUnExpProfit"] = task_data->PreUnExpProfit;
		data["PreLMEPositionProfit"] = task_data->PreLMEPositionProfit;
		data["PreEquity"] = task_data->PreEquity;
		data["PreAvailable1"] = task_data->PreAvailable1;
		data["PreMarketEquity"] = task_data->PreMarketEquity;
		data["CashInValue"] = task_data->CashInValue;
		data["CashOutValue"] = task_data->CashOutValue;
		data["CashAdjustValue"] = task_data->CashAdjustValue;
		data["CashPledged"] = task_data->CashPledged;
		data["FrozenFee"] = task_data->FrozenFee;
		data["FrozenDeposit"] = task_data->FrozenDeposit;
		data["AccountFee"] = task_data->AccountFee;
		data["SwapInValue"] = task_data->SwapInValue;
		data["SwapOutValue"] = task_data->SwapOutValue;
		data["PremiumIncome"] = task_data->PremiumIncome;
		data["PremiumPay"] = task_data->PremiumPay;
		data["CloseProfit"] = task_data->CloseProfit;
		data["FrozenFund"] = task_data->FrozenFund;
		data["UnExpProfit"] = task_data->UnExpProfit;
		data["ExpProfit"] = task_data->ExpProfit;
		data["PositionProfit"] = task_data->PositionProfit;
		data["LmePositionProfit"] = task_data->LmePositionProfit;
		data["OptionMarketValue"] = task_data->OptionMarketValue;
		data["AccountIntialMargin"] = task_data->AccountIntialMargin;
		data["AccountMaintenanceMargin"] = task_data->AccountMaintenanceMargin;
		data["UpperInitalMargin"] = task_data->UpperInitalMargin;
		data["UpperMaintenanceMargin"] = task_data->UpperMaintenanceMargin;
		data["Discount"] = task_data->Discount;
		data["Balance"] = task_data->Balance;
		data["Equity"] = task_data->Equity;
		data["Available"] = task_data->Available;
		data["CanDraw"] = task_data->CanDraw;
		data["MarketEquity"] = task_data->MarketEquity;
		data["AuthMoney"] = task_data->AuthMoney;
		delete task_data;
	}
	this->onRspQryFund(task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRtnFund(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIFundData* task_data = (TapAPIFundData*)task->task_data;
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["CurrencyGroupNo"] = toUtf(task_data->CurrencyGroupNo);
		data["CurrencyNo"] = toUtf(task_data->CurrencyNo);
		data["TradeRate"] = task_data->TradeRate;
		data["FutureAlg"] = task_data->FutureAlg;
		data["OptionAlg"] = task_data->OptionAlg;
		data["PreBalance"] = task_data->PreBalance;
		data["PreUnExpProfit"] = task_data->PreUnExpProfit;
		data["PreLMEPositionProfit"] = task_data->PreLMEPositionProfit;
		data["PreEquity"] = task_data->PreEquity;
		data["PreAvailable1"] = task_data->PreAvailable1;
		data["PreMarketEquity"] = task_data->PreMarketEquity;
		data["CashInValue"] = task_data->CashInValue;
		data["CashOutValue"] = task_data->CashOutValue;
		data["CashAdjustValue"] = task_data->CashAdjustValue;
		data["CashPledged"] = task_data->CashPledged;
		data["FrozenFee"] = task_data->FrozenFee;
		data["FrozenDeposit"] = task_data->FrozenDeposit;
		data["AccountFee"] = task_data->AccountFee;
		data["SwapInValue"] = task_data->SwapInValue;
		data["SwapOutValue"] = task_data->SwapOutValue;
		data["PremiumIncome"] = task_data->PremiumIncome;
		data["PremiumPay"] = task_data->PremiumPay;
		data["CloseProfit"] = task_data->CloseProfit;
		data["FrozenFund"] = task_data->FrozenFund;
		data["UnExpProfit"] = task_data->UnExpProfit;
		data["ExpProfit"] = task_data->ExpProfit;
		data["PositionProfit"] = task_data->PositionProfit;
		data["LmePositionProfit"] = task_data->LmePositionProfit;
		data["OptionMarketValue"] = task_data->OptionMarketValue;
		data["AccountIntialMargin"] = task_data->AccountIntialMargin;
		data["AccountMaintenanceMargin"] = task_data->AccountMaintenanceMargin;
		data["UpperInitalMargin"] = task_data->UpperInitalMargin;
		data["UpperMaintenanceMargin"] = task_data->UpperMaintenanceMargin;
		data["Discount"] = task_data->Discount;
		data["Balance"] = task_data->Balance;
		data["Equity"] = task_data->Equity;
		data["Available"] = task_data->Available;
		data["CanDraw"] = task_data->CanDraw;
		data["MarketEquity"] = task_data->MarketEquity;
		data["AuthMoney"] = task_data->AuthMoney;
		delete task_data;
	}
	this->onRtnFund(data);
};

void TdApi::processRspQryExchange(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIExchangeInfo* task_data = (TapAPIExchangeInfo*)task->task_data;
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["ExchangeName"] = toUtf(task_data->ExchangeName);
		delete task_data;
	}
	this->onRspQryExchange(task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRspQryCommodity(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPICommodityInfo* task_data = (TapAPICommodityInfo*)task->task_data;
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["CommodityName"] = toUtf(task_data->CommodityName);
		data["CommodityEngName"] = toUtf(task_data->CommodityEngName);
		data["RelateExchangeNo"] = toUtf(task_data->RelateExchangeNo);
		data["RelateCommodityType"] = task_data->RelateCommodityType;
		data["RelateCommodityNo"] = toUtf(task_data->RelateCommodityNo);
		data["RelateExchangeNo2"] = toUtf(task_data->RelateExchangeNo2);
		data["RelateCommodityType2"] = task_data->RelateCommodityType2;
		data["RelateCommodityNo2"] = toUtf(task_data->RelateCommodityNo2);
		data["CurrencyGroupNo"] = toUtf(task_data->CurrencyGroupNo);
		data["TradeCurrency"] = toUtf(task_data->TradeCurrency);
		data["ContractSize"] = task_data->ContractSize;
		data["OpenCloseMode"] = task_data->OpenCloseMode;
		data["StrikePriceTimes"] = task_data->StrikePriceTimes;
		data["CommodityTickSize"] = task_data->CommodityTickSize;
		data["CommodityDenominator"] = task_data->CommodityDenominator;
		data["CmbDirect"] = task_data->CmbDirect;
		data["DeliveryMode"] = task_data->DeliveryMode;
		data["DeliveryDays"] = task_data->DeliveryDays;
		data["AddOneTime"] = toUtf(task_data->AddOneTime);
		data["CommodityTimeZone"] = task_data->CommodityTimeZone;
		data["IsAddOne"] = task_data->IsAddOne;
		data["OptionType"] = task_data->OptionType;
		delete task_data;
	}
	this->onRspQryCommodity(task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRspQryContract(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPITradeContractInfo* task_data = (TapAPITradeContractInfo*)task->task_data;
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["ContractNo1"] = toUtf(task_data->ContractNo1);
		data["StrikePrice1"] = toUtf(task_data->StrikePrice1);
		data["CallOrPutFlag1"] = task_data->CallOrPutFlag1;
		data["ContractNo2"] = toUtf(task_data->ContractNo2);
		data["StrikePrice2"] = toUtf(task_data->StrikePrice2);
		data["CallOrPutFlag2"] = task_data->CallOrPutFlag2;
		data["ContractType"] = task_data->ContractType;
		data["QuoteUnderlyingContract"] = toUtf(task_data->QuoteUnderlyingContract);
		data["ContractName"] = toUtf(task_data->ContractName);
		data["ContractExpDate"] = toUtf(task_data->ContractExpDate);
		data["LastTradeDate"] = toUtf(task_data->LastTradeDate);
		data["FirstNoticeDate"] = toUtf(task_data->FirstNoticeDate);
		data["ContractSize"] = task_data->ContractSize;
		delete task_data;
	}
	this->onRspQryContract(task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRtnContract(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPITradeContractInfo* task_data = (TapAPITradeContractInfo*)task->task_data;
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["ContractNo1"] = toUtf(task_data->ContractNo1);
		data["StrikePrice1"] = toUtf(task_data->StrikePrice1);
		data["CallOrPutFlag1"] = task_data->CallOrPutFlag1;
		data["ContractNo2"] = toUtf(task_data->ContractNo2);
		data["StrikePrice2"] = toUtf(task_data->StrikePrice2);
		data["CallOrPutFlag2"] = task_data->CallOrPutFlag2;
		data["ContractType"] = task_data->ContractType;
		data["QuoteUnderlyingContract"] = toUtf(task_data->QuoteUnderlyingContract);
		data["ContractName"] = toUtf(task_data->ContractName);
		data["ContractExpDate"] = toUtf(task_data->ContractExpDate);
		data["LastTradeDate"] = toUtf(task_data->LastTradeDate);
		data["FirstNoticeDate"] = toUtf(task_data->FirstNoticeDate);
		data["ContractSize"] = task_data->ContractSize;
		delete task_data;
	}
	this->onRtnContract(data);
};

void TdApi::processRspOrderAction(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;

	if (task->task_extra)
	{
		TapAPIOrderInfo* task_extra = (TapAPIOrderInfo*)task->task_extra;
		data["AccountNo"] = toUtf(task_extra->AccountNo);
		data["ExchangeNo"] = toUtf(task_extra->ExchangeNo);
		data["CommodityType"] = task_extra->CommodityType;
		data["CommodityNo"] = toUtf(task_extra->CommodityNo);
		data["ContractNo"] = toUtf(task_extra->ContractNo);
		data["StrikePrice"] = toUtf(task_extra->StrikePrice);
		data["CallOrPutFlag"] = task_extra->CallOrPutFlag;
		data["ContractNo2"] = toUtf(task_extra->ContractNo2);
		data["StrikePrice2"] = toUtf(task_extra->StrikePrice2);
		data["CallOrPutFlag2"] = task_extra->CallOrPutFlag2;
		data["OrderType"] = task_extra->OrderType;
		data["OrderSource"] = task_extra->OrderSource;
		data["TimeInForce"] = task_extra->TimeInForce;
		data["ExpireTime"] = toUtf(task_extra->ExpireTime);
		data["IsRiskOrder"] = task_extra->IsRiskOrder;
		data["OrderSide"] = task_extra->OrderSide;
		data["PositionEffect"] = task_extra->PositionEffect;
		data["PositionEffect2"] = task_extra->PositionEffect2;
		data["InquiryNo"] = toUtf(task_extra->InquiryNo);
		data["HedgeFlag"] = task_extra->HedgeFlag;
		data["OrderPrice"] = task_extra->OrderPrice;
		data["OrderPrice2"] = task_extra->OrderPrice2;
		data["StopPrice"] = task_extra->StopPrice;
		data["OrderQty"] = task_extra->OrderQty;
		data["OrderMinQty"] = task_extra->OrderMinQty;
		data["RefInt"] = task_extra->RefInt;
		data["RefDouble"] = task_extra->RefDouble;
		data["RefString"] = toUtf(task_extra->RefString);
		data["MinClipSize"] = task_extra->MinClipSize;
		data["MaxClipSize"] = task_extra->MaxClipSize;
		data["LicenseNo"] = toUtf(task_extra->LicenseNo);
		data["ServerFlag"] = task_extra->ServerFlag;
		data["OrderNo"] = toUtf(task_extra->OrderNo);
		data["ClientOrderNo"] = toUtf(task_extra->ClientOrderNo);
		data["ClientID"] = toUtf(task_extra->ClientID);
		data["TacticsType"] = task_extra->TacticsType;
		data["TriggerCondition"] = task_extra->TriggerCondition;
		data["TriggerPriceType"] = task_extra->TriggerPriceType;
		data["AddOneIsValid"] = task_extra->AddOneIsValid;
		data["ClientLocalIP"] = toUtf(task_extra->ClientLocalIP);
		data["ClientMac"] = toUtf(task_extra->ClientMac);
		data["ClientIP"] = toUtf(task_extra->ClientIP);
		data["OrderStreamID"] = task_extra->OrderStreamID;
		data["UpperNo"] = toUtf(task_extra->UpperNo);
		data["UpperChannelNo"] = toUtf(task_extra->UpperChannelNo);
		data["OrderLocalNo"] = toUtf(task_extra->OrderLocalNo);
		data["UpperStreamID"] = task_extra->UpperStreamID;
		data["OrderSystemNo"] = toUtf(task_extra->OrderSystemNo);
		data["OrderExchangeSystemNo"] = toUtf(task_extra->OrderExchangeSystemNo);
		data["OrderParentSystemNo"] = toUtf(task_extra->OrderParentSystemNo);
		data["OrderInsertUserNo"] = toUtf(task_extra->OrderInsertUserNo);
		data["OrderInsertTime"] = toUtf(task_extra->OrderInsertTime);
		data["OrderCommandUserNo"] = toUtf(task_extra->OrderCommandUserNo);
		data["OrderUpdateUserNo"] = toUtf(task_extra->OrderUpdateUserNo);
		data["OrderUpdateTime"] = toUtf(task_extra->OrderUpdateTime);
		data["OrderState"] = task_extra->OrderState;
		data["OrderMatchPrice"] = task_extra->OrderMatchPrice;
		data["OrderMatchPrice2"] = task_extra->OrderMatchPrice2;
		data["OrderMatchQty"] = task_extra->OrderMatchQty;
		data["OrderMatchQty2"] = task_extra->OrderMatchQty2;
		data["ErrorCode"] = task_extra->ErrorCode;
		data["ErrorText"] = toUtf(task_extra->ErrorText);
		data["IsBackInput"] = task_extra->IsBackInput;
		data["IsDeleted"] = task_extra->IsDeleted;
		data["IsAddOne"] = task_extra->IsAddOne;
		data["ClientLocationID"] = task_extra->ClientLocationID;
		delete task_extra;
	}

	if (task->task_data)
	{
		TapAPIOrderActionRsp* task_data = (TapAPIOrderActionRsp*)task->task_data;
		data["ActionType"] = task_data->ActionType;
		//data["OrderInfo"] = task_data->OrderInfo;
		delete task_data;
	}
	this->onRspOrderAction(task->task_id, task->task_int, data);
};

void TdApi::processRtnOrder(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;


	if (task->task_extra)
	{
		TapAPIOrderInfo* task_extra = (TapAPIOrderInfo*)task->task_extra;
		data["AccountNo"] = toUtf(task_extra->AccountNo);
		data["ExchangeNo"] = toUtf(task_extra->ExchangeNo);
		data["CommodityType"] = task_extra->CommodityType;
		data["CommodityNo"] = toUtf(task_extra->CommodityNo);
		data["ContractNo"] = toUtf(task_extra->ContractNo);
		data["StrikePrice"] = toUtf(task_extra->StrikePrice);
		data["CallOrPutFlag"] = task_extra->CallOrPutFlag;
		data["ContractNo2"] = toUtf(task_extra->ContractNo2);
		data["StrikePrice2"] = toUtf(task_extra->StrikePrice2);
		data["CallOrPutFlag2"] = task_extra->CallOrPutFlag2;
		data["OrderType"] = task_extra->OrderType;
		data["OrderSource"] = task_extra->OrderSource;
		data["TimeInForce"] = task_extra->TimeInForce;
		data["ExpireTime"] = toUtf(task_extra->ExpireTime);
		data["IsRiskOrder"] = task_extra->IsRiskOrder;
		data["OrderSide"] = task_extra->OrderSide;
		data["PositionEffect"] = task_extra->PositionEffect;
		data["PositionEffect2"] = task_extra->PositionEffect2;
		data["InquiryNo"] = toUtf(task_extra->InquiryNo);
		data["HedgeFlag"] = task_extra->HedgeFlag;
		data["OrderPrice"] = task_extra->OrderPrice;
		data["OrderPrice2"] = task_extra->OrderPrice2;
		data["StopPrice"] = task_extra->StopPrice;
		data["OrderQty"] = task_extra->OrderQty;
		data["OrderMinQty"] = task_extra->OrderMinQty;
		data["RefInt"] = task_extra->RefInt;
		data["RefDouble"] = task_extra->RefDouble;
		data["RefString"] = toUtf(task_extra->RefString);
		data["MinClipSize"] = task_extra->MinClipSize;
		data["MaxClipSize"] = task_extra->MaxClipSize;
		data["LicenseNo"] = toUtf(task_extra->LicenseNo);
		data["ServerFlag"] = task_extra->ServerFlag;
		data["OrderNo"] = toUtf(task_extra->OrderNo);
		data["ClientOrderNo"] = toUtf(task_extra->ClientOrderNo);
		data["ClientID"] = toUtf(task_extra->ClientID);
		data["TacticsType"] = task_extra->TacticsType;
		data["TriggerCondition"] = task_extra->TriggerCondition;
		data["TriggerPriceType"] = task_extra->TriggerPriceType;
		data["AddOneIsValid"] = task_extra->AddOneIsValid;
		data["ClientLocalIP"] = toUtf(task_extra->ClientLocalIP);
		data["ClientMac"] = toUtf(task_extra->ClientMac);
		data["ClientIP"] = toUtf(task_extra->ClientIP);
		data["OrderStreamID"] = task_extra->OrderStreamID;
		data["UpperNo"] = toUtf(task_extra->UpperNo);
		data["UpperChannelNo"] = toUtf(task_extra->UpperChannelNo);
		data["OrderLocalNo"] = toUtf(task_extra->OrderLocalNo);
		data["UpperStreamID"] = task_extra->UpperStreamID;
		data["OrderSystemNo"] = toUtf(task_extra->OrderSystemNo);
		data["OrderExchangeSystemNo"] = toUtf(task_extra->OrderExchangeSystemNo);
		data["OrderParentSystemNo"] = toUtf(task_extra->OrderParentSystemNo);
		data["OrderInsertUserNo"] = toUtf(task_extra->OrderInsertUserNo);
		data["OrderInsertTime"] = toUtf(task_extra->OrderInsertTime);
		data["OrderCommandUserNo"] = toUtf(task_extra->OrderCommandUserNo);
		data["OrderUpdateUserNo"] = toUtf(task_extra->OrderUpdateUserNo);
		data["OrderUpdateTime"] = toUtf(task_extra->OrderUpdateTime);
		data["OrderState"] = task_extra->OrderState;
		data["OrderMatchPrice"] = task_extra->OrderMatchPrice;
		data["OrderMatchPrice2"] = task_extra->OrderMatchPrice2;
		data["OrderMatchQty"] = task_extra->OrderMatchQty;
		data["OrderMatchQty2"] = task_extra->OrderMatchQty2;
		data["ErrorCode"] = task_extra->ErrorCode;
		data["ErrorText"] = toUtf(task_extra->ErrorText);
		data["IsBackInput"] = task_extra->IsBackInput;
		data["IsDeleted"] = task_extra->IsDeleted;
		data["IsAddOne"] = task_extra->IsAddOne;
		data["ClientLocationID"] = task_extra->ClientLocationID;
		delete task_extra;
	}

	if (task->task_data)
	{
		TapAPIOrderInfoNotice* task_data = (TapAPIOrderInfoNotice*)task->task_data;
		data["SessionID"] = task_data->SessionID;
		data["ErrorCode"] = task_data->ErrorCode;
		//data["OrderInfo"] = task_data->OrderInfo;
		delete task_data;
	}
	this->onRtnOrder(data);
};

void TdApi::processRspQryOrder(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIOrderInfo* task_data = (TapAPIOrderInfo*)task->task_data;
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["ContractNo"] = toUtf(task_data->ContractNo);
		data["StrikePrice"] = toUtf(task_data->StrikePrice);
		data["CallOrPutFlag"] = task_data->CallOrPutFlag;
		data["ContractNo2"] = toUtf(task_data->ContractNo2);
		data["StrikePrice2"] = toUtf(task_data->StrikePrice2);
		data["CallOrPutFlag2"] = task_data->CallOrPutFlag2;
		data["OrderType"] = task_data->OrderType;
		data["OrderSource"] = task_data->OrderSource;
		data["TimeInForce"] = task_data->TimeInForce;
		data["ExpireTime"] = toUtf(task_data->ExpireTime);
		data["IsRiskOrder"] = task_data->IsRiskOrder;
		data["OrderSide"] = task_data->OrderSide;
		data["PositionEffect"] = task_data->PositionEffect;
		data["PositionEffect2"] = task_data->PositionEffect2;
		data["InquiryNo"] = toUtf(task_data->InquiryNo);
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["OrderPrice"] = task_data->OrderPrice;
		data["OrderPrice2"] = task_data->OrderPrice2;
		data["StopPrice"] = task_data->StopPrice;
		data["OrderQty"] = task_data->OrderQty;
		data["OrderMinQty"] = task_data->OrderMinQty;
		data["RefInt"] = task_data->RefInt;
		data["RefDouble"] = task_data->RefDouble;
		data["RefString"] = toUtf(task_data->RefString);
		data["MinClipSize"] = task_data->MinClipSize;
		data["MaxClipSize"] = task_data->MaxClipSize;
		data["LicenseNo"] = toUtf(task_data->LicenseNo);
		data["ServerFlag"] = task_data->ServerFlag;
		data["OrderNo"] = toUtf(task_data->OrderNo);
		data["ClientOrderNo"] = toUtf(task_data->ClientOrderNo);
		data["ClientID"] = toUtf(task_data->ClientID);
		data["TacticsType"] = task_data->TacticsType;
		data["TriggerCondition"] = task_data->TriggerCondition;
		data["TriggerPriceType"] = task_data->TriggerPriceType;
		data["AddOneIsValid"] = task_data->AddOneIsValid;
		data["ClientLocalIP"] = toUtf(task_data->ClientLocalIP);
		data["ClientMac"] = toUtf(task_data->ClientMac);
		data["ClientIP"] = toUtf(task_data->ClientIP);
		data["OrderStreamID"] = task_data->OrderStreamID;
		data["UpperNo"] = toUtf(task_data->UpperNo);
		data["UpperChannelNo"] = toUtf(task_data->UpperChannelNo);
		data["OrderLocalNo"] = toUtf(task_data->OrderLocalNo);
		data["UpperStreamID"] = task_data->UpperStreamID;
		data["OrderSystemNo"] = toUtf(task_data->OrderSystemNo);
		data["OrderExchangeSystemNo"] = toUtf(task_data->OrderExchangeSystemNo);
		data["OrderParentSystemNo"] = toUtf(task_data->OrderParentSystemNo);
		data["OrderInsertUserNo"] = toUtf(task_data->OrderInsertUserNo);
		data["OrderInsertTime"] = toUtf(task_data->OrderInsertTime);
		data["OrderCommandUserNo"] = toUtf(task_data->OrderCommandUserNo);
		data["OrderUpdateUserNo"] = toUtf(task_data->OrderUpdateUserNo);
		data["OrderUpdateTime"] = toUtf(task_data->OrderUpdateTime);
		data["OrderState"] = task_data->OrderState;
		data["OrderMatchPrice"] = task_data->OrderMatchPrice;
		data["OrderMatchPrice2"] = task_data->OrderMatchPrice2;
		data["OrderMatchQty"] = task_data->OrderMatchQty;
		data["OrderMatchQty2"] = task_data->OrderMatchQty2;
		data["ErrorCode"] = task_data->ErrorCode;
		data["ErrorText"] = toUtf(task_data->ErrorText);
		data["IsBackInput"] = task_data->IsBackInput;
		data["IsDeleted"] = task_data->IsDeleted;
		data["IsAddOne"] = task_data->IsAddOne;
		data["ClientLocationID"] = toUtf(task_data->ClientLocationID);
		delete task_data;
	}
	this->onRspQryOrder(task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRspQryOrderProcess(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIOrderInfo* task_data = (TapAPIOrderInfo*)task->task_data;
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["ContractNo"] = toUtf(task_data->ContractNo);
		data["StrikePrice"] = toUtf(task_data->StrikePrice);
		data["CallOrPutFlag"] = task_data->CallOrPutFlag;
		data["ContractNo2"] = toUtf(task_data->ContractNo2);
		data["StrikePrice2"] = toUtf(task_data->StrikePrice2);
		data["CallOrPutFlag2"] = task_data->CallOrPutFlag2;
		data["OrderType"] = task_data->OrderType;
		data["OrderSource"] = task_data->OrderSource;
		data["TimeInForce"] = task_data->TimeInForce;
		data["ExpireTime"] = toUtf(task_data->ExpireTime);
		data["IsRiskOrder"] = task_data->IsRiskOrder;
		data["OrderSide"] = task_data->OrderSide;
		data["PositionEffect"] = task_data->PositionEffect;
		data["PositionEffect2"] = task_data->PositionEffect2;
		data["InquiryNo"] = toUtf(task_data->InquiryNo);
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["OrderPrice"] = task_data->OrderPrice;
		data["OrderPrice2"] = task_data->OrderPrice2;
		data["StopPrice"] = task_data->StopPrice;
		data["OrderQty"] = task_data->OrderQty;
		data["OrderMinQty"] = task_data->OrderMinQty;
		data["RefInt"] = task_data->RefInt;
		data["RefDouble"] = task_data->RefDouble;
		data["RefString"] = toUtf(task_data->RefString);
		data["MinClipSize"] = task_data->MinClipSize;
		data["MaxClipSize"] = task_data->MaxClipSize;
		data["LicenseNo"] = toUtf(task_data->LicenseNo);
		data["ServerFlag"] = task_data->ServerFlag;
		data["OrderNo"] = toUtf(task_data->OrderNo);
		data["ClientOrderNo"] = toUtf(task_data->ClientOrderNo);
		data["ClientID"] = toUtf(task_data->ClientID);
		data["TacticsType"] = task_data->TacticsType;
		data["TriggerCondition"] = task_data->TriggerCondition;
		data["TriggerPriceType"] = task_data->TriggerPriceType;
		data["AddOneIsValid"] = task_data->AddOneIsValid;
		data["ClientLocalIP"] = toUtf(task_data->ClientLocalIP);
		data["ClientMac"] = toUtf(task_data->ClientMac);
		data["ClientIP"] = toUtf(task_data->ClientIP);
		data["OrderStreamID"] = task_data->OrderStreamID;
		data["UpperNo"] = toUtf(task_data->UpperNo);
		data["UpperChannelNo"] = toUtf(task_data->UpperChannelNo);
		data["OrderLocalNo"] = toUtf(task_data->OrderLocalNo);
		data["UpperStreamID"] = task_data->UpperStreamID;
		data["OrderSystemNo"] = toUtf(task_data->OrderSystemNo);
		data["OrderExchangeSystemNo"] = toUtf(task_data->OrderExchangeSystemNo);
		data["OrderParentSystemNo"] = toUtf(task_data->OrderParentSystemNo);
		data["OrderInsertUserNo"] = toUtf(task_data->OrderInsertUserNo);
		data["OrderInsertTime"] = toUtf(task_data->OrderInsertTime);
		data["OrderCommandUserNo"] = toUtf(task_data->OrderCommandUserNo);
		data["OrderUpdateUserNo"] = toUtf(task_data->OrderUpdateUserNo);
		data["OrderUpdateTime"] = toUtf(task_data->OrderUpdateTime);
		data["OrderState"] = task_data->OrderState;
		data["OrderMatchPrice"] = task_data->OrderMatchPrice;
		data["OrderMatchPrice2"] = task_data->OrderMatchPrice2;
		data["OrderMatchQty"] = task_data->OrderMatchQty;
		data["OrderMatchQty2"] = task_data->OrderMatchQty2;
		data["ErrorCode"] = task_data->ErrorCode;
		data["ErrorText"] = toUtf(task_data->ErrorText);
		data["IsBackInput"] = task_data->IsBackInput;
		data["IsDeleted"] = task_data->IsDeleted;
		data["IsAddOne"] = task_data->IsAddOne;
		data["ClientLocationID"] = toUtf(task_data->ClientLocationID);
		delete task_data;
	}
	this->onRspQryOrderProcess(task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRspQryFill(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIFillInfo* task_data = (TapAPIFillInfo*)task->task_data;
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["ContractNo"] = toUtf(task_data->ContractNo);
		data["StrikePrice"] = toUtf(task_data->StrikePrice);
		data["CallOrPutFlag"] = task_data->CallOrPutFlag;
		data["MatchSource"] = task_data->MatchSource;
		data["MatchSide"] = task_data->MatchSide;
		data["PositionEffect"] = task_data->PositionEffect;
		data["ServerFlag"] = task_data->ServerFlag;
		data["OrderNo"] = toUtf(task_data->OrderNo);
		data["OrderSystemNo"] = toUtf(task_data->OrderSystemNo);
		data["MatchNo"] = toUtf(task_data->MatchNo);
		data["UpperMatchNo"] = toUtf(task_data->UpperMatchNo);
		data["ExchangeMatchNo"] = toUtf(task_data->ExchangeMatchNo);
		data["MatchDateTime"] = toUtf(task_data->MatchDateTime);
		data["UpperMatchDateTime"] = toUtf(task_data->UpperMatchDateTime);
		data["UpperNo"] = toUtf(task_data->UpperNo);
		data["MatchPrice"] = task_data->MatchPrice;
		data["MatchQty"] = task_data->MatchQty;
		data["IsDeleted"] = task_data->IsDeleted;
		data["IsAddOne"] = task_data->IsAddOne;
		data["FeeCurrencyGroup"] = toUtf(task_data->FeeCurrencyGroup);
		data["FeeCurrency"] = toUtf(task_data->FeeCurrency);
		data["FeeValue"] = task_data->FeeValue;
		data["IsManualFee"] = task_data->IsManualFee;
		data["ClosePrositionPrice"] = task_data->ClosePrositionPrice;
		data["CloseProfit"] = task_data->CloseProfit;
		delete task_data;
	}
	this->onRspQryFill(task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRtnFill(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIFillInfo* task_data = (TapAPIFillInfo*)task->task_data;
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["ContractNo"] = toUtf(task_data->ContractNo);
		data["StrikePrice"] = toUtf(task_data->StrikePrice);
		data["CallOrPutFlag"] = task_data->CallOrPutFlag;
		data["MatchSource"] = task_data->MatchSource;
		data["MatchSide"] = task_data->MatchSide;
		data["PositionEffect"] = task_data->PositionEffect;
		data["ServerFlag"] = task_data->ServerFlag;
		data["OrderNo"] = toUtf(task_data->OrderNo);
		data["OrderSystemNo"] = toUtf(task_data->OrderSystemNo);
		data["MatchNo"] = toUtf(task_data->MatchNo);
		data["UpperMatchNo"] = toUtf(task_data->UpperMatchNo);
		data["ExchangeMatchNo"] = toUtf(task_data->ExchangeMatchNo);
		data["MatchDateTime"] = toUtf(task_data->MatchDateTime);
		data["UpperMatchDateTime"] = toUtf(task_data->UpperMatchDateTime);
		data["UpperNo"] = toUtf(task_data->UpperNo);
		data["MatchPrice"] = task_data->MatchPrice;
		data["MatchQty"] = task_data->MatchQty;
		data["IsDeleted"] = task_data->IsDeleted;
		data["IsAddOne"] = task_data->IsAddOne;
		data["FeeCurrencyGroup"] = toUtf(task_data->FeeCurrencyGroup);
		data["FeeCurrency"] = toUtf(task_data->FeeCurrency);
		data["FeeValue"] = task_data->FeeValue;
		data["IsManualFee"] = task_data->IsManualFee;
		data["ClosePrositionPrice"] = task_data->ClosePrositionPrice;
		data["CloseProfit"] = task_data->CloseProfit;
		delete task_data;
	}
	this->onRtnFill(data);
};

void TdApi::processRspQryPosition(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIPositionInfo* task_data = (TapAPIPositionInfo*)task->task_data;
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["ContractNo"] = toUtf(task_data->ContractNo);
		data["StrikePrice"] = toUtf(task_data->StrikePrice);
		data["CallOrPutFlag"] = task_data->CallOrPutFlag;
		data["MatchSide"] = task_data->MatchSide;
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["PositionNo"] = toUtf(task_data->PositionNo);
		data["ServerFlag"] = task_data->ServerFlag;
		data["OrderNo"] = toUtf(task_data->OrderNo);
		data["MatchNo"] = toUtf(task_data->MatchNo);
		data["UpperNo"] = toUtf(task_data->UpperNo);
		data["PositionPrice"] = task_data->PositionPrice;
		data["PositionQty"] = task_data->PositionQty;
		data["PositionStreamId"] = task_data->PositionStreamId;
		data["CommodityCurrencyGroup"] = toUtf(task_data->CommodityCurrencyGroup);
		data["CommodityCurrency"] = toUtf(task_data->CommodityCurrency);
		data["CalculatePrice"] = task_data->CalculatePrice;
		data["AccountInitialMargin"] = task_data->AccountInitialMargin;
		data["AccountMaintenanceMargin"] = task_data->AccountMaintenanceMargin;
		data["UpperInitialMargin"] = task_data->UpperInitialMargin;
		data["UpperMaintenanceMargin"] = task_data->UpperMaintenanceMargin;
		data["PositionProfit"] = task_data->PositionProfit;
		data["LMEPositionProfit"] = task_data->LMEPositionProfit;
		data["OptionMarketValue"] = task_data->OptionMarketValue;
		data["IsHistory"] = task_data->IsHistory;
		delete task_data;
	}
	this->onRspQryPosition(task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRtnPosition(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIPositionInfo* task_data = (TapAPIPositionInfo*)task->task_data;
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["ContractNo"] = toUtf(task_data->ContractNo);
		data["StrikePrice"] = toUtf(task_data->StrikePrice);
		data["CallOrPutFlag"] = task_data->CallOrPutFlag;
		data["MatchSide"] = task_data->MatchSide;
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["PositionNo"] = toUtf(task_data->PositionNo);
		data["ServerFlag"] = task_data->ServerFlag;
		data["OrderNo"] = toUtf(task_data->OrderNo);
		data["MatchNo"] = toUtf(task_data->MatchNo);
		data["UpperNo"] = toUtf(task_data->UpperNo);
		data["PositionPrice"] = task_data->PositionPrice;
		data["PositionQty"] = task_data->PositionQty;
		data["PositionStreamId"] = task_data->PositionStreamId;
		data["CommodityCurrencyGroup"] = toUtf(task_data->CommodityCurrencyGroup);
		data["CommodityCurrency"] = toUtf(task_data->CommodityCurrency);
		data["CalculatePrice"] = task_data->CalculatePrice;
		data["AccountInitialMargin"] = task_data->AccountInitialMargin;
		data["AccountMaintenanceMargin"] = task_data->AccountMaintenanceMargin;
		data["UpperInitialMargin"] = task_data->UpperInitialMargin;
		data["UpperMaintenanceMargin"] = task_data->UpperMaintenanceMargin;
		data["PositionProfit"] = task_data->PositionProfit;
		data["LMEPositionProfit"] = task_data->LMEPositionProfit;
		data["OptionMarketValue"] = task_data->OptionMarketValue;
		data["IsHistory"] = task_data->IsHistory;
		delete task_data;
	}
	this->onRtnPosition(data);
};

void TdApi::processRspQryPositionSummary(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIPositionSummary* task_data = (TapAPIPositionSummary*)task->task_data;
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["ContractNo"] = toUtf(task_data->ContractNo);
		data["StrikePrice"] = toUtf(task_data->StrikePrice);
		data["CallOrPutFlag"] = task_data->CallOrPutFlag;
		data["MatchSide"] = task_data->MatchSide;
		data["PositionPrice"] = task_data->PositionPrice;
		data["PositionQty"] = task_data->PositionQty;
		data["HisPositionQty"] = task_data->HisPositionQty;
		delete task_data;
	}
	this->onRspQryPositionSummary(task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRtnPositionSummary(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIPositionSummary* task_data = (TapAPIPositionSummary*)task->task_data;
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["ContractNo"] = toUtf(task_data->ContractNo);
		data["StrikePrice"] = toUtf(task_data->StrikePrice);
		data["CallOrPutFlag"] = task_data->CallOrPutFlag;
		data["MatchSide"] = task_data->MatchSide;
		data["PositionPrice"] = task_data->PositionPrice;
		data["PositionQty"] = task_data->PositionQty;
		data["HisPositionQty"] = task_data->HisPositionQty;
		delete task_data;
	}
	this->onRtnPositionSummary(data);
};

void TdApi::processRtnPositionProfit(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;

	if (task->task_extra)
	{
		TapAPIPositionProfit* task_extra = (TapAPIPositionProfit*)task->task_extra;
		data["PositionNo"] = toUtf(task_extra->PositionNo);
		data["PositionStreamId"] = task_extra->PositionStreamId;
		data["PositionProfit"] = task_extra->PositionProfit;
		data["LMEPositionProfit"] = task_extra->LMEPositionProfit;
		data["OptionMarketValue"] = task_extra->OptionMarketValue;
		data["CalculatePrice"] = task_extra->CalculatePrice;
		delete task_extra;
	}

	if (task->task_data)
	{
		TapAPIPositionProfitNotice* task_data = (TapAPIPositionProfitNotice*)task->task_data;
		data["IsLast"] = task_data->IsLast;
		//data["Data"] = task_data->Data;
		delete task_data;
	}

	this->onRtnPositionProfit(data);
};

void TdApi::processRspQryCurrency(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPICurrencyInfo* task_data = (TapAPICurrencyInfo*)task->task_data;
		data["CurrencyNo"] = toUtf(task_data->CurrencyNo);
		data["CurrencyGroupNo"] = toUtf(task_data->CurrencyGroupNo);
		data["TradeRate"] = task_data->TradeRate;
		data["TradeRate2"] = task_data->TradeRate2;
		data["FutureAlg"] = task_data->FutureAlg;
		data["OptionAlg"] = task_data->OptionAlg;
		delete task_data;
	}
	this->onRspQryCurrency(task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRspQryTradeMessage(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPITradeMessage* task_data = (TapAPITradeMessage*)task->task_data;
		data["SerialID"] = task_data->SerialID;
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["TMsgValidDateTime"] = toUtf(task_data->TMsgValidDateTime);
		data["TMsgTitle"] = toUtf(task_data->TMsgTitle);
		data["TMsgContent"] = toUtf(task_data->TMsgContent);
		data["TMsgType"] = task_data->TMsgType;
		data["TMsgLevel"] = task_data->TMsgLevel;
		data["IsSendBySMS"] = task_data->IsSendBySMS;
		data["IsSendByEMail"] = task_data->IsSendByEMail;
		data["Sender"] = toUtf(task_data->Sender);
		data["SendDateTime"] = toUtf(task_data->SendDateTime);
		delete task_data;
	}
	this->onRspQryTradeMessage(task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRtnTradeMessage(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPITradeMessage* task_data = (TapAPITradeMessage*)task->task_data;
		data["SerialID"] = task_data->SerialID;
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["TMsgValidDateTime"] = toUtf(task_data->TMsgValidDateTime);
		data["TMsgTitle"] = toUtf(task_data->TMsgTitle);
		data["TMsgContent"] = toUtf(task_data->TMsgContent);
		data["TMsgType"] = task_data->TMsgType;
		data["TMsgLevel"] = task_data->TMsgLevel;
		data["IsSendBySMS"] = task_data->IsSendBySMS;
		data["IsSendByEMail"] = task_data->IsSendByEMail;
		data["Sender"] = toUtf(task_data->Sender);
		data["SendDateTime"] = toUtf(task_data->SendDateTime);
		delete task_data;
	}
	this->onRtnTradeMessage(data);
};

void TdApi::processRspQryHisOrder(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIHisOrderQryRsp* task_data = (TapAPIHisOrderQryRsp*)task->task_data;
		data["Date"] = toUtf(task_data->Date);
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["ContractNo"] = toUtf(task_data->ContractNo);
		data["StrikePrice"] = toUtf(task_data->StrikePrice);
		data["CallOrPutFlag"] = task_data->CallOrPutFlag;
		data["ContractNo2"] = toUtf(task_data->ContractNo2);
		data["StrikePrice2"] = toUtf(task_data->StrikePrice2);
		data["CallOrPutFlag2"] = task_data->CallOrPutFlag2;
		data["OrderType"] = task_data->OrderType;
		data["OrderSource"] = task_data->OrderSource;
		data["TimeInForce"] = task_data->TimeInForce;
		data["ExpireTime"] = toUtf(task_data->ExpireTime);
		data["IsRiskOrder"] = task_data->IsRiskOrder;
		data["OrderSide"] = task_data->OrderSide;
		data["PositionEffect"] = task_data->PositionEffect;
		data["PositionEffect2"] = task_data->PositionEffect2;
		data["InquiryNo"] = toUtf(task_data->InquiryNo);
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["OrderPrice"] = task_data->OrderPrice;
		data["OrderPrice2"] = task_data->OrderPrice2;
		data["StopPrice"] = task_data->StopPrice;
		data["OrderQty"] = task_data->OrderQty;
		data["OrderMinQty"] = task_data->OrderMinQty;
		data["OrderCanceledQty"] = task_data->OrderCanceledQty;
		data["RefInt"] = task_data->RefInt;
		data["RefDouble"] = task_data->RefDouble;
		data["RefString"] = toUtf(task_data->RefString);
		data["ServerFlag"] = task_data->ServerFlag;
		data["OrderNo"] = toUtf(task_data->OrderNo);
		data["OrderStreamID"] = task_data->OrderStreamID;
		data["UpperNo"] = toUtf(task_data->UpperNo);
		data["UpperChannelNo"] = toUtf(task_data->UpperChannelNo);
		data["OrderLocalNo"] = toUtf(task_data->OrderLocalNo);
		data["UpperStreamID"] = task_data->UpperStreamID;
		data["OrderSystemNo"] = toUtf(task_data->OrderSystemNo);
		data["OrderExchangeSystemNo"] = toUtf(task_data->OrderExchangeSystemNo);
		data["OrderParentSystemNo"] = toUtf(task_data->OrderParentSystemNo);
		data["OrderInsertUserNo"] = toUtf(task_data->OrderInsertUserNo);
		data["OrderInsertTime"] = toUtf(task_data->OrderInsertTime);
		data["OrderCommandUserNo"] = toUtf(task_data->OrderCommandUserNo);
		data["OrderUpdateUserNo"] = toUtf(task_data->OrderUpdateUserNo);
		data["OrderUpdateTime"] = toUtf(task_data->OrderUpdateTime);
		data["OrderState"] = task_data->OrderState;
		data["OrderMatchPrice"] = task_data->OrderMatchPrice;
		data["OrderMatchPrice2"] = task_data->OrderMatchPrice2;
		data["OrderMatchQty"] = task_data->OrderMatchQty;
		data["OrderMatchQty2"] = task_data->OrderMatchQty2;
		data["ErrorCode"] = task_data->ErrorCode;
		data["ErrorText"] = toUtf(task_data->ErrorText);
		data["IsBackInput"] = task_data->IsBackInput;
		data["IsDeleted"] = task_data->IsDeleted;
		data["IsAddOne"] = task_data->IsAddOne;
		data["AddOneIsValid"] = task_data->AddOneIsValid;
		data["MinClipSize"] = task_data->MinClipSize;
		data["MaxClipSize"] = task_data->MaxClipSize;
		data["LicenseNo"] = toUtf(task_data->LicenseNo);
		data["TacticsType"] = task_data->TacticsType;
		data["TriggerCondition"] = task_data->TriggerCondition;
		data["TriggerPriceType"] = task_data->TriggerPriceType;
		delete task_data;
	}
	this->onRspQryHisOrder(task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRspQryHisOrderProcess(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIHisOrderProcessQryRsp* task_data = (TapAPIHisOrderProcessQryRsp*)task->task_data;
		data["Date"] = toUtf(task_data->Date);
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["ContractNo"] = toUtf(task_data->ContractNo);
		data["StrikePrice"] = toUtf(task_data->StrikePrice);
		data["CallOrPutFlag"] = task_data->CallOrPutFlag;
		data["ContractNo2"] = toUtf(task_data->ContractNo2);
		data["StrikePrice2"] = toUtf(task_data->StrikePrice2);
		data["CallOrPutFlag2"] = task_data->CallOrPutFlag2;
		data["OrderType"] = task_data->OrderType;
		data["OrderSource"] = task_data->OrderSource;
		data["TimeInForce"] = task_data->TimeInForce;
		data["ExpireTime"] = toUtf(task_data->ExpireTime);
		data["IsRiskOrder"] = task_data->IsRiskOrder;
		data["OrderSide"] = task_data->OrderSide;
		data["PositionEffect"] = task_data->PositionEffect;
		data["PositionEffect2"] = task_data->PositionEffect2;
		data["InquiryNo"] = toUtf(task_data->InquiryNo);
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["OrderPrice"] = task_data->OrderPrice;
		data["OrderPrice2"] = task_data->OrderPrice2;
		data["StopPrice"] = task_data->StopPrice;
		data["OrderQty"] = task_data->OrderQty;
		data["OrderMinQty"] = task_data->OrderMinQty;
		data["OrderCanceledQty"] = task_data->OrderCanceledQty;
		data["RefInt"] = task_data->RefInt;
		data["RefDouble"] = task_data->RefDouble;
		data["RefString"] = toUtf(task_data->RefString);
		data["ServerFlag"] = task_data->ServerFlag;
		data["OrderNo"] = toUtf(task_data->OrderNo);
		data["OrderStreamID"] = task_data->OrderStreamID;
		data["UpperNo"] = toUtf(task_data->UpperNo);
		data["UpperChannelNo"] = toUtf(task_data->UpperChannelNo);
		data["OrderLocalNo"] = toUtf(task_data->OrderLocalNo);
		data["UpperStreamID"] = task_data->UpperStreamID;
		data["OrderSystemNo"] = toUtf(task_data->OrderSystemNo);
		data["OrderExchangeSystemNo"] = toUtf(task_data->OrderExchangeSystemNo);
		data["OrderParentSystemNo"] = toUtf(task_data->OrderParentSystemNo);
		data["OrderInsertUserNo"] = toUtf(task_data->OrderInsertUserNo);
		data["OrderInsertTime"] = toUtf(task_data->OrderInsertTime);
		data["OrderCommandUserNo"] = toUtf(task_data->OrderCommandUserNo);
		data["OrderUpdateUserNo"] = toUtf(task_data->OrderUpdateUserNo);
		data["OrderUpdateTime"] = toUtf(task_data->OrderUpdateTime);
		data["OrderState"] = task_data->OrderState;
		data["OrderMatchPrice"] = task_data->OrderMatchPrice;
		data["OrderMatchPrice2"] = task_data->OrderMatchPrice2;
		data["OrderMatchQty"] = task_data->OrderMatchQty;
		data["OrderMatchQty2"] = task_data->OrderMatchQty2;
		data["ErrorCode"] = task_data->ErrorCode;
		data["ErrorText"] = toUtf(task_data->ErrorText);
		data["IsBackInput"] = task_data->IsBackInput;
		data["IsDeleted"] = task_data->IsDeleted;
		data["IsAddOne"] = task_data->IsAddOne;
		data["AddOneIsValid"] = task_data->AddOneIsValid;
		data["MinClipSize"] = task_data->MinClipSize;
		data["MaxClipSize"] = task_data->MaxClipSize;
		data["LicenseNo"] = toUtf(task_data->LicenseNo);
		data["TacticsType"] = task_data->TacticsType;
		data["TriggerCondition"] = task_data->TriggerCondition;
		data["TriggerPriceType"] = task_data->TriggerPriceType;
		delete task_data;
	}
	this->onRspQryHisOrderProcess(task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRspQryHisMatch(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIHisMatchQryRsp* task_data = (TapAPIHisMatchQryRsp*)task->task_data;
		data["SettleDate"] = toUtf(task_data->SettleDate);
		data["TradeDate"] = toUtf(task_data->TradeDate);
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["ContractNo"] = toUtf(task_data->ContractNo);
		data["StrikePrice"] = toUtf(task_data->StrikePrice);
		data["CallOrPutFlag"] = task_data->CallOrPutFlag;
		data["MatchSource"] = task_data->MatchSource;
		data["MatchSide"] = task_data->MatchSide;
		data["PositionEffect"] = task_data->PositionEffect;
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["MatchPrice"] = task_data->MatchPrice;
		data["MatchQty"] = task_data->MatchQty;
		data["OrderNo"] = toUtf(task_data->OrderNo);
		data["MatchNo"] = toUtf(task_data->MatchNo);
		data["MatchStreamID"] = task_data->MatchStreamID;
		data["UpperNo"] = toUtf(task_data->UpperNo);
		data["MatchCmbNo"] = toUtf(task_data->MatchCmbNo);
		data["ExchangeMatchNo"] = toUtf(task_data->ExchangeMatchNo);
		data["MatchUpperStreamID"] = task_data->MatchUpperStreamID;
		data["CommodityCurrencyGroup"] = toUtf(task_data->CommodityCurrencyGroup);
		data["CommodityCurrency"] = toUtf(task_data->CommodityCurrency);
		data["Turnover"] = task_data->Turnover;
		data["PremiumIncome"] = task_data->PremiumIncome;
		data["PremiumPay"] = task_data->PremiumPay;
		data["AccountFee"] = task_data->AccountFee;
		data["AccountFeeCurrencyGroup"] = toUtf(task_data->AccountFeeCurrencyGroup);
		data["AccountFeeCurrency"] = toUtf(task_data->AccountFeeCurrency);
		data["IsManualFee"] = task_data->IsManualFee;
		data["AccountOtherFee"] = task_data->AccountOtherFee;
		data["UpperFee"] = task_data->UpperFee;
		data["UpperFeeCurrencyGroup"] = toUtf(task_data->UpperFeeCurrencyGroup);
		data["UpperFeeCurrency"] = toUtf(task_data->UpperFeeCurrency);
		data["IsUpperManualFee"] = task_data->IsUpperManualFee;
		data["UpperOtherFee"] = task_data->UpperOtherFee;
		data["MatchDateTime"] = toUtf(task_data->MatchDateTime);
		data["UpperMatchDateTime"] = toUtf(task_data->UpperMatchDateTime);
		data["CloseProfit"] = task_data->CloseProfit;
		data["ClosePrice"] = task_data->ClosePrice;
		data["CloseQty"] = task_data->CloseQty;
		data["SettleGroupNo"] = toUtf(task_data->SettleGroupNo);
		data["OperatorNo"] = toUtf(task_data->OperatorNo);
		data["OperateTime"] = toUtf(task_data->OperateTime);
		delete task_data;
	}
	this->onRspQryHisMatch(task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRspQryHisPosition(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIHisPositionQryRsp* task_data = (TapAPIHisPositionQryRsp*)task->task_data;
		data["SettleDate"] = toUtf(task_data->SettleDate);
		data["OpenDate"] = toUtf(task_data->OpenDate);
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["ContractNo"] = toUtf(task_data->ContractNo);
		data["StrikePrice"] = toUtf(task_data->StrikePrice);
		data["CallOrPutFlag"] = task_data->CallOrPutFlag;
		data["MatchSide"] = task_data->MatchSide;
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["PositionPrice"] = task_data->PositionPrice;
		data["PositionQty"] = task_data->PositionQty;
		data["OrderNo"] = toUtf(task_data->OrderNo);
		data["PositionNo"] = toUtf(task_data->PositionNo);
		data["UpperNo"] = toUtf(task_data->UpperNo);
		data["CurrencyGroup"] = toUtf(task_data->CurrencyGroup);
		data["Currency"] = toUtf(task_data->Currency);
		data["PreSettlePrice"] = task_data->PreSettlePrice;
		data["SettlePrice"] = task_data->SettlePrice;
		data["PositionDProfit"] = task_data->PositionDProfit;
		data["LMEPositionProfit"] = task_data->LMEPositionProfit;
		data["OptionMarketValue"] = task_data->OptionMarketValue;
		data["AccountInitialMargin"] = task_data->AccountInitialMargin;
		data["AccountMaintenanceMargin"] = task_data->AccountMaintenanceMargin;
		data["UpperInitialMargin"] = task_data->UpperInitialMargin;
		data["UpperMaintenanceMargin"] = task_data->UpperMaintenanceMargin;
		data["SettleGroupNo"] = toUtf(task_data->SettleGroupNo);
		data["ServerFlag"] = task_data->ServerFlag;
		data["SuperiorAccount"] = toUtf(task_data->SuperiorAccount);
		delete task_data;
	}
	this->onRspQryHisPosition(task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRspQryHisDelivery(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIHisDeliveryQryRsp* task_data = (TapAPIHisDeliveryQryRsp*)task->task_data;
		data["DeliveryDate"] = toUtf(task_data->DeliveryDate);
		data["OpenDate"] = toUtf(task_data->OpenDate);
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["ContractNo"] = toUtf(task_data->ContractNo);
		data["StrikePrice"] = toUtf(task_data->StrikePrice);
		data["CallOrPutFlag"] = task_data->CallOrPutFlag;
		data["MatchSource"] = task_data->MatchSource;
		data["OpenSide"] = task_data->OpenSide;
		data["OpenPrice"] = task_data->OpenPrice;
		data["DeliveryPrice"] = task_data->DeliveryPrice;
		data["DeliveryQty"] = task_data->DeliveryQty;
		data["FrozenQty"] = task_data->FrozenQty;
		data["OpenNo"] = toUtf(task_data->OpenNo);
		data["UpperNo"] = toUtf(task_data->UpperNo);
		data["CommodityCurrencyGroupy"] = toUtf(task_data->CommodityCurrencyGroupy);
		data["CommodityCurrency"] = toUtf(task_data->CommodityCurrency);
		data["PreSettlePrice"] = task_data->PreSettlePrice;
		data["DeliveryProfit"] = task_data->DeliveryProfit;
		data["AccountFrozenInitialMargin"] = task_data->AccountFrozenInitialMargin;
		data["AccountFrozenMaintenanceMargin"] = task_data->AccountFrozenMaintenanceMargin;
		data["UpperFrozenInitialMargin"] = task_data->UpperFrozenInitialMargin;
		data["UpperFrozenMaintenanceMargin"] = task_data->UpperFrozenMaintenanceMargin;
		data["AccountFeeCurrencyGroup"] = toUtf(task_data->AccountFeeCurrencyGroup);
		data["AccountFeeCurrency"] = toUtf(task_data->AccountFeeCurrency);
		data["AccountDeliveryFee"] = task_data->AccountDeliveryFee;
		data["UpperFeeCurrencyGroup"] = toUtf(task_data->UpperFeeCurrencyGroup);
		data["UpperFeeCurrency"] = toUtf(task_data->UpperFeeCurrency);
		data["UpperDeliveryFee"] = task_data->UpperDeliveryFee;
		data["DeliveryMode"] = task_data->DeliveryMode;
		data["OperatorNo"] = toUtf(task_data->OperatorNo);
		data["OperateTime"] = toUtf(task_data->OperateTime);
		data["SettleGourpNo"] = toUtf(task_data->SettleGourpNo);
		data["FutureContractNo"] = toUtf(task_data->FutureContractNo);
		data["OptionStrikePrice"] = toUtf(task_data->OptionStrikePrice);
		data["SuperiorAccount"] = toUtf(task_data->SuperiorAccount);
		delete task_data;
	}
	this->onRspQryHisDelivery(task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRspQryAccountCashAdjust(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIAccountCashAdjustQryRsp* task_data = (TapAPIAccountCashAdjustQryRsp*)task->task_data;
		data["Date"] = toUtf(task_data->Date);
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["CashAdjustType"] = task_data->CashAdjustType;
		data["CurrencyGroupNo"] = toUtf(task_data->CurrencyGroupNo);
		data["CurrencyNo"] = toUtf(task_data->CurrencyNo);
		data["CashAdjustValue"] = task_data->CashAdjustValue;
		data["CashAdjustRemark"] = toUtf(task_data->CashAdjustRemark);
		data["OperateTime"] = toUtf(task_data->OperateTime);
		data["OperatorNo"] = toUtf(task_data->OperatorNo);
		data["AccountBank"] = toUtf(task_data->AccountBank);
		data["BankAccount"] = toUtf(task_data->BankAccount);
		data["AccountLWFlag"] = task_data->AccountLWFlag;
		data["CompanyBank"] = toUtf(task_data->CompanyBank);
		data["InternalBankAccount"] = toUtf(task_data->InternalBankAccount);
		data["CompanyLWFlag"] = task_data->CompanyLWFlag;
		delete task_data;
	}
	this->onRspQryAccountCashAdjust(task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRspQryBill(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIBillQryRsp* task_data = (TapAPIBillQryRsp*)task->task_data;
		data["Reqdata"] = task_data->Reqdata;
		data["BillLen"] = task_data->BillLen;
		data["BillText"] = task_data->BillText;
		delete task_data;
	}
	this->onRspQryBill(task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRspQryAccountFeeRent(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIAccountFeeRentQryRsp* task_data = (TapAPIAccountFeeRentQryRsp*)task->task_data;
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["MatchSource"] = task_data->MatchSource;
		data["CalculateMode"] = task_data->CalculateMode;
		data["CurrencyGroupNo"] = toUtf(task_data->CurrencyGroupNo);
		data["CurrencyNo"] = toUtf(task_data->CurrencyNo);
		data["OpenCloseFee"] = task_data->OpenCloseFee;
		data["CloseTodayFee"] = task_data->CloseTodayFee;
		delete task_data;
	}
	this->onRspQryAccountFeeRent(task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRspQryAccountMarginRent(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIAccountMarginRentQryRsp* task_data = (TapAPIAccountMarginRentQryRsp*)task->task_data;
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["ContractNo"] = toUtf(task_data->ContractNo);
		data["StrikePrice"] = toUtf(task_data->StrikePrice);
		data["CallOrPutFlag"] = task_data->CallOrPutFlag;
		data["CalculateMode"] = task_data->CalculateMode;
		data["CurrencyGroupNo"] = toUtf(task_data->CurrencyGroupNo);
		data["CurrencyNo"] = toUtf(task_data->CurrencyNo);
		data["InitialMargin"] = task_data->InitialMargin;
		data["MaintenanceMargin"] = task_data->MaintenanceMargin;
		data["SellInitialMargin"] = task_data->SellInitialMargin;
		data["SellMaintenanceMargin"] = task_data->SellMaintenanceMargin;
		data["LockMargin"] = task_data->LockMargin;
		delete task_data;
	}
	this->onRspQryAccountMarginRent(task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRspHKMarketOrderInsert(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIOrderMarketInsertRsp* task_data = (TapAPIOrderMarketInsertRsp*)task->task_data;
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["ContractNo"] = toUtf(task_data->ContractNo);
		data["StrikePrice"] = toUtf(task_data->StrikePrice);
		data["CallOrPutFlag"] = task_data->CallOrPutFlag;
		data["OrderType"] = task_data->OrderType;
		data["TimeInForce"] = task_data->TimeInForce;
		data["ExpireTime"] = toUtf(task_data->ExpireTime);
		data["OrderSource"] = task_data->OrderSource;
		data["BuyPositionEffect"] = task_data->BuyPositionEffect;
		data["SellPositionEffect"] = task_data->SellPositionEffect;
		data["OrderBuyPrice"] = task_data->OrderBuyPrice;
		data["OrderSellPrice"] = task_data->OrderSellPrice;
		data["OrderBuyQty"] = task_data->OrderBuyQty;
		data["OrderSellQty"] = task_data->OrderSellQty;
		data["ServerFlag"] = task_data->ServerFlag;
		data["OrderBuyNo"] = toUtf(task_data->OrderBuyNo);
		data["OrderSellNo"] = toUtf(task_data->OrderSellNo);
		data["AddOneIsValid"] = task_data->AddOneIsValid;
		data["OrderMarketUserNo"] = toUtf(task_data->OrderMarketUserNo);
		data["OrderMarketTime"] = toUtf(task_data->OrderMarketTime);
		data["RefInt"] = task_data->RefInt;
		data["RefDouble"] = task_data->RefDouble;
		data["RefString"] = toUtf(task_data->RefString);
		data["ClientBuyOrderNo"] = toUtf(task_data->ClientBuyOrderNo);
		data["ClientSellOrderNo"] = toUtf(task_data->ClientSellOrderNo);
		data["ErrorCode"] = task_data->ErrorCode;
		data["ErrorText"] = toUtf(task_data->ErrorText);
		data["ClientLocalIP"] = toUtf(task_data->ClientLocalIP);
		data["ClientMac"] = toUtf(task_data->ClientMac);
		data["ClientIP"] = toUtf(task_data->ClientIP);
		data["Remark"] = toUtf(task_data->Remark);
		delete task_data;
	}
	this->onRspHKMarketOrderInsert(task->task_id, task->task_int, data);
};

void TdApi::processRspHKMarketOrderDelete(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIOrderMarketDeleteRsp* task_data = (TapAPIOrderMarketDeleteRsp*)task->task_data;
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["ContractNo"] = toUtf(task_data->ContractNo);
		data["StrikePrice"] = toUtf(task_data->StrikePrice);
		data["CallOrPutFlag"] = task_data->CallOrPutFlag;
		data["OrderType"] = task_data->OrderType;
		data["TimeInForce"] = task_data->TimeInForce;
		data["ExpireTime"] = toUtf(task_data->ExpireTime);
		data["OrderSource"] = task_data->OrderSource;
		data["BuyPositionEffect"] = task_data->BuyPositionEffect;
		data["SellPositionEffect"] = task_data->SellPositionEffect;
		data["OrderBuyPrice"] = task_data->OrderBuyPrice;
		data["OrderSellPrice"] = task_data->OrderSellPrice;
		data["OrderBuyQty"] = task_data->OrderBuyQty;
		data["OrderSellQty"] = task_data->OrderSellQty;
		data["ServerFlag"] = task_data->ServerFlag;
		data["OrderBuyNo"] = toUtf(task_data->OrderBuyNo);
		data["OrderSellNo"] = toUtf(task_data->OrderSellNo);
		data["AddOneIsValid"] = task_data->AddOneIsValid;
		data["OrderMarketUserNo"] = toUtf(task_data->OrderMarketUserNo);
		data["OrderMarketTime"] = toUtf(task_data->OrderMarketTime);
		data["RefInt"] = task_data->RefInt;
		data["RefDouble"] = task_data->RefDouble;
		data["RefString"] = toUtf(task_data->RefString);
		data["ClientBuyOrderNo"] = toUtf(task_data->ClientBuyOrderNo);
		data["ClientSellOrderNo"] = toUtf(task_data->ClientSellOrderNo);
		data["ErrorCode"] = task_data->ErrorCode;
		data["ErrorText"] = toUtf(task_data->ErrorText);
		data["ClientLocalIP"] = toUtf(task_data->ClientLocalIP);
		data["ClientMac"] = toUtf(task_data->ClientMac);
		data["ClientIP"] = toUtf(task_data->ClientIP);
		data["Remark"] = toUtf(task_data->Remark);
		delete task_data;
	}
	this->onRspHKMarketOrderDelete(task->task_id, task->task_int, data);
};

void TdApi::processHKMarketQuoteNotice(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIOrderQuoteMarketNotice* task_data = (TapAPIOrderQuoteMarketNotice*)task->task_data;
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["ContractNo"] = toUtf(task_data->ContractNo);
		data["StrikePrice"] = toUtf(task_data->StrikePrice);
		data["CallOrPutFlag"] = task_data->CallOrPutFlag;
		data["OrderSide"] = task_data->OrderSide;
		data["OrderQty"] = task_data->OrderQty;
		delete task_data;
	}
	this->onHKMarketQuoteNotice(data);
};

void TdApi::processRspOrderLocalRemove(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIOrderLocalRemoveRsp* task_data = (TapAPIOrderLocalRemoveRsp*)task->task_data;
		data["req"] = task_data->req;
		data["ClientLocalIP"] = toUtf(task_data->ClientLocalIP);
		data["ClientMac"] = toUtf(task_data->ClientMac);
		data["ClientIP"] = toUtf(task_data->ClientIP);
		delete task_data;
	}
	this->onRspOrderLocalRemove(task->task_id, task->task_int, data);
};

void TdApi::processRspOrderLocalInput(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIOrderLocalInputRsp* task_data = (TapAPIOrderLocalInputRsp*)task->task_data;
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["ContractNo"] = toUtf(task_data->ContractNo);
		data["StrikePrice"] = toUtf(task_data->StrikePrice);
		data["CallOrPutFlag"] = task_data->CallOrPutFlag;
		data["ContractNo2"] = toUtf(task_data->ContractNo2);
		data["StrikePrice2"] = toUtf(task_data->StrikePrice2);
		data["CallOrPutFlag2"] = task_data->CallOrPutFlag2;
		data["OrderType"] = task_data->OrderType;
		data["OrderSource"] = task_data->OrderSource;
		data["TimeInForce"] = task_data->TimeInForce;
		data["ExpireTime"] = toUtf(task_data->ExpireTime);
		data["IsRiskOrder"] = task_data->IsRiskOrder;
		data["OrderSide"] = task_data->OrderSide;
		data["PositionEffect"] = task_data->PositionEffect;
		data["PositionEffect2"] = task_data->PositionEffect2;
		data["InquiryNo"] = toUtf(task_data->InquiryNo);
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["OrderPrice"] = task_data->OrderPrice;
		data["OrderPrice2"] = task_data->OrderPrice2;
		data["StopPrice"] = task_data->StopPrice;
		data["OrderQty"] = task_data->OrderQty;
		data["OrderMinQty"] = task_data->OrderMinQty;
		data["RefInt"] = task_data->RefInt;
		data["RefDouble"] = task_data->RefDouble;
		data["RefString"] = toUtf(task_data->RefString);
		data["MinClipSize"] = task_data->MinClipSize;
		data["MaxClipSize"] = task_data->MaxClipSize;
		data["LicenseNo"] = toUtf(task_data->LicenseNo);
		data["ServerFlag"] = task_data->ServerFlag;
		data["OrderNo"] = toUtf(task_data->OrderNo);
		data["ClientOrderNo"] = toUtf(task_data->ClientOrderNo);
		data["ClientID"] = toUtf(task_data->ClientID);
		data["TacticsType"] = task_data->TacticsType;
		data["TriggerCondition"] = task_data->TriggerCondition;
		data["TriggerPriceType"] = task_data->TriggerPriceType;
		data["AddOneIsValid"] = task_data->AddOneIsValid;
		data["ClientLocalIP"] = toUtf(task_data->ClientLocalIP);
		data["ClientMac"] = toUtf(task_data->ClientMac);
		data["ClientIP"] = toUtf(task_data->ClientIP);
		data["OrderStreamID"] = task_data->OrderStreamID;
		data["UpperNo"] = toUtf(task_data->UpperNo);
		data["UpperChannelNo"] = toUtf(task_data->UpperChannelNo);
		data["OrderLocalNo"] = toUtf(task_data->OrderLocalNo);
		data["UpperStreamID"] = task_data->UpperStreamID;
		data["OrderSystemNo"] = toUtf(task_data->OrderSystemNo);
		data["OrderExchangeSystemNo"] = toUtf(task_data->OrderExchangeSystemNo);
		data["OrderParentSystemNo"] = toUtf(task_data->OrderParentSystemNo);
		data["OrderInsertUserNo"] = toUtf(task_data->OrderInsertUserNo);
		data["OrderInsertTime"] = toUtf(task_data->OrderInsertTime);
		data["OrderCommandUserNo"] = toUtf(task_data->OrderCommandUserNo);
		data["OrderUpdateUserNo"] = toUtf(task_data->OrderUpdateUserNo);
		data["OrderUpdateTime"] = toUtf(task_data->OrderUpdateTime);
		data["OrderState"] = task_data->OrderState;
		data["OrderMatchPrice"] = task_data->OrderMatchPrice;
		data["OrderMatchPrice2"] = task_data->OrderMatchPrice2;
		data["OrderMatchQty"] = task_data->OrderMatchQty;
		data["OrderMatchQty2"] = task_data->OrderMatchQty2;
		data["ErrorCode"] = task_data->ErrorCode;
		data["ErrorText"] = toUtf(task_data->ErrorText);
		data["IsBackInput"] = task_data->IsBackInput;
		data["IsDeleted"] = task_data->IsDeleted;
		data["IsAddOne"] = task_data->IsAddOne;
		data["ClientLocationID"] = toUtf(task_data->ClientLocationID);
		delete task_data;
	}
	this->onRspOrderLocalInput(task->task_id, task->task_int, data);
};

void TdApi::processRspOrderLocalModify(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIOrderLocalModifyRsp* task_data = (TapAPIOrderLocalModifyRsp*)task->task_data;
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["ContractNo"] = toUtf(task_data->ContractNo);
		data["StrikePrice"] = toUtf(task_data->StrikePrice);
		data["CallOrPutFlag"] = task_data->CallOrPutFlag;
		data["ContractNo2"] = toUtf(task_data->ContractNo2);
		data["StrikePrice2"] = toUtf(task_data->StrikePrice2);
		data["CallOrPutFlag2"] = task_data->CallOrPutFlag2;
		data["OrderType"] = task_data->OrderType;
		data["OrderSource"] = task_data->OrderSource;
		data["TimeInForce"] = task_data->TimeInForce;
		data["ExpireTime"] = toUtf(task_data->ExpireTime);
		data["IsRiskOrder"] = task_data->IsRiskOrder;
		data["OrderSide"] = task_data->OrderSide;
		data["PositionEffect"] = task_data->PositionEffect;
		data["PositionEffect2"] = task_data->PositionEffect2;
		data["InquiryNo"] = toUtf(task_data->InquiryNo);
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["OrderPrice"] = task_data->OrderPrice;
		data["OrderPrice2"] = task_data->OrderPrice2;
		data["StopPrice"] = task_data->StopPrice;
		data["OrderQty"] = task_data->OrderQty;
		data["OrderMinQty"] = task_data->OrderMinQty;
		data["RefInt"] = task_data->RefInt;
		data["RefDouble"] = task_data->RefDouble;
		data["RefString"] = toUtf(task_data->RefString);
		data["MinClipSize"] = task_data->MinClipSize;
		data["MaxClipSize"] = task_data->MaxClipSize;
		data["LicenseNo"] = toUtf(task_data->LicenseNo);
		data["ServerFlag"] = task_data->ServerFlag;
		data["OrderNo"] = toUtf(task_data->OrderNo);
		data["ClientOrderNo"] = toUtf(task_data->ClientOrderNo);
		data["ClientID"] = toUtf(task_data->ClientID);
		data["TacticsType"] = task_data->TacticsType;
		data["TriggerCondition"] = task_data->TriggerCondition;
		data["TriggerPriceType"] = task_data->TriggerPriceType;
		data["AddOneIsValid"] = task_data->AddOneIsValid;
		data["ClientLocalIP"] = toUtf(task_data->ClientLocalIP);
		data["ClientMac"] = toUtf(task_data->ClientMac);
		data["ClientIP"] = toUtf(task_data->ClientIP);
		data["OrderStreamID"] = task_data->OrderStreamID;
		data["UpperNo"] = toUtf(task_data->UpperNo);
		data["UpperChannelNo"] = toUtf(task_data->UpperChannelNo);
		data["OrderLocalNo"] = toUtf(task_data->OrderLocalNo);
		data["UpperStreamID"] = task_data->UpperStreamID;
		data["OrderSystemNo"] = toUtf(task_data->OrderSystemNo);
		data["OrderExchangeSystemNo"] = toUtf(task_data->OrderExchangeSystemNo);
		data["OrderParentSystemNo"] = toUtf(task_data->OrderParentSystemNo);
		data["OrderInsertUserNo"] = toUtf(task_data->OrderInsertUserNo);
		data["OrderInsertTime"] = toUtf(task_data->OrderInsertTime);
		data["OrderCommandUserNo"] = toUtf(task_data->OrderCommandUserNo);
		data["OrderUpdateUserNo"] = toUtf(task_data->OrderUpdateUserNo);
		data["OrderUpdateTime"] = toUtf(task_data->OrderUpdateTime);
		data["OrderState"] = task_data->OrderState;
		data["OrderMatchPrice"] = task_data->OrderMatchPrice;
		data["OrderMatchPrice2"] = task_data->OrderMatchPrice2;
		data["OrderMatchQty"] = task_data->OrderMatchQty;
		data["OrderMatchQty2"] = task_data->OrderMatchQty2;
		data["ErrorCode"] = task_data->ErrorCode;
		data["ErrorText"] = toUtf(task_data->ErrorText);
		data["IsBackInput"] = task_data->IsBackInput;
		data["IsDeleted"] = task_data->IsDeleted;
		data["IsAddOne"] = task_data->IsAddOne;
		data["ClientLocationID"] = toUtf(task_data->ClientLocationID);
		delete task_data;
	}
	this->onRspOrderLocalModify(task->task_id, task->task_int, data);
};

void TdApi::processRspOrderLocalTransfer(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIOrderLocalTransferRsp* task_data = (TapAPIOrderLocalTransferRsp*)task->task_data;
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["ContractNo"] = toUtf(task_data->ContractNo);
		data["StrikePrice"] = toUtf(task_data->StrikePrice);
		data["CallOrPutFlag"] = task_data->CallOrPutFlag;
		data["ContractNo2"] = toUtf(task_data->ContractNo2);
		data["StrikePrice2"] = toUtf(task_data->StrikePrice2);
		data["CallOrPutFlag2"] = task_data->CallOrPutFlag2;
		data["OrderType"] = task_data->OrderType;
		data["OrderSource"] = task_data->OrderSource;
		data["TimeInForce"] = task_data->TimeInForce;
		data["ExpireTime"] = toUtf(task_data->ExpireTime);
		data["IsRiskOrder"] = task_data->IsRiskOrder;
		data["OrderSide"] = task_data->OrderSide;
		data["PositionEffect"] = task_data->PositionEffect;
		data["PositionEffect2"] = task_data->PositionEffect2;
		data["InquiryNo"] = toUtf(task_data->InquiryNo);
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["OrderPrice"] = task_data->OrderPrice;
		data["OrderPrice2"] = task_data->OrderPrice2;
		data["StopPrice"] = task_data->StopPrice;
		data["OrderQty"] = task_data->OrderQty;
		data["OrderMinQty"] = task_data->OrderMinQty;
		data["RefInt"] = task_data->RefInt;
		data["RefDouble"] = task_data->RefDouble;
		data["RefString"] = toUtf(task_data->RefString);
		data["MinClipSize"] = task_data->MinClipSize;
		data["MaxClipSize"] = task_data->MaxClipSize;
		data["LicenseNo"] = toUtf(task_data->LicenseNo);
		data["ServerFlag"] = task_data->ServerFlag;
		data["OrderNo"] = toUtf(task_data->OrderNo);
		data["ClientOrderNo"] = toUtf(task_data->ClientOrderNo);
		data["ClientID"] = toUtf(task_data->ClientID);
		data["TacticsType"] = task_data->TacticsType;
		data["TriggerCondition"] = task_data->TriggerCondition;
		data["TriggerPriceType"] = task_data->TriggerPriceType;
		data["AddOneIsValid"] = task_data->AddOneIsValid;
		data["ClientLocalIP"] = toUtf(task_data->ClientLocalIP);
		data["ClientMac"] = toUtf(task_data->ClientMac);
		data["ClientIP"] = toUtf(task_data->ClientIP);
		data["OrderStreamID"] = task_data->OrderStreamID;
		data["UpperNo"] = toUtf(task_data->UpperNo);
		data["UpperChannelNo"] = toUtf(task_data->UpperChannelNo);
		data["OrderLocalNo"] = toUtf(task_data->OrderLocalNo);
		data["UpperStreamID"] = task_data->UpperStreamID;
		data["OrderSystemNo"] = toUtf(task_data->OrderSystemNo);
		data["OrderExchangeSystemNo"] = toUtf(task_data->OrderExchangeSystemNo);
		data["OrderParentSystemNo"] = toUtf(task_data->OrderParentSystemNo);
		data["OrderInsertUserNo"] = toUtf(task_data->OrderInsertUserNo);
		data["OrderInsertTime"] = toUtf(task_data->OrderInsertTime);
		data["OrderCommandUserNo"] = toUtf(task_data->OrderCommandUserNo);
		data["OrderUpdateUserNo"] = toUtf(task_data->OrderUpdateUserNo);
		data["OrderUpdateTime"] = toUtf(task_data->OrderUpdateTime);
		data["OrderState"] = task_data->OrderState;
		data["OrderMatchPrice"] = task_data->OrderMatchPrice;
		data["OrderMatchPrice2"] = task_data->OrderMatchPrice2;
		data["OrderMatchQty"] = task_data->OrderMatchQty;
		data["OrderMatchQty2"] = task_data->OrderMatchQty2;
		data["ErrorCode"] = task_data->ErrorCode;
		data["ErrorText"] = toUtf(task_data->ErrorText);
		data["IsBackInput"] = task_data->IsBackInput;
		data["IsDeleted"] = task_data->IsDeleted;
		data["IsAddOne"] = task_data->IsAddOne;
		data["ClientLocationID"] = toUtf(task_data->ClientLocationID);
		delete task_data;
	}
	this->onRspOrderLocalTransfer(task->task_id, task->task_int, data);
};

void TdApi::processRspFillLocalInput(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIFillLocalInputRsp* task_data = (TapAPIFillLocalInputRsp*)task->task_data;
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["ContractNo"] = toUtf(task_data->ContractNo);
		data["StrikePrice"] = toUtf(task_data->StrikePrice);
		data["CallOrPutFlag"] = task_data->CallOrPutFlag;
		data["MatchSide"] = task_data->MatchSide;
		data["PositionEffect"] = task_data->PositionEffect;
		data["HedgeFlag"] = task_data->HedgeFlag;
		data["MatchPrice"] = task_data->MatchPrice;
		data["MatchQty"] = task_data->MatchQty;
		data["OrderSystemNo"] = toUtf(task_data->OrderSystemNo);
		data["UpperMatchNo"] = toUtf(task_data->UpperMatchNo);
		data["MatchDateTime"] = toUtf(task_data->MatchDateTime);
		data["UpperMatchDateTime"] = toUtf(task_data->UpperMatchDateTime);
		data["UpperNo"] = toUtf(task_data->UpperNo);
		data["IsAddOne"] = task_data->IsAddOne;
		data["FeeCurrencyGroup"] = toUtf(task_data->FeeCurrencyGroup);
		data["FeeCurrency"] = toUtf(task_data->FeeCurrency);
		data["FeeValue"] = task_data->FeeValue;
		data["IsManualFee"] = task_data->IsManualFee;
		data["ClosePositionPrice"] = task_data->ClosePositionPrice;
		delete task_data;
	}
	this->onRspFillLocalInput(task->task_id, task->task_int, data);
};

void TdApi::processRspFillLocalRemove(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIFillLocalRemoveRsp* task_data = (TapAPIFillLocalRemoveRsp*)task->task_data;
		data["ServerFlag"] = task_data->ServerFlag;
		data["MatchNo"] = toUtf(task_data->MatchNo);
		delete task_data;
	}
	this->onRspFillLocalRemove(task->task_id, task->task_int, data);
};

void TdApi::processRspQrySpotLock(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPISpotLockDataRsp* task_data = (TapAPISpotLockDataRsp*)task->task_data;
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["LockQty"] = task_data->LockQty;
		data["FrozenQty"] = task_data->FrozenQty;
		data["CanUnLockQty"] = task_data->CanUnLockQty;
		delete task_data;
	}
	this->onRspQrySpotLock(task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRtnSpotLock(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPISpotLockDataRsp* task_data = (TapAPISpotLockDataRsp*)task->task_data;
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["LockQty"] = task_data->LockQty;
		data["FrozenQty"] = task_data->FrozenQty;
		data["CanUnLockQty"] = task_data->CanUnLockQty;
		delete task_data;
	}
	this->onRtnSpotLock(data);
};

void TdApi::processRspSubmitUserLoginInfo(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPISubmitUserLoginRspInfo* task_data = (TapAPISubmitUserLoginRspInfo*)task->task_data;
		data["UserNo"] = toUtf(task_data->UserNo);
		delete task_data;
	}
	this->onRspSubmitUserLoginInfo(task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRspSpecialOrderAction(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPISpecialOrderInfo* task_data = (TapAPISpecialOrderInfo*)task->task_data;
		data["SessionID"] = task_data->SessionID;
		data["ErrorCode"] = task_data->ErrorCode;
		data["ErrorText"] = toUtf(task_data->ErrorText);
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["ServerFlag"] = task_data->ServerFlag;
		data["OrderNo"] = toUtf(task_data->OrderNo);
		data["ClientOrderNo"] = toUtf(task_data->ClientOrderNo);
		data["SpecialOrderType"] = task_data->SpecialOrderType;
		data["OrderSource"] = task_data->OrderSource;
		data["CombineStrategy"] = toUtf(task_data->CombineStrategy);
		data["CombineNo"] = toUtf(task_data->CombineNo);
		data["OrderQty"] = task_data->OrderQty;
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["ContractNo"] = toUtf(task_data->ContractNo);
		data["StrikePrice"] = toUtf(task_data->StrikePrice);
		data["CallOrPutFlag"] = task_data->CallOrPutFlag;
		data["OrderSide1"] = task_data->OrderSide1;
		data["CombineQty1"] = task_data->CombineQty1;
		data["HedgeFlag1"] = task_data->HedgeFlag1;
		data["ContractNo2"] = toUtf(task_data->ContractNo2);
		data["StrikePrice2"] = toUtf(task_data->StrikePrice2);
		data["CallOrPutFlag2"] = task_data->CallOrPutFlag2;
		data["OrderSide2"] = task_data->OrderSide2;
		data["CombineQty2"] = task_data->CombineQty2;
		data["HedgeFlag2"] = task_data->HedgeFlag2;
		data["LicenseNo"] = toUtf(task_data->LicenseNo);
		data["ClientLocalIP"] = toUtf(task_data->ClientLocalIP);
		data["ClientMac"] = toUtf(task_data->ClientMac);
		data["ClientIP"] = toUtf(task_data->ClientIP);
		data["OrderStreamID"] = task_data->OrderStreamID;
		data["UpperNo"] = toUtf(task_data->UpperNo);
		data["UpperChannelNo"] = toUtf(task_data->UpperChannelNo);
		data["OrderLocalNo"] = toUtf(task_data->OrderLocalNo);
		data["OrderSystemNo"] = toUtf(task_data->OrderSystemNo);
		data["OrderExchangeSystemNo"] = toUtf(task_data->OrderExchangeSystemNo);
		data["OrderInsertUserNo"] = toUtf(task_data->OrderInsertUserNo);
		data["OrderInsertTime"] = toUtf(task_data->OrderInsertTime);
		data["OrderState"] = task_data->OrderState;
		delete task_data;
	}
	this->onRspSpecialOrderAction(task->task_id, task->task_int, data);
};

void TdApi::processRtnSpecialOrder(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPISpecialOrderInfo* task_data = (TapAPISpecialOrderInfo*)task->task_data;
		data["SessionID"] = task_data->SessionID;
		data["ErrorCode"] = task_data->ErrorCode;
		data["ErrorText"] = toUtf(task_data->ErrorText);
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["ServerFlag"] = task_data->ServerFlag;
		data["OrderNo"] = toUtf(task_data->OrderNo);
		data["ClientOrderNo"] = toUtf(task_data->ClientOrderNo);
		data["SpecialOrderType"] = task_data->SpecialOrderType;
		data["OrderSource"] = task_data->OrderSource;
		data["CombineStrategy"] = toUtf(task_data->CombineStrategy);
		data["CombineNo"] = toUtf(task_data->CombineNo);
		data["OrderQty"] = task_data->OrderQty;
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["ContractNo"] = toUtf(task_data->ContractNo);
		data["StrikePrice"] = toUtf(task_data->StrikePrice);
		data["CallOrPutFlag"] = task_data->CallOrPutFlag;
		data["OrderSide1"] = task_data->OrderSide1;
		data["CombineQty1"] = task_data->CombineQty1;
		data["HedgeFlag1"] = task_data->HedgeFlag1;
		data["ContractNo2"] = toUtf(task_data->ContractNo2);
		data["StrikePrice2"] = toUtf(task_data->StrikePrice2);
		data["CallOrPutFlag2"] = task_data->CallOrPutFlag2;
		data["OrderSide2"] = task_data->OrderSide2;
		data["CombineQty2"] = task_data->CombineQty2;
		data["HedgeFlag2"] = task_data->HedgeFlag2;
		data["LicenseNo"] = toUtf(task_data->LicenseNo);
		data["ClientLocalIP"] = toUtf(task_data->ClientLocalIP);
		data["ClientMac"] = toUtf(task_data->ClientMac);
		data["ClientIP"] = toUtf(task_data->ClientIP);
		data["OrderStreamID"] = task_data->OrderStreamID;
		data["UpperNo"] = toUtf(task_data->UpperNo);
		data["UpperChannelNo"] = toUtf(task_data->UpperChannelNo);
		data["OrderLocalNo"] = toUtf(task_data->OrderLocalNo);
		data["OrderSystemNo"] = toUtf(task_data->OrderSystemNo);
		data["OrderExchangeSystemNo"] = toUtf(task_data->OrderExchangeSystemNo);
		data["OrderInsertUserNo"] = toUtf(task_data->OrderInsertUserNo);
		data["OrderInsertTime"] = toUtf(task_data->OrderInsertTime);
		data["OrderState"] = task_data->OrderState;
		delete task_data;
	}
	this->onRtnSpecialOrder(data);
};

void TdApi::processRspQrySpecialOrder(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPISpecialOrderInfo* task_data = (TapAPISpecialOrderInfo*)task->task_data;
		data["SessionID"] = task_data->SessionID;
		data["ErrorCode"] = task_data->ErrorCode;
		data["ErrorText"] = toUtf(task_data->ErrorText);
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["ServerFlag"] = task_data->ServerFlag;
		data["OrderNo"] = toUtf(task_data->OrderNo);
		data["ClientOrderNo"] = toUtf(task_data->ClientOrderNo);
		data["SpecialOrderType"] = task_data->SpecialOrderType;
		data["OrderSource"] = task_data->OrderSource;
		data["CombineStrategy"] = toUtf(task_data->CombineStrategy);
		data["CombineNo"] = toUtf(task_data->CombineNo);
		data["OrderQty"] = task_data->OrderQty;
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["ContractNo"] = toUtf(task_data->ContractNo);
		data["StrikePrice"] = toUtf(task_data->StrikePrice);
		data["CallOrPutFlag"] = task_data->CallOrPutFlag;
		data["OrderSide1"] = task_data->OrderSide1;
		data["CombineQty1"] = task_data->CombineQty1;
		data["HedgeFlag1"] = task_data->HedgeFlag1;
		data["ContractNo2"] = toUtf(task_data->ContractNo2);
		data["StrikePrice2"] = toUtf(task_data->StrikePrice2);
		data["CallOrPutFlag2"] = task_data->CallOrPutFlag2;
		data["OrderSide2"] = task_data->OrderSide2;
		data["CombineQty2"] = task_data->CombineQty2;
		data["HedgeFlag2"] = task_data->HedgeFlag2;
		data["LicenseNo"] = toUtf(task_data->LicenseNo);
		data["ClientLocalIP"] = toUtf(task_data->ClientLocalIP);
		data["ClientMac"] = toUtf(task_data->ClientMac);
		data["ClientIP"] = toUtf(task_data->ClientIP);
		data["OrderStreamID"] = task_data->OrderStreamID;
		data["UpperNo"] = toUtf(task_data->UpperNo);
		data["UpperChannelNo"] = toUtf(task_data->UpperChannelNo);
		data["OrderLocalNo"] = toUtf(task_data->OrderLocalNo);
		data["OrderSystemNo"] = toUtf(task_data->OrderSystemNo);
		data["OrderExchangeSystemNo"] = toUtf(task_data->OrderExchangeSystemNo);
		data["OrderInsertUserNo"] = toUtf(task_data->OrderInsertUserNo);
		data["OrderInsertTime"] = toUtf(task_data->OrderInsertTime);
		data["OrderState"] = task_data->OrderState;
		delete task_data;
	}
	this->onRspQrySpecialOrder(task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRspQryCombinePosition(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPICombinePositionInfo* task_data = (TapAPICombinePositionInfo*)task->task_data;
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["PositionStreamID"] = task_data->PositionStreamID;
		data["ServerFlag"] = task_data->ServerFlag;
		data["UpperNo"] = toUtf(task_data->UpperNo);
		data["CombineStrategy"] = toUtf(task_data->CombineStrategy);
		data["CombineNo"] = toUtf(task_data->CombineNo);
		data["PositionQty"] = task_data->PositionQty;
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["ContractNo"] = toUtf(task_data->ContractNo);
		data["StrikePrice"] = toUtf(task_data->StrikePrice);
		data["CallOrPutFlag"] = task_data->CallOrPutFlag;
		data["OrderSide1"] = task_data->OrderSide1;
		data["CombineQty1"] = task_data->CombineQty1;
		data["HedgeFlag1"] = task_data->HedgeFlag1;
		data["ContractNo2"] = toUtf(task_data->ContractNo2);
		data["StrikePrice2"] = toUtf(task_data->StrikePrice2);
		data["CallOrPutFlag2"] = task_data->CallOrPutFlag2;
		data["OrderSide2"] = task_data->OrderSide2;
		data["CombineQty2"] = task_data->CombineQty2;
		data["HedgeFlag2"] = task_data->HedgeFlag2;
		data["CommodityCurrencyGroup"] = toUtf(task_data->CommodityCurrencyGroup);
		data["CommodityCurrency"] = toUtf(task_data->CommodityCurrency);
		data["AccountInitialMargin"] = task_data->AccountInitialMargin;
		data["AccountMaintenanceMargin"] = task_data->AccountMaintenanceMargin;
		data["UpperInitialMargin"] = task_data->UpperInitialMargin;
		data["UpperMaintenanceMargin"] = task_data->UpperMaintenanceMargin;
		delete task_data;
	}
	this->onRspQryCombinePosition(task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRtnCombinePosition(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPICombinePositionInfo* task_data = (TapAPICombinePositionInfo*)task->task_data;
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["PositionStreamID"] = task_data->PositionStreamID;
		data["ServerFlag"] = task_data->ServerFlag;
		data["UpperNo"] = toUtf(task_data->UpperNo);
		data["CombineStrategy"] = toUtf(task_data->CombineStrategy);
		data["CombineNo"] = toUtf(task_data->CombineNo);
		data["PositionQty"] = task_data->PositionQty;
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["ContractNo"] = toUtf(task_data->ContractNo);
		data["StrikePrice"] = toUtf(task_data->StrikePrice);
		data["CallOrPutFlag"] = task_data->CallOrPutFlag;
		data["OrderSide1"] = task_data->OrderSide1;
		data["CombineQty1"] = task_data->CombineQty1;
		data["HedgeFlag1"] = task_data->HedgeFlag1;
		data["ContractNo2"] = toUtf(task_data->ContractNo2);
		data["StrikePrice2"] = toUtf(task_data->StrikePrice2);
		data["CallOrPutFlag2"] = task_data->CallOrPutFlag2;
		data["OrderSide2"] = task_data->OrderSide2;
		data["CombineQty2"] = task_data->CombineQty2;
		data["HedgeFlag2"] = task_data->HedgeFlag2;
		data["CommodityCurrencyGroup"] = toUtf(task_data->CommodityCurrencyGroup);
		data["CommodityCurrency"] = toUtf(task_data->CommodityCurrency);
		data["AccountInitialMargin"] = task_data->AccountInitialMargin;
		data["AccountMaintenanceMargin"] = task_data->AccountMaintenanceMargin;
		data["UpperInitialMargin"] = task_data->UpperInitialMargin;
		data["UpperMaintenanceMargin"] = task_data->UpperMaintenanceMargin;
		delete task_data;
	}
	this->onRtnCombinePosition(data);
};

void TdApi::processRspQryUserTrustDevice(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIUserTrustDeviceQryRsp* task_data = (TapAPIUserTrustDeviceQryRsp*)task->task_data;
		data["UserNo"] = toUtf(task_data->UserNo);
		data["LicenseNo"] = toUtf(task_data->LicenseNo);
		data["Mac"] = toUtf(task_data->Mac);
		data["DeviceName"] = toUtf(task_data->DeviceName);
		data["OperatorNo"] = toUtf(task_data->OperatorNo);
		data["OperateTime"] = toUtf(task_data->OperateTime);
		delete task_data;
	}
	this->onRspQryUserTrustDevice(task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRspAddUserTrustDevice(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIUserTrustDeviceAddRsp* task_data = (TapAPIUserTrustDeviceAddRsp*)task->task_data;
		data["UserNo"] = toUtf(task_data->UserNo);
		data["LicenseNo"] = toUtf(task_data->LicenseNo);
		data["Mac"] = toUtf(task_data->Mac);
		data["DeviceName"] = toUtf(task_data->DeviceName);
		data["OperatorNo"] = toUtf(task_data->OperatorNo);
		data["OperateTime"] = toUtf(task_data->OperateTime);
		delete task_data;
	}
	this->onRspAddUserTrustDevice(task->task_id, task->task_int, data);
};

void TdApi::processRspDelUserTrustDevice(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIUserTrustDeviceDelRsp* task_data = (TapAPIUserTrustDeviceDelRsp*)task->task_data;
		data["LicenseNo"] = toUtf(task_data->LicenseNo);
		data["Mac"] = toUtf(task_data->Mac);
		delete task_data;
	}
	this->onRspDelUserTrustDevice(task->task_id, task->task_int, data);
};

void TdApi::processRtnAddUserTrustDevice(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIUserTrustDeviceAddRsp* task_data = (TapAPIUserTrustDeviceAddRsp*)task->task_data;
		data["UserNo"] = toUtf(task_data->UserNo);
		data["LicenseNo"] = toUtf(task_data->LicenseNo);
		data["Mac"] = toUtf(task_data->Mac);
		data["DeviceName"] = toUtf(task_data->DeviceName);
		data["OperatorNo"] = toUtf(task_data->OperatorNo);
		data["OperateTime"] = toUtf(task_data->OperateTime);
		delete task_data;
	}
	this->onRtnAddUserTrustDevice(data);
};

void TdApi::processRtnDelUserTrustDevice(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIUserTrustDeviceDelRsp* task_data = (TapAPIUserTrustDeviceDelRsp*)task->task_data;
		data["LicenseNo"] = toUtf(task_data->LicenseNo);
		data["Mac"] = toUtf(task_data->Mac);
		delete task_data;
	}
	this->onRtnDelUserTrustDevice(data);
};

void TdApi::processRspQryIPOInfo(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIIPOInfoQryRsp* task_data = (TapAPIIPOInfoQryRsp*)task->task_data;
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["CurrencyGroupNo"] = toUtf(task_data->CurrencyGroupNo);
		data["CurrencyNo"] = toUtf(task_data->CurrencyNo);
		data["BeginDate"] = toUtf(task_data->BeginDate);
		data["EndDate"] = toUtf(task_data->EndDate);
		data["IPODate"] = toUtf(task_data->IPODate);
		data["ResultDate"] = toUtf(task_data->ResultDate);
		data["IPOFee"] = task_data->IPOFee;
		data["FinancingFee"] = task_data->FinancingFee;
		data["LoanRatio"] = task_data->LoanRatio;
		data["FinancingDays"] = task_data->FinancingDays;
		data["MaxLoanRatio"] = task_data->MaxLoanRatio;
		data["MaxLoanValue"] = task_data->MaxLoanValue;
		data["Price"] = task_data->Price;
		data["OperatorNo"] = toUtf(task_data->OperatorNo);
		data["OperateTime"] = toUtf(task_data->OperateTime);
		delete task_data;
	}
	this->onRspQryIPOInfo(task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRspQryIPOStockQty(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIAvailableApplyQryRsp* task_data = (TapAPIAvailableApplyQryRsp*)task->task_data;
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["StockQty"] = task_data->StockQty;
		delete task_data;
	}
	this->onRspQryIPOStockQty(task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRspQryAccountIPO(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIAccountIPOQryRsp* task_data = (TapAPIAccountIPOQryRsp*)task->task_data;
		data["EndDate"] = toUtf(task_data->EndDate);
		data["ResultDate"] = toUtf(task_data->ResultDate);
		data["IPODate"] = toUtf(task_data->IPODate);
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["ApplyType"] = task_data->ApplyType;
		data["ApplyQty"] = task_data->ApplyQty;
		data["ApplyCash"] = task_data->ApplyCash;
		data["LoanRatio"] = task_data->LoanRatio;
		data["LoanInterest"] = task_data->LoanInterest;
		data["ApplyFee"] = task_data->ApplyFee;
		data["ApplyStatus"] = task_data->ApplyStatus;
		data["ResultQty"] = task_data->ResultQty;
		data["OperatorNo"] = toUtf(task_data->OperatorNo);
		data["OperateTime"] = toUtf(task_data->OperateTime);
		delete task_data;
	}
	this->onRspQryAccountIPO(task->task_id, task->task_int, task->task_last, data);
};

void TdApi::processRspAddAccountIPO(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIAccountIPOAddRsp* task_data = (TapAPIAccountIPOAddRsp*)task->task_data;
		data["EndDate"] = toUtf(task_data->EndDate);
		data["ResultDate"] = toUtf(task_data->ResultDate);
		data["IPODate"] = toUtf(task_data->IPODate);
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["ApplyType"] = task_data->ApplyType;
		data["ApplyQty"] = task_data->ApplyQty;
		data["ApplyCash"] = task_data->ApplyCash;
		data["LoanRatio"] = task_data->LoanRatio;
		data["LoanInterest"] = task_data->LoanInterest;
		data["ApplyFee"] = task_data->ApplyFee;
		data["ApplyStatus"] = task_data->ApplyStatus;
		data["ResultQty"] = task_data->ResultQty;
		data["OperatorNo"] = toUtf(task_data->OperatorNo);
		data["OperateTime"] = toUtf(task_data->OperateTime);
		delete task_data;
	}
	this->onRspAddAccountIPO(task->task_id, task->task_int, data);
};

void TdApi::processRspCancelAccountIPO(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIAccountIPOCancelRsp* task_data = (TapAPIAccountIPOCancelRsp*)task->task_data;
		data["EndDate"] = toUtf(task_data->EndDate);
		data["ResultDate"] = toUtf(task_data->ResultDate);
		data["IPODate"] = toUtf(task_data->IPODate);
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["ApplyType"] = task_data->ApplyType;
		data["ApplyQty"] = task_data->ApplyQty;
		data["ApplyCash"] = task_data->ApplyCash;
		data["LoanRatio"] = task_data->LoanRatio;
		data["LoanInterest"] = task_data->LoanInterest;
		data["ApplyFee"] = task_data->ApplyFee;
		data["ApplyStatus"] = task_data->ApplyStatus;
		data["ResultQty"] = task_data->ResultQty;
		data["OperatorNo"] = toUtf(task_data->OperatorNo);
		data["OperateTime"] = toUtf(task_data->OperateTime);
		delete task_data;
	}
	this->onRspCancelAccountIPO(task->task_id, task->task_int, data);
};

void TdApi::processRtnAddAccountIPO(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIAccountIPOAddNotice* task_data = (TapAPIAccountIPOAddNotice*)task->task_data;
		data["EndDate"] = toUtf(task_data->EndDate);
		data["ResultDate"] = toUtf(task_data->ResultDate);
		data["IPODate"] = toUtf(task_data->IPODate);
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["ApplyType"] = task_data->ApplyType;
		data["ApplyQty"] = task_data->ApplyQty;
		data["ApplyCash"] = task_data->ApplyCash;
		data["LoanRatio"] = task_data->LoanRatio;
		data["LoanInterest"] = task_data->LoanInterest;
		data["ApplyFee"] = task_data->ApplyFee;
		data["ApplyStatus"] = task_data->ApplyStatus;
		data["ResultQty"] = task_data->ResultQty;
		data["OperatorNo"] = toUtf(task_data->OperatorNo);
		data["OperateTime"] = toUtf(task_data->OperateTime);
		delete task_data;
	}
	this->onRtnAddAccountIPO(data);
};

void TdApi::processRtnCancelAccountIPO(Task* task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		TapAPIAccountIPOCancelNotice* task_data = (TapAPIAccountIPOCancelNotice*)task->task_data;
		data["EndDate"] = toUtf(task_data->EndDate);
		data["ResultDate"] = toUtf(task_data->ResultDate);
		data["IPODate"] = toUtf(task_data->IPODate);
		data["AccountNo"] = toUtf(task_data->AccountNo);
		data["ExchangeNo"] = toUtf(task_data->ExchangeNo);
		data["CommodityType"] = task_data->CommodityType;
		data["CommodityNo"] = toUtf(task_data->CommodityNo);
		data["ApplyType"] = task_data->ApplyType;
		data["ApplyQty"] = task_data->ApplyQty;
		data["ApplyCash"] = task_data->ApplyCash;
		data["LoanRatio"] = task_data->LoanRatio;
		data["LoanInterest"] = task_data->LoanInterest;
		data["ApplyFee"] = task_data->ApplyFee;
		data["ApplyStatus"] = task_data->ApplyStatus;
		data["ResultQty"] = task_data->ResultQty;
		data["OperatorNo"] = toUtf(task_data->OperatorNo);
		data["OperateTime"] = toUtf(task_data->OperateTime);
		delete task_data;
	}
	this->onRtnCancelAccountIPO(data);
};

void TdApi::processRspUnFreezeVerificate(Task* task)
{
	gil_scoped_acquire acquire;
	this->onRspUnFreezeVerificate(task->task_id, task->task_int);
};

///-------------------------------------------------------------------------------------
///主动函数
///-------------------------------------------------------------------------------------

void TdApi::createITapTradeAPI(const dict &req, int iResult)
{
	TapAPIApplicationInfo myreq = TapAPIApplicationInfo();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "AuthCode", myreq.AuthCode);
	getString(req, "KeyOperationLogPath", myreq.KeyOperationLogPath);

	char loglevel;
	getChar(req, "LogLevel", &loglevel);
	myreq.LogLevel = TAPILOGLEVEL(loglevel);

	this->api = (ITapTradeAPI*)CreateITapTradeAPI(&myreq, iResult); // 创建API接口对象
	this->api->SetAPINotify(this);  //注册回调函数对象
};

void TdApi::release()
{	
	FreeITapTradeAPI(this->api);
};

void TdApi::init()
{
	this->active = true;
	this->task_thread = thread(&TdApi::processTask, this);
};


int TdApi::exit()
{
	this->active = false;
	this->task_queue.terminate();
	this->task_thread.join();

	this->api->SetAPINotify(NULL);
	FreeITapTradeAPI(this ->api);
	this->api = NULL;
	return 1;
};

string TdApi::getITapTradeAPIVersion()
{
	string i = GetITapTradeAPIVersion();
	return i;
};

string TdApi::getITapErrorDescribe(int error)
{
	string i = GetITapErrorDescribe(error);
	return toUtf(i);
};

int TdApi::setHostAddress(string IP, int port)
{
	int i = this->api->SetHostAddress(IP.c_str(), (unsigned short)port);
	return i;
};

int TdApi::login(const dict &req)
{
	TapAPITradeLoginAuth myreq = TapAPITradeLoginAuth();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "UserNo", myreq.UserNo);
	getChar(req, "ISModifyPassword", &myreq.ISModifyPassword);
	getString(req, "Password", myreq.Password);
	getString(req, "NewPassword", myreq.NewPassword);
	getString(req, "LoginIP", myreq.LoginIP);
	getString(req, "LoginMac", myreq.LoginMac);
	getString(req, "DeviceName", myreq.DeviceName);
	int i = this->api->Login(&myreq);
	return i;
};

int TdApi::requestVertificateCode(string ContactInfo)
{
	TAPIUINT32 session;
	int i = this->api->RequestVertificateCode(&session, (char*)ContactInfo.c_str());
	return i;
};

int TdApi::setVertificateCode(const dict& req)
{
	TAPIUINT32 session;
	TapAPISecondCertificationReq myreq = TapAPISecondCertificationReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "VertificateCode", myreq.VertificateCode);
	getChar(req, "LoginType", &myreq.LoginType);
	int i = this->api->SetVertificateCode(&session, &myreq);
	return i;
}

int TdApi::disconnect()
{
	int i = this->api->Disconnect();
	return i;
};


int TdApi::authPassword(const dict &req)
{
	TAPIUINT32 session;
	TapAPIAuthPasswordReq myreq = TapAPIAuthPasswordReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "AccountNo", myreq.AccountNo);
	getChar(req, "PasswordType", &myreq.PasswordType);
	getString(req, "Password", myreq.Password);
	int i = this->api->AuthPassword(&session, &myreq);
	return i;
};


int TdApi::haveCertainRight(int rightID)
{
	int i = this->api->HaveCertainRight(rightID);
	return i;
}


pybind11::tuple TdApi::insertOrder(const dict &req)
{
	TAPIUINT32 session;
	TAPISTR_50 ClientOrderNo;
	TapAPINewOrder myreq = TapAPINewOrder();

	getString(req, "AccountNo", myreq.AccountNo);  
	getString(req, "ExchangeNo", myreq.ExchangeNo);
	getChar(req, "CommodityType", &myreq.CommodityType);
	getString(req, "CommodityNo", myreq.CommodityNo);
	getString(req, "ContractNo", myreq.ContractNo);

	getString(req, "StrikePrice", myreq.StrikePrice);
	getChar(req, "CallOrPutFlag", &myreq.CallOrPutFlag);
	getString(req, "ContractNo2", myreq.ContractNo2);
	getString(req, "StrikePrice2", myreq.StrikePrice2);
	getChar(req, "CallOrPutFlag2", &myreq.CallOrPutFlag2);

	getChar(req, "OrderType", &myreq.OrderType);
	getChar(req, "OrderSource", &myreq.OrderSource); 
	getChar(req, "TimeInForce", &myreq.TimeInForce); 
	getString(req, "ExpireTime", myreq.ExpireTime);

	getChar(req, "IsRiskOrder", &myreq.IsRiskOrder);
	getChar(req, "OrderSide", &myreq.OrderSide);
	getChar(req, "PositionEffect", &myreq.PositionEffect);
	getChar(req, "PositionEffect2", &myreq.PositionEffect2);
	getString(req, "InquiryNo", myreq.InquiryNo);
	getChar(req, "HedgeFlag", &myreq.HedgeFlag);

	getDouble(req, "OrderPrice", &myreq.OrderPrice);
	getDouble(req, "OrderPrice2", &myreq.OrderPrice2);
	getDouble(req, "StopPrice", &myreq.StopPrice);
	getUnsignedInt(req, "OrderQty", &myreq.OrderQty); 
	getUnsignedInt(req, "OrderMinQty", &myreq.OrderMinQty);

	getUnsignedInt(req, "MinClipSize", &myreq.MinClipSize);
	getUnsignedInt(req, "MaxClipSize", &myreq.MaxClipSize);

	getInt(req, "RefInt", &myreq.RefInt);
	getDouble(req, "RefDouble", &myreq.RefDouble);
	getString(req, "RefString", myreq.RefString);

	getString(req, "ClientID", myreq.ClientID);
	getChar(req, "TacticsType", &myreq.TacticsType);
	getChar(req, "TriggerCondition", &myreq.TriggerCondition);
	getChar(req, "TriggerPriceType", &myreq.TriggerPriceType);
	getChar(req, "AddOneIsValid", &myreq.AddOneIsValid);
	getString(req, "ClientLocationID", myreq.ClientLocationID);

	int i = this->api->InsertOrder(&session, &ClientOrderNo, &myreq);
	pybind11::tuple result = pybind11::make_tuple(i, session, pybind11::bytes(ClientOrderNo));
	return result;
}

int TdApi::cancelOrder(const dict &req)
{
	TAPIUINT32 session;
	TapAPIOrderCancelReq myreq = TapAPIOrderCancelReq();
	memset(&myreq, 0, sizeof(myreq));
	getInt(req, "RefInt", &myreq.RefInt);
	getDouble(req, "RefDouble", &myreq.RefDouble);
	getString(req, "RefString", myreq.RefString);
	getChar(req, "ServerFlag", &myreq.ServerFlag);
	getString(req, "OrderNo", myreq.OrderNo);
	int i = this->api->CancelOrder(&session, &myreq);
	return i;
}

//-----------------------------------------
int TdApi::qryTradingDate()
{
	TAPIUINT32 session;
	int i = this->api->QryTradingDate(&session);
	return i;
};

int TdApi::qryAccount(const dict& req)
{
	TAPIUINT32 session;
	TapAPIAccQryReq myreq = TapAPIAccQryReq();
	memset(&myreq, 0, sizeof(myreq));
	int i = this->api->QryAccount(&session, &myreq);
	return i;
};

int TdApi::qryFund(const dict& req)
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

int TdApi::qryContract(const dict& req)
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

int TdApi::qryOrder(const dict& req)
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

int TdApi::qryOrderProcess(const dict& req)
{
	TAPIUINT32 session;
	TapAPIOrderProcessQryReq myreq = TapAPIOrderProcessQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getChar(req, "ServerFlag", &myreq.ServerFlag);
	getString(req, "OrderNo", myreq.OrderNo);
	int i = this->api->QryOrderProcess(&session, &myreq);
	return i;
};

int TdApi::qryFill(const dict& req)
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

int TdApi::qryPosition(const dict& req)
{
	TAPIUINT32 session;
	TapAPIPositionQryReq myreq = TapAPIPositionQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "AccountNo", myreq.AccountNo);
	int i = this->api->QryPosition(&session, &myreq);
	return i;
};

int TdApi::qryPositionSummary(const dict& req)
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

int TdApi::qryAccountCashAdjust(const dict& req)
{
	TAPIUINT32 session;
	TapAPIAccountCashAdjustQryReq myreq = TapAPIAccountCashAdjustQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getUnsignedInt(req, "SerialID", &myreq.SerialID);
	getString(req, "AccountNo", myreq.AccountNo);
	getString(req, "BeginDate", myreq.BeginDate);
	getString(req, "EndDate", myreq.EndDate);
	int i = this->api->QryAccountCashAdjust(&session, &myreq);
	return i;
};

int TdApi::qryTradeMessage(const dict& req)
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

int TdApi::qryBill(const dict& req)
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

int TdApi::qryHisOrder(const dict& req)
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

int TdApi::qryHisOrderProcess(const dict& req)
{
	TAPIUINT32 session;
	TapAPIHisOrderProcessQryReq myreq = TapAPIHisOrderProcessQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "Date", myreq.Date);
	getString(req, "OrderNo", myreq.OrderNo);
	int i = this->api->QryHisOrderProcess(&session, &myreq);
	return i;
};

int TdApi::qryHisMatch(const dict& req)
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

int TdApi::qryHisPosition(const dict& req)
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

int TdApi::qryHisDelivery(const dict& req)
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

int TdApi::qryAccountFeeRent(const dict& req)
{
	TAPIUINT32 session;
	TapAPIAccountFeeRentQryReq myreq = TapAPIAccountFeeRentQryReq();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "AccountNo", myreq.AccountNo);
	int i = this->api->QryAccountFeeRent(&session, &myreq);
	return i;
};

int TdApi::qryAccountMarginRent(const dict& req)
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

///-------------------------------------------------------------------------------------
///Boost.Python封装
///-------------------------------------------------------------------------------------

class PyTdApi : public TdApi
{
public:
	using TdApi::TdApi;

	void onConnect(string HostAddress) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onConnect, HostAddress);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspLogin(int error, const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspLogin, error, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnContactInfo(int error, char last, string ContactInfo) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRtnContactInfo, error, last, ContactInfo);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspRequestVertificateCode(unsigned int session, int error, const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspRequestVertificateCode, session, error, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onExpriationDate(string date, int days) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onExpriationDate, date, days);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onAPIReady(int error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onAPIReady, error);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onDisconnect(int reasonCode) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onDisconnect, reasonCode);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspChangePassword(unsigned int session, int error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspChangePassword, session, error);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspAuthPassword(unsigned int session, int error) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspAuthPassword, session, error);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryTradingDate(unsigned int session, int error, const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryTradingDate, session, error, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspSetReservedInfo(unsigned int session, int error, string info) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspSetReservedInfo, session, error, info);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryAccount(unsigned int session, unsigned int error, char last, const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryAccount, session, session, last, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryFund(unsigned int session, int error, char last, const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryFund, session, error, last, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnFund(const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRtnFund, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryExchange(unsigned int session, int error, char last, const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryExchange, session, error, last, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryCommodity(unsigned int session, int error, char last, const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryCommodity, session, error, last, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryContract(unsigned int session, int error, char last, const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryContract, session, error, last, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnContract(const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRtnContract, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspOrderAction(unsigned int session, int error, const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspOrderAction, session, error, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnOrder(const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRtnOrder, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryOrder(unsigned int session, int error, char last, const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryOrder, session, error, last, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryOrderProcess(unsigned int session, int error, char last, const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryOrderProcess, session, error, last, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryFill(unsigned int session, int error, char last, const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryFill, session, error, last, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnFill(const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRtnFill, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryPosition(unsigned int session, int error, char last, const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryPosition, session, error, last, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnPosition(const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRtnPosition, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryPositionSummary(unsigned int session, int error, char last, const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryPositionSummary, session, error, last, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnPositionSummary(const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRtnPositionSummary, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnPositionProfit(const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRtnPositionProfit, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryCurrency(unsigned int session, int error, char last, const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryCurrency, session, error, last, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryTradeMessage(unsigned int session, int error, char last, const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryTradeMessage, session, error, last, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnTradeMessage(const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRtnTradeMessage, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryHisOrder(unsigned int session, int error, char last, const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryHisOrder, session, error, last, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryHisOrderProcess(unsigned int session, int error, char last, const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryHisOrderProcess, session, error, last, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryHisMatch(unsigned int session, int error, char last, const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryHisMatch, session, error, last, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryHisPosition(unsigned int session, int error, char last, const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryHisPosition, session, error, last, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryHisDelivery(unsigned int session, int error, char last, const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryHisDelivery, session, error, last, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryAccountCashAdjust(unsigned int session, int error, char last, const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryAccountCashAdjust, session, error, last, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryBill(unsigned int session, int error, char last, const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryBill, session, error, last, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryAccountFeeRent(unsigned int session, int error, char last, const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryAccountFeeRent, session, error, last, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryAccountMarginRent(unsigned int session, int error, char last, const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryAccountMarginRent, session, error, last, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspHKMarketOrderInsert(unsigned int session, int error, const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspHKMarketOrderInsert, session, error, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspHKMarketOrderDelete(unsigned int session, int error, const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspHKMarketOrderDelete, session, error, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onHKMarketQuoteNotice(const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onHKMarketQuoteNotice, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspOrderLocalRemove(unsigned int session, int error, const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspOrderLocalRemove, session, error, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspOrderLocalInput(unsigned int session, int error, const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspOrderLocalInput, session, error, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspOrderLocalModify(unsigned int session, int error, const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspOrderLocalModify, session, error, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspOrderLocalTransfer(unsigned int session, int error, const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspOrderLocalTransfer, session, error, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspFillLocalInput(unsigned int session, int error, const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspFillLocalInput, session, error, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspFillLocalRemove(unsigned int session, int error, const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspFillLocalRemove, session, error, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQrySpotLock(unsigned int session, int error, char last, const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQrySpotLock, session, error, last, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnSpotLock(const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRtnSpotLock, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspSubmitUserLoginInfo(unsigned int session, int error, char last, const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspSubmitUserLoginInfo, session, error, last, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspSpecialOrderAction(unsigned int session, int error, const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspSpecialOrderAction, session, error, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnSpecialOrder(const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRtnSpecialOrder, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQrySpecialOrder(unsigned int session, int error, char last, const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQrySpecialOrder, session, error, last, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryCombinePosition(unsigned int session, int error, char last, const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRspQryCombinePosition, session, error, last, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnCombinePosition(const dict& data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, TdApi, onRtnCombinePosition, data);
		}
		catch (const error_already_set& e)
		{
			cout << e.what() << endl;
		}
	};

};


PYBIND11_MODULE(vntaptd, m)
{
	class_<TdApi, PyTdApi> TdApi(m, "TdApi", module_local());
	TdApi
		.def(init<>())
		.def("createITapTradeAPI", &TdApi::createITapTradeAPI)
		.def("release", &TdApi::release)
		.def("init", &TdApi::init)
		.def("exit", &TdApi::exit)
		.def("getITapTradeAPIVersion", &TdApi::getITapTradeAPIVersion)
		.def("getITapErrorDescribe", &TdApi::getITapErrorDescribe)
		.def("setHostAddress", &TdApi::setHostAddress)
		.def("login", &TdApi::login)
		.def("requestVertificateCode", &TdApi::requestVertificateCode)
		.def("setVertificateCode", &TdApi::setVertificateCode)
		.def("disconnect", &TdApi::disconnect)
		.def("authPassword", &TdApi::authPassword)
		.def("haveCertainRight", &TdApi::haveCertainRight)
		.def("insertOrder", &TdApi::insertOrder)
		.def("cancelOrder", &TdApi::cancelOrder)

		.def("qryTradingDate", &TdApi::qryTradingDate)
		.def("qryAccount", &TdApi::qryAccount)
		.def("qryFund", &TdApi::qryFund)
		.def("qryExchange", &TdApi::qryExchange)
		.def("qryCommodity", &TdApi::qryCommodity)
		.def("qryContract", &TdApi::qryContract)
		.def("qryOrder", &TdApi::qryOrder)
		.def("qryOrderProcess", &TdApi::qryOrderProcess)
		.def("qryFill", &TdApi::qryFill)
		.def("qryPosition", &TdApi::qryPosition)
		.def("qryPositionSummary", &TdApi::qryPositionSummary)
		.def("qryCurrency", &TdApi::qryCurrency)
		.def("qryAccountCashAdjust", &TdApi::qryAccountCashAdjust)
		.def("qryTradeMessage", &TdApi::qryTradeMessage)
		.def("qryBill", &TdApi::qryBill)
		.def("qryHisOrder", &TdApi::qryHisOrder)
		.def("qryHisOrderProcess", &TdApi::qryHisOrderProcess)
		.def("qryHisMatch", &TdApi::qryHisMatch)
		.def("qryHisPosition", &TdApi::qryHisPosition)
		.def("qryHisDelivery", &TdApi::qryHisDelivery)
		.def("qryAccountFeeRent", &TdApi::qryAccountFeeRent)
		.def("qryAccountMarginRent", &TdApi::qryAccountMarginRent)

		.def("onConnect", &TdApi::onConnect)
		.def("onRspLogin", &TdApi::onRspLogin)
		.def("onRtnContactInfo", &TdApi::onRtnContactInfo)
		.def("onRspRequestVertificateCode", &TdApi::onRspRequestVertificateCode)
		.def("onExpriationDate", &TdApi::onExpriationDate)
		.def("onAPIReady", &TdApi::onAPIReady)
		.def("onDisconnect", &TdApi::onDisconnect)
		.def("onRspChangePassword", &TdApi::onRspChangePassword)
		.def("onRspAuthPassword", &TdApi::onRspAuthPassword)
		.def("onRspQryTradingDate", &TdApi::onRspQryTradingDate)
		.def("onRspSetReservedInfo", &TdApi::onRspSetReservedInfo)
		.def("onRspQryAccount", &TdApi::onRspQryAccount)
		.def("onRspQryFund", &TdApi::onRspQryFund)
		.def("onRtnFund", &TdApi::onRtnFund)
		.def("onRspQryExchange", &TdApi::onRspQryExchange)
		.def("onRspQryCommodity", &TdApi::onRspQryCommodity)
		.def("onRspQryContract", &TdApi::onRspQryContract)
		.def("onRtnContract", &TdApi::onRtnContract)
		.def("onRspOrderAction", &TdApi::onRspOrderAction)
		.def("onRtnOrder", &TdApi::onRtnOrder)
		.def("onRspQryOrder", &TdApi::onRspQryOrder)
		.def("onRspQryOrderProcess", &TdApi::onRspQryOrderProcess)
		.def("onRspQryFill", &TdApi::onRspQryFill)
		.def("onRtnFill", &TdApi::onRtnFill)
		.def("onRspQryPosition", &TdApi::onRspQryPosition)
		.def("onRtnPosition", &TdApi::onRtnPosition)
		.def("onRspQryPositionSummary", &TdApi::onRspQryPositionSummary)
		.def("onRtnPositionSummary", &TdApi::onRtnPositionSummary)
		.def("onRtnPositionProfit", &TdApi::onRtnPositionProfit)
		.def("onRspQryCurrency", &TdApi::onRspQryCurrency)
		.def("onRspQryTradeMessage", &TdApi::onRspQryTradeMessage)
		.def("onRtnTradeMessage", &TdApi::onRtnTradeMessage)
		.def("onRspQryHisOrder", &TdApi::onRspQryHisOrder)
		.def("onRspQryHisOrderProcess", &TdApi::onRspQryHisOrderProcess)
		.def("onRspQryHisMatch", &TdApi::onRspQryHisMatch)
		.def("onRspQryHisPosition", &TdApi::onRspQryHisPosition)
		.def("onRspQryHisDelivery", &TdApi::onRspQryHisDelivery)
		.def("onRspQryAccountCashAdjust", &TdApi::onRspQryAccountCashAdjust)
		.def("onRspQryBill", &TdApi::onRspQryBill)
		.def("onRspQryAccountFeeRent", &TdApi::onRspQryAccountFeeRent)
		.def("onRspQryAccountMarginRent", &TdApi::onRspQryAccountMarginRent)
		.def("onRspHKMarketOrderInsert", &TdApi::onRspHKMarketOrderInsert)
		.def("onRspHKMarketOrderDelete", &TdApi::onRspHKMarketOrderDelete)
		.def("onHKMarketQuoteNotice", &TdApi::onHKMarketQuoteNotice)
		.def("onRspOrderLocalRemove", &TdApi::onRspOrderLocalRemove)
		.def("onRspOrderLocalInput", &TdApi::onRspOrderLocalInput)
		.def("onRspOrderLocalModify", &TdApi::onRspOrderLocalModify)
		.def("onRspOrderLocalTransfer", &TdApi::onRspOrderLocalTransfer)
		.def("onRspFillLocalInput", &TdApi::onRspFillLocalInput)
		.def("onRspFillLocalRemove", &TdApi::onRspFillLocalRemove)
		.def("onRspQrySpotLock", &TdApi::onRspQrySpotLock)
		.def("onRtnSpotLock", &TdApi::onRtnSpotLock)
		.def("onRspSubmitUserLoginInfo", &TdApi::onRspSubmitUserLoginInfo)
		.def("onRspSpecialOrderAction", &TdApi::onRspSpecialOrderAction)
		.def("onRtnSpecialOrder", &TdApi::onRtnSpecialOrder)
		.def("onRspQrySpecialOrder", &TdApi::onRspQrySpecialOrder)
		.def("onRspQryCombinePosition", &TdApi::onRspQryCombinePosition)
		.def("onRtnCombinePosition", &TdApi::onRtnCombinePosition)
		.def("onRspQryUserTrustDevice", &TdApi::onRspQryUserTrustDevice)
		.def("onRspAddUserTrustDevice", &TdApi::onRspAddUserTrustDevice)
		.def("onRspDelUserTrustDevice", &TdApi::onRspDelUserTrustDevice)
		.def("onRtnAddUserTrustDevice", &TdApi::onRtnAddUserTrustDevice)
		.def("onRtnDelUserTrustDevice", &TdApi::onRtnDelUserTrustDevice)
		.def("onRspQryIPOInfo", &TdApi::onRspQryIPOInfo)
		.def("onRspQryIPOStockQty", &TdApi::onRspQryIPOStockQty)
		.def("onRspQryAccountIPO", &TdApi::onRspQryAccountIPO)
		.def("onRspAddAccountIPO", &TdApi::onRspAddAccountIPO)
		.def("onRspCancelAccountIPO", &TdApi::onRspCancelAccountIPO)
		.def("onRtnAddAccountIPO", &TdApi::onRtnAddAccountIPO)
		.def("onRtnCancelAccountIPO", &TdApi::onRtnCancelAccountIPO)
		.def("onRspUnFreezeVerificate", &TdApi::onRspUnFreezeVerificate)
		;

}
