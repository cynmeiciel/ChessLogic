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
                break;
            case TurnState::WhiteSelected:
                this->currentState = TurnState::BlackTurn;
                break;
            case TurnState::BlackTurn:
                this->currentState = TurnState::BlackSelected;
                break;
            case TurnState::BlackSelected:
                this->currentState = TurnState::WhiteTurn;
                break;
            }
        }
    }

}