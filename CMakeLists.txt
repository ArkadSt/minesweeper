cmake_minimum_required(VERSION 3.25)
project(minesweeper)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(minesweeper
        game.cpp
        game.h
        minesweeper.cpp)
