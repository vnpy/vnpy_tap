import platform


from setuptools import Extension, setup


def get_ext_modules() -> list:
    """
    获取三方模块
    Windows需要编译封装接口
    Linux和Mac由于缺乏二进制库支持无法使用
    """
    # Linux
    if platform.system() == "Linux":
        include_dirs = ["vnpy_tap/api/include", "vnpy_tap/api/vntap"]
        library_dirs = ["vnpy_tap/api"]
        extra_compile_flags = [
            "-std=c++17",
            "-O3",
            "-Wno-delete-incomplete",
            "-Wno-sign-compare",
        ]
        extra_link_args = ["-lstdc++"]
        runtime_library_dirs = ["$ORIGIN"]
        libraries = ["iTapTradeAPI", "TapQuoteAPI"]
    # Windows
    elif platform.system() == "Windows":
        include_dirs = ["vnpy_tap/api/include", "vnpy_tap/api/vntap"]
        library_dirs = ["vnpy_tap/api/libs", "vnpy_tap/api"]
        extra_compile_flags = ["-O2", "-MT"]
        extra_link_args = []
        runtime_library_dirs = []
        libraries = ["iTapTradeAPI_64", "TapQuoteAPI"]

    vntapmd = Extension(
        "vnpy_tap.api.vntapmd",
        [
            "vnpy_tap/api/vntap/vntapmd/vntapmd.cpp",
        ],
        include_dirs=include_dirs,
        define_macros=[],
        undef_macros=[],
        library_dirs=library_dirs,
        libraries=libraries,
        extra_compile_args=extra_compile_flags,
        extra_link_args=extra_link_args,
        runtime_library_dirs=runtime_library_dirs,
        depends=[],
        language="cpp",
    )

    vntaptd = Extension(
        "vnpy_tap.api.vntaptd",
        [
            "vnpy_tap/api/vntap/vntaptd/vntaptd.cpp",
        ],
        include_dirs=include_dirs,
        define_macros=[],
        undef_macros=[],
        library_dirs=library_dirs,
        libraries=libraries,
        extra_compile_args=extra_compile_flags,
        extra_link_args=extra_link_args,
        runtime_library_dirs=runtime_library_dirs,
        depends=[],
        language="cpp",
    )

    return [vntaptd, vntapmd]


setup(
    ext_modules=get_ext_modules(),
)
