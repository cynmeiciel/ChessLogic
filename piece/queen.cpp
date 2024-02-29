#include "queen.hpp"

Queen::Queen(bool isWhite) {
    this->m_white = isWhite;
    this->name = (isWhite)? "White Queen" : "Black Queen";
}

bool Queen::move() {
    return false;
}
