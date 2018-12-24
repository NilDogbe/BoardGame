//
// Created by netbook on 23/12/18.
//

#include "PiontForDame.h"
#include "GameDame.h"
#include "iostream"

using namespace std;

PiontForDame::PiontForDame(int color) : Piece{color} {
}

string PiontForDame::toString() {
    return "O";
}

int PiontForDame::canMove(int x_dep, int y_dep, int x_arr, int y_arr) {
    if (abs(x_dep - x_arr) == 1 && abs(y_dep - y_arr) == 1) {
        if (y_arr > y_dep)
            return 1;
        else
            return 2;
    } else
        return 0;
}

vector<int> PiontForDame::getTravel(int x_dep, int y_dep, int x_arr, int y_arr) {
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
    while(true) {
        x_dep += addX;
        y_arr += addY;

        if (x_dep == x_arr && y_dep == y_arr)
            break;

        vector.push_back(y_dep * GameDame::SIZE + x_dep);
    }
}