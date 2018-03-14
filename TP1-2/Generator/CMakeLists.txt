cmake_minimum_required(VERSION 3.9)
project(Generator)

set(CMAKE_CXX_STANDARD 11)

add_executable(Generator
        main.cpp
        Machine.cpp Machine.h
        Commutator.cpp Commutator.h
        Node.cpp Node.h
        )