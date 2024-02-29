#include "board.hpp"

Board::Board() {
    const int initial[8][8] = {
    //    a   b   c   d   e   f   g   h
        { 6,  5,  4,  3,  2,  4,  5,  6},//1
        { 1,  1,  1,  1,  1,  1,  1,  1},//2
        { 0,  0,  0,  0,  0,  0,  0,  0},//3
        { 0,  0,  0,  0,  0,  0,  0,  0},//4
        { 0,  0,  0,  0,  0,  0,  0,  0},//5
        { 0,  0,  0,  0,  0,  0,  0,  0},//6
        {-1, -1, -1, -1, -1, -1, -1, -1},//7
        {-6, -5, -4, -3, -2, -4, -5, -6} //8
        // Note that it is reversed
    };

    for (int row = 0; row < 8; ++row) {
        mess("_");
        for (int col = 0; col < 8; ++col) {
            std::cout << initial[row][col] << "  ";
            Coord xy(col, row);
            bool white = (initial[row][col] > 0)? true : false;

            switch (abs(initial[row][col]))
            {
            case 6:
                this->createPiece<Rook>(xy, white);
                std::cout << "Created Rook at: " << xy.x << xy.y << std::endl;
                break;
            case 5:
                this->createPiece<Knight>(xy, white);
                std::cout << "Created Knight at: " << xy.x << xy.y << std::endl;
                break;
            case 4:
                this->createPiece<Bishop>(xy, white);
                std::cout << "Created Bishop at: " << xy.x << xy.y << std::endl;
                break;
            case 3:
                this->createPiece<Queen>(xy, white);
                std::cout << "Created Queen at: " << xy.x << xy.y << std::endl;
                break;
            case 2:
                this->createPiece<King>(xy, white);
                std::cout << "Created King at: " << xy.x << xy.y << std::endl;
                break;
            case 1:
                this->createPiece<Pawn>(xy, white);
                std::cout << "Created Pawn at: " << xy.x << xy.y << std::endl;
                break;
            case 0:
                this->pieceAlive[col][row] = nullptr;
                std::cout << "Created Nothing at: " << xy.x << xy.y << std::endl;
                break;
            }
        }
    }
}


Board::~Board() {
    mess("Board cleaned!");
}

void Board::pieceCaptured(Coord xy, bool en_passant) {
    the_piece captured;
    captured = this->findPiecebyCoor(xy);
    if (en_passant) {
        switch (this->currentState)
        {
        case TurnState::WhiteSelected:
            xy.y -= 1;
            break;
        case TurnState::BlackSelected:
            xy.y += 1;
            break;
        }
        this->pieceAlive[xy.x][xy.y] = nullptr;
    }
        this->pieceDead.push_back(captured);
}


void Board::view() {
    
}

void Board::movePiece(Coord start, Coord destination, bool en_passant) {
    if (this->pieceAlive[destination.x][destination.y] != nullptr || en_passant)
        this->pieceCaptured(destination, en_passant);

    this->pieceAlive[destination.x][destination.y]
                        =
    std::move(this->pieceAlive[start.x][start.y]);
}
