cmake_minimum_required(VERSION 3.13)
project(BoardGame)

set(CMAKE_CXX_STANDARD 14)

add_executable(BoardGame main.cpp Piece.cpp Piece.h Game.cpp Game.h King.cpp King.h Cavalier.cpp Cavalier.h Tower.cpp Tower.h Bishop.cpp Bishop.h Queen.cpp Queen.h PiontForChess.cpp PiontForChess.h GameChess.cpp GameChess.h Parser.cpp Parser.h)
