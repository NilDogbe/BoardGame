//
// Created by nil on 22/12/2018.
//

#ifndef BOARDGAME_KNIGHT_H
#define BOARDGAME_KNIGHT_H
#include "Piece.h"


class Knight : public Piece {
public:
    Knight(int color);
    Knight(const Piece*);
    Piece* copy();
    void setTravel(int x_dep, int y_dep, int x_arr, int y_arr);
    int canMove(int x_dep, int y_dep, int x_arr, int y_arr);
    std::string toString() override;
    virtual std::vector<int> getPossibleMoves(int current_x, int current_y);
};


#endif //BOARDGAME_KNIGHT_H
