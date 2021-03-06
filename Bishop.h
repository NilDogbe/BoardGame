//
// Created by nil on 22/12/2018.
//

#ifndef BOARDGAME_BISHOP_H
#define BOARDGAME_BISHOP_H
#include "Piece.h"

class Bishop : public Piece {
public:
    Bishop(int color);
    Bishop(const Piece*);
    Piece* copy();
    virtual std::string toString();
    virtual int canMove(int x_dep, int y_dep, int x_arr, int y_arr);
    virtual void setTravel(int x_dep, int y_dep, int x_arr, int y_arr);
    virtual std::vector<int> getPossibleMoves(int current_x, int current_y);
};


#endif //BOARDGAME_BISHOP_H
