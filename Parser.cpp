//
// Created by nil on 24/12/2018.
//

#include "Parser.h"

#include <iostream>
#include <fstream>
using namespace std;

void Parser::ReadScipt(string flux){

    ifstream monFlux(flux);  //Ouverture d'un fichier en lecture

    if(monFlux){
        string ligne;
        getline(monFlux, ligne); //On lit une ligne complète
        //Tout est prêt pour la lecture.
        while(getline(monFlux, ligne)) //Tant qu'on n'est pas à la fin, on lit
        {
            cout << ligne << endl;
            //Et on l'affiche dans la console
            //Ou alors on fait quelque chose avec cette ligne
            //À vous de voir
        }
    }
    else{
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
    }
}

