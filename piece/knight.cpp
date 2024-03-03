#include "knight.hpp"
#include "../board.hpp"

Knight::Knight(bool isWhite) {
    this->m_white = isWhite;
    this->name = (isWhite)? "White Knight" : "Black Knight";
    this->abbrv = (isWhite)? "wN" : "bN";
}

bool Knight::canMove(Coord start, Coord end, Board& board) {
    return true;
}
