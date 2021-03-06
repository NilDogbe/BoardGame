//
// Created by nil on 22/12/2018.
//

#include "Tower.h"
#include "GameChess.h"
#include <cmath>
#include <iostream>
#include <wchar.h>

using namespace std;

Tower::Tower(int color) : Piece(color) {
}

Tower::Tower(const Piece *p) : Piece{p} {
}

Piece* Tower::copy() {
    return new Tower(this);
}

int Tower::canMove(int x_dep, int y_dep, int x_arr, int y_arr) {
    m_travel.clear();
   // cout << "Mouvemment Tower " << x_dep << "," << y_dep << " to " << x_arr << "," << y_arr << endl;

    if (y_dep == y_arr && x_dep == x_arr)
        return false;
    else if ((x_arr == x_dep && y_arr != y_dep) || (x_arr != x_dep && y_arr == y_dep)) {
        setTravel(x_dep, y_dep, x_arr, y_arr);
        return true;
    } else return false;

}

void Tower::setTravel(int x_dep, int y_dep, int x_arr, int y_arr) {
    if (x_arr > x_dep) {
        for (int i = x_dep + 1; i < x_arr; i++)
            m_travel.push_back(y_dep * GameChess::SIZE + i);
    } else if (x_arr < x_dep) {
        for (int i = x_arr + 1; i < x_dep; i++)
            m_travel.push_back(y_dep * GameChess::SIZE + i);
    } else if (y_arr > y_dep) {
        for (int i = y_dep + 1; i < y_arr; i++)
            m_travel.push_back(i * GameChess::SIZE + x_dep);
    } else if (y_arr < y_dep) {
        for (int i = y_arr + 1; i < y_dep; i++)
            m_travel.push_back(i * GameChess::SIZE + x_dep);
    }
}


string Tower::toString() {
    return "T";
}

std::vector<int> Tower::getPossibleMoves(int current_x, int current_y){
    vector<int> res;
    for(int i = 0;i<GameChess::SIZE;i++){
        if(i!= current_x) {
            res.push_back(current_y * GameChess::SIZE + i);
        }
        if(i!= current_y) {
            res.push_back(i * GameChess::SIZE + current_x);
        }
    }
    return res;

}