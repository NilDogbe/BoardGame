//
// Created by nil on 22/12/2018.
//

#include "Cavalier.h"
#include <cmath>
#include <iostream>


bool Cavalier::canMove(int x_dep, int y_dep, int x_arr, int y_arr) {
    //   res=sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p1.y));
    cout << "Mouvemment Cav "<< x_dep << ","<< y_dep <<  " to " << x_arr <<","<< y_arr << endl;

    if (y_dep == y_arr || x_dep == x_arr )
        return false;
    else if ((x_arr - 2 == x_dep || x_arr + 2 == x_dep ) && (y_arr - 1 == y_dep || y_arr + 1 == y_dep))
        return true;
    else if ((x_arr - 1 == x_dep || x_arr - 1 == x_dep) && (y_arr - 2 == y_dep || y_arr + 2 == y_dep))
        return true;
    else return false;

}


void Cavalier::toString() {
    Piece::toString();
}

Cavalier::Cavalier(int color) : Piece(color) {

}
