//
// Created by nil on 23/12/2018.
//

#include "Queen.h"
#include <wchar.h>
#include <iostream>

using namespace std;

int Queen::canMove(int x_dep, int y_dep, int x_arr, int y_arr) {
    m_travel.clear();
    cout << "Mouvemment Queen " << x_dep << "," << y_dep << " to " << x_arr << "," << y_arr << endl;

    if (abs(x_arr - x_dep) == abs(y_arr - y_dep)) {
        cout << "true1";
        cout << " Queen " << x_dep << "," << y_dep << " to " << x_arr << "," << y_arr << endl;
        setTravel(x_dep, y_dep, x_arr, y_arr);
        return true;
    } else if ((x_arr == x_dep && y_arr != y_dep) || (x_arr != x_dep && y_arr == y_dep)) {
        cout << "true2";
         cout << " Queen " << x_dep << "," << y_dep << " to " << x_arr << "," << y_arr << endl;
        setTravel(x_dep, y_dep, x_arr, y_arr);
        return true;

    } else return false;

}

Queen::Queen(int color) : Piece(color) {

}

void Queen::setTravel(int x_dep, int y_dep, int x_arr, int y_arr) {
    if (x_arr > x_dep) {
        if (y_arr == y_dep) {
            for (int i = x_dep + 1; i < x_arr; i++)
                m_travel.push_back(y_dep * m_size + i);
        } else if (y_arr > y_dep) {
            int j = y_dep + 1;
            for (int i = x_dep + 1; i < x_arr; i++) {
                m_travel.push_back(j * m_size + i);
                j++;
            }
        } else if (y_arr < y_dep) {
            int j = y_dep - 1;
            for (int i = x_dep + 1; i < x_arr; i++) {
                m_travel.push_back(j * m_size + i);
                j--;
                cout << "test" << (j * m_size + i) << endl;
            }

        }
    } else if (x_arr < x_dep) {
        if (y_arr == y_dep) {
            for (int i = x_arr + 1; i < x_dep; i++)
                m_travel.push_back(y_dep * m_size + i);
        } else if (x_arr < x_dep && y_arr > y_dep) {
            int j = y_arr + -1;
            for (int i = x_arr + 1; i < x_dep; i++) {
                m_travel.push_back(j * m_size + i);
                j--;
            }
        } else if (y_arr < y_dep) {
            int j = y_arr + 1;
            for (int i = x_arr + 1; i < x_dep; i++) {
                m_travel.push_back(j * m_size + i);
                j++;
            }
        }
    } else if (y_arr < y_dep) {
        for (int i = y_arr + 1; i < y_dep; i++)
            m_travel.push_back(i * m_size + x_dep);
    } else if (y_arr > y_dep) {
        for (int i = y_dep + 1; i < y_arr; i++)
            m_travel.push_back(i * m_size + x_dep);
    }
}

string Queen::toString() {
return "Q";
}

