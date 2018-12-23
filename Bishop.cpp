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
    if(abs(x_arr - x_dep) == abs(y_arr - y_dep)){
        cout << "true";
        return true;
    }
    else{
        cout << abs(x_arr - x_dep) << " " << abs(y_arr - y_dep)<<endl;
        cout << "false"<<endl;

        return false;
    }

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

Bishop::Bishop(int color) : Piece(color) {

}
