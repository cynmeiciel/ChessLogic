#include "king.hpp"

King::King(bool isWhite){
    this->m_white = isWhite;
    this->name = (isWhite)? "White King" : "Black King";
    this->abbrv = (isWhite)? "wK" : "bK";
    this->initialState = true;
}

bool King::canMove() {
}