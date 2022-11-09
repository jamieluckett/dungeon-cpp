//
// Created by jamie on 07/11/2022.
//

#ifndef DUNGEONCPP_FLOOR_H
#define DUNGEONCPP_FLOOR_H

#include <map>
#include <random>
#include "Renderer.h"

int const kMaxWidth = 1000;
int const kMaxHeight = 1000;

static std::random_device m_rd;
static std::mt19937 m_randomDist{m_rd()};

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

    float calcPercentageTileType(Tile tileType);

    void renderFloor();

private:
    int m_tileCount;
    Renderer m_renderer;
};

#endif //DUNGEONCPP_FLOOR_H
