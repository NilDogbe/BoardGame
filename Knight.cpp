//
// Created by nil on 22/12/2018.
//

#include "Knight.h"
#include "GameChess.h"
#include <cmath>
#include <iostream>
#include <wchar.h>
using namespace std;

Knight::Knight(int color) : Piece(color) {
}

Knight::Knight(const Piece *p) : Piece{p} {
}

Piece* Knight::copy() {
    return new Knight(this);
}

int Knight::canMove(int x_dep, int y_dep, int x_arr, int y_arr) {
    m_travel.clear();
    //   res=sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p1.y));
   // cout << "Mouvemment Cav "<< x_dep << ","<< y_dep <<  " to " << x_arr <<","<< y_arr << endl;
    if (y_dep == y_arr || x_dep == x_arr )
        return false;
    else if ((x_arr - 2 == x_dep || x_arr + 2 == x_dep ) && (y_arr - 1 == y_dep || y_arr + 1 == y_dep)) {
        setTravel(x_dep,  y_dep, x_arr, y_arr);
        return true;
    }
    else if ((x_arr - 1 == x_dep || x_arr + 1 == x_dep) && (y_arr - 2 == y_dep || y_arr + 2 == y_dep)) {
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

std::vector<int> Knight::getPossibleMoves(int current_x, int current_y){
    vector<int> res;
    int x[4] = { -2, -1, 1, 2};
    int y[8] = { 1, -1, 2,-2, 2, -2, 1,-1};
    for(int i = 0;i<4;i++){
        int next_y = current_y + (y[(i*2)]);
        int next_x = current_x + (x[i]);
        int tmp = next_y * GameChess::SIZE + next_x;
        if((next_y >=0 && next_y <GameChess::SIZE ) && (next_x >=0 && next_x <GameChess::SIZE ) ){

            res.push_back(tmp);
        }
        next_y = current_y + (y[(i*2)+1]);
        next_x = current_x + (x[i]);
        tmp = next_y * GameChess::SIZE + next_x;
        if((next_y >=0 && next_y <GameChess::SIZE ) && (next_x >=0 && next_x <GameChess::SIZE ) ){
            res.push_back(tmp);
        }
    }

    return res;
}