
#include <iostream>
#include "Piece.h"
#include "Board.h"

using namespace std;


int main() {
   // Piece b("piece");
    Board a;
    a.initBoard(1);
    a.movePiece(1,1,2,2);//roi
    a.movePiece(1,7,2,5);//cavalier
    a.movePiece(7,6,7,4);//tower
    a.movePiece(7,4,2,4);//tower


    a.affichage();

   // cout << "\033[31mUn texte en rouge et\033[0m retour a la normale" << endl;

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