#pragma once

#include "piece.hpp"


class King : public Piece {
private:
    bool initialState;

public:
    King(bool isWhite);

    bool canMove(Coord start, Coord end, Board& board) override;
};