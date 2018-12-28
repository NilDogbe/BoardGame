#include "GameDame.h"
#include "Parser.h"
#include "GameChess.h"
#include <iostream>

using namespace std;

int main() {

    /* Parser p;
     Game* g = new GameChess(0);*/
    Game *g;
    string typeGame;
    string testOrGame;
    string action;
    int idTest;
    int idChar;



    do {
        cout << "***********************************************" << endl
             << "Pour tester : 't'" << endl
             << "Pour jouer : 'j'" << endl
             << "Pour quitter : 'exit'" << endl;
        getline(cin, action);

        if (action.compare("t") == 0) {// rentre dans test
            do {
                cout << "***********************************************" << endl
                     << "Pour test echecs : 'e'" << endl
                     << "Pour test Dames: 'd'" << endl
                     << "Pour quitter les test: 'retour'" << endl;
                idTest = -1;
                getline(cin, action);
                if (action.compare("e") == 0) {
                    do {
                        cout << "***********************************************" << endl
                             << "Choisir un test echec entre 1(compris) et " << Parser::NBR_TEST_CHESS + 1
                             << "(compris)"
                             << endl;
                        getline(cin, action);
                        if (std::atoi(action.c_str()) == 0) {
                            cout << "tapper un nombre supp " << endl;
                        } else {

                            idTest = std::atoi(action.c_str()) - 1;
                            cout << "idTest:" << idTest << endl;

                        }

                        if (idTest <= Parser::NBR_TEST_CHESS && idTest > -1) {
                            cout << "Bonsoir" << endl;
                            g = new GameChess(idTest);
                            break;
                        } else cout << "Recommencez!" << endl;

                    } while (1);
                    break; // fin du test

                } else if (action.compare("d") == 0) { // rentre dans un jeu

                    do {
                        cout << "***********************************************" << endl
                             << "Choisir un test echec entre 1(compris) et " << Parser::NBR_TEST_DAME + 1
                             << "(compris)"
                             << endl;
                        getline(cin, action);
                        if (std::atoi(action.c_str()) == 0) {
                            cout << "tapper un nombre supp " << endl;
                        } else {

                            idTest = std::atoi(action.c_str()) - 1;
                            cout << "idTest:" << idTest << endl;

                        }

                        if (idTest <= Parser::NBR_TEST_DAME && idTest > -1) {
                            cout << "Bonsoir" << endl;
                            g = new GameDame(idTest);
                            break;
                        } else cout << "Recommencez!" << endl;

                    } while (1);
                    break;


                    break;
                } else cout << "PAS COMPRIS1!" << endl;

            } while (1);


        } else if (action.compare("j") == 0) {
            cout << "**********************************************" << endl
                 << "A quel jeu voulez-vous jouer ?" << endl
                 << "Echec tappez : 'e'" << endl
                 << "Dame tappez : 'd'" << endl
                 << "Revenir en arriere : 'retour'" << endl;
            getline(cin, action);
            //cin.ignore();
            if (action.compare("e") == 0) {
                cout << "*********************************" << endl
                     << "Binvenue dans ECHEC " << endl
                     << "Nouvelle partie : 'new'" << endl
                     << "Charger partie : 'char'" << endl
                     << "Revenir en arriere : 'retour'" << endl;

                do {
                    getline(cin, action);
                    if (action.compare("new") == 0) {
                        Game *e = new GameChess();
                        break;
                    } else if (action.compare("char") == 0) {

                        do {
                            cout << "***********************************************" << endl
                                 << "Choisir un Char echec entre 1(compris) et " << Parser::NBR_TEST_CHESS + 1
                                 << "(compris)"
                                 << endl;
                            getline(cin, action);
                            if (std::atoi(action.c_str()) == 0) {
                                cout << "tapper un nombre supp " << endl;
                            } else {

                                idChar = std::atoi(action.c_str()) - 1;
                                cout << "idTest:" << idChar << endl;

                            }

                            if (idChar <= Parser::NBR_TEST_CHESS && idChar > -1) { // creer variable Char
                                cout << "Bonsoir" << endl;
                                g = new GameChess("../Game_Processing/save.txt",idChar);
                                break;
                            } else cout << "Recommencez!" << endl;

                        } while (1);
                        break;
                    } else if (action.compare("retour") == 0)
                        break;
                    else
                        cout << "Pas compris Recommence!" << endl;
                } while (1);

            } else if (action.compare("d") == 0) {
                cout << "*********************************" << endl
                     << "Binvenue dans DAME " << endl
                     << "Nouvelle partie : 'new'" << endl
                     << "Charger partie : 'char'" << endl
                     << "Revenir en arriere : 'retour'" << endl;

                do {
                    getline(cin, action);
                    if (action.compare("new") == 0) {
                        Game *e = new GameDame();
                        break;
                    } else if (action.compare("char") == 0) {
                        //Rhodier char un partie
                        break;
                    } else if (action.compare("retour") == 0)
                        break;
                    else
                        cout << "Pas compris Recommence!" << endl;
                } while (1);


            } else if (action.compare("retour") == 0)
                break;
        } else if (action.compare("exit") == 0) {
            cout << "Ciao!" << endl;
            return 0;
        } else
            cout << "PAS COMPRIS0!" << endl;


    } while (1);

    cout << "fin!" << endl;

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