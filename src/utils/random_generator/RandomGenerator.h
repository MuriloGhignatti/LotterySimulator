//
// Created by muril on 10/02/2022.
//

#ifndef MEGASENASIMULATOR_RANDOMGENERATOR_H
#define MEGASENASIMULATOR_RANDOMGENERATOR_H

#include <stdlib.h>
#include <time.h>

class RandomGenerator {
    int seed;

public:
    explicit RandomGenerator(int seed);

    static int* uniqueRandomList(int size, int start, int end);
};


#endif //MEGASENASIMULATOR_RANDOMGENERATOR_H
