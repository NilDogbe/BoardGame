//
// Created by nil on 24/12/2018.
//

#ifndef BOARDGAME_PARSER_H
#define BOARDGAME_PARSER_H
#include<fstream>
#include <vector>
#include "string.h"

class Parser {
private:
    std::vector<std::string> m_vectorOfMove;
public:
    std::vector<std::vector<int>> ReadScipt(std::string flux, int id, std::string idBalise);

};


#endif //BOARDGAME_PARSER_H
