//
// Created by nil on 23/12/2018.
//

#include "Queen.h"
#include "GameChess.h"
#include <wchar.h>
#include <iostream>

using namespace std;

Queen::Queen(int color) : Piece(color) {
}

Queen::Queen(const Piece *p) : Piece{p} {
}

Piece* Queen::copy() {
    return new Queen(this);
}

int Queen::canMove(int x_dep, int y_dep, int x_arr, int y_arr) {
    m_travel.clear();
    //cout << "Mouvemment Queen " << x_dep << "," << y_dep << " to " << x_arr << "," << y_arr << endl;

    if (abs(x_arr - x_dep) == abs(y_arr - y_dep)) {
   //     cout << "true1";
     //   cout << " Queen " << x_dep << "," << y_dep << " to " << x_arr << "," << y_arr << endl;
        setTravel(x_dep, y_dep, x_arr, y_arr);
        return true;
    } else if ((x_arr == x_dep && y_arr != y_dep) || (x_arr != x_dep && y_arr == y_dep)) {
       // cout << "true2";
         //cout << " Queen " << x_dep << "," << y_dep << " to " << x_arr << "," << y_arr << endl;
        setTravel(x_dep, y_dep, x_arr, y_arr);
        return true;

    } else return false;

}

void Queen::setTravel(int x_dep, int y_dep, int x_arr, int y_arr) {
    if (x_arr > x_dep) {
        if (y_arr == y_dep) {
            for (int i = x_dep + 1; i < x_arr; i++)
                m_travel.push_back(y_dep * GameChess::SIZE + i);
        } else if (y_arr > y_dep) {
            int j = y_dep + 1;
            for (int i = x_dep + 1; i < x_arr; i++) {
                m_travel.push_back(j * GameChess::SIZE + i);
                j++;
            }
        } else if (y_arr < y_dep) {
            int j = y_dep - 1;
            for (int i = x_dep + 1; i < x_arr; i++) {
                m_travel.push_back(j * GameChess::SIZE + i);
                j--;
            }

        }
    } else if (x_arr < x_dep) {
        if (y_arr == y_dep) {
            for (int i = x_arr + 1; i < x_dep; i++)
                m_travel.push_back(y_dep * GameChess::SIZE + i);
        } else if (x_arr < x_dep && y_arr > y_dep) {
            int j = y_arr + -1;
            for (int i = x_arr + 1; i < x_dep; i++) {
                m_travel.push_back(j * GameChess::SIZE + i);
                j--;
            }
        } else if (y_arr < y_dep) {
            int j = y_arr + 1;
            for (int i = x_arr + 1; i < x_dep; i++) {
                m_travel.push_back(j * GameChess::SIZE + i);
                j++;
            }
        }
    } else if (y_arr < y_dep) {
        for (int i = y_arr + 1; i < y_dep; i++)
            m_travel.push_back(i * GameChess::SIZE + x_dep);
    } else if (y_arr > y_dep) {
        for (int i = y_dep + 1; i < y_arr; i++)
            m_travel.push_back(i * GameChess::SIZE + x_dep);
    }
}

string Queen::toString() {
return "Q";
}

std::vector<int> Queen::getPossibleMoves(int current_x, int current_y){
    vector<int> res;
    for(int i = 1;i<GameChess::SIZE - current_x;i++){
        if(current_y + i <GameChess::SIZE)
            res.push_back((current_y + i) * GameChess::SIZE + (current_x + i));
        if(current_y - i >=0)
            res.push_back((current_y - i) * GameChess::SIZE + (current_x + i));
    }

    for(int i = 1;i<=current_x;i++){
        if(current_y + i <GameChess::SIZE)
            res.push_back((current_y + i) * GameChess::SIZE + (current_x - i));
        if(current_y - i >=0)
            res.push_back((current_y - i) * GameChess::SIZE + (current_x - i));
    }

    for(int i = 0;i<GameChess::SIZE;i++){
        if(i!= current_x) {
            res.push_back(current_y * GameChess::SIZE + i);
        }
        if(i!= current_y) {
            res.push_back(i * GameChess::SIZE + current_x);
        }
    }

    return res;

}

