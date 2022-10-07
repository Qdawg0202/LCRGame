cmake_minimum_required(VERSION 3.20)
project(lcr)

set(CMAKE_CXX_STANDARD 14)

add_executable(lcr dice.cpp dice.h player.cpp player.h game.cpp)
