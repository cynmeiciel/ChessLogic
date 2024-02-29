#pragma once

#include <string>
#include <iostream>
#include "../constconfig.hpp"

class Piece {
protected:
    bool m_white;
    std::string name;
    std::string abbrv;

    Coord xy;

public:

    bool isWhite();
    bool setWhite_Black(bool iswhite);

    void beCaptured();

    std::string getName();
    std::string getAbbrv();

    virtual bool move() = 0;
};

typedef std::shared_ptr<Piece> the_piece;