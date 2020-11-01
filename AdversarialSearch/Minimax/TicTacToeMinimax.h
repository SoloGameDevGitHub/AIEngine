#ifndef _TIC_TAC_TOE_MINIMAX_H
#define _TIC_TAC_TOE_MINIMAX_H

#include <vector>

namespace TicTacToeMinimax
{
    const int DRAW = 0;
    const int CROSS_WINS = 1;
    const int CIRCLE_WINS = -1;
    const int PLAYING = 2;

    int predict(int board, bool isMaxTurn);
    std::vector<int> predictAll(int board, bool isMaxTurn);
    int getState(int board);
}
#endif
