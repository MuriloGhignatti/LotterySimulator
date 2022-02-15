//
// Created by muril on 10/02/2022.
//

#ifndef MEGASENASIMULATOR_MEGASENA_H
#define MEGASENASIMULATOR_MEGASENA_H

#include <vector>
#include <iostream>
#include <array>
#include "../jogo/Game.h"
#include "../utils/random_generator/RandomGenerator.h"

class MegaSena {
    double maxPrize;
    double costPerGame;
    double* prizeDistribution;
    int* jackpotNumbers;

    std::vector<std::vector<UID>> winners;
    std::vector<Game> games;

    bool wasNumberDraw(int number);
    int checkHowManyNumbersWhereRight(int* numbers);
    void checkWinners();

public:
    void drawNumbers(bool verbose);
    void addGame(int* numbers);
    void addGame(Game game);
    void addDebugGames();
    void generateRandomGames(int ammount);
    double* publishWinners(bool verbose);

    MegaSena(double maxPrize, double costPerGame, double prizeDistribution[3]);

    ~MegaSena();
};


#endif //MEGASENASIMULATOR_MEGASENA_H
