
#include <iostream>
#include "Piece.h"
using namespace std;


int main() {
    Piece("piece");

    int age(0);
    string nom;
    cout << "Hello " << nom << " coucou quel age a tu ?" << endl;
    cin >> age;
    cin.ignore();

    cout << " votre nom? ";
    getline(cin,nom);

    cout << nom << " a " << age << "ans";
    return 0;
}