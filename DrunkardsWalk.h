//
// Created by jamie on 08/11/2022.
//

#ifndef DUNGEONCPP_DRUNKARDSWALK_H
#define DUNGEONCPP_DRUNKARDSWALK_H


#include "Floor.h"

class DrunkardsWalk: public Floor {
    using Floor::Floor;

public:
    void generate() override;
};


#endif //DUNGEONCPP_DRUNKARDSWALK_H
