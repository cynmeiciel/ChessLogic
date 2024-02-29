#include "king.hpp"

King::King(bool isWhite){
    this->m_white = isWhite;
    this->name = (isWhite)? "White King" : "Black King";
    this->initialState = true;
}

bool King::move()
{
}