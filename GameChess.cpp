//
// Created by nil on 23/12/2018.
//

#include "GameChess.h"
#include <iostream>
#include <wchar.h>
#include "Game.h"
#include "Piece.h"
#include "King.h"
#include "Knight.h"
#include "Tower.h"
#include "Bishop.h"
#include "Queen.h"
#include "PawnForChess.h"
#include "Parser.h"


using namespace std;

GameChess::GameChess() : Game(SIZE, GAME_CHESS){
}

void GameChess::init() {
    for (int i = 0; i < m_size; i++) {
        for (int j = 0; j < m_size; j++) {
            /*if (i == 2 && j == 4)
                m_board[i * m_size + j] = new King(BLACK);*/

             if (i == 1)
                m_board[i * m_size + j] = new PawnForChess(WHITE);
            else if (i == 0)
                if (j == 0 || j == m_size - 1)
                    m_board[i * m_size + j] = new Tower(WHITE);
                else if (j == 1 || j == m_size - 2)
                    m_board[i * m_size + j] = new Knight(WHITE);
                else if (j == 2 || j == m_size - 3)
                    m_board[i * m_size + j] = new Bishop(WHITE);
                else if (j == 3)
                    m_board[i * m_size + j] = new King(WHITE);
                else
                    m_board[i * m_size + j] = new Queen(WHITE);
            else if (i == m_size - 2)
                m_board[i * m_size + j] = new PawnForChess(BLACK);
            else if (i == m_size - 1)
                if (j == 0 || j == m_size - 1)
                    m_board[i * m_size + j] = new Tower(BLACK);
                else if (j == 1 || j == m_size - 2)
                    m_board[i * m_size + j] = new Knight(BLACK);
                else if (j == 2 || j == m_size - 3)
                    m_board[i * m_size + j] = new Bishop(BLACK);
                else if (j == 3)
                    m_board[i * m_size + j] = new Queen(BLACK);
                else
                    m_board[i * m_size + j] = new King(BLACK);
            /* if(j==4 && i == 4){
                 m_board[i * m_size + j] = new Queen(BLACK);
             }
             if(j==1 && i == 4){
                 m_board[i * m_size + j] = new King(BLACK);
             }
              if(j==6 && i == 2){
                  m_board[i * m_size + j] = new King(BLACK);
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
              }*/
        }
    }
}


bool GameChess::movePiece(int x_dep, int y_dep, int x_arr, int y_arr) {
    //cout<<"Bidule";
    if (Game::movePiece(x_dep, y_dep, x_arr, y_arr)) {
       // cout << "test:::" << endl;

        Piece *piece_dep = m_board.at(y_dep * m_size + x_dep);
        Piece *piece_arr = m_board.at(y_arr * m_size + x_arr);

        if (piece_dep->canMove(x_dep, y_dep, x_arr, y_arr) == 1) {

            //mouvement accessible a cette piece
           // cout << "Travel; " << endl;
            if(piece_dep->toString().compare("P") == 0 && piece_arr != nullptr){

                return false;
            }
            for (int i = 0; i < piece_dep->getTravel().size(); i++) {
               // cout << "x:" << (piece_dep->getTravel().at(i)) % 8;
               // cout << ",y:" << (piece_dep->getTravel().at(i)) / 8 << endl;


                if (m_board.at(piece_dep->getTravel().at(i)) != nullptr) {//piece sur le chemin
                  //  cout << "G777" << endl;
                    return false;
                }
            }

            //cout << "VRAI" << endl;
            return true;
        } else if (piece_dep->canMove(x_dep, y_dep, x_arr, y_arr) == 2) {

             if (piece_arr == nullptr)
                return false;
        } else {
           // cout << "6" << endl;
           // cout << "VRAI";
            return true;
        }
    } else return false;
}


/* if( y_dep * m_size + x_dep == m_caseWhitekKing){
     cout<<"king  blanc"<< y_dep * m_size + x_dep << endl;
     y_arr * m_size + x_arr == m_caseWhitekKing
 }*/