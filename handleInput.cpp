#include "game.hpp"
#include "board.hpp"

the_piece Board::findPiecebyCoor(Coord xy) {
    return this->pieceAlive[xy.x][xy.y];
}

void Game::spotSelected(Coord xy) {
    the_piece piece = this->board->findPiecebyCoor(xy);

    if (piece == nullptr)
        this->foundNoPiece();
    else {
        mess("Piece founded:");
        // mess(piece->getName());

        this->successfully = true;
    }
}

void Game::foundNoPiece() {
    mess("No piece was found!");
    mess("Please select again!");
}

void Game::handleInput() {
    std::string input;
    std::cin >> input;
    mess(input);

    if (input == "quit") {
        this->quitGame();
        return;
    } else if (input == "view") {
        this->viewBoard();
        return;
    } else if (input == "help") {
        this->viewHelp();
        return;
    } else if (input == "reset") {
        this->start();
        return;
    }

    // switch (turnState)
    // {
    // case TurnState::WhiteTurn:
        
    //     break;
    
    // default:
    //     break;
    // }

    Coord xy;
    try {
        if (input.length() == 2 && input[1] >= 1 && input[1] <= 8) {
            // Successfully typed
            xy = coord(input);
            spotSelected(xy);

        } else {
            throw std::invalid_argument("Invalid input");
        }
    } catch (const std::invalid_argument& e) {
        mess("Invalid input!");
        return;
    }
    // continue to handle
}
