//
// Created by jamie on 07/11/2022.
//

#ifndef DUNGEONCPP_FLOOR_H
#define DUNGEONCPP_FLOOR_H

#include <map>
#include <random>

class Renderer;

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
    Renderer* m_renderer;


    Floor(int width, int height, &Renderer renderer);

    virtual void generate();

    void Fill(Tile tile);

    float calcPercentageTileType(Tile tileType);

private:
    int m_tileCount;
};

#endif //DUNGEONCPP_FLOOR_H
