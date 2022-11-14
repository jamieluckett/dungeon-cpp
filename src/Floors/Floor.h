//
// Created by jamie on 07/11/2022.
//

#ifndef DUNGEONCPP_FLOOR_H
#define DUNGEONCPP_FLOOR_H

#include <map>
#include <random>
#include <functional>
#include "Coordinate.h"

class Renderer;

int const kMaxWidth = 200;
int const kMaxHeight = 200;

static std::random_device m_rd;
static std::mt19937 m_randomDist{m_rd()};

enum class Tile {
    EMPTY,
    FLOOR,
    WALL,
    DOOR,
    WATER,

    TILE_MAX
};

class Floor {
public:
    Tile m_array[kMaxWidth][kMaxHeight] = {};
    int m_width;
    int m_height;
    std::function<void(Floor& f)> m_rendererCallback;

    void registerRendererCallback(std::function<void(Floor& f)> cb);

    Floor(int width, int height);

    virtual void generate() = 0;

    void Fill(Tile tile);

    float calcPercentageTileType(Tile tileType);

private:
    int m_tileCount;

protected:
    Tile getCoord(int x, int y);
    Tile getCoord(Coordinate coord);

    void setCoord(int x, int y, Tile tile);
    void setCoord(Coordinate coord, Tile tile);
};

#endif //DUNGEONCPP_FLOOR_H
