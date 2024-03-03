#pragma once

#include "piece.hpp"

class Pawn : public Piece {
private:
    bool initialState;

public:
    Pawn(bool isWhite);

    bool canMove(Coord start, Coord end, Board& board) override;
};