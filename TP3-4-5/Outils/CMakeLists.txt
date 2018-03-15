cmake_minimum_required(VERSION 3.8)
project(TP-C++)

set(CMAKE_CXX_STANDARD 11)

file(GLOB base_H "*.h")
file(GLOB base_SRC "*.cpp")

add_executable(main ${base_H} ${base_SRC})