#pragma once

#include "piece.hpp"

class Rook : public Piece {
private:
    bool initialState;

public:
    Rook(bool isWhite);

    bool canMove(Coord start, Coord end, Board& board) override;
};