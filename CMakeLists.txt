cmake_minimum_required(VERSION 3.13)
project(BoardGame)

set(CMAKE_CXX_STANDARD 14)

add_executable(BoardGame
        main.cpp
        Piece.cpp Piece.h
        Game.cpp Game.h
        GameDame.cpp GameDame.h
        PawnForDame.cpp PawnForDame.h
        DameForDame.cpp DameForDame.h
        Parser.cpp Parser.h PawnForDame.cpp PawnForDame.h Definitions.cpp Definitions.h)
