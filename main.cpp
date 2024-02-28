#include "game.hpp"

int main() {

    Game* game = new Game();

    // Game running
    game->start();

    delete game;
    return 0;
}