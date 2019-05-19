#include "TicTacToeMinimax.h"
#include "MinimaxBenchmarker.h"
#include "BitMath.h"

int main()
{
	assert(BitMath::reverseBits(0b10010011, 8) == 0b11001001);
	
	std::cout << std::bitset<7>(0b1001001) << " to " << std::bitset<7>(BitMath::reverseBits(0b1001001, 7)) << std::endl;
	assert(BitMath::reverseBits(0b1001001, 7) == 0b1001001);
	return 0;
	
	TicTacToeMinimax* minimax = new TicTacToeMinimax();
	MinimaxBenchmarker* benchmarker = new MinimaxBenchmarker();
	
	benchmarker -> benchmarkMinimaxVsMinimax(minimax, 0, true);
	benchmarker -> benchmarkEvaluate(minimax, 0, true);
	benchmarker -> benchmarkEvaluate(minimax, 0b100000110000100011, true);
	
	return 0;
};
