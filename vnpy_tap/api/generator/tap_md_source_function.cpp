int MdApi::qryCommodity()
{
	TAPIUINT32 session;
	int i = this->api->QryCommodity(&session);
	return i;
};

int MdApi::qryContract(const dict &req)
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

