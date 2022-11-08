//
// Created by jamie on 07/11/2022.
//

#include <stdexcept>
#include <iostream>
#include "Floor.h"

std::map<Tile, char const> TileChar = {
    {Tile::FLOOR, ' '},
    {Tile::WALL, '#'},
    {Tile::DOOR, '['},
    {Tile::WATER, '~'},
};


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


void Floor::Fill(Tile tile) {
    for (int x = 0; x < m_width; x++) {
        for (int y = 0; y < m_height; y++) {
            m_array[x][y] = tile;
        }
    }
}

void Floor::generate() {
    Fill(Tile::WALL);
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

void Floor::stdout_print() {
    std::cout << "Printing Dungeon" << std::endl;
    for (int x = 0; x < m_width; x++) {
        for (int y = 0; y < m_height; y++) {
            // Init all tiles (in range) to Floor
            std::cout << TileChar[m_array[x][y]];
        }
        std::cout << std::endl;
    }
}
