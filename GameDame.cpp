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
    }/*

    m_board[6 * SIZE + 4] = nullptr;
    m_board[7 * SIZE + 5] = nullptr;
    m_board[8 * SIZE + 6] = nullptr;
    m_board[9 * SIZE + 7] = nullptr;*/
   // m_board[4 * SIZE + 2] = new PawnForDame(BLACK);

}

void GameDame::checkPawnTransform(int x, int y) {
    if ((m_board[y * m_size + x]->getColor() == Game::WHITE && y == m_size - 1)
        || (m_board[y * m_size + x]->getColor() == Game::BLACK && y == 0)) {
        Piece *p = m_board[y * m_size + x];
        m_board[y * m_size + x] = new DameForDame(p);
        delete p;
    }
}

bool GameDame::movePiece2(int x_dep, int y_dep, int x_arr, int y_arr, bool testCanEat) {
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
            if (canMove == 1 && nbr_pieces == 0) {
                std::cout << "3" << std::endl;
                if (!testCanEat || (testCanEat && !canEat())) {
                    if (arr == nullptr) {
                        move = true;
                        std::cout << "bouger" << std::endl;
                    }
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

bool GameDame::movePiece(int x_dep, int y_dep, int x_arr, int y_arr) {
    return movePiece2(x_dep, y_dep,x_arr, y_arr, true);
}

bool GameDame::canEat() {
    Piece* p;
    for (int i = 0; i < m_size * m_size; i++) {
        p = m_board[i];
        if (p != nullptr) {
            if (p->getColor() == m_curP) {
                if (canEat(i % m_size, i / m_size))
                    return true;
            }
        }
    }

    return false;
}

bool GameDame::canEat(int x, int y) {
    Piece* p = m_board.at(y * m_size + x);
    vector<int> moves = getPossibleMove2(x, y, false);
    vector<int> travel;
    for (int i{0}; i < moves.size(); i++) {
        p->setTravel(x, y, moves[i] % m_size, moves[i] / m_size);
        travel = p->getTravel();
        for (int j{0}; j < travel.size(); j++) {
            if (m_board.at(travel.at(j)) != nullptr &&
                m_board.at(travel.at(j))->getColor() != p->getColor()) {
                return true;
            }
        }
    }

    return false;
}

vector<int> GameDame::getPossibleMove(int current_x, int current_y) {
    return getPossibleMove2(current_x, current_y, true);
}

vector<int> GameDame::getPossibleMove2(int current_x, int current_y, bool testCanEat) {
    vector<int> moves;
    Piece *current_piece = m_board.at(current_y * m_size + current_x);
    if (current_piece != nullptr) {
        vector<int> res = current_piece->getPossibleMoves(current_x, current_y);
        for (int i = 0; i < res.size(); i++) {
            int tmp = res.at(i);
            int x = tmp % m_size;
            int y = tmp / m_size;
            if (movePiece2(current_x, current_y, x, y, testCanEat)) {
                moves.push_back(tmp);
            }
        }
    }
    return moves;
}

bool GameDame::endGame() {
    Piece* p;
    int color{WHITE};
    if (m_curP == WHITE)
        color = BLACK;
    for (int i = 0; i < m_board.size(); i++) {
        p = m_board.at(i);
        if (p != nullptr) {
            if (p->getColor() == color)
                return false;
        }
    }

    return true;
}