cmake_minimum_required(VERSION 3.29)
project(Memory_Management)

set(CMAKE_CXX_STANDARD 23)

add_executable(Memory_Management main.cpp
        main.cpp
        GameObject.h
        GameObject.cpp
        MemoryPool.h
        MemoryPool.cpp
        ResourceManager.h
        ResourceManager.cpp)
