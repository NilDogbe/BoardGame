//
// Created by nil on 21/12/2018.
//

#include "King.h"
#include "GameChess.h"
#include <cmath>
#include <wchar.h>
#include <iostream>
using namespace std;

King::King(int color) : Piece(color) {
}

King::King(const Piece *p) : Piece{p} {
}

Piece* King::copy() {
    return new King(this);
}

int King::canMove(int x_dep, int y_dep, int x_arr, int y_arr) {
    //   res=sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p1.y));
   // cout << "Mouvemment King "<< x_dep << ","<< y_dep <<  " to " << x_arr <<","<< y_arr << endl;

    int distance = sqrt(sqr(y_arr - y_dep) + sqr(x_dep - x_arr));
    if (distance > 1) {
       // cout<<"ffffff";

        return false;
    }
    else{

        //cout<<"ttttt";
        return true;
    }
}

string King::toString() {
    return "K";

}
void King::setTravel(int x_dep, int y_dep, int x_arr, int y_arr){
    return;
}

int King::sqr(int x) {
   // cout<<"sqr";
    return x*x;
}

std::vector<int> King::getPossibleMoves(int current_x, int current_y){
    vector<int> res;
    int val[3] = { -1, 0, 1};
    for(int i = 0;i<3;i++){
        int next_x = current_x + (val[i]);
        for(int j = 0; j<3;j++){
           // cout<<"i = "<< i <<" j = " << j <<endl;
            int next_y = current_y + (val[j]);
            if((next_y >=0 && next_y <GameChess::SIZE ) && (next_x >=0 && next_x <GameChess::SIZE ) && !(val[i]==0 && val[j]==0) ){
                res.push_back(next_y * GameChess::SIZE + next_x);
            }
        }
    }
    return res;
}