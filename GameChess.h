//
// Created by nil on 23/12/2018.
//

#ifndef BOARDGAME_CHESS_H
#define BOARDGAME_CHESS_H

#include "Game.h"

class GameChess : public Game {

protected:
    void initGameChess();

public:
    GameChess();
    virtual void affichage();
    virtual bool movePiece(int x_dep, int y_dep, int x_arr, int y_arr);



};


#endif //BOARDGAME_CHESS_H
