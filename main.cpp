#include <iostream>
#include <getopt.h>
#include <memory>
#include "Floor.h"
#include "Renderer.h"
#include "SFMLRenderer.h"
#include "SFML/Graphics.hpp"
#include "SFML/OpenGL.hpp"
#include "DrunkardsWalk.h"
#include "RandomFloor.h"

static int DefaultFloorWidth = 50;
static int DefaultFloorHeight = 50;


void printHelp() {
    std::cout << "help! help!" << std::endl;
}

void sfmlHelloWorldTypeFunction() {

    std::string windowTitle = "dungeongen";

    sf::RenderWindow window(sf::VideoMode(32 * 15, 32 * 15), windowTitle);
    window.clear(sf::Color::Black);
    window.setActive();
    auto sfmlRenderer = SFMLRenderer(window);
    auto floor = std::make_unique<RandomFloor>(15, 15, & sfmlRenderer);

    sfmlRenderer.loadTextures();

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            switch(event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                default:
                    break;
            }
        }

        floor->generate();
        window.display();
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}


int main(int argc, char *argv[]) {

    int floorWidth = DefaultFloorWidth;
    int floorHeight = DefaultFloorHeight;
    int c;

    while ((c = getopt(argc, argv, "?:w:h:rs")) != -1) {
        switch(c) {
            case '?':
                printHelp();
                return -1;
            case 'w':
                floorWidth = strtol(optarg, nullptr, 10);
                continue;
            case 'h':
                floorHeight = strtol(optarg, nullptr, 10);
                continue;
            case 'r':
                continue;
            case 's':
                continue;
            default:
                continue;
        }
    }

    sfmlHelloWorldTypeFunction();

    return 0;
}