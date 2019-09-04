#include "MinimaxBenchmarker.h"
#include "BitMath.h"
#include <cstdlib>

int main(int argc, char *argv[])
{
	TicTacToeMinimax* minimax = new TicTacToeMinimax();
	MinimaxBenchmarker* benchmarker = new MinimaxBenchmarker();

	if (argc > 1)
    {
        int boardState = atoi(argv[1]);
        benchmarker -> benchmarkEvaluate(minimax, boardState, true);
    }
	else
    {
        benchmarker -> benchmarkMinimaxVsMinimax(minimax, 0, true);
    }

	return 0;
};
