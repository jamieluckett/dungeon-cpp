//
// Created by jamie on 09/11/2022.
//

#ifndef DUNGEONCPP_RENDERER_H
#define DUNGEONCPP_RENDERER_H


#include "Floor.h"

class Renderer {
public:
    virtual void renderFloor(Floor& floor) = 0;
};


#endif //DUNGEONCPP_RENDERER_H
