//
// Created by netbook on 23/12/18.
//

#include "GameDame.h"
#include "PawnForDame.h"
#include "DameForDame.h"
#include "Parser.h"
#include <iostream>

using namespace std;

GameDame::GameDame() : Game{SIZE, Game::GAME_DAME}, forceToEat{false} {
}

void GameDame::init() {
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

void GameDame::checkPawnTransform(int x, int y) {
    if ((m_board[y * m_size + x]->getColor() == Game::WHITE && y == m_size - 1)
        || (m_board[y * m_size + x]->getColor() == Game::BLACK && y == 0)) {
        Piece *p = m_board[y * m_size + x];
        m_board[y * m_size + x] = new DameForDame(p);
        delete p;
    }
}

bool GameDame::movePiece(int x_dep, int y_dep, int x_arr, int y_arr) {
    if (Game::movePiece(x_dep, y_dep, x_arr, y_arr)) {
        Piece *dep = m_board[y_dep * m_size + x_dep];
        Piece *arr = m_board[y_arr * m_size + x_arr];
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
            if (canMove == 1 && nbr_pieces == 0 && !forceToEat) {
                std::cout << "3" << std::endl;
                if (arr == nullptr) {
                    move = true;
                    std::cout << "bouger" << std::endl;
                }
            } else if (canMove == 2 || nbr_pieces == 1) {
                vector<int> travel = dep->getTravel();
                for (int i = 0; i < travel.size(); i++) {
                    if (m_board.at(travel.at(i)) != nullptr &&
                        m_board.at(travel.at(i))->getColor() != dep->getColor()) {
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

void GameDame::setForceToEat(bool forceToEat) {
    this->forceToEat = forceToEat;
}
