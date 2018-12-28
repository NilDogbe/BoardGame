//
// Created by nil on 21/12/2018.
//

#ifndef BOARDGAME_BOARD_H
#define BOARDGAME_BOARD_H

#include <vector>
#include "Piece.h"
#include "Move.h"

class Game {
private:
    const std::string m_name;
protected:
    const int m_size;
    std::vector<Piece *> m_board;
    const int m_p1 = WHITE;
    const int m_p2 = BLACK;
    int m_curP = WHITE;
    bool m_endGame;

    Game(int size, std::string name);

    const static std::string GAME_DAME;
    const static std::string GAME_CHESS;

    Game(std::string fileName, int id, int size, std::string name);
    std::vector<Move> moves;

public:
    const static int BLACK = 31;
    const static int WHITE = 30;
    virtual void affichage();
    virtual bool movePiece(int x_dep, int y_dep, int x_arr, int y_arr);
    void getTest(int idTest, std::string idBalise);
    std::vector<int> getPossibleMove(int current_x, int current_y);
    void move(int x_dep, int y_dep, int x_arr, int y_arr);
    void start();
    int getColor(int x, int y);
    std::vector<std::vector<int>> getCurrentPieces();
    void chooseMove();
    void save();
    void back();
};


#endif //BOARDGAME_BOARD_H
