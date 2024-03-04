#include "queen.hpp"
#include "../board.hpp"

Queen::Queen(bool isWhite) {
    this->m_white = isWhite;
    this->name = (isWhite)? "White Queen" : "Black Queen";
    this->symbol = (isWhite)? "♛" : "♕";
}

bool Queen::canMove(Coord start, Coord end, Board& board) {
    if (board.isEmptyLine(start, end)) {
        if (!board.isEmpty(end) 
            && board.findPiecebyCoor(end)->isWhite() == this->isWhite()) {
            return false;
        } else {
            return true;
        }
        
    } else if (board.isEmptyDiagonal(start, end)) {
        if (!board.isEmpty(end) 
            && board.findPiecebyCoor(end)->isWhite() == this->isWhite()) {
            return false;
        } else {
            return true;
        }
    } else
        return false;
}
