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

    TurnState currentState;

public:
    Board();
    ~Board();

    the_piece findPiecebyCoor(Coord xy);
    void pieceCaptured(Coord xy, bool en_passant);

    void view();

    void movePiece(Coord start, Coord destination, bool en_passant = false);

    inline void setState(TurnState state) {
        this->currentState = state;
    }

    template <typename TYPE_OF_PIECE>
    void createPiece(Coord xy, bool isWhite);
};

template <typename TYPE_OF_PIECE>
inline void Board::createPiece(Coord xy, bool isWhite) {
    this->pieceAlive[xy.x][xy.y] = std::make_shared<TYPE_OF_PIECE>(isWhite);
}
