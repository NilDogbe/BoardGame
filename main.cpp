
#include <iostream>
#include "Piece.h"
#include "GameChess.h"

using namespace std;


int main() {
    // Piece b("piece");
    GameChess a;
    a.movePiece(7, 6, 7, 4);//tower

    // a.initGameChess();
    a.movePiece(1, 1, 2, 2);//roi
    a.movePiece(1, 7, 2, 5);//cavalier
    a.movePiece(6, 6, 5, 5);//Bishop
    a.movePiece(5, 6, 6, 6);//Queen
    a.movePiece(6, 6, 7, 5);//Queen
    a.movePiece(2, 2, 2, 3);//roi
    a.movePiece(2, 3, 2, 4);//roi
    a.movePiece(0, 0, 0, 1);//roi*/
    //a.movePiece(6,7,7,5);//cavalier
    //a.movePiece(7,6,7,4);//tower
    //  a.movePiece(7,6,6,6);//tower
    // a.movePiece(2,1,2,2);
    //a.movePiece(2,2,2,3);//roi
    // a.movePiece(2,3,2,4);//roi
    // a.movePiece(7,4,6,4);//tower
    // a.movePiece(6,6,3,3);//Bishop
    //a.movePiece(3,3,4,2);//Bishop
    //a.movePiece(4,2,6,4);//Bishop
    // a.movePiece(4,4,6,6);//Bishop2
    //a.movePiece(4,2,1,5);//Bishop
    //a.movePiece(3,3,5,1);//Bishop2
    //a.movePiece(3,3,1,1);//Bishop2
    a.movePiece(7, 4, 7, 1);//tower
    a.movePiece(4, 4, 0, 0);//Bishop
    a.movePiece(7, 5, 4, 5);//Queen
    a.movePiece(7, 5, 7, 0);//Queen




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