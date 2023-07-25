TapAPITradeLoginAuth = {
    "UserNo": "string",
    "ISModifyPassword": "char",
    "Password": "string",
    "NewPassword": "string",
    "LoginIP": "string",
    "LoginMac": "string",
    "DeviceName": "string",
}

TapAPITradeLoginRspInfo = {
    "UserNo": "string",
    "UserType": "int",
    "UserName": "string",
    "ReservedInfo": "string",
    "LastLoginIP": "string",
    "LastLoginProt": "unsigned int",
    "LastLoginTime": "string",
    "LastLogoutTime": "string",
    "TradeDate": "string",
    "LastSettleTime": "string",
    "StartTime": "string",
    "NextSecondDate": "string",
    "LastLoginInfo": "string",
}

TapAPIRequestVertificateCodeRsp = {
    "SecondSerialID": "string",
    "Effective": "int",
}

TapAPISecondCertificationReq = {
    "VertificateCode": "string",
    "LoginType": "char",
}

TapAPIAccQryReq = {
}

TapAPIAccountInfo = {
    "AccountNo": "string",
    "AccountType": "char",
    "AccountState": "char",
    "AccountTradeRight": "char",
    "CommodityGroupNo": "string",
    "AccountShortName": "string",
    "AccountEnShortName": "string",
}

TapAPINewOrder = {
    "AccountNo": "string",
    "ExchangeNo": "string",
    "CommodityType": "char",
    "CommodityNo": "string",
    "ContractNo": "string",
    "StrikePrice": "string",
    "CallOrPutFlag": "char",
    "ContractNo2": "string",
    "StrikePrice2": "string",
    "CallOrPutFlag2": "char",
    "OrderType": "char",
    "OrderSource": "char",
    "TimeInForce": "char",
    "ExpireTime": "string",
    "IsRiskOrder": "char",
    "OrderSide": "char",
    "PositionEffect": "char",
    "PositionEffect2": "char",
    "InquiryNo": "string",
    "HedgeFlag": "char",
    "OrderPrice": "double",
    "OrderPrice2": "double",
    "StopPrice": "double",
    "OrderQty": "unsigned int",
    "OrderMinQty": "unsigned int",
    "MinClipSize": "unsigned int",
    "MaxClipSize": "unsigned int",
    "RefInt": "int",
    "RefDouble": "double",
    "RefString": "string",
    "ClientID": "string",
    "TacticsType": "char",
    "TriggerCondition": "char",
    "TriggerPriceType": "char",
    "AddOneIsValid": "char",
    "ClientLocationID": "string",
}

TapAPIOrderInfo = {
    "AccountNo": "string",
    "ExchangeNo": "string",
    "CommodityType": "char",
    "CommodityNo": "string",
    "ContractNo": "string",
    "StrikePrice": "string",
    "CallOrPutFlag": "char",
    "ContractNo2": "string",
    "StrikePrice2": "string",
    "CallOrPutFlag2": "char",
    "OrderType": "char",
    "OrderSource": "char",
    "TimeInForce": "char",
    "ExpireTime": "string",
    "IsRiskOrder": "char",
    "OrderSide": "char",
    "PositionEffect": "char",
    "PositionEffect2": "char",
    "InquiryNo": "string",
    "HedgeFlag": "char",
    "OrderPrice": "double",
    "OrderPrice2": "double",
    "StopPrice": "double",
    "OrderQty": "unsigned int",
    "OrderMinQty": "unsigned int",
    "RefInt": "int",
    "RefDouble": "double",
    "RefString": "string",
    "MinClipSize": "unsigned int",
    "MaxClipSize": "unsigned int",
    "LicenseNo": "string",
    "ServerFlag": "char",
    "OrderNo": "string",
    "ClientOrderNo": "string",
    "ClientID": "string",
    "TacticsType": "char",
    "TriggerCondition": "char",
    "TriggerPriceType": "char",
    "AddOneIsValid": "char",
    "ClientLocalIP": "string",
    "ClientMac": "string",
    "ClientIP": "string",
    "OrderStreamID": "unsigned int",
    "UpperNo": "string",
    "UpperChannelNo": "string",
    "OrderLocalNo": "string",
    "UpperStreamID": "unsigned int",
    "OrderSystemNo": "string",
    "OrderExchangeSystemNo": "string",
    "OrderParentSystemNo": "string",
    "OrderInsertUserNo": "string",
    "OrderInsertTime": "string",
    "OrderCommandUserNo": "string",
    "OrderUpdateUserNo": "string",
    "OrderUpdateTime": "string",
    "OrderState": "char",
    "OrderMatchPrice": "double",
    "OrderMatchPrice2": "double",
    "OrderMatchQty": "unsigned int",
    "OrderMatchQty2": "unsigned int",
    "ErrorCode": "unsigned int",
    "ErrorText": "string",
    "IsBackInput": "char",
    "IsDeleted": "char",
    "IsAddOne": "char",
    "ClientLocationID": "string",
}

TapAPIOrderInfoNotice = {
    "SessionID": "unsigned int",
    "ErrorCode": "unsigned int",
    "OrderInfo": "dict",
}

TapAPIOrderActionRsp = {
    "ActionType": "char",
    "OrderInfo": "dict",
}

TapAPIAmendOrder = {
    "ReqData": "dict",
    "ServerFlag": "char",
    "OrderNo": "string",
}

TapAPIOrderCancelReq = {
    "RefInt": "int",
    "RefDouble": "double",
    "RefString": "string",
    "ServerFlag": "char",
    "OrderNo": "string",
}

TapAPIOrderDeactivateReq = TapAPIOrderCancelReq
TapAPIOrderActivateReq = TapAPIOrderCancelReq
TapAPIOrderDeleteReq = TapAPIOrderCancelReq
TapAPIOrderQryReq = {
    "AccountNo": "string",
    "ExchangeNo": "string",
    "CommodityType": "char",
    "CommodityNo": "string",
    "OrderType": "char",
    "OrderSource": "char",
    "TimeInForce": "char",
    "ExpireTime": "string",
    "IsRiskOrder": "char",
    "ServerFlag": "char",
    "OrderNo": "string",
    "IsBackInput": "char",
    "IsDeleted": "char",
    "IsAddOne": "char",
    "OrderQryType": "char",
}

TapAPIOrderProcessQryReq = {
    "ServerFlag": "char",
    "OrderNo": "string",
}

TapAPIFillQryReq = {
    "AccountNo": "string",
    "ExchangeNo": "string",
    "CommodityType": "char",
    "CommodityNo": "string",
    "ContractNo": "string",
    "StrikePrice": "string",
    "CallOrPutFlag": "char",
    "MatchSource": "char",
    "MatchSide": "char",
    "PositionEffect": "char",
    "ServerFlag": "char",
    "OrderNo": "string",
    "UpperNo": "string",
    "IsDeleted": "char",
    "IsAddOne": "char",
}

TapAPIFillInfo = {
    "AccountNo": "string",
    "ExchangeNo": "string",
    "CommodityType": "char",
    "CommodityNo": "string",
    "ContractNo": "string",
    "StrikePrice": "string",
    "CallOrPutFlag": "char",
    "MatchSource": "char",
    "MatchSide": "char",
    "PositionEffect": "char",
    "ServerFlag": "char",
    "OrderNo": "string",
    "OrderSystemNo": "string",
    "MatchNo": "string",
    "UpperMatchNo": "string",
    "ExchangeMatchNo": "string",
    "MatchDateTime": "string",
    "UpperMatchDateTime": "string",
    "UpperNo": "string",
    "MatchPrice": "double",
    "MatchQty": "unsigned int",
    "IsDeleted": "char",
    "IsAddOne": "char",
    "FeeCurrencyGroup": "string",
    "FeeCurrency": "string",
    "FeeValue": "double",
    "IsManualFee": "char",
    "ClosePrositionPrice": "double",
    "CloseProfit": "double",
}

TapAPICloseQryReq = {
    "AccountNo": "string",
    "ExchangeNo": "string",
    "CommodityType": "char",
    "CommodityNo": "string",
}

TapAPICloseInfo = {
    "AccountNo": "string",
    "ExchangeNo": "string",
    "CommodityType": "char",
    "CommodityNo": "string",
    "ContractNo": "string",
    "StrikePrice": "string",
    "CallOrPutFlag": "char",
    "CloseSide": "char",
    "CloseQty": "unsigned int",
    "OpenPrice": "double",
    "ClosePrice": "double",
    "OpenMatchNo": "string",
    "OpenMatchDateTime": "string",
    "CloseMatchNo": "string",
    "CloseMatchDateTime": "string",
    "CloseStreamId": "unsigned int",
    "CommodityCurrencyGroup": "string",
    "CommodityCurrency": "string",
    "CloseProfit": "double",
}

TapAPIPositionQryReq = {
    "AccountNo": "string",
}

TapAPIPositionInfo = {
    "AccountNo": "string",
    "ExchangeNo": "string",
    "CommodityType": "char",
    "CommodityNo": "string",
    "ContractNo": "string",
    "StrikePrice": "string",
    "CallOrPutFlag": "char",
    "MatchSide": "char",
    "HedgeFlag": "char",
    "PositionNo": "string",
    "ServerFlag": "char",
    "OrderNo": "string",
    "MatchNo": "string",
    "UpperNo": "string",
    "PositionPrice": "double",
    "PositionQty": "unsigned int",
    "PositionStreamId": "unsigned int",
    "CommodityCurrencyGroup": "string",
    "CommodityCurrency": "string",
    "CalculatePrice": "double",
    "AccountInitialMargin": "double",
    "AccountMaintenanceMargin": "double",
    "UpperInitialMargin": "double",
    "UpperMaintenanceMargin": "double",
    "PositionProfit": "double",
    "LMEPositionProfit": "double",
    "OptionMarketValue": "double",
    "IsHistory": "char",
}

TapAPIPositionProfit = {
    "PositionNo": "string",
    "PositionStreamId": "unsigned int",
    "PositionProfit": "double",
    "LMEPositionProfit": "double",
    "OptionMarketValue": "double",
    "CalculatePrice": "double",
}

TapAPIPositionProfitNotice = {
    "IsLast": "char",
    "Data": "dict",
}

TapAPIPositionSummary = {
    "AccountNo": "string",
    "ExchangeNo": "string",
    "CommodityType": "char",
    "CommodityNo": "string",
    "ContractNo": "string",
    "StrikePrice": "string",
    "CallOrPutFlag": "char",
    "MatchSide": "char",
    "PositionPrice": "double",
    "PositionQty": "unsigned int",
    "HisPositionQty": "unsigned int",
}

TapAPIFundReq = {
    "AccountNo": "string",
}

TapAPIFundData = {
    "AccountNo": "string",
    "CurrencyGroupNo": "string",
    "CurrencyNo": "string",
    "TradeRate": "double",
    "FutureAlg": "char",
    "OptionAlg": "char",
    "PreBalance": "double",
    "PreUnExpProfit": "double",
    "PreLMEPositionProfit": "double",
    "PreEquity": "double",
    "PreAvailable1": "double",
    "PreMarketEquity": "double",
    "CashInValue": "double",
    "CashOutValue": "double",
    "CashAdjustValue": "double",
    "CashPledged": "double",
    "FrozenFee": "double",
    "FrozenDeposit": "double",
    "AccountFee": "double",
    "SwapInValue": "double",
    "SwapOutValue": "double",
    "PremiumIncome": "double",
    "PremiumPay": "double",
    "CloseProfit": "double",
    "FrozenFund": "double",
    "UnExpProfit": "double",
    "ExpProfit": "double",
    "PositionProfit": "double",
    "LmePositionProfit": "double",
    "OptionMarketValue": "double",
    "AccountIntialMargin": "double",
    "AccountMaintenanceMargin": "double",
    "UpperInitalMargin": "double",
    "UpperMaintenanceMargin": "double",
    "Discount": "double",
    "Balance": "double",
    "Equity": "double",
    "Available": "double",
    "CanDraw": "double",
    "MarketEquity": "double",
    "AuthMoney": "double",
}

TapAPICommodityInfo = {
    "ExchangeNo": "string",
    "CommodityType": "char",
    "CommodityNo": "string",
    "CommodityName": "string",
    "CommodityEngName": "string",
    "RelateExchangeNo": "string",
    "RelateCommodityType": "char",
    "RelateCommodityNo": "string",
    "RelateExchangeNo2": "string",
    "RelateCommodityType2": "char",
    "RelateCommodityNo2": "string",
    "CurrencyGroupNo": "string",
    "TradeCurrency": "string",
    "ContractSize": "double",
    "OpenCloseMode": "char",
    "StrikePriceTimes": "double",
    "CommodityTickSize": "double",
    "CommodityDenominator": "int",
    "CmbDirect": "char",
    "DeliveryMode": "char",
    "DeliveryDays": "int",
    "AddOneTime": "string",
    "CommodityTimeZone": "int",
    "IsAddOne": "char",
    "OptionType": "char",
}

TapAPITradeContractInfo = {
    "ExchangeNo": "string",
    "CommodityType": "char",
    "CommodityNo": "string",
    "ContractNo1": "string",
    "StrikePrice1": "string",
    "CallOrPutFlag1": "char",
    "ContractNo2": "string",
    "StrikePrice2": "string",
    "CallOrPutFlag2": "char",
    "ContractType": "char",
    "QuoteUnderlyingContract": "string",
    "ContractName": "string",
    "ContractExpDate": "string",
    "LastTradeDate": "string",
    "FirstNoticeDate": "string",
    "ContractSize": "double",
}

TapAPICurrencyInfo = {
    "CurrencyNo": "string",
    "CurrencyGroupNo": "string",
    "TradeRate": "double",
    "TradeRate2": "double",
    "FutureAlg": "char",
    "OptionAlg": "char",
}

TapAPITradeMessageReq = {
    "AccountNo": "string",
    "BenginSendDateTime": "string",
    "EndSendDateTime": "string",
}

TapAPITradeMessage = {
    "SerialID": "unsigned int",
    "AccountNo": "string",
    "TMsgValidDateTime": "string",
    "TMsgTitle": "string",
    "TMsgContent": "string",
    "TMsgType": "char",
    "TMsgLevel": "char",
    "IsSendBySMS": "char",
    "IsSendByEMail": "char",
    "Sender": "string",
    "SendDateTime": "string",
}

TapAPIBillQryReq = {
    "UserNo": "string",
    "BillType": "char",
    "BillDate": "string",
    "BillFileType": "char",
}

TapAPIBillQryRsp = {
    "Reqdata": "dict",
    "BillLen": "int",
    "BillText": "char",
}

TapAPIHisOrderQryReq = {
    "AccountNo": "string",
    "BeginDate": "string",
    "EndDate": "string",
}

TapAPIHisOrderQryRsp = {
    "Date": "string",
    "AccountNo": "string",
    "ExchangeNo": "string",
    "CommodityType": "char",
    "CommodityNo": "string",
    "ContractNo": "string",
    "StrikePrice": "string",
    "CallOrPutFlag": "char",
    "ContractNo2": "string",
    "StrikePrice2": "string",
    "CallOrPutFlag2": "char",
    "OrderType": "char",
    "OrderSource": "char",
    "TimeInForce": "char",
    "ExpireTime": "string",
    "IsRiskOrder": "char",
    "OrderSide": "char",
    "PositionEffect": "char",
    "PositionEffect2": "char",
    "InquiryNo": "string",
    "HedgeFlag": "char",
    "OrderPrice": "double",
    "OrderPrice2": "double",
    "StopPrice": "double",
    "OrderQty": "unsigned int",
    "OrderMinQty": "unsigned int",
    "OrderCanceledQty": "unsigned int",
    "RefInt": "int",
    "RefDouble": "double",
    "RefString": "string",
    "ServerFlag": "char",
    "OrderNo": "string",
    "OrderStreamID": "unsigned int",
    "UpperNo": "string",
    "UpperChannelNo": "string",
    "OrderLocalNo": "string",
    "UpperStreamID": "unsigned int",
    "OrderSystemNo": "string",
    "OrderExchangeSystemNo": "string",
    "OrderParentSystemNo": "string",
    "OrderInsertUserNo": "string",
    "OrderInsertTime": "string",
    "OrderCommandUserNo": "string",
    "OrderUpdateUserNo": "string",
    "OrderUpdateTime": "string",
    "OrderState": "char",
    "OrderMatchPrice": "double",
    "OrderMatchPrice2": "double",
    "OrderMatchQty": "unsigned int",
    "OrderMatchQty2": "unsigned int",
    "ErrorCode": "unsigned int",
    "ErrorText": "string",
    "IsBackInput": "char",
    "IsDeleted": "char",
    "IsAddOne": "char",
    "AddOneIsValid": "char",
    "MinClipSize": "unsigned int",
    "MaxClipSize": "unsigned int",
    "LicenseNo": "string",
    "TacticsType": "char",
    "TriggerCondition": "char",
    "TriggerPriceType": "char",
}

TapAPIHisMatchQryReq = {
    "AccountNo": "string",
    "BeginDate": "string",
    "EndDate": "string",
}

TapAPIHisMatchQryRsp = {
    "SettleDate": "string",
    "TradeDate": "string",
    "AccountNo": "string",
    "ExchangeNo": "string",
    "CommodityType": "char",
    "CommodityNo": "string",
    "ContractNo": "string",
    "StrikePrice": "string",
    "CallOrPutFlag": "char",
    "MatchSource": "char",
    "MatchSide": "char",
    "PositionEffect": "char",
    "HedgeFlag": "char",
    "MatchPrice": "double",
    "MatchQty": "unsigned int",
    "OrderNo": "string",
    "MatchNo": "string",
    "MatchStreamID": "unsigned int",
    "UpperNo": "string",
    "MatchCmbNo": "string",
    "ExchangeMatchNo": "string",
    "MatchUpperStreamID": "unsigned int",
    "CommodityCurrencyGroup": "string",
    "CommodityCurrency": "string",
    "Turnover": "double",
    "PremiumIncome": "double",
    "PremiumPay": "double",
    "AccountFee": "double",
    "AccountFeeCurrencyGroup": "string",
    "AccountFeeCurrency": "string",
    "IsManualFee": "char",
    "AccountOtherFee": "double",
    "UpperFee": "double",
    "UpperFeeCurrencyGroup": "string",
    "UpperFeeCurrency": "string",
    "IsUpperManualFee": "char",
    "UpperOtherFee": "double",
    "MatchDateTime": "string",
    "UpperMatchDateTime": "string",
    "CloseProfit": "double",
    "ClosePrice": "double",
    "CloseQty": "unsigned int",
    "SettleGroupNo": "string",
    "OperatorNo": "string",
    "OperateTime": "string",
}

TapAPIHisOrderProcessQryReq = {
    "Date": "string",
    "OrderNo": "string",
}

TapAPIHisOrderProcessQryRsp = TapAPIHisOrderQryRsp
TapAPIHisPositionQryReq = {
    "AccountNo": "string",
    "Date": "string",
    "SettleFlag": "char",
}

TapAPIHisPositionQryRsp = {
    "SettleDate": "string",
    "OpenDate": "string",
    "AccountNo": "string",
    "ExchangeNo": "string",
    "CommodityType": "char",
    "CommodityNo": "string",
    "ContractNo": "string",
    "StrikePrice": "string",
    "CallOrPutFlag": "char",
    "MatchSide": "char",
    "HedgeFlag": "char",
    "PositionPrice": "double",
    "PositionQty": "unsigned int",
    "OrderNo": "string",
    "PositionNo": "string",
    "UpperNo": "string",
    "CurrencyGroup": "string",
    "Currency": "string",
    "PreSettlePrice": "double",
    "SettlePrice": "double",
    "PositionDProfit": "double",
    "LMEPositionProfit": "double",
    "OptionMarketValue": "double",
    "AccountInitialMargin": "double",
    "AccountMaintenanceMargin": "double",
    "UpperInitialMargin": "double",
    "UpperMaintenanceMargin": "double",
    "SettleGroupNo": "string",
    "ServerFlag": "char",
    "SuperiorAccount": "string",
}

TapAPIHisDeliveryQryReq = {
    "AccountNo": "string",
    "BeginDate": "string",
    "EndDate": "string",
    "SettleFlag": "char",
}

TapAPIHisDeliveryQryRsp = {
    "DeliveryDate": "string",
    "OpenDate": "string",
    "AccountNo": "string",
    "ExchangeNo": "string",
    "CommodityType": "char",
    "CommodityNo": "string",
    "ContractNo": "string",
    "StrikePrice": "string",
    "CallOrPutFlag": "char",
    "MatchSource": "char",
    "OpenSide": "char",
    "OpenPrice": "double",
    "DeliveryPrice": "double",
    "DeliveryQty": "unsigned int",
    "FrozenQty": "unsigned int",
    "OpenNo": "string",
    "UpperNo": "string",
    "CommodityCurrencyGroupy": "string",
    "CommodityCurrency": "string",
    "PreSettlePrice": "double",
    "DeliveryProfit": "double",
    "AccountFrozenInitialMargin": "double",
    "AccountFrozenMaintenanceMargin": "double",
    "UpperFrozenInitialMargin": "double",
    "UpperFrozenMaintenanceMargin": "double",
    "AccountFeeCurrencyGroup": "string",
    "AccountFeeCurrency": "string",
    "AccountDeliveryFee": "double",
    "UpperFeeCurrencyGroup": "string",
    "UpperFeeCurrency": "string",
    "UpperDeliveryFee": "double",
    "DeliveryMode": "char",
    "OperatorNo": "string",
    "OperateTime": "string",
    "SettleGourpNo": "string",
    "FutureContractNo": "string",
    "OptionStrikePrice": "string",
    "SuperiorAccount": "string",
}

TapAPIAccountCashAdjustQryReq = {
    "SerialID": "unsigned int",
    "AccountNo": "string",
    "BeginDate": "string",
    "EndDate": "string",
}

TapAPIAccountCashAdjustQryRsp = {
    "Date": "string",
    "AccountNo": "string",
    "CashAdjustType": "char",
    "CurrencyGroupNo": "string",
    "CurrencyNo": "string",
    "CashAdjustValue": "double",
    "CashAdjustRemark": "string",
    "OperateTime": "string",
    "OperatorNo": "string",
    "AccountBank": "string",
    "BankAccount": "string",
    "AccountLWFlag": "char",
    "CompanyBank": "string",
    "InternalBankAccount": "string",
    "CompanyLWFlag": "char",
}

TapAPIAccountFeeRentQryReq = {
    "AccountNo": "string",
}

TapAPIAccountFeeRentQryRsp = {
    "AccountNo": "string",
    "ExchangeNo": "string",
    "CommodityType": "char",
    "CommodityNo": "string",
    "MatchSource": "char",
    "CalculateMode": "char",
    "CurrencyGroupNo": "string",
    "CurrencyNo": "string",
    "OpenCloseFee": "double",
    "CloseTodayFee": "double",
}

TapAPIAccountMarginRentQryReq = {
    "AccountNo": "string",
    "ExchangeNo": "string",
    "CommodityType": "char",
    "CommodityNo": "string",
}

TapAPIAccountMarginRentQryRsp = {
    "AccountNo": "string",
    "ExchangeNo": "string",
    "CommodityType": "char",
    "CommodityNo": "string",
    "ContractNo": "string",
    "StrikePrice": "string",
    "CallOrPutFlag": "char",
    "CalculateMode": "char",
    "CurrencyGroupNo": "string",
    "CurrencyNo": "string",
    "InitialMargin": "double",
    "MaintenanceMargin": "double",
    "SellInitialMargin": "double",
    "SellMaintenanceMargin": "double",
    "LockMargin": "double",
}

TapAPIOrderQuoteMarketNotice = {
    "ExchangeNo": "string",
    "CommodityType": "char",
    "CommodityNo": "string",
    "ContractNo": "string",
    "StrikePrice": "string",
    "CallOrPutFlag": "char",
    "OrderSide": "char",
    "OrderQty": "unsigned int",
}

TapAPIOrderMarketInsertReq = {
    "AccountNo": "string",
    "ExchangeNo": "string",
    "CommodityType": "char",
    "CommodityNo": "string",
    "ContractNo": "string",
    "StrikePrice": "string",
    "CallOrPutFlag": "char",
    "OrderType": "char",
    "TimeInForce": "char",
    "ExpireTime": "string",
    "OrderSource": "char",
    "BuyPositionEffect": "char",
    "SellPositionEffect": "char",
    "AddOneIsValid": "char",
    "OrderBuyPrice": "double",
    "OrderSellPrice": "double",
    "OrderBuyQty": "unsigned int",
    "OrderSellQty": "unsigned int",
    "ClientBuyOrderNo": "string",
    "ClientSellOrderNo": "string",
    "RefInt": "int",
    "RefDouble": "double",
    "RefString": "string",
    "Remark": "string",
}

TapAPIOrderMarketInsertRsp = {
    "AccountNo": "string",
    "ExchangeNo": "string",
    "CommodityType": "char",
    "CommodityNo": "string",
    "ContractNo": "string",
    "StrikePrice": "string",
    "CallOrPutFlag": "char",
    "OrderType": "char",
    "TimeInForce": "char",
    "ExpireTime": "string",
    "OrderSource": "char",
    "BuyPositionEffect": "char",
    "SellPositionEffect": "char",
    "OrderBuyPrice": "double",
    "OrderSellPrice": "double",
    "OrderBuyQty": "unsigned int",
    "OrderSellQty": "unsigned int",
    "ServerFlag": "char",
    "OrderBuyNo": "string",
    "OrderSellNo": "string",
    "AddOneIsValid": "char",
    "OrderMarketUserNo": "string",
    "OrderMarketTime": "string",
    "RefInt": "int",
    "RefDouble": "double",
    "RefString": "string",
    "ClientBuyOrderNo": "string",
    "ClientSellOrderNo": "string",
    "ErrorCode": "unsigned int",
    "ErrorText": "string",
    "ClientLocalIP": "string",
    "ClientMac": "string",
    "ClientIP": "string",
    "Remark": "string",
}

TapAPIOrderMarketDeleteReq = {
    "ServerFlag": "char",
    "OrderBuyNo": "string",
    "OrderSellNo": "string",
}

TapAPIOrderMarketDeleteRsp = TapAPIOrderMarketInsertRsp
TapAPIOrderLocalRemoveReq = {
    "ServerFlag": "char",
    "OrderNo": "string",
}

TapAPIOrderLocalRemoveRsp = {
    "req": "dict",
    "ClientLocalIP": "string",
    "ClientMac": "string",
    "ClientIP": "string",
}

TapAPIOrderLocalInputReq = {
    "AccountNo": "string",
    "ExchangeNo": "string",
    "CommodityType": "char",
    "CommodityNo": "string",
    "ContractNo": "string",
    "StrikePrice": "string",
    "CallOrPutFlag": "char",
    "ContractNo2": "string",
    "StrikePrice2": "string",
    "CallOrPutFlag2": "char",
    "OrderType": "char",
    "OrderSource": "char",
    "TimeInForce": "char",
    "ExpireTime": "string",
    "IsRiskOrder": "char",
    "OrderSide": "char",
    "PositionEffect": "char",
    "PositionEffect2": "char",
    "InquiryNo": "string",
    "HedgeFlag": "char",
    "OrderPrice": "double",
    "OrderPrice2": "double",
    "StopPrice": "double",
    "OrderQty": "unsigned int",
    "OrderMinQty": "unsigned int",
    "OrderSystemNo": "string",
    "OrderExchangeSystemNo": "string",
    "UpperNo": "string",
    "OrderMatchPrice": "double",
    "OrderMatchPrice2": "double",
    "OrderMatchQty": "unsigned int",
    "OrderMatchQty2": "unsigned int",
    "OrderState": "char",
    "IsAddOne": "char",
    "LowerAccount": "string",
}

TapAPIOrderLocalInputRsp = TapAPIOrderInfo
TapAPIOrderLocalModifyReq = {
    "req": "dict",
    "ServerFlag": "char",
    "OrderNo": "string",
}

TapAPIOrderLocalModifyRsp = TapAPIOrderInfo
TapAPIOrderLocalTransferReq = {
    "AccountNo": "string",
    "ServerFlag": "char",
    "OrderNo": "string",
}

TapAPIOrderLocalTransferRsp = TapAPIOrderInfo
TapAPIFillLocalInputReq = {
    "AccountNo": "string",
    "ExchangeNo": "string",
    "CommodityType": "char",
    "CommodityNo": "string",
    "ContractNo": "string",
    "StrikePrice": "string",
    "CallOrPutFlag": "char",
    "MatchSide": "char",
    "PositionEffect": "char",
    "HedgeFlag": "char",
    "MatchPrice": "double",
    "MatchQty": "unsigned int",
    "OrderSystemNo": "string",
    "UpperMatchNo": "string",
    "MatchDateTime": "string",
    "UpperMatchDateTime": "string",
    "UpperNo": "string",
    "IsAddOne": "char",
    "FeeCurrencyGroup": "string",
    "FeeCurrency": "string",
    "FeeValue": "double",
    "IsManualFee": "char",
    "ClosePositionPrice": "double",
}

TapAPIFillLocalInputRsp = TapAPIFillLocalInputReq
TapAPIFillLocalRemoveReq = {
    "ServerFlag": "char",
    "MatchNo": "string",
}

TapAPIFillLocalRemoveRsp = TapAPIFillLocalRemoveReq
TapAPITradingCalendarQryRsp = {
    "CurrTradeDate": "string",
    "LastSettlementDate": "string",
    "PromptDate": "string",
    "LastPromptDate": "string",
}

TapAPISpotLockQryReq = {
    "AccountNo": "string",
}

TapAPISpotLockQryRsp = TapAPISpotLockQryReq
TapAPISpotLockDataRsp = {
    "AccountNo": "string",
    "ExchangeNo": "string",
    "CommodityType": "char",
    "CommodityNo": "string",
    "LockQty": "unsigned int",
    "FrozenQty": "unsigned int",
    "CanUnLockQty": "unsigned int",
}

TapAPISpotLockDataNotice = TapAPISpotLockDataRsp
TapAPISubmitUserLoginInfo = {
    "UserNo": "string",
    "GatherInfo": "string",
    "ClientLoginIP": "string",
    "ClientLoginPort": "unsigned int",
    "ClientLoginDateTime": "string",
    "ClientAppID": "string",
    "AuthKeyVersion": "unsigned int",
    "AbnormalNo": "char",
}

TapAPISubmitUserLoginRspInfo = {
    "UserNo": "string",
}

TapAPISpecialOrderInsertReq = {
    "AccountNo": "string",
    "SpecialOrderType": "char",
    "OrderSource": "char",
    "CombineNo": "string",
    "OrderQty": "unsigned int",
    "ExchangeNo": "string",
    "CommodityType": "char",
    "CommodityNo": "string",
    "ContractNo": "string",
    "StrikePrice": "string",
    "CallOrPutFlag": "char",
    "OrderSide1": "char",
    "HedgeFlag1": "char",
    "ContractNo2": "string",
    "StrikePrice2": "string",
    "CallOrPutFlag2": "char",
}

TapAPISpecialOrderQryReq = {
    "AccountNo": "string",
    "OrderNo": "string",
}

TapAPISpecialOrderInfo = {
    "SessionID": "unsigned int",
    "ErrorCode": "unsigned int",
    "ErrorText": "string",
    "AccountNo": "string",
    "ServerFlag": "char",
    "OrderNo": "string",
    "ClientOrderNo": "string",
    "SpecialOrderType": "char",
    "OrderSource": "char",
    "CombineStrategy": "string",
    "CombineNo": "string",
    "OrderQty": "unsigned int",
    "ExchangeNo": "string",
    "CommodityType": "char",
    "CommodityNo": "string",
    "ContractNo": "string",
    "StrikePrice": "string",
    "CallOrPutFlag": "char",
    "OrderSide1": "char",
    "CombineQty1": "unsigned int",
    "HedgeFlag1": "char",
    "ContractNo2": "string",
    "StrikePrice2": "string",
    "CallOrPutFlag2": "char",
    "OrderSide2": "char",
    "CombineQty2": "unsigned int",
    "HedgeFlag2": "char",
    "LicenseNo": "string",
    "ClientLocalIP": "string",
    "ClientMac": "string",
    "ClientIP": "string",
    "OrderStreamID": "unsigned int",
    "UpperNo": "string",
    "UpperChannelNo": "string",
    "OrderLocalNo": "string",
    "OrderSystemNo": "string",
    "OrderExchangeSystemNo": "string",
    "OrderInsertUserNo": "string",
    "OrderInsertTime": "string",
    "OrderState": "char",
}

TapAPICombinePositionQryReq = {
    "AccountNo": "string",
}

TapAPICombinePositionInfo = {
    "AccountNo": "string",
    "PositionStreamID": "unsigned int",
    "ServerFlag": "char",
    "UpperNo": "string",
    "CombineStrategy": "string",
    "CombineNo": "string",
    "PositionQty": "unsigned int",
    "ExchangeNo": "string",
    "CommodityType": "char",
    "CommodityNo": "string",
    "ContractNo": "string",
    "StrikePrice": "string",
    "CallOrPutFlag": "char",
    "OrderSide1": "char",
    "CombineQty1": "unsigned int",
    "HedgeFlag1": "char",
    "ContractNo2": "string",
    "StrikePrice2": "string",
    "CallOrPutFlag2": "char",
    "OrderSide2": "char",
    "CombineQty2": "unsigned int",
    "HedgeFlag2": "char",
    "CommodityCurrencyGroup": "string",
    "CommodityCurrency": "string",
    "AccountInitialMargin": "double",
    "AccountMaintenanceMargin": "double",
    "UpperInitialMargin": "double",
    "UpperMaintenanceMargin": "double",
}

TapAPIUserTrustDeviceQryReq = {
}

TapAPIUserTrustDeviceQryRsp = {
    "UserNo": "string",
    "LicenseNo": "string",
    "Mac": "string",
    "DeviceName": "string",
    "OperatorNo": "string",
    "OperateTime": "string",
}

TapAPIUserTrustDeviceAddReq = {
}

TapAPIUserTrustDeviceAddRsp = TapAPIUserTrustDeviceQryRsp
TapAPIUserTrustDeviceDelReq = {
    "LicenseNo": "string",
    "Mac": "string",
}

TapAPIUserTrustDeviceDelRsp = TapAPIUserTrustDeviceDelReq
TapAPIIPOInfoQryReq = {
}

TapAPIIPOInfoQryRsp = {
    "ExchangeNo": "string",
    "CommodityType": "char",
    "CommodityNo": "string",
    "CurrencyGroupNo": "string",
    "CurrencyNo": "string",
    "BeginDate": "string",
    "EndDate": "string",
    "IPODate": "string",
    "ResultDate": "string",
    "IPOFee": "double",
    "FinancingFee": "double",
    "LoanRatio": "double",
    "FinancingDays": "unsigned int",
    "MaxLoanRatio": "double",
    "MaxLoanValue": "double",
    "Price": "double",
    "OperatorNo": "string",
    "OperateTime": "string",
}

TapAPIAvailableApplyQryReq = {
    "ExchangeNo": "string",
    "CommodityType": "char",
    "CommodityNo": "string",
}

TapAPIAvailableApplyQryRsp = {
    "ExchangeNo": "string",
    "CommodityType": "char",
    "CommodityNo": "string",
    "StockQty": "unsigned int",
}

TapAPIAccountIPOQryReq = {
    "AccountNo": "string",
}

TapAPIAccountIPOQryRsp = {
    "EndDate": "string",
    "ResultDate": "string",
    "IPODate": "string",
    "AccountNo": "string",
    "ExchangeNo": "string",
    "CommodityType": "char",
    "CommodityNo": "string",
    "ApplyType": "char",
    "ApplyQty": "unsigned int",
    "ApplyCash": "double",
    "LoanRatio": "double",
    "LoanInterest": "double",
    "ApplyFee": "double",
    "ApplyStatus": "char",
    "ResultQty": "unsigned int",
    "OperatorNo": "string",
    "OperateTime": "string",
}

TapAPIAccountIPOAddReq = {
    "AccountNo": "string",
    "ExchangeNo": "string",
    "CommodityType": "char",
    "CommodityNo": "string",
    "ApplyType": "char",
    "ApplyQty": "unsigned int",
    "LoanRatio": "double",
}

TapAPIAccountIPOAddRsp = TapAPIAccountIPOQryRsp
TapAPIAccountIPOCancelReq = {
    "AccountNo": "string",
    "ExchangeNo": "string",
    "CommodityType": "char",
    "CommodityNo": "string",
}

TapAPIAccountIPOCancelRsp = TapAPIAccountIPOQryRsp
TapAPIAccountIPOAddNotice = TapAPIAccountIPOQryRsp
TapAPIAccountIPOCancelNotice = TapAPIAccountIPOQryRsp
TapAPIVerifyIdentityReq = {
    "UserNo": "string",
    "CertificateType": "dict",
    "CertificateNo": "string",
    "EMail": "string",
    "PhoneNo": "string",
}

