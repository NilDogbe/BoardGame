//
// Created by nil on 24/12/2018.
//

#include "Parser.h"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

vector<vector<int>> Parser::ReadScipt(string flux, int id) {

    ifstream monFlux(flux);  //Ouverture d'un fichier en lecture

    if (monFlux) {
        string ligne;
        vector<vector<int>> vector;
        bool add{false};

        while (getline(monFlux, ligne)) { //Tant qu'on n'est pas à la fin, on lit

            int nbr_chessTest = 0;
            if (ligne.compare("<Chess>\r") == 0) {
                //dans un mouvement
                if (id == nbr_chessTest) {
                    // boucler et remplir jusqua \chess
                    add = true;

                } else
                    nbr_chessTest++;
            } else if (ligne.compare("</Chess>\r") == 0 || ligne.compare("</Chess>") == 0){
                cout<<"eeeeee";
                cout << "test ";

                cout << vector[0][0];
                cout << vector[0][1];
                cout << vector[0][2];
                cout << vector[0][3] << endl;

                cout << vector[5][0];
                cout << vector[5][1];
                cout << vector[5][2];
                cout << vector[5][3] << endl;
                return vector;
                break;
            }
            else if (add) {

                std::vector<int> v;
                int elem;
                cout << ligne << endl;
                std::string delimiter = ",";
                size_t pos = 0;
                std::string token;
                while ((pos = ligne.find(delimiter)) != std::string::npos) { // parse la ligne et insert dans le vector les indices
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
    } else {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
    }
}
