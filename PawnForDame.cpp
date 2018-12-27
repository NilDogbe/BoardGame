//
// Created by netbook on 25/12/18.
//

#include "PawnForDame.h"
#include "GameDame.h"

using namespace std;

PawnForDame::PawnForDame(int color) : Piece{color} {
}

string PawnForDame::toString() {
    return "O";
}

int PawnForDame::canMove(int x_dep, int y_dep, int x_arr, int y_arr) {
    if (abs(x_dep - x_arr) == abs(y_arr - y_dep)) {
        if (abs(y_arr - y_dep) == 2)
            return 2;
        else if (m_color == GameDame::WHITE && y_arr - y_dep == 1)
            return 1;
        else if (m_color == GameDame::BLACK && y_arr - y_dep == -1)
            return 1;
    }

    return 0;
}

void PawnForDame::setTravel(int x_dep, int y_dep, int x_arr, int y_arr) {
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

    m_travel.clear();
    while (true) {
        x_dep += addX;
        y_dep += addY;

        if (x_dep == x_arr && y_dep == y_arr)
            break;

        m_travel.push_back(y_dep * GameDame::SIZE + x_dep);
    }
}

std::vector<int> PawnForDame::getPossibleMoves(int current_x, int current_y) {
    return Piece::getPossibleMoves(current_x, current_y);
}