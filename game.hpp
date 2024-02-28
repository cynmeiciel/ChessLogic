#pragma once

#include "constconfig.hpp"
#include "board.hpp"

class Game {
private:

    bool isRunning;
    Board* board;

    void init_var();
    void init_game();

    void quitGame();

    void viewBoard();
    void viewHelp();


    void handleInput();
    void mainloop();

    void spotSelected(Coord xy);

public:

    Game ();
    virtual ~Game();

    void start();

};