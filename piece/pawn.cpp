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
            this->initialState = false;
            return true;
        }
        // Capturing
        else if (abs(start.x - end.x) == 1 && !board.isEmpty(end)
                && board.findPiecebyCoor(end)->isWhite() != this->isWhite()) {
            this->initialState = false;
            return true;
        }
        // En passant
        else if (board.enPassantPawn.has_value()) {
            if (abs(start.x - end.x) == 1 && end == board.enPassantPawn.value()) {
                this->initialState = false;
                board.performEnPassant(Coord(end.x, end.y - direction));
                return true;
            }
        }
    }
    // Initial two-square move and setup for en passant
    else if (initialState && end.y - start.y == 2 * direction
            && start.x == end.x && board.isEmptyLine(start, end)) {
        this->initialState = false;
        board.enPassantPawn = Coord(end.x, end.y - direction);
        board.enPassantDeclared = true;
        return true;
    }
    return false;
}