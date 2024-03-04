#include "game.hpp"

void Game::resetParamsOnTurnSwitch() {
    this->successfully = false;

    switch (this->currentState)
    {
    case TurnState::WhiteSelected:
    case TurnState::BlackSelected:
        this->selectedPtr.reset();
        break;
    default:
        if (this->board->enPassantDeclared) {
            this->board->enPassantDeclared = false;
        } else if (this->board->enPassantPawn.has_value())
            this->board->enPassantPawn.reset();
        break;
    }
}

void Game::mainloop() {

    while (this->isRunning) {
        mess("Input");
        this->handleInput();

        if (this->successfully) {
            this->resetParamsOnTurnSwitch();

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
            // if (this->board->enPassantPawn.has_value()) {
            //     std::cout << "En passant: " << this->board->enPassantPawn.value().to_string() 
            //     << std::endl;
            // }
        } else {
            this->back();
        }
    }

}
