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
    void BenchmarkMinimax(int board, bool isMaxTurn);
    void BenchmarkMinimaxVsMinimax(int board, bool isMaxTurn);
    void BenchmarkEvaluate(int board, bool isMaxTurn);
    void BenchmarkEvaluateAll(int board, bool isMaxTurn);
    void PrintBoard(int board);
    void PrintState(int state);
}
