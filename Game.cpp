//
// Created by nil on 21/12/2018.
//

#include <iostream>
#include <windows.h>
#include <wchar.h>
#include "Game.h"
#include "Piece.h"
#include "King.h"
#include "Cavalier.h"
#include "Tower.h"
#include "Bishop.h"
#include "Queen.h"

using namespace std;

Game::Game(int size) : m_board(size * size, nullptr), m_size(size) {
}


void Game::affichage() {
    for (int i = m_size - 1; i >= 0; i--) {
        cout << i << "| ";
        for (int j = 0; j < m_size; j++) {
            Piece *cur = m_board.at(i * m_size + j);
            if (cur != nullptr) {
                cur->toString();
            } else if ((i + j) % 2 == 0) {
                const wchar_t *white = L"■";
                WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), white, wcslen(white), 0, 0);

            } else {
                const wchar_t *black = L"□";
                WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), black, wcslen(black), 0, 0);
            }
        }
        cout << endl;
    }
    cout << "   ";

    for (int i = 0; i < m_size; i++)
        cout << i;
}

bool Game::movePiece(int x_dep, int y_dep, int x_arr, int y_arr) {
    Piece *piece_dep = m_board.at(y_dep * m_size + x_dep);
    Piece *piece_arr = m_board.at(y_arr * m_size + x_arr);
    // cout << (piece_dep->canMove(x_dep, y_dep, x_arr, y_arr) == 2) << "eeeeeee";

    if (!(y_arr < m_size && y_arr >= 0 && x_arr < m_size && x_dep >= 0)) { // hors des  limites ?
        cout << "G1" << endl;
        return false;
    }
    else if (piece_dep == nullptr) // piece existe
        return false;
    else if (piece_dep->canMove(x_dep, y_dep, x_arr, y_arr) == 0) // piece existe
        return false;
    else if ((piece_arr != nullptr) && (piece_dep->getColor() == piece_arr->getColor()) ){ //manger une piece de meme couleur
        return false;
    }
    else return true;


}



