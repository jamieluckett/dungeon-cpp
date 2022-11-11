//
// Created by jamie on 09/11/2022.
//

#include <iostream>
#include "StdOutRenderer.h"
#include "Floor.h"

void StdOutRenderer::renderFloor(Floor& floor) {
    for (int x = 0; x < floor.m_width; x++) {
        for (int y = 0; y < floor.m_height; y++) {
            // Init all tiles (in range) to Floor
            std::cout << TileChar[floor.m_array[x][y]];
        }
        std::cout << std::endl;
    }
}
