cmake_minimum_required(VERSION 3.21)
project(MegasenaSimulator)

set(CMAKE_CXX_STANDARD 23)

add_executable(MegasenaSimulator src/main.cpp src/jogo/Game.cpp src/jogo/Game.h src/utils/uid/UID.cpp src/utils/uid/UID.h src/megasena/MegaSena.cpp src/megasena/MegaSena.h src/utils/random_generator/RandomGenerator.cpp src/utils/random_generator/RandomGenerator.h)
