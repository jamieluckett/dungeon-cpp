//
// Created by jamie on 07/11/2022.
//

#include "RandomFloor.h"

void RandomFloor::generate() {
    for (int x = 0; x < m_width; x++) {
        for (int y = 0; y < m_height; y++) {
            m_array[x][y] = Tile(std::rand() % (int) Tile::TILE_MAX); // NOLINT(cert-msc30-c, cert-msc50-cpp)
        }
    }
}
