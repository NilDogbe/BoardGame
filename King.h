//
// Created by nil on 21/12/2018.
//

#ifndef BOARDGAME_KING_H
#define BOARDGAME_KING_H

#include "Piece.h"
#include "Game.h"
class King : public Piece {

public:
    King(int color);
    void setTravel(int x_dep, int y_dep, int x_arr, int y_arr);
    int canMove(int x_dep, int y_dep, int x_arr, int y_arr);
    std::string toString();
    int sqr(int x);

};


#endif //BOARDGAME_KING_H
