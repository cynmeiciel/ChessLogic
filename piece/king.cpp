#include "king.hpp"
#include "../board.hpp"

King::King(bool isWhite){
    this->m_white = isWhite;
    this->name = (isWhite)? "White King" : "Black King";
    this->abbrv = (isWhite)? "wK" : "bK";
    this->initialState = true;
}

bool King::canMove(Coord start, Coord end, Board& board) {
    return true;
}