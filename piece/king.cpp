#include "king.hpp"
#include "../board.hpp"

King::King(bool isWhite){
    this->m_white = isWhite;
    this->name = (isWhite)? "White King" : "Black King";
    this->symbol = (isWhite)? "♚" : "♔";
    this->initialState = true;
}

bool King::canMove(Coord start, Coord end, Board& board) {
    Coord distance = start - end;
    if (distance.abs().x <= 1 && distance.abs().y <= 1) {
        if (!board.isEmpty(end) 
            && board.findPiecebyCoor(end)->isWhite() == this->isWhite()) {
            return false;
        } else {
            this->initialState = false;
            return true;
        }
    } else
        return false;
}