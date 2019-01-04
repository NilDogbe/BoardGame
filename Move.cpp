//
// Created by netbook on 28/12/18.
//

#include "Move.h"

Move::Move() : piece_move{nullptr}, piece_delete{nullptr} {
}

void Move::free() {
    if (piece_move != nullptr)
        delete piece_move;
    if (piece_delete != nullptr)
        delete piece_delete;
}

Piece *Move::getPieceMove() const {
    return piece_move;
}

Piece *Move::getPieceDelete() const {
    return piece_delete;
}

int Move::getXDep() const {
    return x_dep;
}

int Move::getYDep() const {
    return y_dep;
}

int Move::getXArr() const {
    return x_arr;
}

int Move::getYArr() const {
    return y_arr;
}

int Move::getXDel() const {
    return x_del;
}

int Move::getYDel() const {
    return y_del;
}

int Move::getCurP() const {
    return curP;
}

void Move::setPieceMove(Piece* p) {
    piece_move = p;
}

void Move::setPieceDelete(Piece* p) {
    piece_delete = p;
}

void Move::setDep(int x, int y) {
    x_dep = x;
    y_dep = y;
}

void Move::setArr(int x, int y) {
    x_arr = x;
    y_arr = y;
}

void Move::setDel(int x, int y) {
    x_del = x;
    y_del = y;
}

void Move::setCurP(int p) {
    curP = p;
}