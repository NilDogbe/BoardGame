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
#include "Bishop.h"
#include "Tower.h"
#include "King.h"
#include "Knight.h"
#include "Queen.h"
#include <iostream>

using namespace std;

string const Game::GAME_DAME = "Dame";
string const Game::GAME_CHESS = "Chess";
string const Game::GAME_MAKRUK = "Makruk";
string const Game::GAME_DAME_ENGLISH = "DameEnglish";

Game::Game(int size, string name) : m_board(size * size, nullptr), m_size(size), m_endGame{0}, m_name{name} {
}

Game::~Game() {
    for (int i = 0; i < m_board.size(); i++) {
        if (m_board[i] != nullptr)
            delete m_board[i];
    }
    for (int i = 0; i < moves.size(); i++)
        moves[i].free();
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

vector<int> Game::getPossibleMove(int current_x, int current_y) {
    vector<int> moves;
    // cout<< "ca vas dedans" <<endl;
    Piece *current_piece = m_board.at(current_y * m_size + current_x);
    if (current_piece != nullptr) {
        vector<int> res = current_piece->getPossibleMoves(current_x, current_y);
        for (int i = 0; i < res.size(); i++) {
            int tmp = res.at(i);
            int x = tmp % m_size;
            int y = tmp / m_size;
            /*cout << "tmp = " << tmp;
            cout << "x = " << x;
            cout << "y = " << y << endl;*/
            if (movePiece(current_x, current_y, x, y)) {
                moves.push_back(tmp);
            }
        }
    }
    return moves;
}

void Game::move(int x_dep, int y_dep, int x_arr, int y_arr) {
   // cout << "Dans move " << m_name << endl;
    if (movePiece(x_dep, y_dep, x_arr, y_arr)) {
        bool changeCurP{true};
        Piece *piece_dep = m_board.at(y_dep * m_size + x_dep);
        Piece *piece_arr = m_board.at(y_arr * m_size + x_arr);
        Move move;
        move.setPieceMove(piece_dep->copy());
        move.setDep(x_dep, y_dep);
        move.setArr(x_arr, y_arr);
        move.setCurP(m_curP);
        cout << m_name << " ," << GAME_MAKRUK << endl;
        if (m_name.compare(Game::GAME_CHESS) == 0 || m_name.compare(Game::GAME_MAKRUK) == 0) {
            if (piece_dep->toString() == "P")
                ((PawnForChess *) piece_dep)->setFirstMove();
            if (piece_arr != nullptr && piece_arr->toString().compare("K") == 0) {
                m_endGame = true;
                return;
            }
            m_board.at(y_dep * m_size + x_dep) = nullptr;

            if (piece_dep->toString() == "P" && piece_dep->getColor() == WHITE && y_arr == (GameChess::SIZE - 1))
                m_board.at(y_arr * m_size + x_arr) = new Queen(WHITE);
            else if (piece_dep->toString() == "P" && piece_dep->getColor() == BLACK && y_arr == 0)
                m_board.at(y_arr * m_size + x_arr) = new Queen(BLACK);
            else
                m_board.at(y_arr * m_size + x_arr) = piece_dep;

            if (piece_arr != nullptr) {
                move.setPieceDelete(piece_arr->copy());
                move.setDel(x_arr, y_arr);
            }
        } else if (m_name.compare(Game::GAME_DAME) == 0 || m_name.compare(Game::GAME_DAME_ENGLISH) == 0) {
            bool manger{false};
            vector<int> travel = piece_dep->getTravel();
            for (int i{0}; i < travel.size(); i++) {
                if (m_board.at(travel.at(i)) != nullptr) {
                    cout << "Les dames ca fait peur" << endl;
                    move.setPieceDelete(m_board.at(travel.at(i))->copy());
                    move.setDel(travel.at(i) % m_size, travel.at(i) / m_size);
                    m_board.at(travel.at(i)) = nullptr;
                    manger = true;
                    break;
                }
            }

            if (((GameDame *) this)->endGame()) {
                m_endGame = true;
                return;
            }
            m_board.at(y_dep * m_size + x_dep) = nullptr;
            m_board.at(y_arr * m_size + x_arr) = piece_dep;
            ((GameDame *) this)->checkPawnTransform(x_arr, y_arr);

            if (manger && ((GameDame *) this)->canEat(x_arr, y_arr))
                changeCurP = false;
        }

        cout << endl << "endgame: " << m_endGame << endl;
        cout << x_dep << "," << y_dep << " -> "
             << x_arr << "," << y_arr << endl;
        moves.push_back(move);
        if (changeCurP) {
            if (m_curP == m_p1)
                m_curP = m_p2;
            else m_curP = m_p1;
        }
    }
}

vector<vector<int>> Game::getCurrentPieces() {
    vector<vector<int>> res;
    for (int i = 0; i < m_board.size(); i++) {
        if (m_board.at(i) != nullptr && m_board.at(i)->getColor() == m_curP) {
            if (getPossibleMove(i % m_size, i / m_size).size() > 0) {
                vector<int> x_y;
                x_y.push_back(i % m_size);
                x_y.push_back(i / m_size);
                res.push_back(x_y);
            }
        }
    }
    return res;
}

void Game::chooseMove() {
    srand(time(NULL));
    vector<vector<int>> pieces = getCurrentPieces();
    int rand = std::rand() % pieces.size();
    vector<int> piece_choosed = pieces.at(rand);
    vector<int> mooves = getPossibleMove(piece_choosed.at(0), piece_choosed.at(1));
    int rand2 = std::rand() % mooves.size();
    int moove_choosed = mooves.at(rand2);
    move(piece_choosed.at(0), piece_choosed.at(1), moove_choosed % m_size, moove_choosed / m_size);
    cout << "random " << rand << endl;
}

void Game::getHelp(int current_x, int current_y) {
    int nb_move = 0;
    Piece *current_piece = m_board.at(current_y * m_size + current_x);
    vector<int> possible_move = getPossibleMove(current_x, current_y);

    for (int i = 0; i < possible_move.size(); i++) {
        int tmp = possible_move.at(i);
        int x = tmp % m_size;
        int y = tmp / m_size;
        /*cout << "tmp = " << tmp;
        cout << "x = " << x;
        cout << "y = " << y << endl;*/

        cout << "La Piece " << current_piece->toString() << " peux aller en " << x << " " << y << " ." << endl;
        nb_move++;
    }
    cout << "Il y a " << nb_move << " move possible." << endl;

}

void Game::startTest(int idTest) {
    string idBalise{"<" + m_name + ">"};
    init();
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
        getHelp(vector[acc][0], vector[acc][1]);
        // cout<<"endgame:aaaaaaaaaaaaaaaa2 "<<m_endGame;

        move(vector[acc][0], vector[acc][1], vector[acc][2], vector[acc][3]);
        // cout<<"endgame:aaaaaaaaaaaaaaaa3 "<<m_endGame;
        affichage();
        /*cout << endl << "endgame: " << m_endGame << endl;
        cout << vector[acc][0] << "," << vector[acc][1] << " -> "
             << vector[acc][2] << "," << vector[acc][3] << endl*/
        cout << " numCoup" << acc << endl;
        acc++;


    }
    cout << "fin du jeu" << endl;

}

void Game::save() {
    string mon_fichier = "../Game_Processing/save.txt";

    ofstream fichier(mon_fichier.c_str(), ios::out | ios::app);
    if (fichier) {
        fichier << "<" << m_name << ">" << "\n";

        fichier << m_nbrPlayers << "\n";

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

                if (p->toString().compare("P") == 0) {
                    if (((PawnForChess *) p)->getFirstMove())
                        fichier << "T";
                    else
                        fichier << "F";
                }
            } else
                fichier << "N";

            //if (i != size - 1)
            fichier << ";";
        }

        fichier << "\n</" << m_name << ">\n";

        fichier.close();
    } else
        cerr << "Erreur à l'ouverture !" << endl;
}

void Game::continueParty(int id) {
    string fileName{"../Game_Processing/save.txt"};
    vector<string> vector{Parser::getLines(fileName)};

    int nbrPlayers{0};
    for (int i{0}; i < vector.size(); i++) {
        string s = vector.at(i);
        if (((s.compare("<" + m_name + ">") == 0) || (s.compare("<" + m_name + ">\r") == 0)) && id == 0) {
            for (int j{0}; j < 3; j++) {
                s = vector.at(i + j + 1);
                if (j == 0)
                    nbrPlayers = std::atoi(s.c_str());
                else if (j == 1) {
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
                        if (token.size() > 1) {
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
                                case 'B':
                                    p = new Bishop(color);
                                    break;
                                case 'K':
                                    p = new King(color);
                                    break;
                                case 'C':
                                    p = new Knight(color);
                                    break;
                                case 'P':
                                    if (token.at(2) == 'T')
                                        p = new PawnForChess(color, true);
                                    else
                                        p = new PawnForChess(color, false);
                                    break;
                                case 'Q':
                                    p = new Queen(color);
                                    break;
                                case 'T':
                                    p = new Tower(color);
                                    break;
                            }
                        }
                        m_board[k] = p;
                        k++;
                        //cout << token << endl;
                        s.erase(0, pos + delimiter.length());
                    }
                }
            }
        } else if (s.compare("</" + m_name + ">") == 0 || s.compare("</" + m_name + ">\r") == 0)
            id--;
    }

    cout << "AAA " << nbrPlayers << endl;
    start(false, nbrPlayers);
}

void Game::start(bool initialisation, int nbrP) {
    m_nbrPlayers = nbrP;
    if (initialisation)
        init();
    cout << "Exemple de coup: 'A1A2' -> Piont A1 se deplace en A2 " << endl
         << "Pour avoir la liste des coups d'une piece tapper (A1) : 'HELP A1' " << endl
         << "Pour save une partie : 'SAVE'" << endl;
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
        if (nbrP == 1 && m_curP == BLACK) {
            chooseMove();
        } else {
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
                            getHelp(x_help, y_help);
                        /* cout << "HELP:"<<x_help<<y_help<<endl;
                         cout << "HELP:"<<x_help<<y_help<< move.size()<<endl;*/
                    }
                } else if (move.substr(0, 4).compare("SAVE") == 0) {
                    save();
                } else if (move.substr(0, 4).compare("BACK") == 0) {
                    back();
                } else if (move.substr(0, 4).compare("QUIT") == 0) {
                    break;

                } else if (!movePiece(x_dep, y_dep, x_arr, y_arr)) {
                    cout << "MOUVEMENT IMPOSSIBLE" << endl;
                    cout << "Exemple de coup: 'A1A2' -> Piont A1 se deplace en A2 " << endl;
                    cout << "Recommencez :" << endl;
                } else if (getColor(x_dep, y_dep) != m_curP) {
                    cout << "Recommencez ce n'est pas votre couleur:" << endl;
                } else {
                    cout << "OK" << endl;
                    Game::move(x_dep, y_dep, x_arr, y_arr);
                    //  chooseMove();
                    /*  vector<vector<int>> tmp = getCurrentPieces();
                      for(int i=0;i<tmp.size();i++){
                          Piece* p = m_board.at((tmp.at(i)).at(1) * m_size + (tmp.at(i)).at(0));
                          cout << "Piece "<<p->toString()<<endl;
                      }*/
                }
            } else cout << "Pas Compris 2!" << endl;
        }

    } while (!m_endGame);
    cout << "LA PARTIE EST FINIE" << endl
         << "LE GAGNANT EST: " << m_curP;

}

void Game::startRobot() {
    init();


    cout << "Exemple de coup: 'A1A2' -> Piont A1 se deplace en A2 " << endl
         << "Pour avoir la liste des coups d'une piece tapper (A1) : 'HELP A1' " << endl
         << "Pour save une partie : 'SAVE'" << endl;
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
        if (move.compare("QUIT") == 0)
            break;
        else {
            cout << move.substr(0, 4) << endl;

            /* x_dep = (int) (move.at(0)) - 65;
             y_dep = (int) (move.at(1)) - 48;
             x_arr = (int) (move.at(2)) - 65;
             y_arr = (int) (move.at(3)) - 48;*/


            cout << "OK" << endl;
            //Game::move(x_dep, y_dep, x_arr, y_arr);
            chooseMove();
            /*  vector<vector<int>> tmp = getCurrentPieces();
              for(int i=0;i<tmp.size();i++){
                  Piece* p = m_board.at((tmp.at(i)).at(1) * m_size + (tmp.at(i)).at(0));
                  cout << "Piece "<<p->toString()<<endl;
              }*/
        }
    } while (!m_endGame);

    cout << "LA PARTIE EST FINIE" << endl
         << "LE GAGNANT EST: " << m_curP;


}

int Game::getColor(int x, int y) {
    m_board[y * m_size + x]->getColor();
}

void Game::back() {
    if (moves.size() > 0) {
        Move move = moves.back();
        moves.pop_back();
        m_board[move.getYDep() * m_size + move.getXDep()] = move.getPieceMove()->copy();
        m_board[move.getYArr() * m_size + move.getXArr()] = nullptr;
        if (move.getPieceDelete() != nullptr)
            m_board[move.getYDel() * m_size + move.getXDel()] = move.getPieceDelete()->copy();

        m_curP = move.getCurP();
    }
}

int Game::getNumberSave(string game) {
    string fileName{"../Game_Processing/save.txt"};
    vector<string> vector{Parser::getLines(fileName)};
    int nbr{0};
    for (int i{0}; i < vector.size(); i++) {
        string s = vector.at(i);
        if (s.compare("<" + game + ">") == 0 || s.compare("<" + game + ">\r") == 0)
            nbr++;
    }

    return nbr;
}