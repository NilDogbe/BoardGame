//
// Created by nil on 21/12/2018.
//

#ifndef BOARDGAME_BOARD_H
#define BOARDGAME_BOARD_H

#include <vector>
#include "Piece.h"


class Game {
protected:
    const int m_size;
    std::vector<Piece*> m_board;

public:
    Game(int size);
    virtual void affichage();
    virtual bool movePiece(int x_dep, int y_dep, int x_arr, int y_arr);

};


#endif //BOARDGAME_BOARD_H
