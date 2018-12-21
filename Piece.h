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
    bool canMove();



    public:
    Piece(int color);
    int getColor();



};


#endif //BOARDGAME_PIECE_H
