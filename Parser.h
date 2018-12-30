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
    static const int NBR_TEST_CHESS = 1;
    static const int NBR_TEST_DAME = 1;
    static const int NBR_TEST_MAKRUK = 1;
    static const int NBR_TEST_DAME_ENGLISH = 1;

    std::vector<std::vector<int>> ReadScipt(std::string flux, int id, std::string idBalise);
    static std::vector<std::string> getLines(std::string fileName);
};


#endif //BOARDGAME_PARSER_H
