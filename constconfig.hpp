#pragma once

#include <iostream>
#include <string>
#include <memory>

// typedef std::uint_least8_t Coord;
typedef std::shared_ptr<Piece> the_piece;

struct Coord {
    std::uint_least8_t x;
    std::uint_least8_t y;
};

inline void mess(std::string mez) {
    std::cout << mez << std::endl;
}

inline std::string XY(std::string raw_coord) {

    std::string coordi;

    std::cout << raw_coord[0] << std::endl;

    switch ((raw_coord[0]))
    {
    case 'a':
        coordi = "0";
        break;
    case 'b':
        coordi = "1";
        break;
    case 'c':
        coordi = "2";
        break;
    case 'd':
        coordi = "3";
        break;
    case 'e':
        coordi = "4";
        break;
    case 'f':
        coordi = "5";
        break;
    case 'g':
        coordi = "6";
        break;
    case 'h':
        coordi = "7";
        break;
    default:
        return "INVALID!";
        break;
    }
    return coordi.append(1, raw_coord[1]);
}

inline Coord coord(std::string raw_coord) {
    std::uint_least8_t a = (std::stoi(XY(raw_coord)));
    Coord xy;
    xy.x = a / 10;
    xy.y = a % 10;

    return xy;
}

enum class TurnState {
    WhiteTurn, WhiteSelected, BlackTurn, BlackSelected
};

enum class GameState {
    Active, WhiteWin, BlackWin, Stalemate
};
