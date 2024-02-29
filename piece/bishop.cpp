#include "bishop.hpp"

Bishop::Bishop(bool isWhite) {
    this->m_white = isWhite;
    this->name = (isWhite)? "White Bishop" : "Black Bishop";
}

bool Bishop::move() {

}
