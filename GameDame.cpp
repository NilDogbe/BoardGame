//
// Created by netbook on 23/12/18.
//

#include "GameDame.h"
#include "PawnForDame.h"
#include "Parser.h"
#include <iostream>

using namespace std;

GameDame::GameDame() : Game{SIZE} {
    initGame();
}

void GameDame::initGame() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < SIZE; j++) {
            if ((i + j) % 2 == 0)
                m_board[i * SIZE + j] = new PawnForDame(WHITE);
        }
    }
    for (int i = SIZE - 1; i >= SIZE - 4; i--) {
        for (int j = 0; j < SIZE; j++) {
            if ((i + j) % 2 == 0)
                m_board[i * SIZE + j] = new PawnForDame(BLACK);
        }
    }
}

bool GameDame::movePiece(int x_dep, int y_dep, int x_arr, int y_arr) {
    if (Game::movePiece(x_dep, y_dep, x_arr, y_arr)) {
        Piece *dep = m_board[y_dep * SIZE + x_dep];
        Piece *arr = m_board[y_arr * SIZE + x_arr];
        std::cout << "1" << std::endl;
        if (arr == nullptr) {
            std::cout << "2" << std::endl;
            if (dep->canMove(x_dep, y_dep, x_arr, y_arr) == 1) {
                dep->setTravel(x_dep, y_dep, x_arr, y_arr);
                int nbr_pieces{0};
                vector<int> v = dep->getTravel();
                for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
                    if (m_board[*it] != nullptr)
                        nbr_pieces += 1;
                std::cout << "3" << std::endl;
                if (nbr_pieces == 0) {
                    m_board[y_dep * SIZE + x_dep] = nullptr;
                    m_board[y_arr * SIZE + x_arr] = dep;

                    std::cout << "bouger" << std::endl;
                    return true;
                } else if (nbr_pieces == 1) {
                    int i = dep->getTravel().back();
                    //if (m_board[i] != nullptr) {
                    m_board[y_dep * SIZE + x_dep] = nullptr;
                    m_board[y_arr * SIZE + x_arr] = dep;
                    m_board[i] = nullptr;
                    std::cout << "manger" << std::endl;
                    return true;
                    //}
                }
            }
        }

        return false;
    }
}

/*bool GameDame::movePiece(int x_dep, int y_dep, int x_arr, int y_arr) {
    if (Game::movePiece(x_dep, y_dep, x_arr, y_arr)) {
        Piece* dep = m_board[y_dep * SIZE + x_dep];
        Piece* arr = m_board[y_arr * SIZE + x_arr];
        std::cout << "1" << std::endl;
        if (arr == nullptr) {
            std::cout << "2" << std::endl;
            if (dep->canMove(x_dep, y_dep, x_arr, y_arr) == 1) {
                std::cout << "3" << std::endl;
                if (arr == nullptr) {
                    m_board[y_dep * SIZE + x_dep] = nullptr;
                    m_board[y_arr * SIZE + x_arr] = dep;
                    std::cout << "bouger" << std::endl;
                    return true;
                }
            } else {
                int i = dep->getTravel(x_dep, y_dep, x_arr, y_arr).back();
                if (m_board[i] != nullptr) {
                    m_board[y_dep * SIZE + x_dep] = nullptr;
                    m_board[y_arr * SIZE + x_arr] = dep;
                    m_board[i] = nullptr;
                    std::cout << "manger" << std::endl;
                    return true;
                }
            }
    } else
        return false;
}*/

GameDame::GameDame(int id_test) : Game(SIZE) {
    initGame();
    getTest(id_test);
}

void GameDame::getTest(int id_test) {
    Game::getTest(id_test, "<Dame>\r");
}


