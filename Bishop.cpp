//
// Created by nil on 22/12/2018.
//

#include "Bishop.h"
#include <windows.h>
#include <wchar.h>
#include <iostream>


bool Bishop::canMove(int x_dep, int y_dep, int x_arr, int y_arr) {
    cout << "Mouvemment Bishop "<< x_dep << ","<< y_dep <<  " to " << x_arr <<","<< y_arr << endl;
    //TODO:

    if (y_dep == y_arr || x_dep == x_arr )
        return false;
    else if ((x_arr - 2 == x_dep || x_arr + 2 == x_dep ) && (y_arr - 1 == y_dep || y_arr + 1 == y_dep))
        return true;
    else if ((x_arr - 1 == x_dep || x_arr - 1 == x_dep) && (y_arr - 2 == y_dep || y_arr + 2 == y_dep))
        return true;
    else return false;
}

void Bishop::toString() {
    if (m_color == 0) {
        const wchar_t *black = L"♗";
        WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), black, wcslen(black), 0, 0);

    }
    if (m_color == 1) {
        const wchar_t *white = L"♝";
        WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), white, wcslen(white), 0, 0);
    }
}
