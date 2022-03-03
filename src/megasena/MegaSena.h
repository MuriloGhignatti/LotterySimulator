//
// Created by muril on 10/02/2022.
//

#ifndef MEGASENASIMULATOR_MEGASENA_H
#define MEGASENASIMULATOR_MEGASENA_H

#include <vector>
#include "../jogo/Game.h"
#include <semaphore>

class MegaSena {
    double maxPrize;
    double prizeDistribution[3];
    int jackpotNumbers[6];
    bool wasWinnersChecked;

    std::binary_semaphore semaphore;

    std::vector<std::vector<UID>> winners;
    std::vector<Game> games;

    bool wasNumberDraw(int number);
    int checkHowManyNumbersWhereRight(int* numbers);
    void checkWinners();
    void privateGenerateRandomGames(int amount);

public:
    double costPerGame;
    void drawNumbers(bool verbose);
    int addGame(int* numbers);
    int addGame(Game game);
    void addDebugGames();
    void generateRandomGamesMultiThreaded(int amount);
    void generateRandomGames(int amount);
    double* publishWinners(bool verbose);
    float checkIfIDIsOnWinners(std::vector<int> games);

    MegaSena(double maxPrize, double costPerGame, double prizeDistribution[3]);
};


#endif //MEGASENASIMULATOR_MEGASENA_H
