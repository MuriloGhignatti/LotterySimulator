//
// Created by muril on 10/02/2022.
//

#include "MegaSena.h"
#include <iostream>
#include <thread>

MegaSena::MegaSena(double maxPrize, double costPerGame, double prizeDistribution[3]): winners(3), semaphore(1), wasWinnersChecked(false), maxPrize(maxPrize), costPerGame(costPerGame){
    memcpy(this->prizeDistribution, prizeDistribution, sizeof(double) * 3);
}

void MegaSena::drawNumbers(bool verbose) {
    RandomGenerator::uniqueRandomList(6, 1, 60, jackpotNumbers);
    if(verbose){
        std::cout << "[";
        for(int i = 0; i < 6; ++i){
            std::cout << jackpotNumbers[i] << ", ";
        }
        std::cout << "]" << std::endl;
    }
}

int MegaSena::addGame(int *numbers) {
    return addGame(Game(numbers));
}

int MegaSena::addGame(Game game) {
    semaphore.acquire();
    games.push_back(game);
    semaphore.release(1);
    return game.uid.id;
}

double* MegaSena::publishWinners(bool verbose) {
    checkWinners();
    double prizeWonPerClassification[3] = {0,0,0};
    char* stringArray[3] = {"Quadra", "Quina", "Sena"};
    for (int i = 0; i < winners.size(); ++i) {
        int winnersSize = winners[i].size();
        if(winnersSize != 0){
            double prize = (prizeDistribution[i] * maxPrize) / winners[i].size();
            prizeWonPerClassification[i] += prize;
            if(verbose){
                std::cout.setf(std::ios::fixed);
                for(int j = 0; j < winnersSize; ++j){
                    std::cout << "[" << winners[i][j].id << "]" << stringArray[i] << ": Congratulations on winning R$ " << prize << std::endl;
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
    for (Game g: games) {
        switch (checkHowManyNumbersWhereRight(g.numeros)) {
            case 4:
                winners[0].push_back(g.uid);
                break;
            case 5:
                winners[1].push_back(g.uid);
                break;
            case 6:
                winners[2].push_back(g.uid);
                break;
            default:
                break;
        }
    }
    wasWinnersChecked = true;
}

void MegaSena::addDebugGames() {
    int* testCaseOne = new int[]{jackpotNumbers[0],0,0,0,0, 0};
    int* testCaseTwo = new int[]{jackpotNumbers[0],jackpotNumbers[1],0,0,0, 0};
    int* testCaseThree = new int[]{jackpotNumbers[0],jackpotNumbers[1],jackpotNumbers[2],0,0, 0};
    int* testCaseFour = new int[]{jackpotNumbers[0],jackpotNumbers[1],jackpotNumbers[2],jackpotNumbers[3],0, 0};
    int* testCaseFive = new int[]{jackpotNumbers[0],jackpotNumbers[1],jackpotNumbers[2],jackpotNumbers[3],jackpotNumbers[4], 0};
    addGame(jackpotNumbers);
    addGame(testCaseFive);
    addGame(testCaseFour);
    addGame(testCaseThree);
    addGame(testCaseTwo);
    addGame(testCaseOne);
}

void MegaSena::generateRandomGamesMultiThreaded(int amount){
    int cpusOnComputer = std::thread::hardware_concurrency() / 2;
    if(cpusOnComputer == 0){
        std::cout << "Cannot automatic retrieve the amount of cpus available on this computer, please input manually if you know";
        std::cin >> cpusOnComputer;
        cpusOnComputer = std::max(cpusOnComputer, 1);
    }
    games.reserve(amount);
    int amountPerThread = amount / cpusOnComputer;
    std::vector<std::thread> threads;
    threads.reserve(cpusOnComputer);
    for(std::size_t _ = 0; _ < cpusOnComputer; ++_){
        threads.emplace_back(std::thread(&MegaSena::privateGenerateRandomGames, this, amountPerThread));
    }
    for(auto& currentThread: threads){
        currentThread.join();
    }
}

void MegaSena::generateRandomGames(int amount) {
    games.reserve(amount);
    privateGenerateRandomGames(amount);
}

void MegaSena::privateGenerateRandomGames(int amount) {
    int memToCopy[6];
    std::cout << "Gerando Jogos" << "\n";
    for(int i = 0; i < amount; ++i){
        RandomGenerator::uniqueRandomList(6, 1, 60, memToCopy);
        addGame(memToCopy);
    }
    std::cout << "Jogos gerados" << "\n";
}

float MegaSena::checkIfIDIsOnWinners(std::vector<int> games) {
    if(!wasWinnersChecked){
        checkWinners();
    }
    float amountWon = 0;
    char* stringArray[3] = {"Quadra", "Quina", "Sena"};
    for(auto id: games){
        for(int i = 0; i < winners.size(); ++i){
            double prize = (prizeDistribution[i] * maxPrize) / winners[i].size();
            for(int j = 0; j < winners[i].size(); ++j){
                if(id == winners[i][j].id){
                    std::cout << "[" << winners[i][j].id << "]" << stringArray[i] << ": Congratulations on winning R$ " << prize << std::endl;
                    amountWon += prize;
                }
            }
        }
    }
    return amountWon;
}
