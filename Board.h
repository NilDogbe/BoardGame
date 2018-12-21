//
// Created by nil on 21/12/2018.
//

#ifndef BOARDGAME_BOARD_H
#define BOARDGAME_BOARD_H

#include "Case.h"
#include <vector>


class Board {
private:
    static int const WHITE = 1;
    static int const BLACK = 0;

    static const int m_size = 8;
    std::vector<Case> m_board;

public:
    Board();
    void affichage();
    void initBoard(int jeu);
};


#endif //BOARDGAME_BOARD_H
