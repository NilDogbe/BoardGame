//
// Created by nil on 21/12/2018.
//

#include <iostream>
#include <windows.h>
#include <wchar.h>
#include "Board.h"
#include "Piece.h"
#include "King.h"
#include "Cavalier.h"
#include "Tower.h"
#include "Bishop.h"
#include "Queen.h"



Board::Board() {
    initBoard(1);
}

void Board::initBoard(int jeu) {
    for (int i = 0; i < m_size; i++) {
        for (int j = 0; j < m_size; j++) {
            if (i == 0 || i == 1) {
                m_board.push_back(new King(0));
            } else if (i == m_size - 1) {
                m_board.push_back(new Cavalier(1));
            } else if (i == m_size - 2 && (j == m_size -1)) {
                m_board.push_back(new Tower(1));
            } else if ((i == m_size - 2) && (j == m_size -2) ) {
                m_board.push_back(new Bishop(1));
            }  else if ((i == m_size - 2) && (j == m_size -3) ) {
                m_board.push_back(new Queen(1));
            }else if ((i + j) % 2 == 0)
                m_board.push_back(nullptr);
            else
                m_board.push_back(nullptr);
        }
    }
}

void Board::affichage() {
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

void Board::movePiece(int x_dep, int y_dep, int x_arr, int y_arr) {
    Piece *piece_dep = m_board.at(y_dep * 8 + x_dep);
    if (y_arr < m_size && y_arr >= 0 && x_arr < m_size && x_dep >= 0) {  // dans les limites
        cout << "1" << endl;
        if (piece_dep != nullptr) { //case dep pas vide ?
            cout << "2" << endl;
            if (piece_dep->canMove(x_dep, y_dep, x_arr, y_arr)) { //mouvement accessible a cette piece
                cout << "3" << endl;
                Piece *piece_arr = m_board.at(y_arr * 8 + x_arr);
                if (piece_arr != nullptr) {  //
                    cout << "4" << endl;
                    if (piece_arr->getColor() != piece_dep->getColor()) { //test si les couleurs sont identiques
                        cout << "5" << endl;
                        m_board.at(y_dep * 8 + x_dep) = nullptr;
                        m_board.at(y_arr * 8 + x_arr) = piece_dep;
                    } else;//mange un point a toi meme
                } else {
                    cout << "6" << endl;
                    m_board.at(y_dep * 8 + x_dep) = nullptr;
                    m_board.at(y_arr * 8 + x_arr) = piece_dep;

                }
            }
        }
    }
}



