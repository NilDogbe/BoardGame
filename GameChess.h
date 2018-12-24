//
// Created by nil on 23/12/2018.
//

#ifndef BOARDGAME_CHESS_H
#define BOARDGAME_CHESS_H

#include "Game.h"

class GameChess : public Game {

protected:
    void initGameChess();
    const static int BLACK = 31;
    const static int WHITE = 30;

public:
    GameChess();
    virtual void affichage();
    virtual bool movePiece(int x_dep, int y_dep, int x_arr, int y_arr);



};


#endif //BOARDGAME_CHESS_H
