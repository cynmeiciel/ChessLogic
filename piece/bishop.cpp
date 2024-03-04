#include "bishop.hpp"
#include "../board.hpp"

Bishop::Bishop(bool isWhite) {
    this->m_white = isWhite;
    this->name = (isWhite)? "White Bishop" : "Black Bishop";
    this->symbol = (isWhite)? "♝" : "♗";
}

bool Bishop::canMove(Coord start, Coord end, Board& board) {
    if (board.isEmptyDiagonal(start, end)) {
        if (!board.isEmpty(end) 
            && board.findPiecebyCoor(end)->isWhite() == this->isWhite()) {
            return false;
        } else {
            return true;
        }
    } else
        return false;
}
