#include "game.hpp"


void Game::mainloop() {

    while (this->isRunning) {
        mess("Input");
        handleInput();
    }

}