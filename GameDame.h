//
// Created by netbook on 23/12/18.
//

#ifndef BOARDGAME_DAME_H
#define BOARDGAME_DAME_H


#include "Game.h"

class GameDame : public Game {
private:
protected:
    virtual void initGame();
public:
    const static int SIZE = 10;
    const static int BLACK = 37;
    const static int WHITE = 30;
    GameDame();
    GameDame(int id_test);
    void getTest(int id_test);

    virtual bool movePiece(int x_dep, int y_dep, int x_arr, int y_arr);
};


#endif //BOARDGAME_DAME_H
