//
// Created by nil on 22/12/2018.
//

#include "Bishop.h"
#include <wchar.h>
#include <iostream>

using namespace std;

int Bishop::canMove(int x_dep, int y_dep, int x_arr, int y_arr) {
    m_travel.clear();
    //cout << "Mouvemment Bishop " << x_dep << "," << y_dep << " to " << x_arr << "," << y_arr << endl;
    //TODO:
    if (abs(x_arr - x_dep) == abs(y_arr - y_dep)) {
        setTravel(x_dep, y_dep, x_arr, y_arr);
       // cout << "true";
        return true;
    } else {
       // cout << abs(x_arr - x_dep) << " " << abs(y_arr - y_dep) << endl;
        //cout << "false" << endl;

        return false;
    }

}

string Bishop::toString() {
   return "B";
}

void Bishop::setTravel(int x_dep, int y_dep, int x_arr, int y_arr) {
    if (x_arr > x_dep && y_arr > y_dep) {
        int j = y_dep + 1;
        for (int i = x_dep + 1; i < x_arr; i++) {
            m_travel.push_back(j * m_size + i);
            j++;
        }
    } else if (x_arr < x_dep && y_arr > y_dep) {
        int j = y_arr + -1;
        for (int i = x_arr + 1; i < x_dep; i++) {
            m_travel.push_back(j * m_size + i);
            j--;
        }
    } else if (x_arr > x_dep && y_arr < y_dep) {
        int j = y_dep - 1;
        for (int i = x_dep + 1; i < x_arr; i++) {
            m_travel.push_back(j * m_size + i);
            j--;
           // cout << "test" << (j * m_size + i) << endl;
        }
    } else if (x_arr < x_dep && y_arr < y_dep) {
        int j = y_arr + 1;
        for (int i = x_arr + 1; i < x_dep; i++) {
            m_travel.push_back(j * m_size + i);
            j++;
           // cout << "test" << (j * m_size + i) << endl;
        }
    }
}

Bishop::Bishop(int color) : Piece(color) {

}

std::vector<int> Bishop::getPossibleMoves(int current_x, int current_y){
    vector<int> res;
    for(int i = 1;i<m_size - current_x;i++){
        if(current_y + i <m_size)
        res.push_back((current_y + i) * m_size + (current_x + i));
        if(current_y - i >=0)
        res.push_back((current_y - i) * m_size + (current_x + i));
    }

    for(int i = 1;i<=current_x ;i++){
        if(current_y + i <m_size)
            res.push_back((current_y + i) * m_size + (current_x - i));
        if(current_y - i >=0)
            res.push_back((current_y - i) * m_size + (current_x - i));
    }

    return res;
}
