#include <iostream>
#include <getopt.h>
#include <memory>
#include <thread>
#include "Floor.h"
#include "SFMLRenderer.h"
#include "SFML/Graphics.hpp"
#include "SFML/OpenGL.hpp"
#include "RandomFloor.h"

static int DefaultFloorWidth = 10;
static int DefaultFloorHeight = 10;
static int StartingWindowHeight = 800;
static int StartingWindowWidth = 600;


using namespace std::chrono_literals;

void printHelp() {
    std::cout << "help! help!" << std::endl;
}

//void genrerateRenderLoops(sf::RenderWindow* sfmlWindow) {
//    sfmlWindow->setActive(true);
//    sfmlWindow->setFramerateLimit(60);
//    while (sfmlWindow->isOpen()) {
//        switch(rand() % 4) {
//            case 1:
//                sfmlWindow->clear(sf::Color::Green);
//                break;
//            case 2:
//                sfmlWindow->clear(sf::Color::Blue);
//                break;
//            case 3:
//                sfmlWindow->clear(sf::Color::Red);
//                break;
//            case 4:
//                sfmlWindow->clear(sf::Color::Green);
//                break;
//        }
//        sfmlWindow->display();
//        std::this_thread::sleep_for(1000ms);
//    }
//}

int main(int argc, char *argv[]) {

    int floorWidth = DefaultFloorWidth;
    int floorHeight = DefaultFloorHeight;
    std::string rendererName;
    std::string algorithmName;
    std::string windowTitle = "dungeongen";
    sf::View view;
    float tileSize;

    int opt;

    while (( opt = getopt(argc, argv, "?:w:h:a:")) != -1) {
        switch(opt) {
            case '?':
                printHelp();
                return -1;
            case 'w':
                floorWidth = strtol(optarg, nullptr, 10);
                continue;
            case 'h':
                floorHeight = strtol(optarg, nullptr, 10);
                continue;
            case 'a':
                algorithmName = optarg;
                continue;
            default:
                continue;
        }
    }


    // https://www.sfml-dev.org/tutorials/2.5/graphics-draw.php
    // Set window active in main thread before we pass it to the generate/render thread
    sf::RenderWindow sfmlWindow(sf::VideoMode(StartingWindowHeight, StartingWindowWidth), windowTitle);
//    sfmlWindow.setActive(false);
    auto renderer = SFMLRenderer();
    tileSize = (float) renderer.getTileSize();

    view.setCenter(sf::Vector2f(800.f, 600.f));
    view.setSize(sf::Vector2f(tileSize * (float) floorWidth, tileSize * (float) floorHeight));

    sfmlWindow.setView(view);
    sf::Sprite sprite;
    sprite.setTexture(renderer.TileTextureMap[Tile::DOOR]);
    sfmlWindow.draw(sprite);

//    std::thread threadObj(genrerateRenderLoops, &sfmlWindow);
//    threadObj.detach();
//    std::this_thread::sleep_for(100ms);

    while (sfmlWindow.isOpen()) {
        sf::Event event{};
        while (sfmlWindow.pollEvent(event))
        {
            switch(event.type) {
                case sf::Event::Closed:
                    sfmlWindow.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    std::cout << "clik" << std::endl;
                    break;
                case sf::Event::KeyPressed:
                    switch(event.key.code) {
                        case sf::Keyboard::Key::Hyphen:
                            std::cout << "- zoom out" << std::endl;
                        case sf::Keyboard::Key::Subtract:
                            view.zoom(0.9f);
                            break;
                        case sf::Keyboard::Key::Add:
                            std::cout << "+ zoom in" << std::endl;
                            view.zoom(1.11111111111f);
                            break;
                        default:
                            break;
                    }
                default:
                    break;
            }
        }
        sfmlWindow.display();
    }

//    sf::RenderTexture renderTexture;
//    renderTexture.create(floorWidth * 32, floorHeight*32);
//
//    auto floor = std::make_unique<RandomFloor>(floorWidth, floorHeight);
//
//    auto cbLambda = [&](Floor& f){renderer.renderFloor(f);};
//    floor->registerRendererCallback(cbLambda);

}
