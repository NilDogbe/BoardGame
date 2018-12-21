//
// Created by nil on 21/12/2018.
//

#include <iostream>
#include "Board.h"
#include "Piece.h"


Board::Board() {
    initBoard(1);
    affichage();
}

void Board::initBoard(int jeu) {
    for (int i = 0; i < m_size; i++) {
        for (int j = 0; j < m_size; j++) {
            if (i == 0 || i == 1)
                if ((i + j) % 2 == 0)
                    m_board.push_back(Case(i, j, BLACK, new Piece(0)));
                else
                    m_board.push_back(Case(i, j, WHITE, new Piece(0)));
            else if (i == m_size - 1|| i == m_size - 2) {
                if ((i + j) % 2 == 0)
                    m_board.push_back(Case(i, j, BLACK, new Piece(1)));
                else
                    m_board.push_back(Case(i, j, WHITE, new Piece(1)));
            } else if ((i + j) % 2 == 0)
                m_board.push_back(Case(i, j, BLACK, nullptr));
            else
                m_board.push_back(Case(i, j, WHITE, nullptr));
        }
    }
}

void Board::affichage() {
    for (int i = m_size - 1; i >= 0; i--) {
        cout << i << "| ";

        for (int j = 0; j < m_size; j++) {
            Case cur = m_board.at(i * m_size + j);
            if (!cur.isEmpty()) {
                if (cur.getPiece()->getColor() == 0)
                    cout << "O";
                else if (cur.getPiece()->getColor() == 1)
                cout << "T";
            } else if (cur.getColor() == WHITE)
                cout << "W";
            else
                cout << "B";
        }
        cout << endl;
    }
    cout <<"   ";

    for(int i = 0 ; i<m_size; i++)
        cout << i;


}


