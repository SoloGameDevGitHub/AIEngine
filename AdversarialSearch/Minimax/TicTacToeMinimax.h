#ifndef _TIC_TAC_TOE_MINIMAX_H
#define _TIC_TAC_TOE_MINIMAX_H

#include <vector>
#include <cmath>
#include <iostream>
#include <cstdio>

extern unsigned int Playing;
extern unsigned int Draw;
extern unsigned int CrossWins;
extern unsigned int CircleWins;

class TicTacToeMinimax
{
    friend class MinimaxBenchmarker;
    private:
        float getMaxTreeScore(unsigned int board, float alpha, float beta, int depth);
        float getMinTreeScore(unsigned int board, float alpha, float beta, int depth);
        unsigned int evaluateMaxDecision(unsigned int board);
        unsigned int evaluateMinDecision(unsigned int board);
        std::vector<unsigned int> evaluateMaxDecisions(unsigned int board);
        std::vector<unsigned int> evaluateMinDecisions(unsigned int board);
        static int getScore(const unsigned int &state);
        static int getState(const unsigned int &board);
    public:
        unsigned int evaluate(unsigned int board, bool isMaxTurn);
        std::vector<unsigned int> evaluateAll(unsigned int board, bool isMaxTurn);
};
#endif
