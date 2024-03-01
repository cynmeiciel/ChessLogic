#include "piece.hpp"

bool Piece::isWhite()
{
    return this->m_white;
}

void Piece::beCaptured() {
    std::cout << "Was captured!";
}

std::string Piece::getName() {
    return this->name;
}

std::string Piece::getAbbrv() {
    return this->abbrv;
}
