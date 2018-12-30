//
// Created by nil on 21/12/2018.
//

#ifndef BOARDGAME_PIECE_H
#define BOARDGAME_PIECE_H
#include <vector>
#include <string>


class Piece {
protected:
    int m_color;
    std::vector<int> m_travel;
public:
    Piece(int color);
    Piece(const Piece* p);
    virtual Piece* copy() = 0;
    virtual int getColor();
    virtual std::string toString() = 0;
    virtual int canMove(int x_dep, int y_dep, int x_arr, int y_arr) = 0;
    virtual void setTravel(int x_dep, int y_dep, int x_arr, int y_arr);
    virtual std::vector<int> getTravel();
    virtual std::vector<int> getPossibleMoves(int current_x, int current_y);
    int sqr(int x);

};


#endif //BOARDGAME_PIECE_H
