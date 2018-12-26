
#include <iostream>
#include "Piece.h"
#include "GameChess.h"
#include "Parser.h"
#include "GameDame.h"


using namespace std;

int main() {

    /* Parser p;
     Game* g = new GameChess(0);*/
    Game *g;
    string typeGame;
    string testOrGame;
    int idTest = -1;
    cout << "Pour tester : 't'" << endl << "Pour jouer : 'j'" << endl;
    do {
        getline(cin, testOrGame);

        if (testOrGame.compare("t") == 0) {// rentre dans test
            do {
                cout << "Pour test echecs : 'e'" << endl << "Pour test Dames: 'd'" << endl;
                getline(cin, typeGame);
                if (typeGame.compare("e") == 0) {
                    do {
                        cout << "Choisir un test echec entre 0(compris) et " << Parser::NBR_TEST_CHESS << "(compris)" << endl;
                        cin >> idTest;
                        cin.ignore();
                        if (idTest <= Parser::NBR_TEST_CHESS && idTest > -1) {
                            cout << "Bonsoir" << endl;
                            g = new GameChess(idTest);
                            break;
                        } else cout << "Recommencez!" << endl;

                    } while (1);
                    break; // fin du test

                } else if (typeGame.compare("d") == 0) { // rentre dans un jeu

                    do {
                        cout << "Choisir un test dame entre 0(compris) et " << Parser::NBR_TEST_DAME << "(compris)" << endl;
                        cin >> idTest;
                        cin.ignore();
                        if (idTest <= Parser::NBR_TEST_CHESS && idTest > -1) {

                            g = new GameDame(idTest);
                            //delete(d);
                            break;
                        } else cout << "Recommencez!" << endl;
                    } while (1);
                    break; // fin du test
                }
            }while(1);



        } else if (testOrGame.compare("j") == 0) {
            cout << "vous allez commencer une partie" << endl;
            break;
        } else
            cout << "Recommencez222!" << endl;


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