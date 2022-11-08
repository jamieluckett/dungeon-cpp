#include <iostream>
#include "Floor.h"
#include "RandomFloor.h"
#include "DrunkardsWalk.h"

int main() {
    DrunkardsWalk *floor = new DrunkardsWalk(70, 370);
    floor->generate();
    floor->stdout_print();
    return 0;
}
