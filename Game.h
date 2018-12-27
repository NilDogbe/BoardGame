//
// Created by nil on 21/12/2018.
//

#ifndef BOARDGAME_BOARD_H
#define BOARDGAME_BOARD_H

#include <vector>
#include "Piece.h"

class Game {
private:
    const std::string m_name;
protected:
    const int m_size;
    std::vector<Piece *> m_board;
    const static int BLACK = 31;
    const static int WHITE = 30;
    const int m_p1 = WHITE;
    const int m_p2 = BLACK;
    int m_curP = WHITE;
    bool m_endGame;

    Game(int size, std::string name);

    const static std::string GAME_DAME;
    const static std::string GAME_CHESS;

public:
    virtual void affichage();

    virtual bool movePiece(int x_dep, int y_dep, int x_arr, int y_arr);

    void getTest(int idTest, std::string idBalise);

    void getPossibleMove(int current_x, int current_y);

    int division(int x, int modulo);

    void move(int x_dep, int y_dep, int x_arr, int y_arr);
    void start();
    int getColor(int x, int y);

    void save();

    Game* initWithFile(std::string file);
};


#endif //BOARDGAME_BOARD_H
