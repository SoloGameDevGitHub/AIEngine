#include "MinimaxTester.h"

/// @brief Get a string representation for a given 'TicTacToeMinimax' flag.
/// @param state A 'TicTacToeMinimax' flag.
/// @return An string representing the 'state' parameter.
string GetStateText(int state)
{
    if (state == TicTacToeMinimax::PLAYING)
        return "Playing";
    else if (state == TicTacToeMinimax::DRAW)
        return "Draw";
    else if (state == TicTacToeMinimax::CROSS_WINS)
        return "CrossWins";
    return "CircleWins";
}

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
    const vector<MinimaxTestCase> testCases = {
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
        const MinimaxTestCase testCase = testCases[i];
        std::cout << std::boolalpha;
        std::cout << "IsMaxTurn=" << testCase.IsMaxTurn << " / ";
        std::cout << "Board=" << testCase.CurrentBoard << " / ";
        std::cout << "Expected=";
        bool isResultExpected = false;
        int result = TicTacToeMinimax::Predict(testCase.CurrentBoard, testCase.IsMaxTurn, 6);
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
            PrintBoard(testCase.CurrentBoard);
            std::cout << "Predicted board state:" << std::endl;
            PrintBoard(result);
        }
        std::cout << std::endl;
    }
}

void TicTacToeMinimax::BenchmarkMinimax(int board, bool isMaxTurn)
{
    long long int totalDuration = 0ll;
    PrintBoard(board);
    int state = TicTacToeMinimax::GetState(board);
    if (state == PLAYING)
    {
        auto begin = std::chrono::steady_clock::now();
        board = TicTacToeMinimax::Predict(board, isMaxTurn, 6);
        auto end = std::chrono::steady_clock::now();
        totalDuration += (end - begin).count();
    }
    PrintBoard(board);
    PrintState(state);
    cout << "benchmarkMinimax: " << totalDuration << " ns";
    cout << endl << endl;
}

void TicTacToeMinimax::BenchmarkMinimaxVsMinimax(int board, bool isMaxTurn)
{
    std::vector<long long int> durationByMove;
    long long int totalDuration = 0ll;
    int firstBoard = board;
    int currentBoard = firstBoard;
    int state = TicTacToeMinimax::GetState(currentBoard);
    while (state == PLAYING)
    {
        auto begin = std::chrono::steady_clock::now();

        // actually run the minimax algorithm
        int bestMove = TicTacToeMinimax::Predict(currentBoard, isMaxTurn, 6);

        auto end = std::chrono::steady_clock::now();
        // calculate the algorithm's duration in nanoseconds
        long long int nanos = (end - begin).count();
        totalDuration += nanos;
        // store the duration
        durationByMove.emplace_back(nanos);

        isMaxTurn = !isMaxTurn;
        currentBoard = bestMove;
        state = TicTacToeMinimax::GetState(currentBoard);
        // print an error in case the algorithm ends up doing something completely wrong
        if (state != PLAYING && state != DRAW)
        {
            std::cerr << "'" << GetStateText(state) << "' state must never happen during a Minimax vs Minimax battle!" << std::endl;
            return;
        }
    }
    PrintBoard(firstBoard);
    PrintBoard(currentBoard);
    PrintState(state);
    for (int i = 0; i < durationByMove.size(); ++i)
    {
        long long int nanoseconds = durationByMove[i];
        printf("Move %i took %.6f ms\n", (i + 1), (nanoseconds / 1'000'000.0));
    }
    printf("Total duration: %.6f ms\n", (totalDuration / 1'000'000.0));
    cout << endl << endl;
}

void TicTacToeMinimax::PrintBoard(int board)
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

void TicTacToeMinimax::PrintState(int state)
{
    string stateText = GetStateText(state);
    cout << stateText << endl;
}
