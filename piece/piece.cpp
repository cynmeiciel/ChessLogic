#include "piece.hpp"

bool Piece::isWhite() {
    return this->m_white;
}

bool Piece::setWhite_Black(bool iswhite) {
    this->m_white = iswhite;
}

void Piece::beCaptured() {
    std::cout << "Was captured!";
}

std::string Piece::getName() {
    return this->name;
}
