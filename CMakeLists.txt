cmake_minimum_required(VERSION 3.23)
project(dungeoncpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(dungeoncpp main.cpp Floor.cpp Floor.h RandomFloor.cpp RandomFloor.h DrunkardsWalk.cpp DrunkardsWalk.h)
