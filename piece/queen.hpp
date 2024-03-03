#pragma once

#include "piece.hpp"


class Queen : public Piece {
private:

public:
    Queen(bool isWhite);

    bool canMove(Coord start, Coord end, Board& board) override;
};