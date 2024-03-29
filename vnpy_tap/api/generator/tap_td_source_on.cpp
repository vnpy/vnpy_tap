void onConnect(string HostAddress) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onConnect, HostAddress);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspLogin(int error, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspLogin, error, data);
	}
	catch (const error_already_set &e)
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
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspRequestVertificateCode(unsigned int session, int error, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspRequestVertificateCode, session, error, data);
	}
	catch (const error_already_set &e)
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
	catch (const error_already_set &e)
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
	catch (const error_already_set &e)
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
	catch (const error_already_set &e)
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
	catch (const error_already_set &e)
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
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryTradingDate(unsigned int session, int error, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryTradingDate, session, error, data);
	}
	catch (const error_already_set &e)
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
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryAccount(unsigned int session, unsigned int error, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryAccount, session, error, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryFund(unsigned int session, int error, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryFund, session, error, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnFund(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRtnFund, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryExchange(unsigned int session, int error, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryExchange, session, error, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryCommodity(unsigned int session, int error, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryCommodity, session, error, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryContract(unsigned int session, int error, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryContract, session, error, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnContract(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRtnContract, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspOrderAction(unsigned int session, int error, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspOrderAction, session, error, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnOrder(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRtnOrder, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryOrder(unsigned int session, int error, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryOrder, session, error, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryOrderProcess(unsigned int session, int error, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryOrderProcess, session, error, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryFill(unsigned int session, int error, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryFill, session, error, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnFill(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRtnFill, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryPosition(unsigned int session, int error, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryPosition, session, error, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnPosition(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRtnPosition, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryPositionSummary(unsigned int session, int error, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryPositionSummary, session, error, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnPositionSummary(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRtnPositionSummary, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnPositionProfit(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRtnPositionProfit, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryCurrency(unsigned int session, int error, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryCurrency, session, error, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryTradeMessage(unsigned int session, int error, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryTradeMessage, session, error, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnTradeMessage(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRtnTradeMessage, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryHisOrder(unsigned int session, int error, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryHisOrder, session, error, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryHisOrderProcess(unsigned int session, int error, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryHisOrderProcess, session, error, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryHisMatch(unsigned int session, int error, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryHisMatch, session, error, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryHisPosition(unsigned int session, int error, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryHisPosition, session, error, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryHisDelivery(unsigned int session, int error, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryHisDelivery, session, error, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryAccountCashAdjust(unsigned int session, int error, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryAccountCashAdjust, session, error, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryBill(unsigned int session, int error, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryBill, session, error, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryAccountFeeRent(unsigned int session, int error, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryAccountFeeRent, session, error, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryAccountMarginRent(unsigned int session, int error, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryAccountMarginRent, session, error, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspHKMarketOrderInsert(unsigned int session, int error, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspHKMarketOrderInsert, session, error, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspHKMarketOrderDelete(unsigned int session, int error, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspHKMarketOrderDelete, session, error, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onHKMarketQuoteNotice(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onHKMarketQuoteNotice, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspOrderLocalRemove(unsigned int session, int error, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspOrderLocalRemove, session, error, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspOrderLocalInput(unsigned int session, int error, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspOrderLocalInput, session, error, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspOrderLocalModify(unsigned int session, int error, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspOrderLocalModify, session, error, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspOrderLocalTransfer(unsigned int session, int error, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspOrderLocalTransfer, session, error, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspFillLocalInput(unsigned int session, int error, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspFillLocalInput, session, error, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspFillLocalRemove(unsigned int session, int error, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspFillLocalRemove, session, error, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQrySpotLock(unsigned int session, int error, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQrySpotLock, session, error, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnSpotLock(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRtnSpotLock, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspSubmitUserLoginInfo(unsigned int session, int error, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspSubmitUserLoginInfo, session, error, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspSpecialOrderAction(unsigned int session, int error, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspSpecialOrderAction, session, error, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnSpecialOrder(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRtnSpecialOrder, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQrySpecialOrder(unsigned int session, int error, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQrySpecialOrder, session, error, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryCombinePosition(unsigned int session, int error, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryCombinePosition, session, error, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnCombinePosition(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRtnCombinePosition, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryUserTrustDevice(unsigned int session, int error, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryUserTrustDevice, session, error, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspAddUserTrustDevice(unsigned int session, int error, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspAddUserTrustDevice, session, error, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspDelUserTrustDevice(unsigned int session, int error, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspDelUserTrustDevice, session, error, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnAddUserTrustDevice(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRtnAddUserTrustDevice, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnDelUserTrustDevice(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRtnDelUserTrustDevice, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryIPOInfo(unsigned int session, int error, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryIPOInfo, session, error, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryIPOStockQty(unsigned int session, int error, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryIPOStockQty, session, error, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspQryAccountIPO(unsigned int session, int error, char last, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspQryAccountIPO, session, error, last, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspAddAccountIPO(unsigned int session, int error, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspAddAccountIPO, session, error, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspCancelAccountIPO(unsigned int session, int error, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspCancelAccountIPO, session, error, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnAddAccountIPO(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRtnAddAccountIPO, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnCancelAccountIPO(const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRtnCancelAccountIPO, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRspUnFreezeVerificate(unsigned int session, int error) override
{
	try
	{
		PYBIND11_OVERLOAD(void, TdApi, onRspUnFreezeVerificate, session, error);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

