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
    PawnForChess(int color, bool m_firstMove);
    PawnForChess(int color);
    PawnForChess(const Piece*);
    Piece* copy();
    void setTravel(int x_dep, int y_dep, int x_arr, int y_arr);
    int canMove(int x_dep, int y_dep, int x_arr, int y_arr);
    std::string toString() override;
    std::vector<int> getPossibleMoves(int current_x, int current_y);
    void setFirstMove();
    bool getFirstMove();
};


#endif //BOARDGAME_PAWN_H
