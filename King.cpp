//
// Created by nil on 21/12/2018.
//

#include "King.h"
#include <cmath>
#include <wchar.h>
#include <iostream>
using namespace std;

/*int King::sqr(int x) {
    return x*x;
}*/

int King::canMove(int x_dep, int y_dep, int x_arr, int y_arr) {
    //   res=sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p1.y));
    cout << "Mouvemment King "<< x_dep << ","<< y_dep <<  " to " << x_arr <<","<< y_arr << endl;

    int distance = sqrt(sqr(y_arr - y_dep) + sqr(x_dep - x_arr));
    if (distance > 1) {
        cout<<"ffffff";

        return false;
    }
    else{

        cout<<"ttttt";
        return true;
    }
}

string King::toString() {
    return "K";

}
void King::setTravel(int x_dep, int y_dep, int x_arr, int y_arr){
    return;
}

King::King(int color) : Piece(color) {

}

int King::sqr(int x) {
    cout<<"sqr";
    return x*x;
}

