#include "game.hpp"


void Game::mainloop() {

    while (this->isRunning) {
        mess("Input");
        handleInput();

        if (this->successfully) {
            this->successfully = false;

            switch (this->currentState)
            {
            case TurnState::WhiteTurn:
                this->currentState = TurnState::WhiteSelected;
                mess("Select your destination!");
                break;
            case TurnState::WhiteSelected:
                this->currentState = TurnState::BlackTurn;
                mess("Select your piece!");
                break;
            case TurnState::BlackTurn:
                this->currentState = TurnState::BlackSelected;
                mess("Select your destination!");
                break;
            case TurnState::BlackSelected:
                this->currentState = TurnState::WhiteTurn;
                mess("Select your piece!");
                break;
            }
        }
    }

}
