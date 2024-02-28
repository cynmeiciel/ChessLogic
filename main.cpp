#include "game.hpp"

int main() {

    Game* game = new Game();

    game->start();
    // Game running

    delete game;
    return 0;
}