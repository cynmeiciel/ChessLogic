#pragma once

#include "piece/includethis.hpp"
#include "constconfig.hpp"
#include <vector>
#include <string>
#include <memory>


class Board {
private:
    the_piece pieceAlive[8][8];
    std::vector<the_piece> pieceDead;

public:
    Board();
    ~Board();

    the_piece findPiecebyCoor(Coord xy);
    void pieceCaptured(Coord xy);

    void view();

    template <typename T>
    the_piece createPiece(Coord xy, bool isWhite);
};

// template <typename T>
// inline the_piece Board::createPiece(Coord xy, bool isWhite)
// {
//     return std::make_shared<T>();
// }
