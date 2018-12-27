//
// Created by nil on 24/12/2018.
//

#include "Parser.h"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

vector<vector<int>> Parser::ReadScipt(string flux, int idTest, string idBalise) {

    ifstream monFlux(flux);//Ouverture d'un fichier en lecture
    //faire un switch case
    string endBalise;
    if (idBalise.compare("<Chess>\r") == 0)
        endBalise = "</Chess>\r";
    else if (idBalise.compare("<Dame>\r") == 0)
        endBalise = "</Dame>\r";
    int nbr_chessTest = 0;

    if (monFlux) {
        string ligne;
        vector<vector<int>> vector;
        bool add{false};
        while (getline(monFlux, ligne)) { //Tant qu'on n'est pas à la fin, on lit
            cout << "Balise aaaaaaaa "<< ligne << endl;


            if (ligne.compare(idBalise) == 0) {
                cout << "niportr" << ligne;

                if (idTest == nbr_chessTest) {

                    // boucler et remplir jusqua \chess
                    add = true;

                } else
                    nbr_chessTest++;
            } else if (ligne.compare(endBalise) == 0 && add) {
                /*cout<<"eeeeee";
                cout << "test ";*/
                cout << (ligne.compare(endBalise) == 0) << endBalise;
                for (int i = 0; i < vector.size(); i++) {
                    cout << vector[i][0];
                    cout << vector[i][1];
                    cout << vector[i][2];
                    cout << vector[i][3] << endl;
                }
                return vector;
               // break;
            } else if (add) {
                cout << "7";

                std::vector<int> v;
                int elem;
                // cout << ligne << endl;
                std::string delimiter = ",";
                size_t pos = 0;
                std::string token;
                while ((pos = ligne.find(delimiter)) !=
                       std::string::npos) { // parse la ligne et insert dans le vector les indices
                    token = ligne.substr(0, pos);
                    ligne.erase(0, pos + delimiter.length());
                    elem = std::atoi(token.c_str());
                    v.push_back(elem);
                }
                elem = std::atoi(ligne.c_str());
                v.push_back(elem);
                vector.push_back(v);
            }
        }
        cout<<"fin du parser";
    } else {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
    }
}

vector<string> Parser::getLines(string fileName) {
    ifstream fichier(fileName, ios::in);
    vector<string> vector;

    if (fichier) {
        string s;

        while (getline(fichier, s)) {
            vector.push_back(s);
        }
    } else
        cerr << "Impossible d'ouvrir le fichier !" << endl;

    return vector;
}