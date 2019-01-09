//
// Created by nil on 28/12/2018.
//

#include "Seed.h"
#include "GameChess.h"
#include <iostream>
#include <cmath>


using namespace std;


Seed::Seed(int color) : Piece(color) {
}

Seed::Seed(const Piece *p) : Piece{p} {
}

Piece *Seed::copy() {
    return new Seed(this);
}

std::string Seed::toString() {
    return "S";
}

int Seed::canMove(int x_dep, int y_dep, int x_arr, int y_arr) {
    m_travel.clear();
   // cout << "Mouvemment Seed " << x_dep << "," << y_dep << " to " << x_arr << "," << y_arr << endl;
    int distance = sqrt(sqr(y_arr - y_dep) + sqr(x_dep - x_arr));

    if (abs(x_arr - x_dep) == abs(y_arr - y_dep) && distance == 1) {
        setTravel(x_dep, y_dep, x_arr, y_arr);
        return true;
    } else
        return false;
}

void Seed::setTravel(int x_dep, int y_dep, int x_arr, int y_arr) {
    return;
}

std::vector<int> Seed::getPossibleMoves(int current_x, int current_y) {
    vector<int> res;
    if (current_y > 0) {
        if (current_x > 0) {
            res.push_back((current_y - 1 )* GameChess::SIZE + current_x - 1);
        }
        if (current_x < GameChess::SIZE - 1) {
            res.push_back((current_y - 1) * GameChess::SIZE + current_x + 1);
        }
    }
    if (current_y < GameChess::SIZE - 1) {
        if (current_x > 0) {
            res.push_back((current_y + 1) * GameChess::SIZE + current_x - 1);
        }
        if (current_x < GameChess::SIZE - 1) {
            res.push_back((current_y + 1) * GameChess::SIZE + current_x + 1);
        }
    }
    return res;
}

