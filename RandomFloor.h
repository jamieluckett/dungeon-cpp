//
// Created by jamie on 07/11/2022.
//

#ifndef DUNGEONCPP_RANDOMFLOOR_H
#define DUNGEONCPP_RANDOMFLOOR_H


#include "Floor.h"

class RandomFloor: public Floor {
    using Floor::Floor;

public:
    void generate() override;
};

#endif //DUNGEONCPP_RANDOMFLOOR_H
