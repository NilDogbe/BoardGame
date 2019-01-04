//
// Created by netbook on 23/12/18.
//

#ifndef BOARDGAME_DAME_H
#define BOARDGAME_DAME_H

#include "Game.h"

class GameDame : public Game {
protected:
    virtual void init();
public:
    const static int SIZE = 10;
    GameDame();
    virtual bool movePiece(int x_dep, int y_dep, int x_arr, int y_arr);
    virtual void checkPawnTransform(int x, int y);
    bool canEat(int x, int y);
};


#endif //BOARDGAME_DAME_H
