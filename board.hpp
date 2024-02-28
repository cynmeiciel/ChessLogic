#pragma once

#include "piece/piece.hpp"
#include "constconfig.hpp"
#include <vector>
#include <array>
#include <string>
#include <memory>


class Board {
private:
    the_piece pieceAlive[8][8];

public:
    Board();
    ~Board();

    the_piece findPiecebyCoor(Coord xy);

    void view();
};

