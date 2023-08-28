#include "MinimaxTester.h"

int main(int argc, char *argv[])
{
	if (argc > 1)
    {
        int boardState = atoi(argv[1]);
        TicTacToeMinimax::BenchmarkMinimax(boardState, true);
    }
	else
    {
        TicTacToeMinimax::RunMinimaxTests();
        TicTacToeMinimax::BenchmarkMinimaxVsMinimax(0, true);
    }
	return 0;
}
