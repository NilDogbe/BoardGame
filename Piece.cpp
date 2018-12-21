//
// Created by nil on 21/12/2018.
//

#include "Piece.h"
#include <string>

using namespace std;


Piece::Piece(string name) {
    m_name = name;
}

string Piece::getNom() {
    return m_name;
}