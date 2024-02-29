#include "pawn.hpp"

Pawn::Pawn(bool isWhite) {
    this->m_white = isWhite;
    this->name = (isWhite)? "White Pawn" : "Black Pawn";
    this->initialState = true;
}

bool Pawn::move() {
    mess("loz");
}