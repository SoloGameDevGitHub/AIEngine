#ifndef _TIC_TAC_TOE_MINIMAX_H
#define _TIC_TAC_TOE_MINIMAX_H

#include <vector>

namespace TicTacToeMinimax
{
    const int DRAW = 0;
    const int CROSS_WINS = 1;
    const int CIRCLE_WINS = -1;
    const int PLAYING = 2;

    int predictMaxTreeScore(int board, int alpha, int beta);
    int predictMinTreeScore(int board, int alpha, int beta);
    int predictMaxDecision(int board);
    int predictMinDecision(int board);
    std::vector<int> predictMaxDecisions(int board);
    std::vector<int> predictMinDecisions(int board);
    int getState(int board);
    int predict(int board, bool isMaxTurn);
    std::vector<int> evaluateAll(int board, bool isMaxTurn);
}
#endif
