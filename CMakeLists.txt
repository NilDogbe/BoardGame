cmake_minimum_required(VERSION 3.13)
project(BoardGame)

set(CMAKE_CXX_STANDARD 14)

add_executable(BoardGame main.cpp Menu.cpp Menu.h Piece.cpp Piece.h Board.cpp Board.h Case.cpp Case.h)
