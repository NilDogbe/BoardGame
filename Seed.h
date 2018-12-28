//
// Created by nil on 28/12/2018.
//

#ifndef BOARDGAME_SEED_H
#define BOARDGAME_SEED_H

#include "Piece.h"


class Seed : public Piece {

    Seed(int color);

    std::string toString();

    int canMove(int x_dep, int y_dep, int x_arr, int y_arr);

    void setTravel(int x_dep, int y_dep, int x_arr, int y_arr);

    virtual std::vector<int> getPossibleMoves(int current_x, int current_y);


};


#endif //BOARDGAME_SEED_H
