cmake_minimum_required(VERSION 3.5)
project(TestC)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

set(SOURCE_FILES main.c)
add_executable(TestC ${SOURCE_FILES})