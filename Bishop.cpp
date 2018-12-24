//
// Created by nil on 22/12/2018.
//

#include "Bishop.h"
#include <windows.h>
#include <wchar.h>
#include <iostream>

using namespace std;

int Bishop::canMove(int x_dep, int y_dep, int x_arr, int y_arr) {
    m_travel.clear();
    cout << "Mouvemment Bishop " << x_dep << "," << y_dep << " to " << x_arr << "," << y_arr << endl;
    //TODO:
    if (abs(x_arr - x_dep) == abs(y_arr - y_dep)) {
        setTravel(x_dep, y_dep, x_arr, y_arr);
        cout << "true";
        return true;
    } else {
        cout << abs(x_arr - x_dep) << " " << abs(y_arr - y_dep) << endl;
        cout << "false" << endl;

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

void Bishop::setTravel(int x_dep, int y_dep, int x_arr, int y_arr) {
    if (x_arr > x_dep && y_arr > y_dep) {
        int j = y_dep + 1;
        for (int i = x_dep + 1; i < x_arr; i++) {
            m_travel.push_back(j * m_size + i);
            j++;
        }
    } else if (x_arr < x_dep && y_arr > y_dep) {
        int j = y_dep + 1;
        for (int i = x_arr + 1; i < x_dep; i++) {
            m_travel.push_back(j * m_size + i);
            j++;
        }
    } else if (x_arr > x_dep && y_arr < y_dep) {
        int j = y_arr + 1;
        for (int i = x_dep + 1; i < x_arr; i++) {
            m_travel.push_back(j * m_size + i);
            j++;
            cout << "test" << (j * m_size + i) << endl;
        }
    } else if (x_arr < x_dep && y_arr < y_dep) {
        int j = y_arr + 1;
        for (int i = x_arr + 1; i < x_dep; i++) {
            m_travel.push_back(j * m_size + i);
            j++;
        }
    }
    return;
}

Bishop::Bishop(int color) : Piece(color) {

}
