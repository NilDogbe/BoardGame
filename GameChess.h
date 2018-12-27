//
// Created by nil on 23/12/2018.
//

#ifndef BOARDGAME_CHESS_H
#define BOARDGAME_CHESS_H

#include "Game.h"

class GameChess : public Game {

protected:
    void initGameChess();
    const static int SIZE = 8;
    int m_caseBlackKing = (m_size - 1) * m_size + 5; // 61
    int m_caseWhitekKing = m_size * 0 + 3;


public:
    GameChess();
    GameChess(int id_test);
    GameChess(std::string fileName, int id);
    void getTest(int id_test);
    virtual bool movePiece(int x_dep, int y_dep, int x_arr, int y_arr);


};


#endif //BOARDGAME_CHESS_H
