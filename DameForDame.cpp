//
// Created by netbook on 25/12/18.
//

#include "DameForDame.h"
#include "GameDame.h"

using namespace std;

DameForDame::DameForDame(int color) : Piece{color} {
}

string DameForDame::toString() {
    return "D";
}

int DameForDame::canMove(int x_dep, int y_dep, int x_arr, int y_arr) {
    if ((m_color == GameDame::WHITE) && (x_dep != x_arr) && (y_arr - y_dep > 0))
        return 1;
    else if ((m_color == GameDame::BLACK) && (x_dep != x_arr) && (y_arr - y_dep < 0))
        return 1;
    else
        return 0;
}

void DameForDame::setTravel(int x_dep, int y_dep, int x_arr, int y_arr) {
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

std::vector<int> DameForDame::getPossibleMoves(int current_x, int current_y){
    return Piece::getPossibleMoves(current_x,current_x);
}