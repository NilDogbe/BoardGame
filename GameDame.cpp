//
// Created by netbook on 23/12/18.
//

#include "GameDame.h"
#include "PiontForDame.h"
#include <iostream>

GameDame::GameDame() : Game{SIZE} {
    initGame();
}

void GameDame::initGame() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < SIZE; j++) {
            if ((i + j) % 2 == 0)
                m_board[i * SIZE + j] = new PiontForDame(WHITE);
        }
    }
    for (int i = SIZE - 1; i >= SIZE - 4; i--) {
        for (int j = 0; j < SIZE; j++) {
            if ((i + j) % 2 != 0)
                m_board[i * SIZE + j] = new PiontForDame(BLACK);
        }
    }
}

bool GameDame::movePiece(int x_dep, int y_dep, int x_arr, int y_arr) {
    if (Game::movePiece(x_dep, y_dep, x_arr, y_arr)) {
        Piece* dep = m_board[y_dep * SIZE + y_dep];
        Piece* arr = m_board[y_arr * SIZE + y_arr];
            if (dep->canMove(x_dep, y_dep, x_arr, y_arr) == 1) {
                if (arr == nullptr) {
                    m_board[y_dep * SIZE + x_dep] = nullptr;
                    m_board[y_arr * SIZE + x_arr] = dep;
                    std::cout << "lala" << std::endl;
                }
            }
    } else
        return false;
}