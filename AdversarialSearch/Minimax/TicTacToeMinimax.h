#pragma once

#include <limits.h>
#include <vector>

namespace TicTacToeMinimax
{
    const int DRAW = 0;
    const int CROSS_WINS = 1;
    const int CIRCLE_WINS = -1;
    const int PLAYING = 2;

    int predict(int board, bool isMaxTurn, int maxDepth);
    std::vector<int> predictAll(int board, bool isMaxTurn, int maxDepth);
    int getState(int board);
}
