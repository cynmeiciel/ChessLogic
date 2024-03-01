#include "bishop.hpp"

Bishop::Bishop(bool isWhite) {
    this->m_white = isWhite;
    this->name = (isWhite)? "White Bishop" : "Black Bishop";
    this->abbrv = (isWhite)? "wB" : "bB";
}

bool Bishop::canMove() {

}
