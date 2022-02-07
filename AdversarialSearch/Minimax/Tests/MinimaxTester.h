#pragma once

#include "../TicTacToeMinimax.h"

#include <vector>
#include <random>
#include <ctime>
#include <iostream>
#include <cstdio>
#include <chrono>
#include <cassert>
#include <string>

using namespace std;

namespace TicTacToeMinimax
{
    void RunMinimaxTests();
    void benchmarkMinimax(int board, bool isMaxTurn);
    void benchmarkMinimaxVsMinimax(int board, bool isMaxTurn);
    void benchmarkEvaluate(int board, bool isMaxTurn);
    void benchmarkEvaluateAll(int board, bool isMaxTurn);
    void printBoard(int board);
    void printState(int state);
}
