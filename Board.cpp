//
// Created by nil on 21/12/2018.
//

#include <iostream>
#include "Board.h"


Board::Board() {
    initBoard(1);
    affichage();
}

void Board::initBoard(int jeu) {
    for (int i = 0; i < m_size; i++) {
        for (int j = 0; j < m_size; j++) {
            if ((i + j) % 2 == 0) {
                m_board.push_back(Case(i, j, BLACK));
            } else
                m_board.push_back(Case(i, j, WHITE));
        }
    }
}

void Board::affichage() {
    for (int i = m_size - 1; i >= 0; i--) {
        cout << i << " ";

        for (int j =0; j < m_size; j++) {
            if (m_board.at(i * m_size + j).getColor() == WHITE)
                cout << "W";
            else
                cout << "B";
        }
        cout << endl;
    }

}


