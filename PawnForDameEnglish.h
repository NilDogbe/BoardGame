//
// Created by netbook on 30/12/18.
//

#ifndef BOARDGAME_PAWNFORDAMEENGLISH_H
#define BOARDGAME_PAWNFORDAMEENGLISH_H


#include "Piece.h"

class PawnForDameEnglish : public Piece {
public:
    PawnForDameEnglish(int color);
    PawnForDameEnglish(const Piece*);
    Piece* copy();
    virtual std::string toString();
    virtual int canMove(int x_dep, int y_dep, int x_arr, int y_arr);
    virtual void setTravel(int x_dep, int y_dep, int x_arr, int y_arr);
    virtual std::vector<int> getPossibleMoves(int current_x, int current_y);
};


#endif //BOARDGAME_PAWNFORDAMEENGLISH_H
