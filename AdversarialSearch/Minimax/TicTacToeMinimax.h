#ifndef _TIC_TAC_TOE_MINIMAX_H
#define _TIC_TAC_TOE_MINIMAX_H
#include <limits.h>
#include <vector>

namespace TicTacToeMinimax
{
    const int DRAW = 0;
    const int CROSS_WINS = 1;
    const int CIRCLE_WINS = -1;
    const int PLAYING = 2;

    int predict(int board, bool isMaxTurn, int maxDepth = INT_MAX);
    std::vector<int> predictAll(int board, bool isMaxTurn, int maxDepth = INT_MAX);
    int getState(int board);
}
#endif
