//
// Created by nil on 28/12/2018.
//

#ifndef BOARDGAME_KHON_H
#define BOARDGAME_KHON_H


#include "Piece.h"
#include "Game.h"

class Khon : public Piece {

public:
    Khon(int color);

    void setTravel(int x_dep, int y_dep, int x_arr, int y_arr);

    int canMove(int x_dep, int y_dep, int x_arr, int y_arr);

    std::string toString();

    virtual std::vector<int> getPossibleMoves(int current_x, int current_y);

};


#endif //BOARDGAME_KHON_H
