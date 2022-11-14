//
// Created by jamie on 07/11/2022.
//

#include <stdexcept>
#include "Floor.h"

Floor::Floor(int width, int height) {
    if (width >= kMaxWidth) {
        throw std::runtime_error("Requested floor width exceeds kMaxWidth");
    }
    if (height >= kMaxHeight) {
        throw std::runtime_error("Requested floor height exceeds kMaxHeight");
    }
    m_width = width;
    m_height = height;
    m_tileCount = width * height;
}

void Floor::registerRendererCallback(std::function<void(Floor& f)> cb) {
    m_rendererCallback = cb;
}


void Floor::Fill(Tile tile) {
    for (int x = 0; x < m_width; x++) {
        for (int y = 0; y < m_height; y++) {
            setCoord(x, y, tile);
        }
    }
}

float Floor::calcPercentageTileType(Tile tileType) {
    int tileTypeCount = 0;
    for (int x = 0; x < m_width; x++) {
        for (int y = 0; y < m_height; y++) {
            if (m_array[x][y] == tileType) { tileTypeCount++; }
        }
    }
    return ((float) tileTypeCount / (float) m_tileCount) * 100;
}


Tile Floor::getCoord(int x, int y) {
    return m_array[x][y];
}

Tile Floor::getCoord(Coordinate coord) {
    return getCoord(coord.x, coord.y);
};


void Floor::setCoord(int x, int y, Tile tile) {
    m_array[x][y] = tile;
}

void Floor::setCoord(Coordinate coord, Tile tile) {
    setCoord(coord.x, coord.y, tile);
}
