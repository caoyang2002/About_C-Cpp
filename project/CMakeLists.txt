cmake_minimum_required(VERSION 3.25)
project(project C)

set(CMAKE_C_STANDARD 11)

add_executable(project
        base/add.c base/test.c base/test.c)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fexec-charset=GBK")
