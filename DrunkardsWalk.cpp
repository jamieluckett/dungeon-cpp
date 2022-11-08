//
// Created by jamie on 08/11/2022.
//

#include "DrunkardsWalk.h"

void DrunkardsWalk::generate() {
    Fill(Tile::WALL);
    // Choose a random starting place
    std::pair<int, int> startingCoordinates = {rand() % m_width, rand() % m_height};
}
