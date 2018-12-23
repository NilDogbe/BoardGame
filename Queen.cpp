//
// Created by nil on 23/12/2018.
//

#include "Queen.h"
#include <windows.h>
#include <wchar.h>
#include <iostream>
using namespace std;
bool Queen::canMove(int x_dep, int y_dep, int x_arr, int y_arr) {
    cout << "Mouvemment Queen "<< x_dep << ","<< y_dep <<  " to " << x_arr <<","<< y_arr << endl;

    if(abs(x_arr - x_dep) == abs(y_arr - y_dep)){
        cout << "true1";
        cout << " Bishop "<< x_dep << ","<< y_dep <<  " to " << x_arr <<","<< y_arr << endl;

        return true;
    }
    else if ( (x_arr == x_dep && y_arr != y_dep) || (x_arr != x_dep && y_arr == y_dep)){
        cout << "true2";
        cout << " Bishop "<< x_dep << ","<< y_dep <<  " to " << x_arr <<","<< y_arr << endl;
        return true;

    }
    else return false;

}

Queen::Queen(int color) : Piece(color) {

}

void Queen::setTravel(int x_dep, int y_dep, int x_arr, int y_arr){
    return;
}

void Queen::toString() {
    if (m_color == 0) {
        const wchar_t *black = L"♔";
        WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), black, wcslen(black), 0, 0);

    }
    if (m_color == 1) {
        const wchar_t *white = L"♚";
        WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), white, wcslen(white), 0, 0);
    }
}

