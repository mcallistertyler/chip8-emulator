cmake_minimum_required(VERSION 3.5)

project(Chip8 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Chip8 main.cpp chip8.cpp)
