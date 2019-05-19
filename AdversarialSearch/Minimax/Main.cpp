#include "MinimaxBenchmarker.h"
#include "BitMath.h"

int main()
{
	TicTacToeMinimax* minimax = new TicTacToeMinimax();
	MinimaxBenchmarker* benchmarker = new MinimaxBenchmarker();
	
	benchmarker -> benchmarkMinimaxVsMinimax(minimax, 0, true);
	benchmarker -> benchmarkEvaluate(minimax, 0, true);
	benchmarker -> benchmarkEvaluate(minimax, 0b100000110000100011, true);
	benchmarker -> benchmarkEvaluate(minimax, 0b100000110011100011, false);
	benchmarker -> benchmarkEvaluate(minimax, 0b100000110011101011, true);
	
	return 0;
};
