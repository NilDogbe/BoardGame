//
// Created by netbook on 23/12/18.
//

#include "PawnForDame.h"
#include "GameDame.h"
#include "iostream"

using namespace std;

PawnForDame::PawnForDame(int color) : Piece{color} {
}

string PawnForDame::toString() {
    return "P";
}

int PawnForDame::canMove(int x_dep, int y_dep, int x_arr, int y_arr) {
    if ((m_color == GameDame::WHITE) && (abs(x_dep - x_arr) <= 2) && (y_arr - y_dep <= 2))
        return 1;
    else if ((m_color == GameDame::BLACK) && (abs(x_dep - x_arr) <= 2) && (y_arr - y_dep >= -2))
        return 1;
    else
        return 0;
}

vector<int> PawnForDame::getTravel(int x_dep, int y_dep, int x_arr, int y_arr) {
    int addX{0};
    int addY{0};
    if (x_arr > x_dep)
        addX = 1;
    else
        addX = -1;
    if (y_arr > y_dep)
        addY = 1;
    else
        addY = -1;

    vector<int> vector;
    while (true) {
        x_dep += addX;
        y_dep += addY;

        if (x_dep == x_arr && y_dep == y_arr)
            break;

        vector.push_back(y_dep * GameDame::SIZE + x_dep);
    }

    return vector;
}