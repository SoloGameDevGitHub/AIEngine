#pragma once

#include <climits>
#include <vector>

namespace TicTacToeMinimax
{
    const int DRAW = 0;
    const int CROSS_WINS = 1;
    const int CIRCLE_WINS = -1;
    const int PLAYING = 2;

    int Predict(int board, bool isMaxTurn, int maxDepth);
    std::vector<int> PredictAll(int board, bool isMaxTurn, int maxDepth);
    int GetState(int board);
}
