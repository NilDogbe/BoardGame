//
// Created by netbook on 25/12/18.
//

#ifndef BOARDGAME_DAMEFORDAME_H
#define BOARDGAME_DAMEFORDAME_H


#include "Piece.h"

class DameForDame : public Piece {
public:
    DameForDame(int color);
    virtual std::string toString();
    virtual int canMove(int x_dep, int y_dep, int x_arr, int y_arr);
    virtual std::vector<int> getTravel(int x_dep, int y_dep, int x_arr, int y_arr);
};


#endif //BOARDGAME_DAMEFORDAME_H