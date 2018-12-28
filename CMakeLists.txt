cmake_minimum_required(VERSION 3.13)
project(BoardGame)

set(CMAKE_CXX_STANDARD 14)

add_executable(BoardGame
        main.cpp
        Piece.cpp Piece.h
        Game.cpp Game.h
        King.cpp King.h
        Knight.cpp Knight.h
        Tower.cpp Tower.h
        Bishop.cpp Bishop.h
        Queen.cpp Queen.h
        PawnForChess.cpp PawnForChess.h
        GameChess.cpp GameChess.h
        GameDame.cpp GameDame.h
        PawnForDame.cpp PawnForDame.h
        Parser.cpp Parser.h
        DameForDame.cpp DameForDame.h
        Move.cpp Move.h)
