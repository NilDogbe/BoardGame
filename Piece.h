//
// Created by nil on 21/12/2018.
//

#ifndef BOARDGAME_PIECE_H
#define BOARDGAME_PIECE_H
#include <vector>
#include <string>

class Piece {

protected:
    static const int m_size = 8;
    int m_color;
    std::vector<int> m_travel;

public:

    Piece(int color);
    int sqr(int x);
    virtual int getColor();
    virtual void toString();
    virtual void setTravel(int x_dep, int y_dep, int x_arr, int y_arr);
    virtual int canMove(int x_dep, int y_dep, int x_arr, int y_arr);
    virtual std::vector<int> getTravel();
};


#endif //BOARDGAME_PIECE_H
