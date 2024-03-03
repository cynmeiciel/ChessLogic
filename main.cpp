#include "game.hpp"

int main() {

    Game* game = new Game();

    // Start the game
    game->start();

    // Clean up
    delete game;
    return 0;
}