#ifndef _TIC_TAC_TOE_MINIMAX_H
#define _TIC_TAC_TOE_MINIMAX_H

#include <vector>
#include <math.h>
#include <iostream>
#include <stdio.h>

enum ETicTacToeState
{
    Playing,
    Draw,
    CrossWins,
    CircleWins
};

class TicTacToeMinimax
{
    friend class MinimaxBenchmarker;
    private:
        float getMaxTreeScore(const int board, float alpha, float beta, int depth);
        float getMinTreeScore(const int board, float alpha, float beta, int depth);
        int evaluateMaxDecision(const int board);
        int evaluateMinDecision(const int board);
        std::vector<int> evaluateMaxDecisions(const int board);
        std::vector<int> evaluateMinDecisions(const int board);
        int getScore(const int state);
        int getState(const int board);
    public:
        int evaluate(const int board, const bool isMaxTurn);
        std::vector<int> evaluateAll(const int board, const bool isMaxTurn);
};
#endif
