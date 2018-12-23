//
// Created by nil on 22/12/2018.
//

#include "Cavalier.h"
#include <cmath>
#include <iostream>
#include <windows.h>
#include <wchar.h>
using namespace std;

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
    if (m_color == 0) {
        const wchar_t *black = L"♘";
        WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), black, wcslen(black), 0, 0);

    }
    if (m_color == 1) {
        const wchar_t *white = L"♞";
        WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), white, wcslen(white), 0, 0);
    }
}

void Cavalier::setTravel(int x_dep, int y_dep, int x_arr, int y_arr){
    return;
}

Cavalier::Cavalier(int color) : Piece(color) {

}
