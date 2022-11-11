//
// Created by jamie on 07/11/2022.
//

#include <iostream>
#include "RandomFloor.h"
#include "Renderer.h"

void RandomFloor::generate() {
    std::cout << "help! help!" << std::endl;

    for (int x = 0; x < m_width; x++) {
        for (int y = 0; y < m_height; y++) {
            std::cout << "help! help!" << std::endl;
            m_array[x][y] = Tile(std::rand() % (int) Tile::TILE_MAX);
            m_renderer->renderFloor(*this);

        }
    }
}
