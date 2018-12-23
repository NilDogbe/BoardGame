//
// Created by nil on 21/12/2018.
//

#include "Piece.h"
#include <string>
#include <wchar.h>
//#include <windows.h>
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
bool Piece::canMove(int x_dep, int y_dep, int x_arr, int y_arr) {
    return false;
}

void Piece::setTravel(int x_dep, int y_dep, int x_arr, int y_arr){
    return;
}
void Piece::toString() {

    const wchar_t *white = L"♖";
    const wchar_t *black = L"♚♛♜♝♞♟\r\n";
    //WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), white, wcslen(white), 0, 0);
}

int Piece::sqr(int x) {
    cout<<"sqr";
    return x*x;
}

