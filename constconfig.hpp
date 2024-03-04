#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <memory>
#include <optional>


/// @brief A struct representing a coordinate on the board.
struct Coord {
    std::uint_least8_t x;
    std::uint_least8_t y;

    Coord(std::uint_least8_t a, std::uint_least8_t b) : x(a), y(b) {}
    Coord() {};

    std::string to_string() {
        std::string s;
        s.append(1, (char)(x + 97));
        s.append(1, (char)(y + 49));
        return s;
    }

    friend bool operator==(const Coord& a, const Coord& b) {
        return a.x == b.x && a.y == b.y;
    }

    friend bool operator!=(const Coord& a, const Coord& b) {
        return !(a == b);
    }
};

/**
 * @brief Prints a message to the console.
 *
 * This function prints the specified message to the console, followed by a newline.
 *
 * @param mez The message to print.
 */
inline void mess(std::string mez) {
    std::cout << mez << "\n" << std::endl;
}

/**
 * @brief Converts a chess coordinate to an array index.
 *
 * This function converts a chess coordinate to an array index.
 *
 * @param raw_coord The raw chess coordinate to convert.
 * @return The array index corresponding to the chess coordinate.
 */
inline std::string XY(std::string raw_coord) {

    std::string coordi;

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

/**
 * @brief Converts a raw chess coordinate to a Coord struct.
 *
 * This function converts a raw chess coordinate to a Coord struct.
 *
 * @param raw_coord The raw chess coordinate to convert.
 * @return The Coord struct corresponding to the chess coordinate.
 */
inline Coord coord(std::string raw_coord) {
    std::uint_least8_t a = (std::stoi(XY(raw_coord)));
    Coord xy;
    xy.x = a / 10;
    xy.y = a % 10 - 1;

    return xy;
}

/// @brief An enum representing the current turn state of the game.
enum class TurnState {
    WhiteTurn, WhiteSelected, BlackTurn, BlackSelected
};
