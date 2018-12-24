//
// Created by nil on 23/12/2018.
//

#ifndef BOARDGAME_PIONT_H
#define BOARDGAME_PIONT_H

#include "Piece.h"

class PiontForChess : public Piece{
private:
    bool m_firstMove = true;

public:
    PiontForChess(int color);
    void setTravel(int x_dep, int y_dep, int x_arr, int y_arr);
    int canMove(int x_dep, int y_dep, int x_arr, int y_arr);
    void toString() override;

};


#endif //BOARDGAME_PIONT_H
