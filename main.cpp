
#include <iostream>
#include "Piece.h"
#include "Board.h"

using namespace std;


int main() {
   // Piece b("piece");
    Board a;
    a.initBoard(1);
    a.movePiece(1,1,2,2);
    a.affichage();
    int age(0);
    string nom;
   /* cout << "Hello " << nom << " coucou quel age a tu ?" << endl;
    cin >> age;
    cin.ignore();

    cout << " votre nom? ";
    getline(cin,nom);

    cout << nom << " a " << age << "ans";*/
    return 0;
}