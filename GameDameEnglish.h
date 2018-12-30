//
// Created by netbook on 30/12/18.
//

#ifndef BOARDGAME_GAMEDAMEENGLISH_H
#define BOARDGAME_GAMEDAMEENGLISH_H


#include "GameDame.h"

class GameDameEnglish : public GameDame {
public:
    GameDameEnglish();
protected:
    virtual void init();
public:
    const static int SIZE = 8;
    virtual void checkPawnTransform(int x, int y);
};


#endif //BOARDGAME_GAMEDAMEENGLISH_H
