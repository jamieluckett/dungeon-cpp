//
// Created by jamie on 08/11/2022.
//

#include <unistd.h>
#include "DrunkardsWalk.h"
#include "Coordinate.h"
#include <iostream>
#include <array>

static int kWalkedGoalPercentage = 45;
static std::uniform_int_distribution uid(0,3);

std::array<Coordinate, 4> cardinalDirections = {{
        {0, 1},  // N
        {1, 0},  // E
        {0, -1}, // S
        {-1, 0}, // W
}};


Coordinate randomDirection() {
    return cardinalDirections[uid(m_randomDist)];
}

void DrunkardsWalk::generate() {
    Fill(Tile::WALL);
    float currentWalkedPercentage = 0;
    // Choose a random starting place
    Coordinate currentCoordinates = {
            std::uniform_int_distribution(0, m_width - 1)(m_randomDist),
            std::uniform_int_distribution(0, m_height - 1)(m_randomDist),
    };

    int i = 0;
    int lastP = 0;

    m_randomDist;

    std::cout << currentCoordinates.prettyName() << std::endl;
    while (currentWalkedPercentage < kWalkedGoalPercentage) {
        Coordinate nextDirection = randomDirection();

        Coordinate proposedCoordinates = currentCoordinates + nextDirection;
        // Check proposedCoordinates is in-bounds
//        if (
//                proposedCoordinates.m_x >= 0 &&
//                proposedCoordinates.m_x < m_width &&
//                proposedCoordinates.m_y >= 0
//                && proposedCoordinates.m_y < m_height
//        ) {
        if (
                proposedCoordinates.m_x >= 1 &&
                proposedCoordinates.m_x < m_width - 1 &&
                proposedCoordinates.m_y >= 11
                && proposedCoordinates.m_y < m_height - 1
                ) {
            currentCoordinates = proposedCoordinates;
            m_array[currentCoordinates.m_x][currentCoordinates.m_y] = Tile::FLOOR;

            currentWalkedPercentage = calcPercentageTileType(Tile::FLOOR);
            if ((int) currentWalkedPercentage > lastP) {
                system("clear");
                std::cout << currentCoordinates.prettyName() + " | % = " + std::to_string(currentWalkedPercentage) << std::endl;
                stdout_print();
                lastP = (int) currentWalkedPercentage;
            }
        }
    }
}
