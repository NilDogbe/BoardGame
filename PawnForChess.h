//
// Created by nil on 23/12/2018.
//

#ifndef BOARDGAME_PAWN_H
#define BOARDGAME_PAWN_H

#include "Piece.h"

class PawnForChess : public Piece{
private:
    bool m_firstMove = true;

public:
    PawnForChess(int color);
    void setTravel(int x_dep, int y_dep, int x_arr, int y_arr);
    int canMove(int x_dep, int y_dep, int x_arr, int y_arr);
    std::string toString() override;

};


#endif //BOARDGAME_PAWN_H
