#pragma once

#include "piece.hpp"


class Knight : public Piece {
private:

public:
    Knight(bool isWhite);

    bool canMove() override;
};