//
// Created by jamie on 07/11/2022.
//

#include <iostream>
#include "RandomFloor.h"

static std::uniform_int_distribution uid((int) Tile::EMPTY + 1,(int) Tile::TILE_MAX - 1);

void RandomFloor::generate() {
    std::cout << "help! help!" << std::endl;

    for (int x = 0; x < m_width; x++) {
        for (int y = 0; y < m_height; y++) {
            setCoord(x, y, Tile(uid(m_randomDist)));
            m_rendererCallback(*this);
        }
    }
}
