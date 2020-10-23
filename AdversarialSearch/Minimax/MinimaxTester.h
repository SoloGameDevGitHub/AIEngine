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

void RunMinimaxTests(TicTacToeMinimax &minimax);
void benchmarkMinimaxVsMinimax(TicTacToeMinimax& ticTacToeMinimax, const int board, bool isMaxTurn);
void benchmarkEvaluate(TicTacToeMinimax& ticTacToeMinimax, const int board, bool isMaxTurn);
void benchmarkEvaluateAll(TicTacToeMinimax& ticTacToeMinimax, const int board, bool isMaxTurn);
void printBoard(const int board);
void printState(const int state);
