//
// Created by nil on 21/12/2018.
//

#ifndef BOARDGAME_PIECE_H
#define BOARDGAME_PIECE_H
using namespace std;

#include <string>

class Piece {

    private:
    string m_name;


    public:
    Piece(string name);
    std::string getNom();



};


#endif //BOARDGAME_PIECE_H
