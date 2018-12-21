//
// Created by nil on 21/12/2018.
//

#include "Case.h"


int Case::getY(){
    return m_y;
}
int Case::getColor(){
    return m_color;
}
Piece Case::getPiece(){
    return m_piece;
}
void Case::setX(int x){
    m_x = x;
}
void Case::setY(int y){
    m_y = y;
}
bool Case::isEmpty(){
    return true;//(m_piece = NULL);
}