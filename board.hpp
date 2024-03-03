#pragma once

#include "piece/includethis.hpp"
#include "constconfig.hpp"
#include <vector>
#include <string>
#include <memory>


/**
 * @class Board
 * @brief Represents a chess board.
 *
 * The Board class represents a chess board consisting of 8x8 squares. It manages the state of the board, including the positions of the pieces and the current turn state.
 */
class Board {
private:
    the_piece pieceAlive[8][8]; /**< The array representing the alive pieces on the board. */
    std::vector<the_piece> pieceDead; /**< The vector representing the captured pieces. */
    TurnState currentState; /**< The current turn state of the board. */

public:
    /**
     * @brief Default constructor for the Board class.
     */
    Board();

    /**
     * @brief Destructor for the Board class.
     */
    ~Board();

    /**
     * @brief Find the piece with the provided coordinates.
     *
     * This function searches for a piece on the board with the specified coordinates.
     *
     * @param xy The coordinates of the piece.
     * @return The pointer to the piece, or nullptr if no piece is found.
     */
    the_piece findPiecebyCoor(Coord xy);

    /**
     * @brief Notifies the board that a piece has been captured.
     *
     * This function is called when a piece is captured during the game. It updates the internal state of the board accordingly.
     *
     * @param xy The coordinates of the captured piece.
     * @param en_passant A flag indicating whether the capture was an en passant capture.
     */
    void pieceCaptured(Coord xy, bool en_passant);

    /**
     * @brief Displays the current state of the board.
     */
    void view();

    /**
     * @brief Moves a piece on the board.
     *
     * This function moves a piece from one coordinate to another. If the move is an en passant capture, the captured pawn is removed from the board.
     *
     * @param start The starting coordinate of the piece.
     * @param destination The destination coordinate of the piece.
     * @param en_passant Whether the move is an en passant capture.
     */
    void movePiece(Coord start, Coord destination, bool en_passant = false);

    /**
     * @brief Checks if a square on the board is empty.
     *
     * This function checks if a square on the board is empty (i.e., no piece is present).
     *
     * @param xy The coordinates of the square to check.
     * @return True if the square is empty, false otherwise.
     */
    inline bool isEmpty(Coord xy) {
        return this->pieceAlive[xy.x][xy.y] == nullptr;
    }

    /**
     * @brief Sets the current turn state of the board.
     *
     * @param state The turn state to set.
     */
    inline void setState(TurnState state) {
        this->currentState = state;
    }

    /**
     * @brief Creates a new piece on the board.
     *
     * This function creates a new piece of the specified type at the specified coordinate.
     *
     * @tparam TYPE_OF_PIECE The type of piece to create.
     * @param xy The coordinate at which to create the piece.
     * @param isWhite Whether the piece is white.
     */
    template <typename TYPE_OF_PIECE>
    inline void createPiece(Coord xy, bool isWhite) {
        this->pieceAlive[xy.x][xy.y] = std::make_shared<TYPE_OF_PIECE>(isWhite);
    };
};
