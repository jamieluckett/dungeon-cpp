//
// Created by jluckett on 08/11/22.
//

#include "Coordinate.h"

Coordinate::Coordinate(int x, int y) {
    this->x = x;
    this->y = y;
};

Coordinate Coordinate::operator+(const Coordinate& c) const {
    return {x + c.x, y + c.y};
}

Coordinate Coordinate::operator-(const Coordinate& c) const {
    return {x - c.x, y - c.y};
}

bool Coordinate::operator==(const Coordinate& c) const {
    return (x == c.x && y == c.y);
}

bool Coordinate::operator!=(const Coordinate& c) const {
    return !(*this == c);
}

std::string Coordinate::prettyName() const {
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}
