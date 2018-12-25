//
// Created by netbook on 25/12/18.
//

#ifndef BOARDGAME_PAWNFORDAME_H
#define BOARDGAME_PAWNFORDAME_H


#include "Piece.h"

class PawnForDame : public Piece {
public:
    PawnForDame(int color);
    virtual std::string toString();
    virtual int canMove(int x_dep, int y_dep, int x_arr, int y_arr);
    virtual std::vector<int> getTravel(int x_dep, int y_dep, int x_arr, int y_arr);
};


#endif //BOARDGAME_PAWNFORDAME_H
