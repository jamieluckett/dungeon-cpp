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
    m_drunkardLocation = {
            std::uniform_int_distribution(0, m_width - 1)(m_randomDist),
            std::uniform_int_distribution(0, m_height - 1)(m_randomDist),
    };

    int lastP = 0;

    std::cout << m_drunkardLocation.prettyName() << std::endl;
    while (currentWalkedPercentage < kWalkedGoalPercentage) {
        Coordinate nextDirection = randomDirection();

        Coordinate proposedCoordinates = m_drunkardLocation + nextDirection;
        if (proposedCoordinates.x >= 1 && proposedCoordinates.x < m_width - 1 && proposedCoordinates.y >= 11 && proposedCoordinates.y < m_height - 1) {
            m_drunkardLocation = proposedCoordinates;
            m_array[m_drunkardLocation.x][m_drunkardLocation.y] = Tile::FLOOR;

            currentWalkedPercentage = calcPercentageTileType(Tile::FLOOR);
            if ((int) currentWalkedPercentage > lastP) {
                lastP = (int) currentWalkedPercentage;
            }
        }
    }

}
