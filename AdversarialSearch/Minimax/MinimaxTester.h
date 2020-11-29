#pragma once
#include <vector>
#include <random>
#include <ctime>
#include <iostream>
#include <cstdio>
#include <chrono>
#include <cassert>
#include <string>
#include "TicTacToeMinimax.h"

using namespace std;

namespace TicTacToeMinimax
{
    namespace
    {
        string getStateText(int state)
        {
            if (state == TicTacToeMinimax::PLAYING)
                return "Playing";
            else if (state == TicTacToeMinimax::DRAW)
                return "Draw";
            else if (state == TicTacToeMinimax::CROSS_WINS)
                return "CrossWins";
            return "CircleWins";
        }
    }

    void RunMinimaxTests();
    void benchmarkMinimax(int board, bool isMaxTurn);
    void benchmarkMinimaxVsMinimax(int board, bool isMaxTurn);
    void benchmarkEvaluate(int board, bool isMaxTurn);
    void benchmarkEvaluateAll(int board, bool isMaxTurn);
    void printBoard(int board);
    void printState(int state);
}
