# 未发布

1. 升级外盘行情API至TapQuoteAPI V9.3.1.11，支持新版行情全文结构和价格保护带字段
2. 升级北斗星9.0交易API至iTapTradeApi V9.3.9.18。下单和改单的最小变动价位修正、委托量校验由新交易DLL完成，gateway不另做改价
3. Linux运行库改为libesssl.so.1.1和libescrypto.so.1.1，并继续安装libTapDataCollectAPI.so。9.3.9.18 SDK的Win64包里附带的TapDataCollectAPI.dll也是32位，所以不装进x64的Windows包
4. 修复品种、合约、资金查询收到空尾包时读取字段抛出KeyError的问题。空尾包仍继续后续查询；账号空包不发起资金查询

# 9.4.11版本

1. 修复在Linux系统上的编译打包问题

# 9.4.10版本

1. 适配vnpy框架4.0版本

# 9.4.7版本

1. 修复bytes类型委托号替换处理时的bug

# 9.4.6版本

1. 升级pybind11封装工具库的版本，支持Python 3.12编译

# 9.4.5版本

1. 优化对于下单委托号为byte类型的处理

# 9.4.4版本

1. 修复Linux系统上枚举值转换导致的编译失败问题

# 9.4.3版本

1. 增加createITapTradeAPI函数的LogLevel支持
2. 修复setTapQuoteAPILogLevel失效的问题

# 9.4.2版本

1. 解决commit历史冲突问题

# 9.4.1版本

1. 替换正确头文件，重新编译API
2. 修改批量生成脚本
3. 拆分tap_constant
4. 接口连接时增加区域代码参数，修复子账号委托未传区域代码报错的问题
5. 增加交易API的getITapErrorDescribe函数支持

# 9.4.0版本

1. 增加对初始化时是否要查询日内委托成交的控制参数

# 9.3.9版本

1. 修复跨交易所CommodityNo重复导致的问题

# 9.3.8版本
1. 增加Linux系统支持

# 9.0.3版本

1. 使用zoneinfo替换pytz库
2. 调整安装脚本setup.cfg，添加Python版本限制

# 9.0.2版本

1. 修复源码打包中缺少lib文件的问题
2. 添加关闭接口时对于API退出函数的调用

# 9.0.1版本

1. 调整安装脚本setup.py，支持Windows下安装时根据Python版本进行编译
2. 调整接口初始化时，接口名称的赋值方式
