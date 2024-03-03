#include "board.hpp"

Board::Board() {
    // BOARD OF PIECES
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

the_piece Board::findPiecebyCoor(Coord xy) {
    the_piece piece = this->pieceAlive[xy.x][xy.y];
    return piece;
}

void Board::pieceCaptured(Coord xy) {
    the_piece captured = this->findPiecebyCoor(xy);
    this->pieceDead.push_back(captured);
}

void Board::performEnPassant(Coord enPassant) {
    this->pieceAlive[enPassant.x][enPassant.y] = nullptr;
    this->pieceCaptured(enPassant);
}

void Board::movePiece(Coord start, Coord destination) {
    if (!this->isEmpty(destination))
        this->pieceCaptured(destination);

    this->pieceAlive[destination.x][destination.y]
                        =
    std::move(this->pieceAlive[start.x][start.y]);
}

bool Board::isEmptyLine(Coord start, Coord end) {
    // Error handling if the start and end are not in the same line
    if (start.x != end.x && start.y != end.y)
        throw std::invalid_argument("The start and end are not in the same line!");

    // Error handling if the start and end are the same
    if (start.x == end.x && start.y == end.y)
        throw std::invalid_argument("The start and end are the same!");

    // Check if the line is empty except for the start cell
    if (start.x == end.x) {
        int dy = (end.y - start.y) / abs(end.y - start.y);
        for (int y = start.y + dy; y != end.y; y += dy) {
            if (!this->isEmpty(Coord(start.x, y)))
                return false;
        }
    } else {
        int dx = (end.x - start.x) / abs(end.x - start.x);
        for (int x = start.x + dx; x != end.x; x += dx) {
            if (!this->isEmpty(Coord(x, start.y)))
                return false;
        }
    }
    return true;
}

bool Board::isEmptyDiagonal(Coord start, Coord end) {
    // Error handling if the start and end are not in the same diagonal
    if (abs(start.x - end.x) != abs(start.y - end.y))
        throw std::invalid_argument("The start and end are not in the same diagonal!");

    // Error handling if the start and end are the same
    if (start.x == end.x && start.y == end.y)
        throw std::invalid_argument("The start and end are the same!");

    // Check if the diagonal is empty except for the start cell
    int dx = (end.x - start.x) / abs(end.x - start.x);
    int dy = (end.y - start.y) / abs(end.y - start.y);
    for (int x = start.x + dx, y = start.y + dy; x != end.x; x += dx, y += dy) {
        if (!this->isEmpty(Coord(x, y)))
            return false;
    }
    return true;
}

void Board::view() {
    std::cout.setf(std::ios::left | std::ios::fixed);
    for (int row = 7; row >= 0; row--) {
        mess("");
        std::cout << row+1 << "  ";
        for (int col = 0; col < 8; col++) {
            bool empty = (this->isEmpty(Coord(col, row)));
            std::string mez = (empty)? "[ ]" : this->pieceAlive[col][row]->getAbbrv();
            std::cout << std::setw(5) << mez;
        }
    }
    std::cout << "\n" << std::endl << "   A    B    C    D    E    F    G    H    _";
}
