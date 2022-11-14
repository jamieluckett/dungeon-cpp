//
// Created by jamie on 10/11/2022.
//

#ifndef DUNGEONCPP_SFMLRENDERER_H
#define DUNGEONCPP_SFMLRENDERER_H

#include "Floor.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Renderer.h"

class SFMLRenderer: public Renderer {
public:
    SFMLRenderer();

    std::map<Tile, sf::Texture> TileTextureMap;
    std::map<Tile, std::string> TileTextureNameMap = {
            {Tile::FLOOR, "dirt0.png"},
            {Tile::WALL, "brick_dark3.png"},
            {Tile::DOOR, "dngn_closed_door.png"},
            {Tile::WATER, "dngn_open_sea.png"},
    };

    void loadTextures();
    void renderFloor(Floor& floor) override;

    int getTileSize();

private:
    sf::RenderWindow m_sfmlWindow;
    static sf::Texture loadTexture(const std::string& textureName);

};

#endif //DUNGEONCPP_SFMLRENDERER_H
