//
// Created by nil on 23/12/2018.
//

#include "GameChess.h"
#include <iostream>
#include <windows.h>
#include <wchar.h>
#include "Game.h"
#include "Piece.h"
#include "King.h"
#include "Cavalier.h"
#include "Tower.h"
#include "Bishop.h"
#include "Queen.h"
#include "PiontForChess.h"


using namespace std;


GameChess::GameChess() : Game(8) {
    initGameChess();
}

void GameChess::initGameChess() {
    for (int i = 0; i < m_size; i++) {
        for (int j = 0; j < m_size; j++) {
           /* if (i == 1)
                m_board[i * m_size + j] = new PiontForChess(1);
            else if (i == 0)
                if (j == 0 || j == m_size - 1)
                    m_board[i * m_size + j] = new Tower(1);
                else if (j == 1 || j == m_size - 2)
                    m_board[i * m_size + j] = new Cavalier(1);
                else if (j == 2 || j == m_size - 3)
                    m_board[i * m_size + j] = new Bishop(1);
                else if (j == 3)
                    m_board[i * m_size + j] = new King(1);
                else
                    m_board[i * m_size + j] = new Queen(1);
            else if (i == m_size - 2)
                m_board[i * m_size + j] = new PiontForChess(0);
            else if (i == m_size - 1)
                if (j == 0 || j == m_size - 1)
                    m_board[i * m_size + j] = new Tower(0);
                else if (j == 1 || j == m_size - 2)
                    m_board[i * m_size + j] = new Cavalier(0);
                else if (j == 2 || j == m_size - 3)
                    m_board[i * m_size + j] = new Bishop(0);
                else if (j == 3)
                    m_board[i * m_size + j] = new Queen(0);
                else
                    m_board[i * m_size + j] = new King(0);*/
           if(j==4 && i == 4){
               m_board[i * m_size + j] = new Queen(0);
           }
           if(j==1 && i == 4){
               m_board[i * m_size + j] = new King(0);
           }
            if(j==6 && i == 2){
                m_board[i * m_size + j] = new King(0);
            }
            if(j==2 && i == 2){
                m_board[i * m_size + j] = new King(0);
            }
            if(j==4 && i == 2){
                m_board[i * m_size + j] = new King(0);
            }
            if(j==6 && i == 6){
                m_board[i * m_size + j] = new King(0);
            }

            if(j==2 && i == 6){
                m_board[i * m_size + j] = new King(0);
            }
        }
    }
}

void GameChess::affichage() {
    Game::affichage();
}

bool GameChess::movePiece(int x_dep, int y_dep, int x_arr, int y_arr) {

    if (Game::movePiece(x_dep, y_dep, x_arr, y_arr)) {
        cout << "test:::" << endl;

        Piece *piece_dep = m_board.at(y_dep * m_size + x_dep);
        Piece *piece_arr = m_board.at(y_arr * m_size + x_arr);

        if (piece_dep->canMove(x_dep, y_dep, x_arr, y_arr) == 1) {
            cout << "G2" << endl;

            //mouvement accessible a cette piece
            cout  << "Travel; "<<endl;

            for (int i = 0; i < piece_dep->getTravel().size(); i++) {
                cout  << "x:" << (piece_dep->getTravel().at(i))%8;
                cout  <<",y:" << (piece_dep->getTravel().at(i))/8<<endl;


                if (m_board.at(piece_dep->getTravel().at(i)) != nullptr) {//piece sur le chemin
                    cout << "G777" << endl;
                    return false;
                }
            }
            cout << "G3";
            m_board.at(y_dep * m_size + x_dep) = nullptr;
            m_board.at(y_arr * m_size + x_arr) = piece_dep;
            return true;
        } else if (piece_dep->canMove(x_dep, y_dep, x_arr, y_arr) == 2) {
            cout << "G3" << endl;// Piont
            if (piece_arr == nullptr)
                return false;
        }
            else {
                cout << "6" << endl;
                m_board.at(y_dep * m_size + x_dep) = nullptr;
                m_board.at(y_arr * m_size + x_arr) = piece_dep;
                return true;
            }
    }
    else return false;
}
