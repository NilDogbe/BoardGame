//
// Created by nil on 23/12/2018.
//

#ifndef BOARDGAME_QUEEN_H
#define BOARDGAME_QUEEN_H

#include "Piece.h"

class Queen : public Piece {
public:
    Queen(int color);
    Queen(const Piece*);
    Piece* copy();
    void setTravel(int x_dep, int y_dep, int x_arr, int y_arr);
    int canMove(int x_dep, int y_dep, int x_arr, int y_arr);
    std::string toString() override;
    virtual std::vector<int> getPossibleMoves(int current_x, int current_y);
};


#endif //BOARDGAME_QUEEN_H
