//
// Created by nil on 22/12/2018.
//

#ifndef BOARDGAME_BISHOP_H
#define BOARDGAME_BISHOP_H
#include "Piece.h"

class Bishop : public Piece {
public:
    Bishop(int color);
    void setTravel(int x_dep, int y_dep, int x_arr, int y_arr);
    int canMove(int x_dep, int y_dep, int x_arr, int y_arr);
    void toString() override;

};


#endif //BOARDGAME_BISHOP_H
