//
// Created by netbook on 23/12/18.
//

#include "GameDame.h"
#include "PawnForDame.h"
#include "DameForDame.h"
#include "Parser.h"
#include <iostream>

using namespace std;

GameDame::GameDame() : Game{SIZE, Game::GAME_DAME} {
    initGame();
    start();
}

GameDame::GameDame(string fileName, int id) : Game{fileName, id, SIZE, Game::GAME_DAME} {
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

    m_board[6 * SIZE + 4] = nullptr;
    m_board[7 * SIZE + 5] = nullptr;
    m_board[8 * SIZE + 6] = nullptr;
    m_board[9 * SIZE + 7] = nullptr;
}

/*bool GameDame::movePiece(int x_dep, int y_dep, int x_arr, int y_arr) {
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
                if (nbr_pieces <= 1) {
                    if (nbr_pieces == 0) {
                        std::cout << "bouger" << std::endl;
                    } else if (nbr_pieces == 1) {
                        int i = dep->getTravel().back();
                        m_board[i] = nullptr;
                        std::cout << "manger" << std::endl;
                    }
                    m_board[y_dep * SIZE + x_dep] = nullptr;
                    m_board[y_arr * SIZE + x_arr] = dep;
                    checkPawnTransform(x_arr, y_arr);
                    return true;
                }
            }
        }

        return false;
    }
}*/

void GameDame::checkPawnTransform(int x, int y) {
    if ((m_curP == Game::WHITE && y == SIZE - 1) || (m_curP == Game::BLACK && y == 0)) {
        Piece *p = m_board[y * SIZE + x];
        m_board[y * SIZE + x] = new DameForDame(p);
        delete p;
    }
}

bool GameDame::movePiece(int x_dep, int y_dep, int x_arr, int y_arr) {
    if (Game::movePiece(x_dep, y_dep, x_arr, y_arr)) {
        Piece *dep = m_board[y_dep * SIZE + x_dep];
        Piece *arr = m_board[y_arr * SIZE + x_arr];
        std::cout << "1" << std::endl;
        if (arr == nullptr) {
            std::cout << "2" << std::endl;
            int canMove{dep->canMove(x_dep, y_dep, x_arr, y_arr)};
            int nbr_pieces{0};
            dep->setTravel(x_dep, y_dep, x_arr, y_arr);
            vector<int> v = dep->getTravel();
            for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
                if (m_board[*it] != nullptr)
                    nbr_pieces += 1;
            bool move{false};
            if (canMove == 1 && nbr_pieces == 0) {
                std::cout << "3" << std::endl;
                if (arr == nullptr) {
                    move = true;
                    std::cout << "bouger" << std::endl;
                }
            } else if (canMove == 2 || nbr_pieces == 1) {
                vector<int> travel = dep->getTravel();
                for(int i = 0;i<travel.size();i++) {
                    if (m_board.at(travel.at(i)) != nullptr && m_board.at(travel.at(i))->getColor() != dep->getColor()) {
                        move = true;
                        break;
                    }
                }
            }

            if (move) {
                return true;
            }
        }
    }

    return false;
}

GameDame::GameDame(int
                   id_test) : Game(SIZE, Game::GAME_DAME) {
    initGame();
    getTest(id_test);
}

void GameDame::getTest(int id_test) {
    Game::getTest(id_test, "<Dame>");
}

