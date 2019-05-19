#include <vector>
#include <math.h>

enum ETicTacToeState
{
    Playing,
    Draw,
    CrossWins,
    CircleWins
};

enum ETurnOwner
{
    Cross,
    Circle
};

class TicTacToeMinimax
{
    friend class MinimaxBenchmarker;
    private:
        int getMaxTreeScore(int board, int alpha, int beta);
        int getMinTreeScore(int board, int alpha, int beta);
        int evaluateMaxDecision(int board);
        int evaluateMinDecision(int board);
        std::vector<int> evaluateMaxDecisions(int board);
        std::vector<int> evaluateMinDecisions(int board);
        int getScore(int state);
        int getState(int board);
    public:
        int evaluate(int board, bool isMaxTurn);
        std::vector<int> evaluateAll(int board, bool isMaxTurn);
};
