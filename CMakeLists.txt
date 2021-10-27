cmake_minimum_required(VERSION 3.13)

include(pico-sdk/pico_sdk_init.cmake)
include(toolchains/gcc-arm-none-eabi_toolchain.cmake)

project(project C CXX ASM)
set(CMAKE_C_STANDARD 11)

set(default_build_type "Debug")
set(PICO_NO_UF2 on)

pico_sdk_init()

add_subdirectory(src)