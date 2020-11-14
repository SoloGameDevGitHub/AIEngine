#include "MinimaxTester.h"

struct MinimaxTestCase
{
public:
    const int CurrentBoard;
    const vector<int> ExpectedBoards;
    const bool IsMaxTurn;
    MinimaxTestCase(int currentBoard, bool isMaxTurn, vector<int> expectedNextBoard)
                    : CurrentBoard(currentBoard), ExpectedBoards(expectedNextBoard), IsMaxTurn(isMaxTurn)
    {
        //
    }
};

void TicTacToeMinimax::RunMinimaxTests()
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
        int result = TicTacToeMinimax::predict(testCase.CurrentBoard, testCase.IsMaxTurn);
        for(unsigned int x = 0; x < testCase.ExpectedBoards.size(); x++)
        {
            if (i > 0U && i < testCase.ExpectedBoards.size() - 1U)
            {
                std::cout << ";";
            }
            int expected = testCase.ExpectedBoards[x];
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

void TicTacToeMinimax::benchmarkMinimax(int board, bool isMaxTurn)
{
    long long int totalDuration = 0ll;
    printBoard(board);
    int state = TicTacToeMinimax::getState(board);
    if (state == PLAYING)
    {
        auto begin = std::chrono::steady_clock::now();
        board = TicTacToeMinimax::predict(board, isMaxTurn);
        auto end = std::chrono::steady_clock::now();
        totalDuration += (end - begin).count();
    }
    printBoard(board);
    printState(state);
    cout << "benchmarkMinimax: " << totalDuration << " ns";
    cout << endl << endl;
}

void TicTacToeMinimax::benchmarkMinimaxVsMinimax(int board, bool isMaxTurn)
{
    std::vector<long long int> durationByMove;
    long long int totalDuration = 0ll;
    int firstBoard = board;
    int currentBoard = firstBoard;
    int state = TicTacToeMinimax::getState(currentBoard);
    while (state == PLAYING)
    {
        auto begin = std::chrono::steady_clock::now();
        int bestMove = TicTacToeMinimax::predict(currentBoard, isMaxTurn, 6);
        auto end = std::chrono::steady_clock::now();
        long long int nanos = (end - begin).count();
        totalDuration += nanos;
        durationByMove.emplace_back(nanos);
        isMaxTurn = !isMaxTurn;
        currentBoard = bestMove;
        state = TicTacToeMinimax::getState(currentBoard);
        if (state != PLAYING && state != DRAW)
        {
            std::cerr << "'" << getStateText(state) << "' state must never happen during a Minimax vs Minimax battle!" << std::endl;
            return;
        }
    }
    printBoard(firstBoard);
    printBoard(currentBoard);
    printState(state);
    for (int i = 0; i < durationByMove.size(); ++i)
    {
        long long int nanoseconds = durationByMove[i];
        printf("Move %i took %.6f ms\n", (i + 1), (nanoseconds / 1'000'000.0));
    }
    printf("Total duration: %.6f ms\n", (totalDuration / 1'000'000.0));
    cout << endl << endl;
}

void TicTacToeMinimax::printBoard(int board)
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

void TicTacToeMinimax::printState(int state)
{
    string stateText = getStateText(state);
    cout << stateText << endl;
}
