//
// Created by nil on 28/12/2018.
//

#include "Khon.h"
#include "GameChess.h"
#include <cmath>

using namespace std;

Khon::Khon(int color) : Piece(color) {
}

Khon::Khon(const Piece *p) : Piece{p} {
}

Piece* Khon::copy() {
    return new Khon(this);
}

void Khon::setTravel(int x_dep, int y_dep, int x_arr, int y_arr) {
    return;
}

int Khon::canMove(int x_dep, int y_dep, int x_arr, int y_arr) {
    int distance = sqrt(sqr(y_arr - y_dep) + sqr(x_dep - x_arr));

    if (distance == 1) {
        if (this->getColor() == Game::WHITE) {
            if ((x_dep != x_arr && y_arr == y_dep) || (x_dep == x_arr && y_dep - 1 == y_arr)) {
                return false;
            } else return true;
        }
        else {
            if ((x_dep != x_arr && y_arr == y_dep) || (x_dep == x_arr && y_dep + 1 == y_arr) )
                return false;
            else return true;

        }
    } else return false;
}


std::string Khon::toString() {
    return "N"; // pour Noble
}

std::vector<int> Khon::getPossibleMoves(int current_x, int current_y) {
    vector<int> res;
    if (this->getColor() == Game::WHITE) {
        if (current_y < GameChess::SIZE - 1) {
            res.push_back((current_y + 1) * GameChess::SIZE + current_x);
            if (current_x < GameChess::SIZE - 1) {
                res.push_back((current_y + 1) * GameChess::SIZE + (current_x + 1));
                if(current_y > 0)
                    res.push_back((current_y - 1) * GameChess::SIZE + current_x + 1);
            }
            if (current_x > 0) {
                res.push_back((current_y + 1) * GameChess::SIZE + (current_x - 1));
                if(current_y > 0)
                    res.push_back((current_y - 1) * GameChess::SIZE + current_x - 1);
            }
        }
    } else {
        if (current_y > 0) {
            res.push_back((current_y - 1) * GameChess::SIZE + current_x);
            if (current_x < GameChess::SIZE - 1) {
                res.push_back((current_y - 1) * GameChess::SIZE + (current_x + 1));
                if(current_y > GameChess::SIZE - 1)
                    res.push_back((current_y + 1) * GameChess::SIZE + current_x + 1);
            }
            if (current_x > 0) {
                res.push_back((current_y - 1) * GameChess::SIZE + (current_x - 1));
                if(current_y > GameChess::SIZE - 1)
                    res.push_back((current_y + 1) * GameChess::SIZE + current_x - 1);
            }
        }
    }
    return res;

}
