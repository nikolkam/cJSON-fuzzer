cmake_minimum_required (VERSION 3.10)
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang)
project (fuzz)

############################################################
# Create a library
############################################################
add_library(cjson STATIC cJSON.c)

############################################################
# Create an executable
############################################################
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -fsanitize=fuzzer,address -Wall -Werror")
add_executable(fuzzing main.c)
target_link_libraries(fuzzing PRIVATE cjson)
