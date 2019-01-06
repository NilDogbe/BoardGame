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
    int m_nbrPlayers;
protected:
    std::string m_name;
    int m_size;
    std::vector<Piece*> m_board;
    const int m_p1 = WHITE;
    const int m_p2 = BLACK;
    int m_curP = WHITE;
    bool m_endGame;

    Game(int size, std::string name);
    virtual void init() = 0;

    std::vector<Move> moves;
public:
    const static std::string GAME_DAME;
    const static std::string GAME_CHESS;
    const static std::string GAME_MAKRUK;
    const static std::string GAME_DAME_ENGLISH;
    const static int BLACK = 31;
    const static int WHITE = 30;
    virtual void affichage();
    virtual bool movePiece(int x_dep, int y_dep, int x_arr, int y_arr);
    virtual std::vector<int> getPossibleMove(int current_x, int current_y);
    void move(int x_dep, int y_dep, int x_arr, int y_arr);
    void start(bool init, int nbrP);
    int getColor(int x, int y);
    std::vector<std::vector<int>> getCurrentPieces();
    void chooseMove();
    void save();
    void startTest(int id);
    void continueParty(int id);
    void startRobot();
    void getHelp(int current_x, int current_y);

    void back();
    static int getNumberSave(std::string);
    virtual ~Game();
};


#endif //BOARDGAME_BOARD_H
