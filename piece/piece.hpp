#include <string>
#include <iostream>
#include "../constconfig.hpp"

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