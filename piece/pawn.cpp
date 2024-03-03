#include "pawn.hpp"
#include "../board.hpp"

Pawn::Pawn(bool isWhite) {
    this->m_white = isWhite;
    this->name = (isWhite)? "White Pawn" : "Black Pawn";
    this->abbrv = (isWhite)? "w" : "b";
    this->initialState = true;
}

bool Pawn::canMove(Coord start, Coord end, Board& board) {
    // Pawns can only move forward
    int direction = (this->isWhite()) ? 1 : -1;
    if (end.y - start.y == direction) {
        // Moving one square forward
        if (start.x == end.x && board.isEmpty(end)) {
            return true;
        }
        // Capturing
        else if (abs(start.x - end.x) == 1 && !board.isEmpty(end)
                && board.findPiecebyCoor(end)->isWhite() != this->isWhite()) {
            return true;
        }
    }
    // Initial two-square move
    else if (initialState && end.y - start.y == 2 * direction
            && start.x == end.x && board.isEmpty(end)) {
        return true;
    }
    return false;
}