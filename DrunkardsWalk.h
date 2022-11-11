//
// Created by jamie on 08/11/2022.
//

#ifndef DUNGEONCPP_DRUNKARDSWALK_H
#define DUNGEONCPP_DRUNKARDSWALK_H


#include "Floor.h"
#include "Coordinate.h"

class DrunkardsWalk: public Floor {
    using Floor::Floor;

public:
    void generate() override;

private:
    Coordinate m_drunkardLocation;
};


#endif //DUNGEONCPP_DRUNKARDSWALK_H
