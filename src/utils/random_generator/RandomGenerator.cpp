//
// Created by muril on 10/02/2022.
//

#include "RandomGenerator.h"

RandomGenerator::RandomGenerator(int seed) {
    this->seed = seed;
}

int *RandomGenerator::uniqueRandomList(int size, int start, int end) {
    srand(time(NULL));
    int* list = new int[size];
    int randomNumber;
    bool alreadyGenerated = true;
    for (int i = 0; i < size; ++i) {
        while(alreadyGenerated){
            randomNumber = rand() % end + start;
            for(int j = 0; j < size; ++j){
                if(list[j] == randomNumber){
                    continue;
                }
            }
            alreadyGenerated = false;
        }
        list[i] = randomNumber;
        alreadyGenerated = true;
    }
    return list;
}
