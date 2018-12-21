//
// Created by nil on 21/12/2018.
//

#include "Case.h"

Case::Case(int x, int y, int color, Piece* piece){
    m_x=x;
    m_y=y;
    m_color = color;
    m_piece = piece;
}

Case::Case(){
}
Piece* Case::getPiece(){
    return m_piece;
}
int Case::getColor(){
    return m_color;
}
void Case::setX(int x){
    m_x = x;
}
void Case::setY(int y){
    m_y = y;
}
bool Case::isEmpty(){
    return (m_piece == NULL);
}