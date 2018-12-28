//
// Created by netbook on 25/12/18.
//

#ifndef BOARDGAME_PAWNFORDAME_H
#define BOARDGAME_PAWNFORDAME_H


#include "Piece.h"

class PawnForDame : public Piece {
public:
    PawnForDame(int color);
    PawnForDame(const Piece*);
    Piece* copy();
    virtual std::string toString();
    virtual int canMove(int x_dep, int y_dep, int x_arr, int y_arr);
    virtual void setTravel(int x_dep, int y_dep, int x_arr, int y_arr);
    virtual std::vector<int> getPossibleMoves(int current_x, int current_y);
};


#endif //BOARDGAME_PAWNFORDAME_H
