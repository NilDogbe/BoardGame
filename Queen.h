//
// Created by nil on 23/12/2018.
//

#ifndef BOARDGAME_QUEEN_H
#define BOARDGAME_QUEEN_H
#include "Piece.h"


class Queen : public Piece {
public:
    Queen(int color);
    void setTravel(int x_dep, int y_dep, int x_arr, int y_arr);
    bool canMove(int x_dep, int y_dep, int x_arr, int y_arr);
    void toString() override;


};


#endif //BOARDGAME_QUEEN_H
