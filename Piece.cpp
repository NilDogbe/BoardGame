//
// Created by nil on 21/12/2018.
//

#include "Piece.h"
#include <string>
#include <wchar.h>
#include <iostream>

using namespace std;


Piece::Piece(int couleur) {
    m_color = couleur;
}

int Piece::getColor(){
    return m_color;
}

vector<int> Piece::getTravel(){
    return m_travel;
}

void Piece::setTravel(int x_dep, int y_dep, int x_arr, int y_arr) {
    return;
}

vector<int> Piece::getPossibleMoves(int current_x, int current_y){
    vector<int> res;
    return res;
}