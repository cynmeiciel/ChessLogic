#pragma once

#include "piece.hpp"


class Bishop : public Piece {
private:

public:
    Bishop(bool isWhite);

    bool canMove(Coord start, Coord end, Board& board) override;
};