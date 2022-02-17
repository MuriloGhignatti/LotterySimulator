//
// Created by muril on 10/02/2022.
//

#include "RandomGenerator.h"
#include <chrono>

std::mt19937 RandomGenerator::rand;

void RandomGenerator::uniqueRandomList(int size, int start, int end, int arrayToPopulate[6]) {
    RandomGenerator::rand.seed(std::chrono::system_clock::now().time_since_epoch().count());
    int randomNumber;
    bool alreadyGenerated = true;
    for (int i = 0; i < size; ++i) {
        while(alreadyGenerated){
            randomNumber = RandomGenerator::rand() % end + start;
            for(int j = 0; j < size; ++j){
                if(arrayToPopulate[j] == randomNumber){
                    continue;
                }
            }
            alreadyGenerated = false;
        }
        arrayToPopulate[i] = randomNumber;
        alreadyGenerated = true;
    }
}
