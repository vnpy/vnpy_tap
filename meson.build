project(
  'vnpy_tap',
  'cpp',
  version: '9.4.11',
  license: 'MIT',
  meson_version: '>=1.7.0',
  default_options: [
    'buildtype=release',
    'cpp_std=c++17',
    'warning_level=2',
  ],
)

# 导入文件系统和Python模块
fs = import('fs')
py = import('python').find_installation(pure: false)
py_dep = py.dependency()

# 获取pybind11路径
python_cmd = host_machine.system() == 'windows' ? 'python' : 'python3'
pybind11_include_dir = run_command(python_cmd, '-c', 'import pybind11; print(pybind11.get_include())', check: true).stdout().strip()
message('使用pybind11路径: ' + pybind11_include_dir)

# 获取编译器信息
cpp = meson.get_compiler('cpp')
compiler_id = cpp.get_id()

# 输出构建目标系统信息
message('构建目标系统: ' + host_machine.system())

# 初始化变量
tapthostmduserapi_lib = []
tapthosttraderapi_lib = []
extra_cpp_args = []
extra_link_args = []

# 初始化库变量
tapthostmduserapi_lib = []
tapthosttraderapi_lib = []

# 初始化其他编译选项
install_rpath_value = ''

# 设置Windows特定编译选项
if host_machine.system() == 'windows'
  # Windows编译器设置
  add_project_arguments('/MT', language : 'cpp')
  
  # 设置库目录
  lib_dir = meson.current_source_dir() / 'vnpy_tap/api/libs'
  api_dir = meson.current_source_dir() / 'vnpy_tap/api'
  
  # 设置include目录
  include_dirs = include_directories(
    'vnpy_tap/api/include',
    'vnpy_tap/api/vntap',
    pybind11_include_dir,
  )
  
  # 定义CTP库
  TapQuoteAPI_lib = cpp.find_library('TapQuoteAPI', 
                                       dirs: [lib_dir, api_dir],
                                       required: true)
  iTapTradeAPI_lib = cpp.find_library('iTapTradeAPI_64', 
                                       dirs: [lib_dir, api_dir],
                                       required: true)

# 设置Linux特定编译选项
else  # Linux
  # Linux编译器设置
  extra_cpp_args = [
    '-std=c++17',
    '-O3',
    '-Wno-delete-incomplete',
    '-Wno-sign-compare',
  ]
  
  extra_link_args = [
    '-lstdc++',
  ]
  
  # 设置库目录
  lib_dir = meson.current_source_dir() / 'vnpy_tap/api'
  
  # 设置include目录
  include_dirs = include_directories(
    'vnpy_tap/api/include',
    'vnpy_tap/api/vntap',
    pybind11_include_dir,
  )
  
  # 定义CTP库
  TapQuoteAPI_lib = cpp.find_library('TapQuoteAPI', 
                                       dirs: [lib_dir],
                                       required: true)
  iTapTradeAPI_lib = cpp.find_library('iTapTradeAPI', 
                                       dirs: [lib_dir],
                                       required: true)
endif

# 创建MD模块扩展
md_module = py.extension_module(
  'vntapmd',
  sources: ['vnpy_tap/api/vntap/vntapmd/vntapmd.cpp'],
  include_directories: include_dirs,
  dependencies: [py_dep],
  cpp_args: extra_cpp_args,
  link_args: extra_link_args + [
    '-L' + lib_dir,
    '-lTapQuoteAPI',
    '-Wl,-rpath,$ORIGIN'
  ],
  install: true,
  install_rpath: '$ORIGIN',
  subdir: 'vnpy_tap/api'
)

# 创建TD模块扩展
td_module = py.extension_module(
  'vntaptd',
  sources: ['vnpy_tap/api/vntap/vntaptd/vntaptd.cpp'],
  include_directories: include_dirs,
  dependencies: [py_dep],
  cpp_args: extra_cpp_args,
  link_args: extra_link_args + [
    '-L' + lib_dir,
    '-l' + (host_machine.system() == 'windows' ? 'iTapTradeAPI_64' : 'iTapTradeAPI'),
    '-Wl,-rpath,$ORIGIN'
  ],
  install: true,
  install_rpath: '$ORIGIN',
  subdir: 'vnpy_tap/api'
)

# 安装Python源代码
python_files = [
  ['vnpy_tap/__init__.py', 'vnpy_tap'],
  ['vnpy_tap/api/__init__.py', 'vnpy_tap/api'],
  ['vnpy_tap/api/tap_md_constant.py', 'vnpy_tap/api'],
  ['vnpy_tap/api/tap_td_constant.py', 'vnpy_tap/api'],
  ['vnpy_tap/gateway/__init__.py', 'vnpy_tap/gateway'],
  ['vnpy_tap/gateway/tap_gateway.py', 'vnpy_tap/gateway'],
]

foreach file : python_files
  py.install_sources(
    [file[0]],
    pure: false,
    subdir: file[1]
  )
endforeach

# 安装API动态库文件
if host_machine.system() == 'windows'
  api_libs = [
    'vnpy_tap/api/TapQuoteAPI.dll',
    'vnpy_tap/api/iTapTradeAPI_64.dll',
  ]
  
  install_data(
    api_libs,
    install_dir: py.get_install_dir() / 'vnpy_tap/api'
  )
else  # Linux
  api_libs = [
    'vnpy_tap/api/libTapQuoteAPI.so',
    'vnpy_tap/api/libiTapTradeAPI.so',
    'vnpy_tap/api/libTapDataCollectAPI.so',
    'vnpy_tap/api/libcrypto.so.1.1',
    'vnpy_tap/api/libssl.so.1.1'
  ]
  
  install_data(
    api_libs,
    install_dir: py.get_install_dir() / 'vnpy_tap/api'
  )
endif
