#include <iostream>
#include <getopt.h>
#include <memory>
#include "Floor.h"
#include "SFML/Graphics.hpp"

static int DefaultFloorWidth = 50;
static int DefaultFloorHeight = 50;


void printHelp() {
    std::cout << "help! help!" << std::endl;
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
                floorHeight = strtol(optarg, nullptr, 10);;
                continue;
            case 'r':
                continue;
            case 's':
                continue;
            default:
                continue;
        }
    }

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.display();
    }

    auto floor = std::make_unique<Floor>(floorWidth, floorHeight);
    floor->generate();
    floor->stdout_print();

    return 0;
}
