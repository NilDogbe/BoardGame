//
// Created by nil on 21/12/2018.
//

#ifndef BOARDGAME_PIECE_H
#define BOARDGAME_PIECE_H

#include <string>

class Piece {

    private:
    string m_name;


    public:
    Piece(string name);
    string getNom();


};


#endif //BOARDGAME_PIECE_H
