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
    const static int BLACK = 31;
    const static int WHITE = 30;
    const int m_p1 = WHITE;
    const int m_p2 = BLACK;
    int m_curP = WHITE;
    bool m_endGame;
    Game(int size);

public:
    virtual void affichage();
    virtual bool movePiece(int x_dep, int y_dep, int x_arr, int y_arr);
    void getTest(int idTest, std::string idBalise);


};


#endif //BOARDGAME_BOARD_H
