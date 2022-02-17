//
// Created by muril on 10/02/2022.
//

#ifndef MEGASENASIMULATOR_RANDOMGENERATOR_H
#define MEGASENASIMULATOR_RANDOMGENERATOR_H

#include <random>

class RandomGenerator {

    static std::mt19937 rand;

public:
    static void uniqueRandomList(int size, int start, int end, int arrayToPopulate[6]);
};


#endif //MEGASENASIMULATOR_RANDOMGENERATOR_H
