//
// Created by nil on 21/12/2018.
//

#include "Piece.h"
#include <string>

using namespace std;


Piece::Piece(int couleur) {
    m_color = couleur;
}

int Piece::getColor(){
    return m_color;
}