#include "game.hpp"

Game::Game() {
    this->isRunning = true;
    this->board = new Board();
    this->currentState = TurnState::WhiteTurn;
    this->successfully = false;

    mess("Game initialized!");
    std::cout << "\n";
}

Game::~Game() {
    delete this->board;
}

void Game::viewBoard() {
    mess("View board: ");
    this->board->view();
    switch (this->currentState)
    {
    case TurnState::WhiteTurn:
    case TurnState::WhiteSelected:
        mess("White Turn");
        break;
    default:
        mess("Black Turn");
        break;
    }
}

void Game::viewHelp() {
    mess("View help: ");
}

void Game::start()
{
    mess("Welcome to chess!");
    mess("Select a piece!");
    this->mainloop();
}

void Game::back() {
    switch (this->currentState)
    {
    case TurnState::WhiteSelected:
        this->currentState = TurnState::WhiteTurn;
        break;
    case TurnState::BlackSelected:
        this->currentState = TurnState::BlackTurn;
    default:
        break;
    }
}

void Game::quitGame() {
    this->isRunning = false;
    mess("Quited!");
}


