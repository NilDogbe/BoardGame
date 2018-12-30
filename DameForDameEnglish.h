//
// Created by netbook on 30/12/18.
//

#ifndef BOARDGAME_DAMEFORDAMEENGLISH_H
#define BOARDGAME_DAMEFORDAMEENGLISH_H


#include "Piece.h"

class DameForDameEnglish : public Piece {
public:
    DameForDameEnglish(int color);
    DameForDameEnglish(const Piece*);
    virtual std::string toString();
    virtual int canMove(int x_dep, int y_dep, int x_arr, int y_arr);
    virtual void setTravel(int x_dep, int y_dep, int x_arr, int y_arr);
    virtual std::vector<int> getPossibleMoves(int current_x, int current_y);
    virtual Piece* copy();
};


#endif //BOARDGAME_DAMEFORDAMEENGLISH_H
