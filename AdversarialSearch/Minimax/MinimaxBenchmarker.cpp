#include "MinimaxBenchmarker.h"

void MinimaxBenchmarker::benchmarkMinimaxVsMinimax(TicTacToeMinimax* ticTacToeMinimax, unsigned int board, bool isMaxTurn)
{
    auto start = chrono::high_resolution_clock::now();
    unsigned int firstBoard = board;

    unsigned int currentBoard = firstBoard;
    
    int state = ticTacToeMinimax -> getState(currentBoard);
    while (state == Playing)
    {
        int bestMove = ticTacToeMinimax -> evaluate(currentBoard, isMaxTurn);
        isMaxTurn = !isMaxTurn;
        currentBoard = bestMove;
        state = ticTacToeMinimax -> getState(currentBoard);
        assert(state == Playing || state == Draw);
    }
    
    auto finish = chrono::high_resolution_clock::now();
    
    //printBoard(firstBoard);
    //printBoard(nextBoard);
    //printState(ticTacToeMinimax -> getState(nextBoard));

    auto nanoseconds = chrono::duration_cast<chrono::nanoseconds>(finish - start);
    printf("benchmarkMinimaxVsMinimax: %.2f ms", (nanoseconds.count() / 1000000.0f));
    cout << endl << endl;
}

void MinimaxBenchmarker::benchmarkEvaluate(TicTacToeMinimax* ticTacToeMinimax, unsigned int board, bool isMaxTurn)
{
    auto start = chrono::high_resolution_clock::now();
    unsigned int nextBoard = ticTacToeMinimax -> evaluate(board, isMaxTurn);
    auto finish = chrono::high_resolution_clock::now();
    auto nanoseconds = chrono::duration_cast<chrono::nanoseconds>(finish - start);
    
    printBoard(board);
    printBoard(nextBoard);
    cout << endl << endl;

    printf("benchmarkEvaluate: %.2f ms", (nanoseconds.count() / 1000000.0f));
}

void MinimaxBenchmarker::benchmarkEvaluateAll(TicTacToeMinimax* ticTacToeMinimax, unsigned int board, bool isMaxTurn)
{
    auto start = chrono::high_resolution_clock::now();
    vector<unsigned int> bestBoards = ticTacToeMinimax -> evaluateAll(board, isMaxTurn);
    auto finish = chrono::high_resolution_clock::now();
    
    cout << "Found '" << bestBoards.size() << "' possibilities." << endl;
    
    auto nanoseconds = chrono::duration_cast<chrono::nanoseconds>(finish - start);
    printf("benchmarkEvaluateAll: %.2f ms", (nanoseconds.count() / 1000000.0f));
    cout << endl << endl;
}

void MinimaxBenchmarker::printBoard(unsigned int board)
{
    unsigned int crossMask  = 3;
    
    cout << endl;
    for (int x = 0; x < 9; x++)
    {
        if (x > 0 && x % 3 == 0) cout << endl;
        
        if ((board & crossMask) == 0)
        {
            cout << "[ ]";
        }
        else
        {
            if ((board & crossMask) == crossMask) cout << "[X]";
            else cout << "[O]";
        }
        
        crossMask <<= 2;
    }
    cout << endl;
}

void MinimaxBenchmarker::printState(int state)
{
    if (state == Playing) cout << "Playing" << endl;
    else if (state == Draw) cout << "Draw" << endl;
    else if (state == CrossWins) cout << "CrossWins" << endl;
    else cout << "CircleWins" << endl;
}
