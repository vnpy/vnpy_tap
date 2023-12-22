APIYNFLAG_YES = "Y"
APIYNFLAG_NO = "N"
APILOGLEVEL_NONE = "N"
APILOGLEVEL_ERROR = "E"
APILOGLEVEL_WARNING = "W"
APILOGLEVEL_DEBUG = "D"
TAPI_COMMODITY_TYPE_NONE = "N"
TAPI_COMMODITY_TYPE_SPOT = "P"
TAPI_COMMODITY_TYPE_FUTURES = "F"
TAPI_COMMODITY_TYPE_OPTION = "O"
TAPI_COMMODITY_TYPE_SPREAD_MONTH = "S"
TAPI_COMMODITY_TYPE_SPREAD_COMMODITY = "M"
TAPI_COMMODITY_TYPE_BUL = "U"
TAPI_COMMODITY_TYPE_BER = "E"
TAPI_COMMODITY_TYPE_STD = "D"
TAPI_COMMODITY_TYPE_STG = "G"
TAPI_COMMODITY_TYPE_PRT = "R"
TAPI_COMMODITY_TYPE_BLT = "L"
TAPI_COMMODITY_TYPE_BRT = "Q"
TAPI_COMMODITY_TYPE_DIRECTFOREX = "X"
TAPI_COMMODITY_TYPE_INDIRECTFOREX = "I"
TAPI_COMMODITY_TYPE_CROSSFOREX = "C"
TAPI_COMMODITY_TYPE_INDEX = "Z"
TAPI_COMMODITY_TYPE_STOCK = "T"
TAPI_COMMODITY_TYPE_SPOT_TRADINGDEFER = "Y"
TAPI_COMMODITY_TYPE_FUTURE_LOCK = "J"
TAPI_COMMODITY_TYPE_EFP = "A"
TAPI_COMMODITY_TYPE_TAS = "B"
TAPI_CALLPUT_FLAG_CALL = "C"
TAPI_CALLPUT_FLAG_PUT = "P"
TAPI_CALLPUT_FLAG_NONE = "N"
TAPI_AUTHTYPE_DIRECT = "1"
TAPI_AUTHTYPE_RELAY = "2"

TAPIERROR_SUCCEED = 0
TAPIERROR_ConnectFail = -1
TAPIERROR_LinkAuthFail = -2
TAPIERROR_HostUnavailable = -3
TAPIERROR_SendDataError = -4
TAPIERROR_TestIDError = -5
TAPIERROR_NotReadyTestNetwork = -6
TAPIERROR_CurTestNotOver = -7
TAPIERROR_NOFrontAvailable = -8
TAPIERROR_DataPathAvaiable = -9
TAPIERROR_RepeatLogin = -10
TAPIERROR_InnerError = -11
TAPIERROR_LastReqNotFinish = -12
TAPIERROR_InputValueError = -13
TAPIERROR_AuthCode_Invalid = -14
TAPIERROR_AuthCode_Expired = -15
TAPIERROR_AuthCode_TypeNotMatch = -16
TAPIERROR_API_NotReady = -17
TAPIERROR_UDP_LISTEN_FAILED = -18
TAPIERROR_UDP_LISTENING = -19
TAPIERROR_NotImplemented = -20
TAPIERROR_CallOneTimeOnly = -21
TAPIERROR_Frequently = -22
TAPIERROR_DataCollect = -23
TAPIERROR_DataLoad = -24
TAPIERROR_NoRelay = -25
TAPIERROR_INPUTERROR_NULL = -10000
TAPIERROR_INPUTERROR_TAPIYNFLAG = -10001
TAPIERROR_INPUTERROR_TAPILOGLEVEL = -10002
TAPIERROR_INPUTERROR_TAPICommodityType = -10003
TAPIERROR_INPUTERROR_TAPICallOrPutFlagType = -10004
TAPIERROR_INPUTERROR_TAPIAccountType = -12001
TAPIERROR_INPUTERROR_TAPIAccountState = -12003
TAPIERROR_INPUTERROR_TAPIAccountFamilyType = -12004
TAPIERROR_INPUTERROR_TAPIOrderTypeType = -12005
TAPIERROR_INPUTERROR_TAPIOrderSourceType = -12006
TAPIERROR_INPUTERROR_TAPITimeInForceType = -12007
TAPIERROR_INPUTERROR_TAPISideType = -12008
TAPIERROR_INPUTERROR_TAPIPositionEffectType = -12009
TAPIERROR_INPUTERROR_TAPIHedgeFlagType = -12010
TAPIERROR_INPUTERROR_TAPIOrderStateType = -12011
TAPIERROR_INPUTERROR_TAPICalculateModeType = -12012
TAPIERROR_INPUTERROR_TAPIMatchSourceType = -12013
TAPIERROR_INPUTERROR_TAPIOpenCloseModeType = -12014
TAPIERROR_INPUTERROR_TAPIFutureAlgType = -12015
TAPIERROR_INPUTERROR_TAPIOptionAlgType = -12016
TAPIERROR_INPUTERROR_TAPIBankAccountLWFlagType = -12017
TAPIERROR_INPUTERROR_TAPIMarginCalculateModeType = -12021
TAPIERROR_INPUTERROR_TAPIOptionMarginCalculateModeType = -12022
TAPIERROR_INPUTERROR_TAPICmbDirectType = -12023
TAPIERROR_INPUTERROR_TAPIDeliveryModeType = -12024
TAPIERROR_INPUTERROR_TAPIContractTypeType = -12025
TAPIERROR_INPUTERROR_TAPITacticsTypeType = -12035
TAPIERROR_INPUTERROR_TAPIORDERACT = -12036
TAPIERROR_INPUTERROR_TAPITriggerConditionType = -12041
TAPIERROR_INPUTERROR_TAPITriggerPriceTypeType = -12042
TAPIERROR_INPUTERROR_TAPITradingStateType = -12043
TAPIERROR_INPUTERROR_TAPIMarketLevelType = -12044
TAPIERROR_INPUTERROR_TAPIOrderQryTypeType = -12045
TAPIERROR_DISCONNECT_CLOSE_INIT = 1
TAPIERROR_DISCONNECT_CLOSE_PASS = 2
TAPIERROR_DISCONNECT_READ_ERROR = 3
TAPIERROR_DISCONNECT_WRITE_ERROR = 4
TAPIERROR_DISCONNECT_BUF_FULL = 5
TAPIERROR_DISCONNECT_IOCP_ERROR = 6
TAPIERROR_DISCONNECT_PARSE_ERROR = 7
TAPIERROR_DISCONNECT_CONNECT_TIMEOUT = 8
TAPIERROR_DISCONNECT_INIT_ERROR = 9
TAPIERROR_DISCONNECT_HAS_CONNECTED = 10
TAPIERROR_DISCONNECT_HAS_EXIT = 11
TAPIERROR_DISCONNECT_TRY_LATER = 12
TAPIERROR_DISCONNECT_HEARTBEAT_FAILED = 13
TAPIERROR_LOGIN = 10001
TAPIERROR_LOGIN_USER = 10002
TAPIERROR_LOGIN_DDA = 10003
TAPIERROR_LOGIN_LICENSE = 10004
TAPIERROR_LOGIN_MODULE = 10005
TAPIERROR_LOGIN_FORCE = 10006
TAPIERROR_LOGIN_STATE = 10007
TAPIERROR_LOGIN_PASS = 10008
TAPIERROR_LOGIN_RIGHT = 10009
TAPIERROR_LOGIN_COUNT = 10010
TAPIERROR_LOGIN_NOTIN_SERVERFLAGUSRES = 10011
TAPIERROR_LOGIN_USER_EXPIRED = 10012
TAPIERROR_LOGIN_NO_ACCOUNT = 10013
TAPIERROR_LOGIN_NO_JGT = 10014
TAPIERROR_LOGIN_ERROR_TIMES = 10015
TAPIERROR_LOGIN_ERROR_AUTHTYPE = 10016
TAPIERROR_LOGIN_ERROR_AUTHEXPIRED = 10017
TAPIERROR_LOGIN_ERROR_PASSWDEXPIRED = 10018
TAPIERROR_LOGIN_ERROR_USERTRUST = 10019
TAPIERROR_LOGIN_ERROR_CLIENTVERSION = 10020
TAPIERROR_LOGIN_ERROR_AUTHCODEINFO = 10021
TAPIERROR_USERINFO_QRY = 10101
TAPIERROR_USERALLRIGHT_QRY = 11001
TAPIERROR_USERALLACCOUNT_QRY = 11501
TAPIERROR_USERPASSWORD_MOD = 11701
TAPIERROR_USERPASSWORD_MOD_SOURCE = 11702
TAPIERROR_USERPASSWORD_MOD_SAME = 11703
TAPIERROR_USERPASSWORD_MOD_COMPLEXITY = 11704
TAPIERROR_ACCOUNTINFO_QRY = 20201
TAPIERROR_TRADENO_QRY = 20701
TAPIERROR_CONTRACTINFO_QRY = 22801
TAPIERROR_SPECIALOPTIONFUTURE_QRY = 22901
TAPIERROR_COMMODITYORDERTYPE_QRY = 25501
TAPIERROR_ORDERTIMEINFORCE_QRY = 25601
TAPIERROR_USER_ORDER_FREQUENCE_QRY = 28901
TAPIERROR_USERSUBMITAUTHTYPE_ERROR = 29591
TAPIERROR_USERSUBMITINFO_EMPTY = 29592
TAPIERROR_USERAUTHKEYVERSION_ERROR = 29593
TAPIERROR_USERSUBMITINFO_PARTY = 29594
TAPIERROR_USERSUBMITINFO_TESTKEY = 29595
TAPIERROR_USERSUBMITINFO_USERNO = 29596
TAPIERROR_ORDERINSERT_ACCOUNT = 60001
TAPIERROR_ORDERINSERT_ACCOUNT_STATE = 60002
TAPIERROR_ORDERINSERT_SIDE_TRADE = 60003
TAPIERROR_ORDERINSERT_OPTIONS_TRADE = 60004
TAPIERROR_ORDERINSERT_COMMODITY_TRADE = 60005
TAPIERROR_ORDERINSERT_OPEN_RIGHT = 60006
TAPIERROR_ORDERINSERT_RISK_CHECK = 60007
TAPIERROR_ORDERINSERT_CONTRACT = 60011
TAPIERROR_ORDERINSERT_TRADEROUTE = 60021
TAPIERROR_ORDERINSERT_POSITIONMAX = 60022
TAPIERROR_ORDER_NOTRADE = 60023
TAPIERROR_ORDER_CLOSE = 60024
TAPIERROR_ORDERINSERT_NOTENOUGHFUND = 60031
TAPIERROR_ORDERINSERT_ORDERTYPE = 60032
TAPIERROR_ORDERINSERT_TIMEINFORCE = 60033
TAPIERROR_ORDERINSERT_NO_TACTICS = 60034
TAPIERROR_ORDERINSERT_POSITION_CANNOT_CLOSE = 60035
TAPIERROR_ORDERINSERT_AUTOCHECK_FAIL = 60036
TAPIERROR_ORDERINSERT_LME_NOTREADY = 60037
TAPIERROR_ORDERINSERT_CLOSEMODE = 60038
TAPIERROR_ORDERINSERT_PARENTNOTENOUGHFUND = 60039
TAPIERROR_SWAP_CONTRACT = 60040
TAPIERROR_ORDERINSERT_PRICE = 60041
TAPIERROR_ORDERINSERT_EFFECT = 60042
TAPIERROR_ORDERINSERT_TARGETCONTRACT = 60043
TAPIERROR_USERNO_NOTHAS_ACCOUNT = 60051
TAPIERROR_UPPERCHANNEL_BROKEN = 60052
TAPIERROR_UPPERCHANNEL_NOT_EXIST = 60053
TAPIERROR_ORDERDELETE_NOT_SYSNO = 60061
TAPIERROR_ORDERDELETE_NOT_STATE = 60062
TAPIERROR_ORDERACTIVE_NOT_STATE = 60063
TAPIERROR_ORDERDELETE_NOT_LAST = 60064
TAPIERROR_ORDERCHECK_NOT_STATE = 60071
TAPIERROR_ORDERCHECK_FAIL = 60072
TAPIERROR_ORDERMODIFY_NOT_STATE = 60081
TAPIERROR_ORDERMODIFY_BACK_INPUT = 60082
TAPIERROR_ORDERINSERT_FEE = 60091
TAPIERROR_ORDERINSERT_MARGIN = 60092
TAPIERROR_ORDER_NO_PERMIT = 60100
TAPIERROR_RSPQUOTE_NO_PERMIT = 60101
TAPIERROR_RSPQUOTE_CHILD_NO_PERMIT = 60102
TAPIERROR_TRADENO_NOT_FIND = 60103
TAPIERROR_ORDER_NO_CLOSE = 60104
TAPIERROR_QRY_QUOTE_NO_PERMIT = 60105
TAPIERROR_EXPIREDATE_NO_PERMIT = 60106
TAPIERROR_CMB_NO_PERMIT = 60107
TAPIERROR_ORDERSERVER_NO_PERMIT = 60108
TAPIERROR_POSITION_CANNOT_EXEC_OR_ABANDON = 60109
TAPIERROR_ORDERCHECK_NO_PERMIT = 60110
TAPIERROR_ORDERMAXOPENVOL_NO_PERMIT = 60111
TAPIERROR_ORDERLIMIT_OPEN_NO_PERMIT = 60112
TAPIERROR_ORDER_SINGLEVOL_NO_PERMIT = 60113
TAPIERROR_ORDER_POSITIONVOL_NO_PERMIT = 60114
TAPIERROR_ORDER_QTY_NO_PERMIT = 60115
TAPIERROR_ORDER_APPLY_NO_PERMIT = 60117
TAPIERROR_ORDER_FREQ_OVERRUN = 60118
TAPIERROR_COMB_NO_SIDEORHEDGE = 60119
TAPIERROR_REQQUOTE_EXITREASONABLPRICE = 60120
TAPIERROR_RSPQUOTE_PRICE = 60121
TAPIERROR_RISKORDER_CANCEL = 60122
TAPIERROR_RSPQUOTE_EFFECT = 60123
TAPIERROR_ORDERINSERT_SIDEMODE = 60124
TAPIERROR_AUTOORDER_MAXCOUNT = 60125
TAPIERROR_SHFEDEEPQUOTE_LIMIT = 60126
TAPIERROR_SHFEDEEPQUOTE_NODATA = 60127
TAPIERROR_SELFMATCH = 60128
TAPIERROR_ERRORORDER_MAXCOUNT = 60129
TAPIERROR_ORDER_UPPERFREQ_OVERRUN = 60130
TAPIERROR_ORDER_FREQUENCY = 61001
TAPIERROR_ORDER_QUERYING = 61002
TAPIERROR_SUBSCRIBEQUOTE_MAX = 72001
TAPIERROR_SUBSCRIBEQUOTE_EXCHANGE_MAX = 72002
TAPIERROR_SUBSCRIBEQUOTE_NO_RIGHT = 72101
TAPIERROR_SUBSCRIBEQUOTE_NO_EXCHANGE_RIGHT = 72102
TAPIERROR_SUBSCRIBEQUOTE_COMMODITY_NOT_EXIST = 72103
TAPIERROR_SUBSCRIBEQUOTE_CONTRACT_MAY_NOT_EXIST = 72104
TAPIERROR_QUOTEFRONT_UNKNOWN_PROTOCOL = 83001
TAPIERROR_QUOTEFRONT_LOGIN_TOTALCOUNT = 83002
TAPIERROR_QUOTEFRONT_SUB_COUNT = 83003
TAPIERROR_ORDER_SEND = 80001
TAPIERROR_DLG_NULL = 80002
TAPIERROR_ORDER_FIELD = 80003
TAPIERROR_TRADE_REJ_BYUPPER = 80004
TAPIERROR_ORDER_FORBIDEXEC = 80005
