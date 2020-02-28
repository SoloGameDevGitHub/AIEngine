#include "MinimaxBenchmarker.h"

void MinimaxBenchmarker::benchmarkMinimaxVsMinimax(TicTacToeMinimax* ticTacToeMinimax, int board, bool isMaxTurn)
{
    auto start = chrono::high_resolution_clock::now();
    int firstBoard = board;
    
    int currentBoard = firstBoard;
    int nextBoard;
    
    int state = ticTacToeMinimax -> getState(currentBoard);
    while (state == Playing)
    {
        int bestMove = ticTacToeMinimax -> evaluate(currentBoard, isMaxTurn);
        isMaxTurn = !isMaxTurn;

        currentBoard = bestMove;
        
        state = ticTacToeMinimax -> getState(currentBoard);
        assert(state == Playing || state == Draw);
    }
    
    nextBoard = currentBoard;
    auto finish = chrono::high_resolution_clock::now();
    
    printBoard(firstBoard);
    printBoard(nextBoard);
    printState(ticTacToeMinimax -> getState(nextBoard));

    auto milliseconds = chrono::duration_cast<chrono::milliseconds>(finish - start);
    auto nanoseconds = chrono::duration_cast<chrono::nanoseconds>(finish - start);            
    cout << "benchmarkMinimaxVsMinimax: " << milliseconds.count() << "ms / " << nanoseconds.count() << "ns" << endl;
    cout << endl << endl;
};

void MinimaxBenchmarker::benchmarkEvaluate(TicTacToeMinimax* ticTacToeMinimax, int board, bool isMaxTurn)
{
    auto start = chrono::high_resolution_clock::now();	
    int nextBoard = ticTacToeMinimax -> evaluate(board, isMaxTurn);
    auto finish = chrono::high_resolution_clock::now();
    auto milliseconds = chrono::duration_cast<chrono::milliseconds>(finish - start);
    auto nanoseconds = chrono::duration_cast<chrono::nanoseconds>(finish - start);
    
    printBoard(board);
    printBoard(nextBoard);
    cout << endl << endl;
    
    cout << "benchmarkEvaluate: " << milliseconds.count() << "ms / " << nanoseconds.count() << "ns" << endl;
};

void MinimaxBenchmarker::benchmarkEvaluateAll(TicTacToeMinimax* ticTacToeMinimax, int board, bool isMaxTurn)
{
    auto start = chrono::high_resolution_clock::now();
    vector<int> bestBoards = ticTacToeMinimax -> evaluateAll(board, isMaxTurn);
    auto finish = chrono::high_resolution_clock::now();
    
    cout << "Found '" << bestBoards.size() << "' possibilities." << endl;
    
    auto milliseconds = chrono::duration_cast<chrono::milliseconds>(finish - start);
    auto nanoseconds = chrono::duration_cast<chrono::nanoseconds>(finish - start);
    cout << "benchmarkEvaluateAll: " << milliseconds.count() << "ms / " << nanoseconds.count() << "ns" << endl;
    cout << endl << endl;
};

void MinimaxBenchmarker::printBoard(int board)
{
    int crossMask  = 3;
    
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
};

void MinimaxBenchmarker::printState(int state)
{
    if (state == Playing) cout << "Playing" << endl;
    else if (state == Draw) cout << "Draw" << endl;
    else if (state == CrossWins) cout << "CrossWins" << endl;
    else cout << "CircleWins" << endl;
};
