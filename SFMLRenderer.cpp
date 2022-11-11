//
// Created by jamie on 10/11/2022.
//

#include <SFML/Graphics/Texture.hpp>
#include <stdexcept>
#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>
#include "SFMLRenderer.h"
#include "Floor.h"


SFMLRenderer::SFMLRenderer(sf::RenderWindow& window): m_sfmlWindow(window) { }

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
    for (auto tileTexturePair : TileTextureNameMap) {
        TileTextureMap[tileTexturePair.first] = loadTexture(tileTexturePair.second);
    }
}

void SFMLRenderer::renderFloor(Floor& floor) {
    for (int x = 0; x < floor.m_width; x++) {
        for (int y = 0; y < floor.m_height; y++) {

        }
    }
}
