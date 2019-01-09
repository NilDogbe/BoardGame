//
// Created by netbook on 30/12/18.
//

#include "DameForDameEnglish.h"
#include "GameDameEnglish.h"

using namespace std;

DameForDameEnglish::DameForDameEnglish(int color) : Piece{color} {
}

DameForDameEnglish::DameForDameEnglish(const Piece *p) : Piece{p} {
}

Piece* DameForDameEnglish::copy() {
    return new DameForDameEnglish(this);
}

string DameForDameEnglish::toString() {
    return "D";
}

int DameForDameEnglish::canMove(int x_dep, int y_dep, int x_arr, int y_arr) {
    if (abs(x_dep - x_arr) == abs(y_arr - y_dep)) {
        if (abs(y_arr - y_dep) == 1)
            return 1;
        else
            return 2;
    }

    return 0;
}

void DameForDameEnglish::setTravel(int x_dep, int y_dep, int x_arr, int y_arr) {
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

        m_travel.push_back(y_dep * GameDameEnglish::SIZE + x_dep);
    }
}

std::vector<int> DameForDameEnglish::getPossibleMoves(int current_x, int current_y) {
    vector<int> res;
    for(int i = 1;i<GameDameEnglish::SIZE - current_x;i++){
        if(current_y + i <GameDameEnglish::SIZE)
            res.push_back((current_y + i) * GameDameEnglish::SIZE + (current_x + i));
        if(current_y - i >=0)
            res.push_back((current_y - i) * GameDameEnglish::SIZE + (current_x + i));
    }

    for(int i = 1;i<=current_x ;i++){
        if(current_y + i <GameDameEnglish::SIZE)
            res.push_back((current_y + i) * GameDameEnglish::SIZE + (current_x - i));
        if(current_y - i >=0)
            res.push_back((current_y - i) * GameDameEnglish::SIZE + (current_x - i));
    }
    return res;
}
