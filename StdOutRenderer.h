//
// Created by jamie on 09/11/2022.
//

#ifndef DUNGEONCPP_STDOUTRENDER_H
#define DUNGEONCPP_STDOUTRENDER_H


#include "Renderer.h"
#include "Floor.h"

class StdOutRenderer: Renderer {
public:
    std::map<Tile, char const> TileChar = {
            {Tile::FLOOR, ' '},
            {Tile::WALL, '#'},
            {Tile::DOOR, '['},
            {Tile::WATER, '~'},
    };

    void renderFloor(Floor& floor) override;
};

#endif //DUNGEONCPP_STDOUTRENDER_H
