//
// Created by nil on 22/12/2018.
//

#ifndef BOARDGAME_TOWER_H
#define BOARDGAME_TOWER_H
#include "Piece.h"


class Tower : public Piece{
public:
    Tower(int color);

    bool canMove(int x_dep, int y_dep, int x_arr, int y_arr);
    void toString() override;

};



#endif //BOARDGAME_TOWER_H
