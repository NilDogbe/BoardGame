//
// Created by nil on 21/12/2018.
//

#include "Game.h"
#include "Parser.h"
#include "GameDame.h"
#include "GameChess.h"
#include "Piece.h"
#include "PawnForDame.h"
#include "DameForDame.h"
#include "PawnForChess.h"
#include "Tower.h"
#include "King.h"
#include "Knight.h"
#include "Queen.h"
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

    if (x_dep >= m_size || x_dep < 0 || y_dep >= m_size || y_dep < 0 || x_arr >= m_size || x_arr < 0 ||
        y_arr >= m_size || y_arr < 0)  // hors des  limites ?
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
    int nb_move = 0;
    // cout<< "ca vas dedans" <<endl;
    Piece *current_piece = m_board.at(current_y * m_size + current_x);
    if (current_piece != nullptr) {
        vector<int> res = current_piece->getPossibleMoves(current_x, current_y);
        int s = res.size();
        for (int i = 0; i < res.size(); i++) {
            int tmp = res.at(i);
            int x = tmp % m_size;
            int y = tmp / m_size;
            /* cout <<"tmp = " << tmp;
             cout <<"x = " << x;
             cout <<"y = " << y << endl;*/
            if (movePiece(current_x, current_y, x, y)) {
                cout << "La Piece " << current_piece->toString() << " peux aller " << x << " " << y << " ." << endl;
                nb_move++;
            }
        }
    }
    cout << "Il y a " << nb_move << " move possible." << endl;
}

void Game::move(int x_dep, int y_dep, int x_arr, int y_arr) {
    cout << "Dans move " << m_name << endl;
    if (movePiece(x_dep, y_dep, x_arr, y_arr)) {
        Piece *piece_dep = m_board.at(y_dep * m_size + x_dep);
        Piece *piece_arr = m_board.at(y_arr * m_size + x_arr);
        if (m_name.compare(Game::GAME_CHESS) == 0) {
            if (piece_dep->toString() == "P")
                ((PawnForChess *) piece_dep)->setFirstMove();
            if (piece_arr != nullptr && piece_arr->toString().compare("K") == 0) {
                cout << "aaaaaaaaaaaaaaa";
                m_endGame = true;
                return;
            }
            m_board.at(y_dep * m_size + x_dep) = nullptr;
            m_board.at(y_arr * m_size + x_arr) = piece_dep;
        } else if (m_name.compare(Game::GAME_DAME) == 0) {
            vector<int> travel = piece_dep->getTravel();
            for (int i = 0; i < travel.size(); i++) {
                if (m_board.at(travel.at(i)) != nullptr) {
                    cout << "Les dames ca fait peur" << endl;
                    m_board.at(travel.at(i)) = nullptr;
                    break;
                }
            }

            cout << "Les dames c'est trop bien" << endl;
            m_board.at(y_dep * m_size + x_dep) = nullptr;
            m_board.at(y_arr * m_size + x_arr) = piece_dep;
            ((GameDame *) this)->checkPawnTransform(x_arr, y_arr);
        }
    }
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
             << vector[acc][2] << "," << vector[acc][3] << endl
             << " numCoup" << acc << endl;
        acc++;


    }
    cout << "fin du jeu" << endl;

}

void Game::save() {
    string mon_fichier = "../Game_Processing/save.txt";

    ofstream fichier(mon_fichier.c_str(), ios::out | ios::app);
    if (fichier) {
        fichier << "<Game>\n";

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

            //if (i != size - 1)
            fichier << ";";
        }

        fichier << "\n</Game>\n";

        fichier.close();
    } else
        cerr << "Erreur à l'ouverture !" << endl;
}

Game::Game(string fileName, int id, int size, string name) : Game{size, name} {
    vector<string> vector{Parser::getLines(fileName)};

    for (int i{0}; i < vector.size(); i++) {
        string s = vector.at(i);
        if (s.compare("<Game>") == 0 && id == 0) {
            for (int j{0}; j < 2; j++) {
                s = vector.at(i + j + 1);
                if (j == 0) {
                    if (s.compare("WHITE") == 0)
                        m_curP = WHITE;
                    else
                        m_curP = BLACK;
                } else {
                    size_t pos{0};
                    string token;
                    string delimiter = ";";
                    int k{0};
                    while ((pos = s.find(delimiter)) != string::npos) {
                        token = s.substr(0, pos);
                        cout << token << endl;
                        Piece *p{nullptr};
                        if (token.size() == 2) {
                            int color{0};
                            if (token.at(1) == 'B')
                                color = BLACK;
                            else
                                color = WHITE;
                            switch (token.at(0)) {
                                case 'O':
                                    p = new PawnForDame(color);
                                    break;
                                case 'D':
                                    p = new DameForDame(color);
                                    break;
                                case 'K':
                                    p = new King(color);
                                    break;
                                case 'C':
                                    p = new Knight(color);
                                    break;
                                case 'P':
                                    p = new PawnForChess(color);
                                    break;
                                case 'Q':
                                    p = new Queen(color);
                                    break;
                                case 'T':
                                    p = new Tower(color);
                                    break;
                            }
                        }
                        m_board[k] = (p);
                        k++;
                        //cout << token << endl;
                        s.erase(0, pos + delimiter.length());
                    }
                }
            }
        } else if (s.compare("</Game>") == 0)
            id--;
    }
}

void Game::start() {

    cout << "Exemple de coup: 'A1A2' -> Piont A1 se deplace en A2 " << endl
         << "Pour avoir la liste des coups d'une piece tapper (A1) : 'HELP A1' " <<endl
         << "Pour save une partie : 'SAVE'" <<endl;
    int x_dep(-1), y_dep(-1), x_arr(-1), y_arr(-1), x_help(-1), y_help(-1);
    string move("");


    do {
        cout << "*************************************************" << endl;


        if (m_curP == WHITE)
            cout << "Joueur: " << 1 << " a vous de jouer " << endl;
        else
            cout << "Joueur: " << 2 << " a vous de jouer " << endl;
        affichage();
        cout << endl;
        getline(cin, move);
        cout << move.substr(0, 4) << endl;
        if (move.size() == 4 || move.size() == 7) {

            x_dep = (int) (move.at(0)) - 65;
            y_dep = (int) (move.at(1)) - 48;
            x_arr = (int) (move.at(2)) - 65;
            y_arr = (int) (move.at(3)) - 48;

            if (move.substr(0, 4).compare("HELP") == 0) {
                if (move.size() == 7) {
                    x_help = (int) (move.at(5)) - 65;
                    y_help = (int) (move.at(6)) - 48;
                    if (x_help < 0 || x_help >= m_size || y_help < 0 || y_help >= m_size)
                        cout << "Hors limite recommencez" << endl;
                    else
                        getPossibleMove(x_help, y_help);
                    /* cout << "HELP:"<<x_help<<y_help<<endl;
                     cout << "HELP:"<<x_help<<y_help<< move.size()<<endl;*/
                }
            }
            else if (move.substr(0, 4).compare("SAVE") == 0){
                save();
            }
            else if (!movePiece(x_dep, y_dep, x_arr, y_arr)) {
                cout << "MOUVEMENT IMPOSSIBLE" << endl;
                cout << "Exemple de coup: 'A1A2' -> Piont A1 se deplace en A2 " << endl;
                cout << "Recommencez :" << endl;
            } else if (getColor(x_dep, y_dep) != m_curP) {
                cout << "Recommencez ce n'est pas votre couleur:" << endl;
            } else {
                cout << "OK" << endl;
                Game::move(x_dep, y_dep, x_arr, y_arr);
                if (m_curP == m_p1)
                    m_curP = m_p2;
                else m_curP = m_p1;
            }
        } else cout << "Pas Compris 2!" << endl;

    } while (!m_endGame);
    cout << "LA PARTIE EST FINIE" << endl
         << "LE GAGNANT EST: " << m_curP;

}

int Game::getColor(int x, int y) {
    m_board[y * m_size + x]->getColor();
}