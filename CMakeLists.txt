cmake_minimum_required (VERSION 3.10)
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang)
set(CMAKE_C_FLAGS "-g -fsanitize=fuzzer,address -Wall -Werror")
project (fuzz)

add_library(cjson SHARED cJSON.c)


add_executable(fuzz main.c)


target_link_libraries(fuzz cjson)
