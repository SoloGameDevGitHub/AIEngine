#ifndef _TIC_TAC_TOE_MINIMAX_H
#define _TIC_TAC_TOE_MINIMAX_H

#include <vector>
#include <cmath>
#include <iostream>
#include <cstdio>
#include <bitset>

#define PLAYING 0
#define DRAW 1
#define CROSS_WINS 2
#define  CIRCLE_WINS 3

class TicTacToeMinimax
{
    private:
        int getMaxTreeScore(const int board, int alpha, int beta);
        int getMinTreeScore(const int board, int alpha, int beta);
        int evaluateMaxDecision(const int board);
        int evaluateMinDecision(const int board);
        std::vector<int> evaluateMaxDecisions(const int board);
        std::vector<int> evaluateMinDecisions(const int board);
        inline int getScore(const int state);
        inline int getState(const int board);

    public:
    int evaluate(const int board, const bool isMaxTurn);
        std::vector<int> evaluateAll(const int board, const bool isMaxTurn);

    private:
        friend void RunMinimaxTests(TicTacToeMinimax&);
        friend void benchmarkMinimaxVsMinimax(TicTacToeMinimax&, const int, bool);
        friend void benchmarkEvaluate(TicTacToeMinimax&, const int, bool);
        friend void benchmarkEvaluateAll(TicTacToeMinimax&, const int, bool);
};
#endif
