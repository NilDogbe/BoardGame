//
// Created by netbook on 23/12/18.
//

#ifndef BOARDGAME_DAME_H
#define BOARDGAME_DAME_H

#include "Game.h"

class GameDame : public Game {

protected:
    virtual void initGame();
public:
    void checkPawnTransform(int x, int y);
    const static int BLACK = 31;
    const static int WHITE = 30;
    const static int SIZE = 10;
    GameDame();
    GameDame(std::string fileName, int id);
    GameDame(int id_test);
    void getTest(int id_test);
    virtual bool movePiece(int x_dep, int y_dep, int x_arr, int y_arr);
};


#endif //BOARDGAME_DAME_H
