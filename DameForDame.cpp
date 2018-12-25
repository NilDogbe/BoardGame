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

vector<int> DameForDame::getTravel(int x_dep, int y_dep, int x_arr, int y_arr) {
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