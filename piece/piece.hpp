#pragma once

#include <string>
#include <iostream>
#include "../constconfig.hpp"

/// @brief An abstract class representing a piece on the board
class Piece {
protected:
    /// @brief A boolean representing the color of the piece, true for white, false for black
    bool m_white;
    /// @brief A string representing the name of the piece
    std::string name;
    /// @brief A string representing the abbreviation of the piece
    std::string abbrv;
public:

    /// @brief Get the color of the piece
    /// @return true if the piece is white, false if the piece is black
    bool isWhite();

    /// @brief Handle when the piece is captured
    void beCaptured();
    
    /// @brief Get the name of the piece
    std::string getName();
    /// @brief Get the abbreviation of the piece
    std::string getAbbrv();

    /// @brief A pure virtual function to check if the piece can move
    virtual bool canMove() = 0;
};

/// @brief A pointer representing a piece locating on the board, if not nullptr
typedef std::shared_ptr<Piece> the_piece;