//
// Created by netbook on 28/12/18.
//

#ifndef BOARDGAME_MOVE_H
#define BOARDGAME_MOVE_H

class Piece;

class Move {
private:
    Piece* piece_move;
    Piece* piece_delete;
    int x_dep, y_dep;
    int x_arr, y_arr;
    int x_del, y_del;
    int curP;
public:
    Move();
    ~Move();
    Piece* getPieceMove() const;
    Piece* getPieceDelete() const;
    int getXDep() const;
    int getYDep() const;
    int getXArr() const;
    int getYArr() const;
    int getXDel() const;
    int getYDel() const;
    int getCurP() const;
    void setPieceMove(Piece*);
    void setPieceDelete(Piece*);
    void setDep(int x, int y);
    void setArr(int x, int y);
    void setDel(int x, int y);
    void setCurP(int);
};


#endif //BOARDGAME_MOVE_H
