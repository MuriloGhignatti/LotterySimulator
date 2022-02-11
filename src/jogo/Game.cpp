//
// Created by muril on 10/02/2022.
//

#include "Game.h"

Game Game::gerarJogoAleatorio() {
    return Game(RandomGenerator::uniqueRandomList(6, 1, 60));
}

Game::Game(int *numeros) {
    uid = new UID();
    this->numeros = numeros;
}

Game::~Game() {
    delete uid;
    delete[] numeros;
}