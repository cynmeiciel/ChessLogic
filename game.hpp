#pragma once

#include "constconfig.hpp"
#include "board.hpp"

/**
 * @class Game
 * @brief Represents a chess game.
 *
 * The Game class represents a chess game. It manages the game state, including the chess board and the current turn state.
 */
class Game {
private:

    bool isRunning;

    /// @brief if the last move was successful
    bool successfully;
    Board* board;
    TurnState currentState;

    /// @brief The coordinates of the selected piece that is to be moved.
    Coord selectedPiece;
    the_piece selectedPtr;

    /**
     * @brief Quits the game.
     *
     * This function ends the game and cleans up any necessary resources.
     */
    void quitGame();

    /**
     * @brief Displays the current state of the chess board.
     *
     * This function prints the current state of the chess board to the console.
     */
    void viewBoard();

    /**
     * @brief Checks if the input is a valid chess coordinate.
     *
     * @param input The user input to be checked.
     */
    void checkInput(std::string input);

    /**
     * @brief Handles the case when the user picks a chess piece.
     *
     * @param whiteTurn True if it is currently white's turn, False if it is black's turn.
     * @param xy The coordinates of the selected piece.
     */
    void handlePick(bool whiteTurn, Coord xy);

    /**
     * @brief Handles the case when the user moves a chess piece.
     *
     * @param whiteTurn True if it is currently white's turn, False if it is black's turn.
     * @param xy The coordinates of the selected piece.
     */
    void handleMove(Coord xy);

    /**
     * @brief Displays the help menu.
     *
     * This function prints the help menu to the console.
     */
    void viewHelp();

    /**
     * @brief Handles user input.
     *
     * This function waits for user input and performs the corresponding action based on the input.
     */
    void handleInput();

    /**
     * @brief Handles the case when the user picks a wrong side.
     */
    void pickWrongSide();

    /**
     * @brief Undoes the last move and goes back to the previous state.
     */
    void back();

    /**
     * @brief The main game loop.
     *
     * This function contains the main game loop that continues until the game is over.
     */
    void mainloop();

    /**
     * @brief Handles the case when a spot on the chess board is selected.
     *
     * @param xy The coordinates of the selected spot.
     */
    void spotSelected(Coord xy);

    /**
     * @brief Handles the case when no chess piece is found at the selected spot.
     */
    void foundNoPiece();

public:

    /**
     * @brief Default constructor.
     *
     * Initializes a new instance of the Game class.
     */
    Game();

    /**
     * @brief Destructor.
     *
     * Cleans up any resources used by the Game instance.
     */
    ~Game();

    /**
     * @brief Starts the game.
     *
     * This function initializes the game and starts the main game loop.
     */
    void start();

    /**
     * @brief Resets the game.
     *
     * This function resets the game to its initial state.
     */
    void reset();

};