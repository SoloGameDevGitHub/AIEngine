#include "MinimaxTester.h"

int main(int argc, char *argv[])
{
    TicTacToeMinimax minimax;
	if (argc > 1)
    {
        int boardState = atoi(argv[1]);
        benchmarkEvaluate(minimax, boardState, true);
    }
	else
    {
        benchmarkMinimaxVsMinimax(minimax, 0, true);
        //RunMinimaxTests(minimax);
    }
	return 0;
}
