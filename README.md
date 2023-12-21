# VeighNa框架的易盛外盘交易接口

<p align="center">
  <img src ="https://vnpy.oss-cn-shanghai.aliyuncs.com/vnpy-logo.png"/>
</p>

<p align="center">
    <img src ="https://img.shields.io/badge/version-9.4.0-blueviolet.svg"/>
    <img src ="https://img.shields.io/badge/platform-windows-yellow.svg"/>
    <img src ="https://img.shields.io/badge/python-3.8|3.9|3.10|3.11|3.12-blue.svg" />
    <img src ="https://img.shields.io/github/license/vnpy/vnpy.svg?color=orange"/>
</p>

## 说明

基于易盛的北斗星交易API的9.0接口（iTapTradeApi9.3.8.7）封装开发的接口，适用于香港、新加坡以及其他境外交易所行情/交易。

## 安装

安装需要基于3.9.0版本以上的[VeighNa Studio](https://www.vnpy.com)。

直接使用pip命令：

```
pip install vnpy_tap
```


或者下载源代码后，解压后在cmd中运行：

```
pip install .
```

使用源代码安装时需要进行C++编译，因此在执行上述命令之前请确保已经安装了【Visual Studio（Windows）】或者【GCC（Linux）】编译器。


## 使用

以脚本方式启动（script/run.py）：

```
from vnpy.event import EventEngine
from vnpy.trader.engine import MainEngine
from vnpy.trader.ui import MainWindow, create_qapp

from vnpy_tap import TapGateway


def main():
    """主入口函数"""
    qapp = create_qapp()

    event_engine = EventEngine()
    main_engine = MainEngine(event_engine)
    main_engine.add_gateway(TapGateway)
    
    main_window = MainWindow(main_engine, event_engine)
    main_window.showMaximized()

    qapp.exec()


if __name__ == "__main__":
    main()
```


## 连接

**请注意，若需通过子账号下单，请在连接登录时对【子账号】与【区域代码】进行配置**。

如果下单人位于美国或加拿大，地址信息需填写到省份，共5个字节，省份信息如下：ftp://ftp.cmegroup.com/fix/coo/country_state.rtf

如果下单人位于其他地区，地址信息需填写到国家，共2个字节，国家信息如下：ftp://ftp.cmegroup.com/fix/coo/country_codes.rtf
