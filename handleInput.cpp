#include "game.hpp"

the_piece Board::findPiecebyCoor(Coord xy) {
    return this->pieceAlive[xy.x][xy.y];
}

void Game::spotSelected(Coord xy) {
    the_piece piece = this->board->findPiecebyCoor(xy);

    if (piece == nullptr) {
        
    } else {
        
    }
}


void Game::handleInput() {
    std::string input;
    std::cin >> input;
    mess(input);

    Coord xy;

    try {
        xy = coord(input.substr(input.length() - 2));
    }
    catch (const char* ms ) {
        if (input == "quit") this->quitGame();
        else if (input == "view") this->viewBoard();
        else if (input == "help") this->viewHelp();
        else if (input == "reset") this->start();
        else mess("INVALID INPUT!");

        return;
    }

    spotSelected(xy);

    // continue to handle
}
