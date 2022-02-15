//
// Created by muril on 10/02/2022.
//

#ifndef MEGASENASIMULATOR_GAME_H
#define MEGASENASIMULATOR_GAME_H

#include <vector>
#include <stdlib.h>
#include <cstring>
#include "../utils/uid/UID.h"
#include "../utils/random_generator/RandomGenerator.h"

class Game {
public:
    UID uid;
    int numeros[6];

    explicit Game(int numeros[6]);

    static Game gerarJogoAleatorio();
};


#endif //MEGASENASIMULATOR_GAME_H
