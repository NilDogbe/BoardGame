
#include <iostream>
#include "Piece.h"
#include "GameChess.h"
#include "GameMakruk.h"

#include "Parser.h"
#include "GameDame.h"


using namespace std;

int nbrTest(string x) {
    if (x.compare("e") == 0)
        return Parser::NBR_TEST_CHESS + 1;
    else if (x.compare("d") == 0)
        return Parser::NBR_TEST_DAME + 1;
    else if (x.compare("m") == 0)
        return Parser::NBR_TEST_MAKRUK + 1;
}

string realName(string x) {
    if (x.compare("e") == 0)
        return Game::GAME_CHESS;
    else if (x.compare("d") == 0)
        return Game::GAME_DAME;
    else if (x.compare("m") == 0)
        return Game::GAME_MAKRUK;
}


int main() {

    /* Parser p;
     Game* g = new GameChess(0);*/
    Game *g;
    string typeGame;
    string testOrGame;
    string action;
    int idTest(-1);
    int idChar(-1);
    string nameGame("");
    bool retour(false);


    do {
        cout << "***********************************************" << endl
             << "Pour tester : 't'" << endl
             << "Pour jouer : 'j'" << endl
             << "Pour simuler : 's'" << endl
             << "Pour quitter : 'exit'" << endl;
        getline(cin, action);

        if (action.compare("t") == 0) {// rentre dans test
            do {
                retour = false;
                cout << "***********************************************" << endl
                     << "Pour test echecs : 'e'" << endl
                     << "Pour test Dames: 'd'" << endl
                     << "Pour test Makruk: 'm'" << endl
                     << "Pour test Dame2: 'x'" << endl
                     << "Pour quitter les test: 'retour'" << endl;
                do {
                    getline(cin, nameGame);
                    if (nameGame.compare("e") == 0 || nameGame.compare("d") == 0 || nameGame.compare("m") == 0 ||
                        nameGame.compare("x") == 0) {
                        cout << "***********************************************" << endl
                             << "Choisir un test " << realName(nameGame) << " entre 1(compris) et " << nbrTest(nameGame)
                             << "(compris)"
                             << endl;
                        break;
                    } else if (nameGame.compare("retour") == 0) {
                        retour = true;
                        break;

                    } else cout << "Pas Compris5" << endl;
                } while (1);
                do {
                    if (retour)
                        break;

                    getline(cin, action);
                    if (std::atoi(action.c_str()) == 0) {
                        cout << "IMPOSSIBLE: choisir un nombre entre 1 et " << nbrTest(nameGame) << endl;
                    } else break;
                } while (1);

                if (retour)
                    break;

                idTest = std::atoi(action.c_str()) - 1;
                cout << "idTest:" << idTest << endl;

                if (nameGame.compare("e") == 0 || nameGame.compare("d") == 0 || nameGame.compare("m") ||
                    nameGame.compare("x")) {
                    if (idTest <= nbrTest(nameGame) && idTest > -1) {
                        cout << "Bonsoir" << endl;
                        if (nameGame.compare("e") == 0) {
                            g = new GameChess();
                            g->startTest(idTest);
                        } else if (nameGame.compare("d") == 0) {
                            g = new GameDame();
                            g->startTest(idTest);
                        } else if (nameGame.compare("m") == 0) {
                            g = new GameMakruk();
                            g->startTest(idTest);
                        } else if (nameGame.compare("x") == 0) {
                            //TODO
                        }
                        break;
                    }
                } else cout << "Pas Compris Recommencez!" << endl;

            } while (1);
            // break; // fin du test
            // else cout << "PAS COMPRIS1!" << endl;

        } else if (action.compare("j") == 0) {

            cout << "**********************************************" << endl
                 << "A quel jeu voulez-vous jouer ?" << endl
                 << "Echec tappez : 'e'" << endl
                 << "Dame tappez : 'd'" << endl
                 << "Makruk tappez : 'm'" << endl
                 << "Revenir en arriere : 'retour'" << endl;
            getline(cin, nameGame);
            //cin.ignore();
            if (nameGame.compare("e") == 0 || nameGame.compare("d") == 0
                || nameGame.compare("m") == 0 || nameGame.compare("x") == 0) {
                cout << "**********************************************" << endl
                     << "Binvenue dans " << realName(nameGame) << endl
                     << "Nouvelle partie : 'new'" << endl
                     << "Charger partie : 'char'" << endl
                     << "Revenir en arriere : 'retour'" << endl;

                do {
                    getline(cin, action);
                    if (action.compare("new") == 0) {   // && (nameGame.compare("e") == 0)) {
                        cout << "Coisir le nombre de joueur 1 ou 2" << endl;
                        do {
                            int nbrP = -1;
                            getline(cin, action);
                            if (std::atoi(action.c_str()) == 0) {
                                cout << "tapper un nombre supp a 0" << endl;
                            } else {

                                nbrP = std::atoi(action.c_str());
                                cout << "nbrP:" << nbrP << endl;

                            }


                            if (nameGame.compare("e") == 0 && (nbrP == 1 || nbrP == 2)) {
                                Game *e = new GameChess();
                                e->start(true, nbrP);
                                return 1;
                            } else if (nameGame.compare("d") == 0 && (nbrP == 1 || nbrP == 2)) {
                                Game *e = new GameDame();
                                e->start(true, nbrP);
                                return 1;
                            } else if (nameGame.compare("m") == 0 && (nbrP == 1 || nbrP == 2)) {
                                Game *e = new GameMakruk();
                                e->start(true, nbrP);
                                return 1;
                            } else if (nameGame.compare("x") == 0 && (nbrP == 1 || nbrP == 2)) {
                                Game *e = new GameDame();
                                e->start(true, nbrP);
                                return 1;
                            } else {
                                cout << "Recommencer!";
                            }

                        } while (1);

                    } else if (action.compare("char") == 0) {
                        cout << "***********************************************" << endl
                             << "Choisir un Char" << realName(nameGame) << "entre 1(compris) et "
                             << Game::getNumberSave(nameGame)
                             << "(compris)"
                             << endl;

                        do {
                            getline(cin, action);
                            if (std::atoi(action.c_str()) == 0) {
                                cout << "tapper un nombre supp a 0" << endl;
                            } else {

                                idChar = std::atoi(action.c_str()) - 1;
                                cout << "idTest:" << idChar << endl;

                            }

                            if (idChar <= Game::getNumberSave(realName(nameGame)) && idChar > -1 &&
                                nameGame.compare("e") == 0) { // creer variable Char
                                cout << "Partie " << realName(nameGame) << " chargée" << endl;
                                g = new GameChess();
                                g->continueParty(idChar);
                                return 1;
                            } else if (idChar <= Game::getNumberSave(realName(nameGame)) && idChar > -1 &&
                                       nameGame.compare("d") == 0) { // creer variable Char
                                cout << "Partie " << realName(nameGame) << " chargée" << endl;
                                g = new GameDame();
                                g->continueParty(idChar);
                                return 1;
                            } else if (idChar <= Game::getNumberSave(realName(nameGame)) && idChar > -1 &&
                                       nameGame.compare("m") == 0) { // creer variable Char
                                cout << "Partie " << realName(nameGame) << " chargée" << endl;
                                g = new GameMakruk();
                                g->continueParty(idChar);
                                return 1;
                            } else if (idChar <= Game::getNumberSave(realName(nameGame)) && idChar > -1 &&
                                       nameGame.compare("x") == 0) {
                                //TODO Rhodier
                                cout << "Partie " << realName(nameGame) << " chargée" << endl;
                                g = new GameMakruk();
                                g->continueParty(idChar);
                                break;
                            } else cout << "Recommencez 7!" << endl;


                        } while (1);


                       // break;
                    } else if (action.compare("retour") == 0)
                        break;
                    else
                        cout << "Pas compris Recommence!" << endl;


                } while (1);

            }
        } else if (action.compare("s") == 0) {
            cout << "Simuler une partie d'ECHEC : 'e' " << endl
                 << "Simuler une partie de DAME : 'd' " << endl
                 << "Simuler une partie de MAKRUK : 'm' " << endl
                 << "Simuler une partie de XXXX : 'x' " << endl
                 << "Retour : 'retour' " << endl;


            do {
                getline(cin, nameGame);
                if (nameGame.compare("retour") == 0)
                    break;

                if (nameGame.compare("e") == 0 || nameGame.compare("d") == 0 || nameGame.compare("m") ||
                    nameGame.compare("x")) {
                    if (nameGame.compare("e") == 0) {
                        Game *g = new GameChess();
                        g->startRobot();
                        break;
                    } else if (nameGame.compare("d") == 0) {
                        Game *g = new GameDame();
                        g->startRobot();
                        break;
                    } else if (nameGame.compare("m") == 0) {
                        Game *g = new GameMakruk();
                        g->startRobot();
                        break;
                    } else if (nameGame.compare("x") == 0) { //TODO
                        g = new GameMakruk();
                        g->startRobot();
                        break;
                    }
                }
                else
                    cout << "Pas compris repeter";
            } while (1);
        } else if (action.compare("exit") == 0) {
            cout << "Ciao!" << endl;
            break;
        } else
            cout << "PAS COMPRIS0!" << endl;


    } while (1);

    cout << "Merci d'avoir jouer a notre appliation!" <<
         endl;

//Game* gd = new GameChess(0);

//Game_Processing\\Script_Test.txt" pour leo
//p.ReadScipt("D:\\Work\\Git\\BoardGame\\Game_Processing\\Script_Test.txt",0);
// cout << "\033[31mUn texte en rouge et\033[0m retour a la normale" << endl;
// int age(0);
// string nom;
/* cout << "Hello " << nom << " coucou quel age a tu ?" << endl;
 cin >> age;
 cin.ignore();
 cout << " votre nom? ";
 getline(cin,nom);
 cout << nom << " a " << age << "ans";*/
    return 0;
}