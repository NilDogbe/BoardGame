//
// Created by nil on 22/12/2018.
//

#ifndef BOARDGAME_BISHOP_H
#define BOARDGAME_BISHOP_H
#include "Piece.h"

class Bishop : public Piece {
public:
    Bishop(int color);
    virtual std::string toString();
    virtual int canMove(int x_dep, int y_dep, int x_arr, int y_arr);
    virtual std::vector<int> setTravel(int x_dep, int y_dep, int x_arr, int y_arr);
};


#endif //BOARDGAME_BISHOP_H
