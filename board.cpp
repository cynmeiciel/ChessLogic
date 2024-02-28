#include "board.hpp"

Board::Board() {
    for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                pieceAlive[i][j] = nullptr;
            }
        }
}


Board::~Board() {
    mess("Board cleaned!");
}


std::ostream& operator<<(std::ostream &os, const Board &obj) {
    os << (std::string)"lolol";
    return os;
}
