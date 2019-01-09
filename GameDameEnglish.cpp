//
// Created by netbook on 30/12/18.
//

#include "GameDameEnglish.h"
#include "PawnForDameEnglish.h"
#include "DameForDameEnglish.h"

GameDameEnglish::GameDameEnglish() : GameDame() {
    m_name = Game::GAME_DAME_ENGLISH;
    m_size = GameDameEnglish::SIZE;
};

void GameDameEnglish::init() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < SIZE; j++) {
            if ((i + j) % 2 == 0)
                m_board[i * SIZE + j] = new DameForDameEnglish(WHITE);
        }
    }
    for (int i = SIZE - 1; i >= SIZE - 3; i--) {
        for (int j = 0; j < SIZE; j++) {
            if ((i + j) % 2 == 0)
                m_board[i * SIZE + j] = new PawnForDameEnglish(BLACK);
        }
    }

    /*m_board[6 * SIZE + 4] = nullptr;
    m_board[7 * SIZE + 5] = nullptr;*/

}

void GameDameEnglish::checkPawnTransform(int x, int y) {
    if ((m_board[y * m_size + x]->getColor() == Game::WHITE && y == m_size - 1)
        || (m_board[y * m_size + x]->getColor() == Game::BLACK && y == 0)) {
        Piece *p = m_board[y * m_size + x];
        m_board[y * m_size + x] = new DameForDameEnglish(p);
        delete p;
    }
}