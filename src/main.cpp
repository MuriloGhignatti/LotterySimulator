//#include <iostream>
#include "jogo/Game.h"
#include "megasena/MegaSena.h"
//#include <chrono>

int main() {
    //auto start = std::chrono::high_resolution_clock::now();
    double prizeDistribution[6] = {0.19, 0.19, 0.35};
    MegaSena megaSena(3000000.00, 4.5, prizeDistribution);
    megaSena.drawNumbers(true);
    //megaSena.addDebugGames();
    megaSena.generateRandomGamesMultiThreaded(8630475);
    //megaSena.generateRandomGames(8630475);
    megaSena.publishWinners(true);
    //auto end = std::chrono::high_resolution_clock::now();
    //std::cout << "Tempo de execucao: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << std::endl;
    return 0;
}