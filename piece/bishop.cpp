#include "bishop.hpp"
#include "../board.hpp"

Bishop::Bishop(bool isWhite) {
    this->m_white = isWhite;
    this->name = (isWhite)? "White Bishop" : "Black Bishop";
    this->abbrv = (isWhite)? "wB" : "bB";
}

bool Bishop::canMove(Coord start, Coord end, Board& board) {
    return true;
}
