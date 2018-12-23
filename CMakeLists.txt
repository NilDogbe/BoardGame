cmake_minimum_required(VERSION 3.13)
project(BoardGame)

set(CMAKE_CXX_STANDARD 14)

add_executable(BoardGame main.cpp Piece.cpp Piece.h Board.cpp Board.h King.cpp King.h Game.cpp Game.h Cavalier.cpp Cavalier.h Tower.cpp Tower.h Bishop.cpp Bishop.h Queen.cpp Queen.h)
