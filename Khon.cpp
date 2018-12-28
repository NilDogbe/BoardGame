//
// Created by nil on 28/12/2018.
//

#include "Khon.h"
#include <cmath>

using namespace std;


void Khon::setTravel(int x_dep, int y_dep, int x_arr, int y_arr) {
    return;
}

int Khon::canMove(int x_dep, int y_dep, int x_arr, int y_arr) {
    int distance = sqrt(sqr(y_arr - y_dep) + sqr(x_dep - x_arr));
    if (distance == 1) {
        if ((x_dep != x_arr && y_arr == y_dep) || (x_dep == x_arr && y_dep - 1 == y_arr)) {
            return false;
        } else return true;
    } else return false;
}

std::string Khon::toString() {
    return "N"; // pour Noble
}

std::vector<int> Khon::getPossibleMoves(int current_x, int current_y) {
    vector<int> res;
/*
 * Todo leo
 */
    return res;

}
