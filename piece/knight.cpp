#include "knight.hpp"
#include "../board.hpp"

Knight::Knight(bool isWhite) {
    this->m_white = isWhite;
    this->name = (isWhite)? "White Knight" : "Black Knight";
    this->symbol = (isWhite)? "♞" : "♘";
}

bool Knight::canMove(Coord start, Coord end, Board& board) {
    Coord distance = start - end;
    if (distance.abs().x == 2 && distance.abs().y == 1) {
        if (!board.isEmpty(end) 
            && board.findPiecebyCoor(end)->isWhite() == this->isWhite()) {
            return false;
        } else {
            return true;
        }
    } else if (distance.abs().x == 1 && distance.abs().y == 2) {
        if (!board.isEmpty(end) 
            && board.findPiecebyCoor(end)->isWhite() == this->isWhite()) {
            return false;
        } else {
            return true;
        }
    } else
        return false;
}
