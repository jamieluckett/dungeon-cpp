#include <iostream>
#include "Floor.h"
#include "RandomFloor.h"

int main() {
    RandomFloor *floor = new RandomFloor(15, 15);
    floor->generate();
    floor->stdout_print();
    return 0;
}
