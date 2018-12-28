//
// Created by nil on 23/12/2018.
//

#ifndef BOARDGAME_CHESS_H
#define BOARDGAME_CHESS_H

//#include "Game.h"
#include "Piece.h"
#include "King.h"
#include "Knight.h"
#include "Tower.h"
#include "Bishop.h"
#include "Queen.h"
#include "PawnForChess.h"
#include "Parser.h"

class GameChess : public Game {

protected:
    virtual void init();

public:
    const static int SIZE = 8;

    GameChess(); // new partie
    bool movePiece(int x_dep, int y_dep, int x_arr, int y_arr);
};


#endif //BOARDGAME_CHESS_H
