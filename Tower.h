//
// Created by nil on 22/12/2018.
//

#ifndef BOARDGAME_TOWER_H
#define BOARDGAME_TOWER_H
#include "Piece.h"


class Tower : public Piece{
public:
    Tower(int color);
    Tower(const Piece*);
    Piece* copy();
    int canMove(int x_dep, int y_dep, int x_arr, int y_arr);
    std::string toString() override;
    void setTravel(int x_dep, int y_dep, int x_arr, int y_arr);
    virtual std::vector<int> getPossibleMoves(int current_x, int current_y);
};



#endif //BOARDGAME_TOWER_H
