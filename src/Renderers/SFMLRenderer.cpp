//
// Created by jamie on 10/11/2022.
//

#include "Floor.h"
#include "SFMLRenderer.h"
#include <GL/gl.h>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>
#include <stdexcept>


SFMLRenderer::SFMLRenderer() {
    loadTextures();
}

sf::Texture SFMLRenderer::loadTexture(const std::string& textureName) {
    sf::Texture texture;
    std::string texturePath = "tiles/" + textureName;
    std::cout << "Loading " + texturePath << std::endl;

    if (!texture.loadFromFile(texturePath))  {
        throw std::runtime_error("");
    }
    texture.setSmooth(false);
    return texture;
}

void SFMLRenderer::loadTextures() {
    for (const auto& tileTexturePair : TileTextureNameMap) {
        TileTextureMap[tileTexturePair.first] = loadTexture(tileTexturePair.second);
    }
}

int SFMLRenderer::getTileSize() {
    // a LOT of faith here that the textures are both square and all the same size
    return (int) TileTextureMap.begin()->second.getSize().x;
}

void SFMLRenderer::renderFloor(Floor& floor) {
    // TODO - Use SF::View
    //   https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1View.php
    for (int x = 0; x < floor.m_width; x++) {
        for (int y = 0; y < floor.m_height; y++) {
            auto tile = floor.m_array[x][y];
            if (tile != Tile::EMPTY) {
                sf::Sprite sprite;
                auto texture = TileTextureMap[tile];
                sprite.setTexture(texture);
                sprite.setPosition(x * texture.getSize().x, y * texture.getSize().y);
                m_sfmlWindow.draw(sprite);
            }
        }
    }
    m_sfmlWindow.display();
}
