#include "MinimaxTester.h"

struct MinimaxTestCase
{
public:
    const int CurrentBoard;
    const vector<int> ExpectedBoards;
    const bool IsMaxTurn;
    MinimaxTestCase(const int currentBoard, const bool isMaxTurn, vector<int> expectedNextBoard)
                    : CurrentBoard(currentBoard), ExpectedBoards(expectedNextBoard), IsMaxTurn(isMaxTurn)
    {
        //
    }
};

void RunMinimaxTests(TicTacToeMinimax &minimax)
{
    vector<MinimaxTestCase> testCases = {
            MinimaxTestCase(0b10'10'00'00'11'00'00'00'00, true,  {0b10'10'11'00'11'00'00'00'00}),
            MinimaxTestCase(0b11'11'00'00'10'00'00'00'00, false, {0b11'11'10'00'10'00'00'00'00}),
            MinimaxTestCase(0b00'00'00'00'11'00'00'10'10, true,  {0b00'00'00'00'11'00'11'10'10}),
            MinimaxTestCase(0b00'00'00'00'10'00'00'11'11, false, {0b00'00'00'00'10'00'10'11'11}),
            MinimaxTestCase(0b00'10'10'00'11'11'00'00'00, true,  {0b00'10'10'11'11'11'00'00'00}),
            MinimaxTestCase(0b00'11'11'00'10'10'00'00'00, false, {0b00'11'11'10'10'10'00'00'00}),
            MinimaxTestCase(0b00'11'00'11'10'11'10'00'10, true,  {0b11'11'00'11'10'11'10'00'10,
                                                                  0b00'11'11'11'10'11'10'00'10,
                                                                  0b00'11'00'11'10'11'10'11'10}),
            MinimaxTestCase(0b00'10'00'10'11'10'11'00'11, false, {0b10'10'00'10'11'10'11'00'11,
                                                                  0b00'10'10'10'11'10'11'00'11,
                                                                  0b00'10'00'10'11'10'11'10'11}),
    };

    for(unsigned int i = 0; i < testCases.size(); i++)
    {
        std::cout << "Test Case " << (i + 1) << " (";
        MinimaxTestCase testCase = testCases[i];
        std::cout << std::boolalpha;
        std::cout << "IsMaxTurn=" << testCase.IsMaxTurn << " / ";
        std::cout << "Board=" << testCase.CurrentBoard << " / ";
        std::cout << "Expected=";
        bool isResultExpected = false;
        int result = minimax.evaluate(testCase.CurrentBoard, testCase.IsMaxTurn);
        for(unsigned int i = 0; i < testCase.ExpectedBoards.size(); i++)
        {
            if (i > 0U && i < testCase.ExpectedBoards.size() - 1U)
            {
                std::cout << ";";
            }
            int expected = testCase.ExpectedBoards[i];
            std::cout << expected;
            isResultExpected |= result == expected;
        }
        std::cout << ") ";
        if (isResultExpected)
        {
            std::cout << "[PASSED]";
        }
        else
        {
            std::cout << "[FAILED] Result was=" << result;
            std::cout << "CurrentBoard:" << std::endl;
            printBoard(testCase.CurrentBoard);
            std::cout << "Predicted board state:" << std::endl;
            printBoard(result);
        }
        std::cout << std::endl;
    }
}

void benchmarkMinimaxVsMinimax(TicTacToeMinimax& minimax, const int board, bool isMaxTurn)
{
    double duration = 0.0;
    int firstBoard = board;
    int currentBoard = firstBoard;
    int state = minimax.getState(currentBoard);
    while (state == PLAYING)
    {
        auto start = chrono::high_resolution_clock::now();
        int bestMove = minimax.evaluate(currentBoard, isMaxTurn);
        auto finish = chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> millis = finish - start;
        duration += millis.count();
        isMaxTurn = !isMaxTurn;
        currentBoard = bestMove;
        state = minimax.getState(currentBoard);
        assert(state == PLAYING || state == DRAW);
    }
    printBoard(firstBoard);
    printBoard(currentBoard);
    printState(state);
    cout << "benchmarkMinimaxVsMinimax: " << duration << " ms";
    cout << endl << endl;
}

void benchmarkEvaluate(TicTacToeMinimax& minimax, const int board, bool isMaxTurn)
{
    auto start = chrono::high_resolution_clock::now();
    int nextBoard = minimax.evaluate(board, isMaxTurn);
    auto finish = chrono::high_resolution_clock::now();
    printBoard(board);
    printBoard(nextBoard);
    cout << endl << endl;
    std::chrono::duration<double, std::milli> millis = finish - start;
    cout << "benchmarkMinimaxVsMinimax: " << millis.count() << " ms";
    cout << endl << endl;
}

void benchmarkEvaluateAll(TicTacToeMinimax& minimax, const int board, bool isMaxTurn)
{
    auto start = chrono::high_resolution_clock::now();
    vector<int> bestBoards = minimax.evaluateAll(board, isMaxTurn);
    auto finish = chrono::high_resolution_clock::now();

    cout << "Found '" << bestBoards.size() << "' possibilities." << endl;

    auto nanoseconds = chrono::duration_cast<chrono::nanoseconds>(finish - start);
    printf("benchmarkEvaluateAll: %.2f ms", (nanoseconds.count() / 1000000.0f));
    cout << endl << endl;
}

void printBoard(const int board)
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
}

void printState(const int state)
{
    if (state == PLAYING) cout << "Playing" << endl;
    else if (state == DRAW) cout << "Draw" << endl;
    else if (state == CROSS_WINS) cout << "CrossWins" << endl;
    else cout << "CircleWins" << endl;
}
