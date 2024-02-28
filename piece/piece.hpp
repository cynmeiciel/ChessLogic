#include <string>
#include <iostream>
#include "../constconfig.hpp"

#define newPiece std::make_shared<Piece>

class Piece {
private:
    bool m_white;
    std::string name;

    Coord xy;

public:
    Piece();
    virtual ~Piece();

    bool isWhite();
    bool setWhite_Black(bool iswhite);

    void beCaptured();

    std::string getName();

    virtual void move();
};

typedef std::shared_ptr<Piece> the_piece;