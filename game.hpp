#pragma once

#include "constconfig.hpp"
#include "board.hpp"

class Game {
private:

    bool isRunning;
    bool successfully;
    Board* board;
    TurnState currentState;


    void quitGame();

    void viewBoard();
    void viewHelp();


    void handleInput();
    void mainloop();

    void spotSelected(Coord xy);
    void foundNoPiece();

public:

    Game();
    virtual ~Game();

    void start();

};