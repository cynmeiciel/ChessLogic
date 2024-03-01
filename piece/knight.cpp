#include "knight.hpp"

Knight::Knight(bool isWhite) {
    this->m_white = isWhite;
    this->name = (isWhite)? "White Knight" : "Black Knight";
    this->abbrv = (isWhite)? "wN" : "bN";
}

bool Knight::canMove() {

}
