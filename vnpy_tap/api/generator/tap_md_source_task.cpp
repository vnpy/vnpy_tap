void MdApi::OnRspLogin(TAPIINT32 errorCode, const TapAPIQuotLoginRspInfo *info)
{
	Task task = Task();
	task.task_name = ONRSPLOGIN;
	task.task_int = errorCode;
	if (info)
	{
		TapAPIQuotLoginRspInfo *task_data = new TapAPIQuotLoginRspInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void MdApi::OnAPIReady()
{
	Task task = Task();
	task.task_name = ONAPIREADY;
	this->task_queue.push(task);
};

void MdApi::OnDisconnect(TAPIINT32 reasonCode)
{
	Task task = Task();
	task.task_name = ONDISCONNECT;
	task.task_int = reasonCode;
	this->task_queue.push(task);
};

void MdApi::OnRspQryCommodity(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPIQuoteCommodityInfo *info)
{
	Task task = Task();
	task.task_name = ONRSPQRYCOMMODITY;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIQuoteCommodityInfo *task_data = new TapAPIQuoteCommodityInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void MdApi::OnRspQryContract(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPIQuoteContractInfo *info)
{
	Task task = Task();
	task.task_name = ONRSPQRYCONTRACT;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIQuoteContractInfo *task_data = new TapAPIQuoteContractInfo();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void MdApi::OnRspSubscribeQuote(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPIQuoteWhole *info)
{
	Task task = Task();
	task.task_name = ONRSPSUBSCRIBEQUOTE;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIQuoteWhole *task_data = new TapAPIQuoteWhole();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void MdApi::OnRspUnSubscribeQuote(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPIContract *info)
{
	Task task = Task();
	task.task_name = ONRSPUNSUBSCRIBEQUOTE;
	task.task_id = sessionID;
	task.task_int = errorCode;
	task.task_last = isLast;
	if (info)
	{
		TapAPIContract *task_data = new TapAPIContract();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void MdApi::OnRtnQuote(const TapAPIQuoteWhole *info)
{
	Task task = Task();
	task.task_name = ONRTNQUOTE;
	if (info)
	{
		TapAPIQuoteWhole *task_data = new TapAPIQuoteWhole();
		*task_data = *info;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

