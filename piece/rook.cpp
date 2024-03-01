#include "rook.hpp"

Rook::Rook(bool isWhite) {
    this->m_white = isWhite;
    this->name = (isWhite)? "White Rook" : "Black Rook";
    this->abbrv = (isWhite)? "wR" : "bR";
    this->initialState = true;
}

bool Rook::canMove() {
    
}