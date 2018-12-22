//
// Created by nil on 21/12/2018.
//

#ifndef BOARDGAME_PIECE_H
#define BOARDGAME_PIECE_H
using namespace std;

#include <string>

class Piece {

protected:
    int m_color;


public:
    Piece(int color);
    virtual int getColor();
    virtual void toString();

    virtual bool canMove(int x_dep, int y_dep, int x_arr, int y_arr);
};


#endif //BOARDGAME_PIECE_H
