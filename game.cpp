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
}

void Game::viewHelp() {
    mess("View help: ");
}

void Game::start() {
    mess("Welcome to chess!");

    this->mainloop();
}

void Game::quitGame() {
    this->isRunning = false;
    std::cout << "Game quited!" << std::endl;
}


