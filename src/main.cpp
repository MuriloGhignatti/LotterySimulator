#include <iostream>
#include "jogo/Game.h"
#include "megasena/MegaSena.h"

int main() {
    MegaSena megaSena(3000000.00, 4.5, new double[]{0.19, 0.19, 0.35});
    megaSena.drawNumbers(true);
    megaSena.addDebugGames();
    megaSena.publishWinners(true);
    return 0;
}
