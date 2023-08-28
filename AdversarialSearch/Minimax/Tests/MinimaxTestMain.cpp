#include "MinimaxTester.h"

int main(int argc, char *argv[])
{
	if (argc > 1)
    {
        int boardState = atoi(argv[1]);
        TicTacToeMinimax::benchmarkMinimax(boardState, true);
    }
	else
    {
        TicTacToeMinimax::RunMinimaxTests();
        TicTacToeMinimax::benchmarkMinimaxVsMinimax(0, true);
    }
	return 0;
}
