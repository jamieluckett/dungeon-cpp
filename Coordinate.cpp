//
// Created by jluckett on 08/11/22.
//

#include "Coordinate.h"

Coordinate::Coordinate(int x, int y) {
    m_x = x;
    m_y = y;
};

Coordinate Coordinate::operator+(const Coordinate& c) const {
    return {m_x + c.m_x, m_y + c.m_y};
}

Coordinate Coordinate::operator-(const Coordinate& c) const {
    return {m_x - c.m_x, m_y - c.m_y};
}

bool Coordinate::operator==(const Coordinate& c) const {
    return (m_x == c.m_x && m_y == c.m_y);
}

bool Coordinate::operator!=(const Coordinate& c) const {
    return !(*this == c);
}

std::string Coordinate::prettyName() {
    return "(" + std::to_string(m_x) + ", " + std::to_string(m_y) + ")";
}
