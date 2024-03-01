#include "queen.hpp"

Queen::Queen(bool isWhite) {
    this->m_white = isWhite;
    this->name = (isWhite)? "White Queen" : "Black Queen";
    this->abbrv = (isWhite)? "wQ" : "bQ";
}

bool Queen::canMove() {
    return false;
}
