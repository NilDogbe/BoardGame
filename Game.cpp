//
// Created by nil on 21/12/2018.
//

#include "Game.h"
#include "Parser.h"
#include "PawnForChess.h"
#include "GameDame.h"
#include "GameChess.h"
#include "Piece.h"
#include "PawnForDame.h"
#include "DameForDame.h"
#include <iostream>

using namespace std;
class PawnForDame;

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
    } else if (piece_dep == nullptr) // piece existe
        return false;
    else if (piece_dep->canMove(x_dep, y_dep, x_arr, y_arr) == 0) // piece existe
        return false;
    else if ((piece_arr != nullptr) &&
             (piece_dep->getColor() == piece_arr->getColor())) { //manger une piece de meme couleur
        return false;
    } else return true;
}

void Game::getPossibleMove(int current_x, int current_y) {
    cout << "ca vas dedans" << endl;
    Piece *current_piece = m_board.at(current_y * m_size + current_x);
    if (current_piece != nullptr) {
        vector<int> res = current_piece->getPossibleMoves(current_x, current_y);
        int s = res.size();
        for (int i = 0; i < res.size(); i++) {
            int tmp = res.at(i);
            int x = tmp % m_size;
            int y = division(tmp, m_size);
            cout << "tmp = " << tmp;
            cout << "x = " << x;
            cout << "y = " << y;
            if (movePiece(current_x, current_y, x, y)) {
                cout << "La Piece " << current_piece->toString() << " peux aller " << x << " " << y << " ." << endl;
            }
        }
    }
}

void Game::move(int x_dep, int y_dep, int x_arr, int y_arr) {
    if (movePiece(x_dep, y_dep, x_arr, y_arr)) {
        Piece *piece_dep = m_board.at(y_dep * m_size + x_dep);
        //if(piece_dep->toString() == "P")
        //  ((PawnForChess*) piece_dep)->setFirstMove();
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
    vector<vector<int>> vector = p.ReadScipt(
            "C:\\Users\\Leo\\CLionProjects\\BoardGame\\Game_Processing\\Script_Test.txt", idTest, idBalise);
    int acc = 0;
    string sens;
    while (acc >= 0 && acc < vector.size() && !m_endGame) {

        getline(cin, sens);
        getPossibleMove(vector[acc][0], vector[acc][1]);
        move(vector[acc][0], vector[acc][1], vector[acc][2], vector[acc][3]);

        acc++;
        affichage();
        cout << "endgame: " << m_endGame;
        cout << vector.size() << ": " << acc;

    }
    cout << "fin du jeu" << endl;

}

void Game::save() {
    string mon_fichier = "../Game_Processing/save.txt";

    ofstream fichier(mon_fichier.c_str(), ios::out | ios::trunc);
    if (fichier) {
        if (m_name.compare(GAME_DAME) == 0)
            fichier << m_name << " \n";

        if (m_curP == WHITE)
            fichier << "WHITE\n";
        else
            fichier << "BLACK\n";

        int size = m_size * m_size;
        for (int i = 0; i < size; i++) {
            Piece *p = m_board[i];
            if (p != nullptr) {
                fichier << p->toString();

                if (p->getColor() == WHITE)
                    fichier << "W";
                else
                    fichier << "B";
            } else
                fichier << "N";

            if (i != size - 1)
                fichier << ", ";
        }

        fichier.close();
    } else
        cerr << "Erreur à l'ouverture !" << endl;
}


/*Game* Game::initGameWithFile(file) {
    ifstream fichier("../Game_Processing/save.txt", ios::in);

    if (fichier) {
        string s;

        for (int i{0}; i < 2; i++) {
            getline(fichier, s);
            if (i == 0) {
                size_t pos{0};
                string token;
                string delimiter = ", ";
                while ((pos = s.find(delimiter)) != string::npos) {
                    token = s.substr(0, pos);
                    Piece *p{nullptr};
                    if (token.size() == 2) {
                        switch (token.at(0)) {
                            case 'P':
                                p = new PawnForDame(token.at(1));
                            case 'D':
                                p = new DameForDame(token.at(1));
                        }
                    }
                    game->m_board.push_back(p);
                    cout << token << endl;
                    s.erase(0, pos + delimiter.length());
                }
            } else {
                if (s.compare("WHITE") == 0)
                    game->m_curP = WHITE;
                else
                    game->m_curP = BLACK;
            }
        }
        fichier.close();

    } else
        cerr << "Impossible d'ouvrir le fichier !" << endl;
}*/