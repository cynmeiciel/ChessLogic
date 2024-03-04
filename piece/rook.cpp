#include "rook.hpp"
#include "../board.hpp"

Rook::Rook(bool isWhite) {
    this->m_white = isWhite;
    this->name = (isWhite)? "White Rook" : "Black Rook";
    this->symbol = (isWhite)? "♜" : "♖";
    this->initialState = true;
}

bool Rook::canMove(Coord start, Coord end, Board& board) {
    if (board.isEmptyLine(start, end)) {
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
