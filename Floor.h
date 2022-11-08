//
// Created by jamie on 07/11/2022.
//

#ifndef DUNGEONCPP_FLOOR_H
#define DUNGEONCPP_FLOOR_H

#include <map>

int const kMaxWidth = 100;
int const kMaxHeight = 100;

enum class Tile {
    FLOOR,
    WALL,
    DOOR,
    WATER,

    TILE_MAX
};

extern std::map<Tile, char const> TileChar;

class Floor {
public:
    Tile m_array[kMaxWidth][kMaxHeight];
    int m_width;
    int m_height;

    Floor(int width, int height);

    virtual void generate();

    void stdout_print();

    void Fill(Tile tile);
};

#endif //DUNGEONCPP_FLOOR_H
