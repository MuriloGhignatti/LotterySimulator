//
// Created by muril on 10/02/2022.
//

#ifndef MEGASENASIMULATOR_GAME_H
#define MEGASENASIMULATOR_GAME_H

#include <vector>
#include <stdlib.h>
#include "../utils/uid/UID.h"
#include "../utils/random_generator/RandomGenerator.h"

class Game {
public:
    UID* uid;
    int* numeros;

    explicit Game(int* numeros);

    ~Game();

    static Game gerarJogoAleatorio();
};


#endif //MEGASENASIMULATOR_GAME_H
