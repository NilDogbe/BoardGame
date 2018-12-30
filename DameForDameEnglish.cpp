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
        if (abs(y_arr - y_dep) == 2)
            return 2;
        else if (m_color == Game::WHITE && y_arr - y_dep == 1)
            return 1;
        else if (m_color == Game::BLACK && y_arr - y_dep == -1)
            return 1;
    }
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
    if (this->getColor() == Game::WHITE) {
        if (current_y < GameDameEnglish::SIZE - 1) {
            if (current_x < GameDameEnglish::SIZE - 1)
                res.push_back((current_y + 1) * GameDameEnglish::SIZE + current_x + 1);
            if (current_x > 0)
                res.push_back((current_y + 1) * GameDameEnglish::SIZE + current_x - 1);
        }
    } else {
        if (current_y > 0) {
            if (current_x < GameDameEnglish::SIZE - 1)
                res.push_back((current_y - 1) * GameDameEnglish::SIZE + current_x + 1);
            if (current_x > 0)
                res.push_back((current_y - 1) * GameDameEnglish::SIZE + current_x - 1);
        }
    }
    if (current_y < GameDameEnglish::SIZE - 2) {
        if (current_x < GameDameEnglish::SIZE - 2)
            res.push_back((current_y + 2) * GameDameEnglish::SIZE + current_x + 2);
        if (current_x > 1)
            res.push_back((current_y + 2) * GameDameEnglish::SIZE + current_x - 2);
    }

    if (current_y > 1) {
        if (current_x < GameDameEnglish::SIZE - 2)
            res.push_back((current_y - 2) * GameDameEnglish::SIZE + current_x + 2);
        if (current_x > 1)
            res.push_back((current_y - 2) * GameDameEnglish::SIZE + current_x - 2);
    }
    return res;
}
