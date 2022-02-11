//
// Created by muril on 10/02/2022.
//

#include "MegaSena.h"

MegaSena::MegaSena(double maxPrize, double costPerGame, double* prizeDistribution) {
    this->maxPrize = maxPrize;
    this->costPerGame = costPerGame;
    this->prizeDistribution = prizeDistribution;
    winners = std::vector<std::vector<UID*>>(3, std::vector<UID*>());
}

MegaSena::~MegaSena() {
    delete prizeDistribution;
    delete jackpotNumbers;
    for (auto& vec : winners){
        for (auto uid : vec){
            delete uid;
        }
    }
}

void MegaSena::drawNumbers(bool verbose) {
    this->jackpotNumbers = RandomGenerator::uniqueRandomList(6, 1, 60);
    if(verbose){
        std::cout << "[";
        for(int i = 0; i < 6; ++i){
            std::cout << jackpotNumbers[i] << ", ";
        }
        std::cout << "]" << std::endl;
    }
}

void MegaSena::addGame(int *numbers) {
    addGame(new Game(numbers));
}

void MegaSena::addGame(Game *game) {
    games.push_back(game);
}

double* MegaSena::publishWinners(bool verbose) {
    checkWinners();
    double* prizeWonPerClassification = new double[]{0,0,0};
    for (int i = 0; i < winners.size(); ++i) {
        int winnersSize = winners[i].size();
        if(winnersSize != 0){
            double prize = (prizeDistribution[i] * maxPrize) / winners[i].size();
            prizeWonPerClassification[i] += prize;
            if(verbose){
                for(int j = 0; j < winnersSize; ++j){
                    std::cout << "[" << winners[i][j]->id << "]" << "Congratulations on winning R$ " << prize << std::endl;
                }
            }
        }
    }
    return prizeWonPerClassification;
}

bool MegaSena::wasNumberDraw(int number) {
    for (int i = 0; i < 6; ++i) {
        if(jackpotNumbers[i] == number){
            return true;
        }
    }
    return false;
}

int MegaSena::checkHowManyNumbersWhereRight(int *numbers) {
    int counter{0};
    for(int i = 0; i < 6; ++i){
        if(wasNumberDraw(numbers[i])){
            counter++;
        }
    }
    return counter;
}

void MegaSena::checkWinners() {
    for (Game* g: games) {
        switch (checkHowManyNumbersWhereRight(g->numeros)) {
            case 4:
                winners[0].push_back(g->uid);
                break;
            case 5:
                winners[1].push_back(g->uid);
                break;
            case 6:
                winners[2].push_back(g->uid);
                break;
            default:
                break;
        }
    }
}

void MegaSena::addDebugGames() {
    int testCaseOne[]{jackpotNumbers[0],0,0,0,0, 0};
    int testCaseTwo[]{jackpotNumbers[0],jackpotNumbers[1],0,0,0, 0};
    int testCaseThree[]{jackpotNumbers[0],jackpotNumbers[1],jackpotNumbers[2],0,0, 0};
    int testCaseFour[]{jackpotNumbers[0],jackpotNumbers[1],jackpotNumbers[2],jackpotNumbers[3],0, 0};
    int testCaseFive[]{jackpotNumbers[0],jackpotNumbers[1],jackpotNumbers[2],jackpotNumbers[3],jackpotNumbers[4], 0};
    addGame(jackpotNumbers);
    addGame(testCaseFive);
    addGame(testCaseFour);
    addGame(testCaseThree);
    addGame(testCaseTwo);
    addGame(testCaseOne);
}
