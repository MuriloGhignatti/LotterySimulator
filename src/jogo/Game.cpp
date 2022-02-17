//
// Created by muril on 10/02/2022.
//

#include "Game.h"

Game Game::gerarJogoAleatorio() {
    int tempArray[6];
    RandomGenerator::uniqueRandomList(6, 1, 60, tempArray);
    return Game(tempArray);
}

Game::Game(int toCopy[6]){
    memcpy(this->numeros, toCopy, sizeof(int) * 6);
}