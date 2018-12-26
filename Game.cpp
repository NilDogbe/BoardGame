//
// Created by nil on 21/12/2018.
//

#include "Game.h"
#include "Parser.h"
#include <iostream>

using namespace std;

Game::Game(int size) : m_board(size * size, nullptr), m_size(size), m_endGame{0}{
}

void Game::affichage() {
    for (int i = m_size - 1; i >= 0; i--) {
        cout<<i<<" ";
        for (int j = 0; j < m_size; j++) {
            Piece *p = m_board[i * m_size + j];
            string s = "m  ";
            if (p != nullptr) {
                s = ";" + to_string(p->getColor()) + "m " + p->toString();
            }
            if ((i + j) % 2 == 0)
                cout << "\033[46;1" << s <<  " \033[0m";//noir
            else
                cout << "\033[47;1" << s << " \033[0m";//blanc
            //[31;1;4;5;7mLe texte[0m
        }
        cout << endl;
    }
    cout << "   ";

    for (int i = 0; i < m_size; i++) {
        cout << i << "  ";
    }
}

bool Game::movePiece(int x_dep, int y_dep, int x_arr, int y_arr) {
    Piece *piece_dep = m_board.at(y_dep * m_size + x_dep);
    Piece *piece_arr = m_board.at(y_arr * m_size + x_arr);
    // cout << (piece_dep->canMove(x_dep, y_dep, x_arr, y_arr) == 2) << "eeeeeee";

    if (!(y_arr < m_size && y_arr >= 0 && x_arr < m_size && x_dep >= 0)) { // hors des  limites ?
        cout << "G1" << endl;
        return false;
    }
    else if (piece_dep == nullptr) // piece existe
        return false;
    else if (piece_dep->canMove(x_dep, y_dep, x_arr, y_arr) == 0) // piece existe
        return false;
    else if ((piece_arr != nullptr) && (piece_dep->getColor() == piece_arr->getColor()) ){ //manger une piece de meme couleur
        return false;
    }
    else return true;


}

void Game::getTest(int idTest, std::string idBalise) {

    Parser p;
    vector<vector<int>> vector = p.ReadScipt("D:\\Work\\Git\\BoardGame\\Game_Processing\\Script_Test.txt", idTest,idBalise);
    int acc = 0;
    string next;
    while (acc >= 0 && acc < vector.size() && !m_endGame) {

        getline(cin, next);
        movePiece(vector[acc][0], vector[acc][1], vector[acc][2], vector[acc][3]);
        acc++;
        affichage();
        cout<<"endgame: "<<m_endGame;
        cout << vector.size()<<": "<< acc;

    }
   // acc = 0;
    cout<<"fin du jeu car endgame="<<m_endGame<< "et acc = "<< acc<<endl;

}





