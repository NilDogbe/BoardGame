//
// Created by nil on 22/12/2018.
//

#include "Tower.h"
#include <cmath>
#include <iostream>
#include <windows.h>
#include <wchar.h>


bool Tower::canMove(int x_dep, int y_dep, int x_arr, int y_arr) {
    cout << "Mouvemment Tower "<< x_dep << ","<< y_dep <<  " to " << x_arr <<","<< y_arr << endl;

    if (y_dep == y_arr && x_dep == x_arr )
        return false;
    else if ( (x_arr == x_dep && y_arr != y_dep) || (x_arr != x_dep && y_arr == y_dep))
        return true;
    else return false;

}


void Tower::toString() {
    if (m_color == 0) {
        const wchar_t *black = L"♖";
        WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), black, wcslen(black), 0, 0);

    }
    if (m_color == 1) {
        const wchar_t *white = L"♜";
        WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), white, wcslen(white), 0, 0);
    }}

Tower::Tower(int color) : Piece(color) {

}