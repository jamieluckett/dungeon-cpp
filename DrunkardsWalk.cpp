//
// Created by jamie on 08/11/2022.
//

#include <unistd.h>
#include "DrunkardsWalk.h"
#include <chrono>
#include <thread>
#include <iostream>

int kWalkedGoalPercentage = 50;
std::array<std::pair<int, int>, 4> cardinalDirections = {{
        {0, 1},  // N
        {1, 0},  // E
        {0, -1}, // S
        {-1, 0}, // W
}};


void DrunkardsWalk::generate() {
    Fill(Tile::WALL);
    int currentWalkedPercentage = 0;
    // Choose a random starting place
    std::pair<int, int> currentCoordinates = {rand() % m_width, rand() % m_height};

    int i = 40;
    while (currentWalkedPercentage < kWalkedGoalPercentage) {
        std::pair<int, int> nextDirection = cardinalDirections[rand() % cardinalDirections.size()];
        currentCoordinates.first += nextDirection.first;
        currentCoordinates.second += nextDirection.second;
        m_array[currentCoordinates.first][currentCoordinates.second] = Tile::FLOOR;

        currentWalkedPercentage = calcPercentageTileType(Tile::FLOOR);
        i--;
        if (i == 0) {
            system("clear");
            std::cout << currentCoordinates.first << currentCoordinates.second << std::endl;
            stdout_print();
            i = 40;
        }
    }
}
