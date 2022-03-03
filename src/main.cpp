//#include <iostream>
#include "jogo/Game.h"
#include "megasena/MegaSena.h"
#include <iostream>
//#include <chrono>

void generateMygames(int numberOfGames, MegaSena* megaSena, std::vector<int>* myGames){
    int game[6];
    for(int i = 0; i < numberOfGames; ++i){
        RandomGenerator::uniqueRandomList(6, 1, 60, game);
        myGames->push_back(megaSena->addGame(game));
    }
}

int main() {

    // Consts
    int realAmountOfGamesToEmulate = 8630475;
    int realAmountOfMyGames = 1000;

    int numberOfGames = realAmountOfMyGames;
    std::vector<int> myGames;
    myGames.reserve(numberOfGames);

    //auto start = std::chrono::high_resolution_clock::now();
    double prizeDistribution[6] = {0.19, 0.19, 0.35};
    MegaSena megaSena(3000000.00, 4.5, prizeDistribution);
    megaSena.drawNumbers(true);
    //megaSena.addDebugGames();
    megaSena.generateRandomGamesMultiThreaded(realAmountOfGamesToEmulate);
    generateMygames(numberOfGames, &megaSena, &myGames);
    //megaSena.generateRandomGames(8630475);
    //megaSena.publishWinners(true);
    std::cout << "My Games: " << '\n';
    float amountIWon = megaSena.checkIfIDIsOnWinners(myGames);
    std::cout << "Money Won: " << (amountIWon - (numberOfGames * megaSena.costPerGame));
    //auto end = std::chrono::high_resolution_clock::now();
    //std::cout << "Tempo de execucao: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << std::endl;
    return 0;
}