#pragma once

#include <vector>
#include <random>
#include <ctime>
#include <iostream>
#include <cstdio>
#include <chrono>
#include <cassert>
#include "TicTacToeMinimax.h"

using namespace std;

class MinimaxBenchmarker
{
    public:
        void benchmarkMinimaxVsMinimax(TicTacToeMinimax* ticTacToeMinimax, unsigned int board, bool isMaxTurn);
        void benchmarkEvaluate(TicTacToeMinimax* ticTacToeMinimax, unsigned int board, bool isMaxTurn);
        void benchmarkEvaluateAll(TicTacToeMinimax* ticTacToeMinimax, unsigned int board, bool isMaxTurn);
        void printBoard(unsigned int board);
        void printState(int state);
};
