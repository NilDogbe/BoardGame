//
// Created by netbook on 23/12/18.
//

#ifndef BOARDGAME_PIONTFORDAME_H
#define BOARDGAME_PIONTFORDAME_H

#include "Piece.h"

class PiontForDame : public Piece {
public:
    PiontForDame(int color);
protected:
public:
    virtual std::string toString();
    virtual int canMove(int x_dep, int y_dep, int x_arr, int y_arr);
    std::vector<int> getTravel(int x_dep, int y_dep, int x_arr, int y_arr);
};

#endif //BOARDGAME_PIONTFORDAME_H
