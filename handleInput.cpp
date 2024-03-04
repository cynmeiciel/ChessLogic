#include "game.hpp"

void Game::handlePick(bool whiteTurn, Coord xy) {
    the_piece piece = this->board->findPiecebyCoor(xy);

    if (piece == nullptr)
        this->foundNoPiece();
    else if (piece->isWhite() == whiteTurn) { // Check if having picked the right side
        this->selectedPiece = xy;
        this->selectedPtr = piece;
        this->successfully = true;
    } else {
        this->pickWrongSide();
    }
}

void Game::handleMove(Coord xy) {
    if (this->selectedPtr->canMove(this->selectedPiece, xy, *(this->board))
        && this->selectedPiece == xy) {
        this->board->movePiece(this->selectedPiece, xy);
        this->successfully = true;

    } else {
        mess("Invalid move!");
        mess("Please select again! You can type \"view\" to view the current board.");
    }
}

void Game::spotSelected(Coord xy) {
    switch (this->currentState)
    {
    case TurnState::WhiteTurn:
        this->handlePick(true, xy);
        break;
    case TurnState::WhiteSelected:
        this->handleMove(xy);
        break;
    case TurnState::BlackTurn:
        this->handlePick(false, xy);
        break;
    case TurnState::BlackSelected:
        this->handleMove(xy);
        break;
    }
}

void Game::foundNoPiece() {
    mess("No piece was found!");
    mess("Please select again! You can type \"view\" to view the current board.");
}

void Game::pickWrongSide() {
    mess("This is not your piece!");
    mess("Please select again! You can type \"view\" to view the current board.");
}

void Game::handleInput() {
    std::string input;
    std::cin >> input;

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
        this->reset();
        return;
    } else if (input == "back") {
        this->back();
        return;
    }
    
    this->checkInput(input);
}

void Game::checkInput(std::string input) {
    Coord xy;
    try {
        xy = coord(input);
        if (input.length() == 2 && xy.y <= 7) {
            // Successfully typed
            spotSelected(xy);

        } else {
            throw std::invalid_argument("Invalid input!");
        }
    } catch (const std::invalid_argument& e) {
        mess("Invalid input!");
        return;
    }
}