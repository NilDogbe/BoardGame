//
// Created by nil on 23/12/2018.
//

#include "PawnForChess.h"
#include <cmath>
#include <wchar.h>
#include <iostream>

using namespace std;


int PawnForChess::canMove(int x_dep, int y_dep, int x_arr, int y_arr) {
    m_travel.clear();
    cout << "Mouvemment Piont " << x_dep << "," << y_dep << " to " << x_arr << "," << y_arr << endl;
    if (m_color == 0) {
        cout << "15 P" << endl;

        if ((abs(x_dep - x_arr) == 1) && (y_dep - y_arr == 1)) {
            cout << "mange P" << endl;
            m_firstMove = false;
            return 2;
        } else if (x_dep == x_arr && (y_dep - y_arr == 2 || y_dep - y_arr == 1)) {
            cout << "1 P" << endl;

            if (m_firstMove) {
                cout << "2 P" << endl;

                m_firstMove = false;
                return 1;
            } else if (y_dep - y_arr == 1) {
                cout << "3 P" << endl;

                m_firstMove = false;
                return 1;
            } else return 0;
        } else return 0;
    } else {
        cout << "16 P" << endl;

        if ((abs(x_arr - x_dep) == 1) && (y_arr - y_dep == 1)) {
            cout << "mange P" << endl;
            m_firstMove = false;
            return 2;
        } else if (x_dep == x_arr && (y_arr - y_dep == 2 || y_arr - y_dep == 1)) {
            cout << "10 P" << endl;

            if (m_firstMove) {
                cout << "20 P" << endl;

                m_firstMove = false;
                return 1;
            } else if (y_arr - y_dep == 1) {
                cout << "30 P" << endl;

                m_firstMove = false;
                return 1;
            } else return 0;
        } else return 0;
    }
}

string PawnForChess::toString() {
   return "P";
}

void PawnForChess::setTravel(int x_dep, int y_dep, int x_arr, int y_arr) {
    Piece::setTravel(x_dep, y_dep, x_arr, y_arr);
}

PawnForChess::PawnForChess(int color) : Piece(color) {

}