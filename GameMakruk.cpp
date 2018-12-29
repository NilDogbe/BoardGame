//
// Created by nil on 28/12/2018.
//

#include <iostream>
#include "GameMakruk.h"
#include "Game.h"
#include "Khon.h"
#include "Seed.h"

using namespace std;


GameMakruk::GameMakruk():GameChess(){
}

void GameMakruk::init(){
    cout << "eeeeee";
    for (int i = 0; i < m_size; i++) {
        for (int j = 0; j < m_size; j++) {
            if (i == 2 && j == 4)
                m_board[i * m_size + j] = new King(BLACK);

            else if (i == 2)
                m_board[i * m_size + j] = new PawnForChess(WHITE,false);
            else if (i == 0)
                if (j == 0 || j == m_size - 1)
                    m_board[i * m_size + j] = new Tower(WHITE);
                else if (j == 1 || j == m_size - 2)
                    m_board[i * m_size + j] = new Knight(WHITE);
                else if (j == 2 || j == m_size - 3)
                    m_board[i * m_size + j] = new Khon(WHITE);
                else if (j == 3)
                    m_board[i * m_size + j] = new Seed(WHITE);
                else
                    m_board[i * m_size + j] = new King(WHITE);
            else if (i == m_size - 3)
                m_board[i * m_size + j] = new PawnForChess(BLACK,false);
            else if (i == m_size - 1)
                if (j == 0 || j == m_size - 1)
                    m_board[i * m_size + j] = new Tower(BLACK);
                else if (j == 1 || j == m_size - 2)
                    m_board[i * m_size + j] = new Knight(BLACK);
                else if (j == 2 || j == m_size - 3)
                    m_board[i * m_size + j] = new Khon(BLACK);
                else if (j == 3)
                    m_board[i * m_size + j] = new King(BLACK);
                else
                    m_board[i * m_size + j] = new Seed(BLACK);
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
