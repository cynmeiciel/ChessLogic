#include "board.hpp"

Board::Board() {
    // const int initial[8][8] = {
    //     {}
    // };

    for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                pieceAlive[i][j] = nullptr;
            }
        }

    pieceAlive[0][0] = std::make_shared<Pawn>();
}


Board::~Board() {
    mess("Board cleaned!");
}

void Board::pieceCaptured(Coord xy) {
    the_piece captured = this->findPiecebyCoor(xy);
    this->findPiecebyCoor(xy) = nullptr;
    this->pieceDead.push_back(captured);
}


void Board::view() {
    
}
