//
// Created by nil on 21/12/2018.
//

#include <iostream>
#include "Board.h"
#include "Piece.h"
#include "King.h"


Board::Board() {
    initBoard(1);
}

void Board::initBoard(int jeu) {
    for (int i = 0; i < m_size; i++) {
        for (int j = 0; j < m_size; j++) {
            if (i == 0 || i == 1)
                if ((i + j) % 2 == 0)
                    m_board.push_back(new King(0));
                else
                    m_board.push_back(new King(0));
            else if (i == m_size - 1 || i == m_size - 2) {
                if ((i + j) % 2 == 0)
                    m_board.push_back(new King(1));
                else
                    m_board.push_back(new King(1));
            } else if ((i + j) % 2 == 0)
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
            }
            else if ((i + j) % 2 == 0)
                cout << "W";
            else
                cout << "B";
        }
        cout << endl;
    }
    cout << "   ";

    for (int i = 0; i < m_size; i++)
        cout << i;
}

void Board::movePiece(int x_dep, int y_dep, int x_arr, int y_arr) {
    Piece *piece_dep = m_board.at(x_dep * 8 + y_dep);
    if (x_arr < m_size && x_arr >= 0 && y_arr < m_size && y_dep >= 0) {  // dans les limites
        cout << "1" << endl;
        if (piece_dep != nullptr) { //case dep pas vide ?
            cout << "2" << endl;
            if (piece_dep->canMove(x_dep, y_dep, x_arr, y_arr)) { //mouvement accessible a cette piece
                cout << "3" << endl;
                Piece *piece_arr = m_board.at(x_arr * 8 + y_arr);
                if (piece_arr != nullptr) {  //
                    cout << "4" << endl;
                    if (piece_arr->getColor() != piece_dep->getColor()) { //test si les couleurs sont identiques
                        cout << "5" << endl;
                        m_board.at(x_dep * 8 + y_dep) = nullptr;
                        m_board.at(x_arr * 8 + y_arr) = piece_dep;
                    }
                    else ;//mange un point a toi meme
                }
                else {
                    cout << "6" << endl;
                    m_board.at(x_dep * 8 + y_dep) = nullptr;
                    m_board.at(x_arr * 8 + y_arr) = piece_dep;

                }
            }
        }
    }
}



