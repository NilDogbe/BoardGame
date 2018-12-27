//
// Created by nil on 21/12/2018.
//

#include "Game.h"
#include "Parser.h"
#include "PawnForChess.h"
#include "GameDame.h"
#include "GameChess.h"
#include "Piece.h"
#include <iostream>

using namespace std;

string const Game::GAME_DAME = "DAME";
string const Game::GAME_CHESS = "CHESS";

Game::Game(int size, string name) : m_board(size * size, nullptr), m_size(size), m_endGame{0}, m_name{name} {
}

void Game::affichage() {
    for (int i = m_size - 1; i >= 0; i--) {
        cout << i << " ";
        for (int j = 0; j < m_size; j++) {
            Piece *p = m_board[i * m_size + j];
            string s = "m  ";
            if (p != nullptr) {
                s = ";" + to_string(p->getColor()) + "m " + p->toString();
            }
            if ((i + j) % 2 == 0)
                cout << "\033[46;1" << s << " \033[0m";//noir
            else
                cout << "\033[47;1" << s << " \033[0m";//blanc
            //[31;1;4;5;7mLe texte[0m
        }
        cout << endl;
    }
    cout << "   ";

    for (int i = 0; i < m_size; i++) {
        cout << (char) (i + 65) << "  ";
    }
}

bool Game::movePiece(int x_dep, int y_dep, int x_arr, int y_arr) {

    // cout << (piece_dep->canMove(x_dep, y_dep, x_arr, y_arr) == 2) << "eeeeeee";

    if (x_dep >= m_size || x_dep < 0 || y_dep >= m_size || y_dep < 0 || x_arr >= m_size || x_arr < 0 || y_arr >= m_size || y_arr < 0 )  // hors des  limites ?
        //  cout << "G1" << endl;
        return false;
        Piece *piece_dep = m_board.at(y_dep * m_size + x_dep);
        Piece *piece_arr = m_board.at(y_arr * m_size + x_arr);
     if (piece_dep == nullptr) // piece existe
        return false;
    else if (piece_dep->canMove(x_dep, y_dep, x_arr, y_arr) == 0) // piece existe
        return false;
    else if ((piece_arr != nullptr) &&
             (piece_dep->getColor() == piece_arr->getColor())) { //manger une piece de meme couleur
        return false;
    } else return true;
}

void Game::getPossibleMove(int current_x, int current_y) {
    //cout<< "ca vas dedans" <<endl;
    Piece *current_piece = m_board.at(current_y * m_size + current_x);
    if (current_piece != nullptr) {
        vector<int> res = current_piece->getPossibleMoves(current_x, current_y);
        int s = res.size();
        for (int i = 0; i < res.size(); i++) {
            int tmp = res.at(i);
            int x = tmp % m_size;
            int y = division(tmp, m_size);
            /* cout <<"tmp = " << tmp;
             cout <<"x = " << x;
             cout <<"y = " << y << endl;*/
            if (movePiece(current_x, current_y, x, y)) {
                cout << "La Piece " << current_piece->toString() << " peux aller " << x << " " << y << " ." << endl;
            }
        }
    }
}

void Game::move(int x_dep, int y_dep, int x_arr, int y_arr) {
    if (movePiece(x_dep, y_dep, x_arr, y_arr)) {
        Piece *piece_dep = m_board.at(y_dep * m_size + x_dep);
        if (piece_dep->toString() == "P")
            ((PawnForChess *) piece_dep)->setFirstMove();
        m_board.at(y_dep * m_size + x_dep) = nullptr;
        m_board.at(y_arr * m_size + x_arr) = piece_dep;
    }
}

int Game::division(int x, int modulo) {
    int res = 0;
    int tmp = x;
    while (tmp >= modulo) {
        tmp -= modulo;
        res++;
    }
    return res;
}

void Game::getTest(int idTest, std::string idBalise) {

    Parser p;
    //C:\Users\Leo\CLionProjects\BoardGame\Game_Processing\Script_Test.txt : leo
    // D:\Work\Git\BoardGame\Game_Processing\Script_Test.txt : nil

    vector<vector<int>> vector = p.ReadScipt("../Game_Processing/Script_Test.txt", idTest,
                                             idBalise);
    int acc = 0;
    string sens;

    while (acc >= 0 && acc < vector.size() && !m_endGame) {
        // cout<<"endgame:aaaaaaaaaaaaaaaa0 "<<m_endGame;

        getline(cin, sens);
        getPossibleMove(vector[acc][0], vector[acc][1]);
        // cout<<"endgame:aaaaaaaaaaaaaaaa2 "<<m_endGame;

        move(vector[acc][0], vector[acc][1], vector[acc][2], vector[acc][3]);
        // cout<<"endgame:aaaaaaaaaaaaaaaa3 "<<m_endGame;
        affichage();
        cout << endl << "endgame: " << m_endGame << endl;
        cout << vector[acc][0] << "," << vector[acc][1] << " -> "
        << vector[acc][2] << "," << vector[acc][3] <<endl
        <<" numCoup" << acc<<endl;
        acc++;


    }
    cout << "fin du jeu" << endl;

}

void Game::start() {

    cout << "Exemple de coup: 'A1A2' -> Piont A1 se deplace en A2 " << endl;
    int x_dep(-1),y_dep(-1),x_arr(-1),y_arr(-1);
    string move("");


        do{
            cout << "*************************************************" << endl;


            if (m_curP == WHITE)
                cout << "Joueur: " << 1 << " a vous de jouer " << endl;
            else
                cout << "Joueur: " << 2 << " a vous de jouer " << endl;
            affichage();
            cout<<endl;
            getline(cin, move);
            x_dep = (int)(move.at(0)) - 65;
            y_dep = (int)(move.at(1)) - 48;
            x_arr = (int)(move.at(2)) - 65;
            y_arr = (int)(move.at(3)) - 48;

            if(!movePiece(x_dep,y_dep,x_arr,y_arr)) {
                cout << "MOUVEMENT IMPOSSIBLE" << endl;
                cout << "Exemple de coup: 'A1A2' -> Piont A1 se deplace en A2 " << endl;
                cout << "Recommencez :" << endl;
            }
            else if(getColor(x_dep,y_dep) != m_curP){
                cout << "Recommencez ce n'est pas votre couleur:" << endl;
            }
            else{
                cout <<"OK" << endl;
                Game::move(x_dep,y_dep,x_arr,y_arr);
                if (m_curP == m_p1)
                    m_curP = m_p2;
                else m_curP = m_p1;
            }
        }while(!m_endGame);
        cout<<"LA PARTIE EST FINIE"<<endl
        <<"LE GAGNANT EST: "<< m_curP;

}

int Game::getColor(int x, int y) {
    m_board[y * m_size + x]->getColor();
}





