#include "game.hpp"

void Game::init_var() {
    this->board = new Board();
    mess("Game initialized!");
}

void Game::init_game() {
    mess("Game initialized!");
}

Game::Game() {
    this->init_var();
    this->init_game();
}

Game::~Game() {
    delete this->board;
}

void Game::viewBoard() {
    mess("View board: ");
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


