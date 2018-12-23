//
// Created by nil on 22/12/2018.
//

#ifndef BOARDGAME_CAVALIER_H
#define BOARDGAME_CAVALIER_H
#include "Piece.h"


class Cavalier : public Piece {
public:
    Cavalier(int color);
    void setTravel(int x_dep, int y_dep, int x_arr, int y_arr);
    bool canMove(int x_dep, int y_dep, int x_arr, int y_arr);
    void toString() override;

};


#endif //BOARDGAME_CAVALIER_H
