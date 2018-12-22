//
// Created by nil on 21/12/2018.
//

#ifndef BOARDGAME_BOARD_H
#define BOARDGAME_BOARD_H

#include <vector>
#include "Piece.h"


class Board {
private:
    static int const WHITE = 1;
    static int const BLACK = 0;

    static const int m_size = 8;
    std::vector<Piece*> m_board;

public:
    Board();
    void affichage();
    void initBoard(int jeu);
    void movePiece(int x_dep, int y_dep, int x_arr, int y_arr);
};


#endif //BOARDGAME_BOARD_H
