//
// Created by nil on 21/12/2018.
//

#ifndef BOARDGAME_KING_H
#define BOARDGAME_KING_H

#include "Piece.h"
#include "Board.h"
class King : public Piece {

public:
    King(int color);
    int sqr(int x);
    bool canMove(int x_dep, int y_dep, int x_arr, int y_arr);
    void toString();

};


#endif //BOARDGAME_KING_H
