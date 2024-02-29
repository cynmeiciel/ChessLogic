#pragma once

#include "constconfig.hpp"
#include "board.hpp"

class Game {
private:

    bool isRunning;
    /// @brief True if the action was taken successfully, thus changing the state of the game
    bool successfully;
    Board* board;
    TurnState currentState;

    Coord selectedPiece;


    void quitGame();

    void viewBoard();
    void viewHelp();


    void handleInput();
    /// @brief Check if the input is a valid chess coordinate
    void checkInput(std::string input);
    void pickWrongSide();
    void captureAlly();

    void handlePick(bool whiteTurn, Coord xy);
    void handleMove(bool whiteTurn, Coord xy);

    void back();

    void mainloop();

    void spotSelected(Coord xy);
    void foundNoPiece();

public:

    Game();
    virtual ~Game();

    void start();

};