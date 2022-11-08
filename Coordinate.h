//
// Created by jluckett on 08/11/22.
//

#ifndef DUNGEONCPP_COORDINATE_H
#define DUNGEONCPP_COORDINATE_H

#include <string>

class Coordinate {
public:
    Coordinate(int x, int y);

    Coordinate operator+(const Coordinate& c) const;
    Coordinate operator-(const Coordinate& c) const;
    bool operator==(const Coordinate& c) const;
    bool operator!=(const Coordinate& c) const;

    std::string prettyName();

    int m_x;
    int m_y;
};


#endif //DUNGEONCPP_COORDINATE_H
