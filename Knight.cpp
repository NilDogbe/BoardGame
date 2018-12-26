//
// Created by nil on 22/12/2018.
//

#include "Knight.h"
#include <cmath>
#include <iostream>
#include <wchar.h>
using namespace std;

int Knight::canMove(int x_dep, int y_dep, int x_arr, int y_arr) {
    m_travel.clear();
    //   res=sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p1.y));
    cout << "Mouvemment Cav "<< x_dep << ","<< y_dep <<  " to " << x_arr <<","<< y_arr << endl;
    if (y_dep == y_arr || x_dep == x_arr )
        return false;
    else if ((x_arr - 2 == x_dep || x_arr + 2 == x_dep ) && (y_arr - 1 == y_dep || y_arr + 1 == y_dep)) {
        setTravel(x_dep,  y_dep, x_arr, y_arr);
        return true;
    }
    else if ((x_arr - 1 == x_dep || x_arr - 1 == x_dep) && (y_arr - 2 == y_dep || y_arr + 2 == y_dep)) {
        setTravel(x_dep,  y_dep, x_arr, y_arr);
        return true;
    }
    else return false;

}


string Knight::toString() {
return "C";
}

void Knight::setTravel(int x_dep, int y_dep, int x_arr, int y_arr){
    return;
}

Knight::Knight(int color) : Piece(color) {

}

std::vector<int> Knight::getPossibleMoves(int current_x, int current_y){
    return Piece::getPossibleMoves(current_x,current_x);
}