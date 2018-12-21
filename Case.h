//
// Created by nil on 21/12/2018.
//

#ifndef BOARDGAME_CASE_H
#define BOARDGAME_CASE_H

#include "Piece.h"

class Case {

private:
    int m_color;
    Piece m_piece;
    int m_x, m_y;

public:
    Case(int x, int y, int color);

    int getX();
    int getY();
    int getColor();
    Piece getPiece();
    void setX(int x);
    void setY(int y);
    bool isEmpty();


};


#endif //BOARDGAME_CASE_H
