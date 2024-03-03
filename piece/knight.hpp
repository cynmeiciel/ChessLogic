#pragma once

#include "piece.hpp"


class Knight : public Piece {
private:

public:
    Knight(bool isWhite);

    bool canMove(Coord start, Coord end, Board& board) override;
};