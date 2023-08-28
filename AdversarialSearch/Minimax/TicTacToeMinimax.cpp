#include "TicTacToeMinimax.h"

#define MAXIMUM_MASK_VALUE 0b1'00'00'00'00'00'00'00'00'00
#define DRAW_BOARD_STATE 0b10'10'10'10'10'10'10'10'10
const int winnerMasks[8] =
{
    0b10'10'10'00'00'00'00'00'00,
    0b10'00'00'10'00'00'10'00'00,
    0b00'00'00'00'00'00'10'10'10,
    0b00'00'10'00'00'10'00'00'10,
    0b10'00'00'00'10'00'00'00'10,
    0b00'10'00'00'10'00'00'10'00,
    0b00'00'00'10'10'10'00'00'00,
    0b00'00'10'00'10'00'10'00'00,
};
int _maxDepth;

namespace TicTacToeMinimax
{
    int predictMinTreeScore(const int board, int alpha, int beta, int depth);

    int predictMaxTreeScore(const int board, int alpha, int beta, int depth)
    {
        const int state = getState(board);
        if (state != PLAYING || depth >= _maxDepth)
        {
            return state;
        }
        int bestScore = INT_MIN;
        int mask = 0b11;
        depth++;
        while (mask < MAXIMUM_MASK_VALUE)
        {
            if ((board & mask) == 0)
            {
                const int newBoard = board | mask;
                const int score = predictMinTreeScore(newBoard, alpha, beta, depth);
                if (score >= beta)
                    return score;
                if (score > alpha)
                    alpha = score;
                if (score > bestScore)
                    bestScore = score;
            }
            mask <<= 2;
        }
        return bestScore;
    }

    int predictMinTreeScore(int board, int alpha, int beta, int depth)
    {
        const int state = getState(board);
        if (state != PLAYING || depth >= _maxDepth)
        {
            return state;
        }
        int bestScore = INT_MAX;
        int mask = 0b10;
        depth++;
        while (mask < MAXIMUM_MASK_VALUE)
        {
            if ((board & mask) == 0)
            {
                const int newBoard = board | mask;
                const int score = predictMaxTreeScore(newBoard, alpha, beta, depth);
                if (score <= alpha)
                    return score;
                if (score < beta)
                    beta = score;
                if (score < bestScore)
                    bestScore = score;
            }
            mask <<= 2;
        }
        return bestScore;
    }

    int predictMaxDecision(int board)
    {
        int bestMove = 0;
        int bestMoveScore = INT_MIN;
        int mask = 0b11;
        while (mask < MAXIMUM_MASK_VALUE)
        {
            if ((board & mask) == 0)
            {
                const int newBoard = board | mask;
                const int score = predictMinTreeScore(newBoard, INT_MIN, INT_MAX, 1);
                if (score > bestMoveScore)
                {
                    bestMoveScore = score;
                    bestMove = newBoard;
                }
            }
            mask <<= 2;
        }
        return bestMove;
    }

    int predictMinDecision(int board)
    {
        int bestMove = 0;
        int bestMoveScore = INT_MAX;
        int mask = 0b10;
        while (mask < MAXIMUM_MASK_VALUE)
        {
            if ((board & mask) == 0)
            {
                const int newBoard = board | mask;
                const int score = predictMaxTreeScore(newBoard, INT_MIN, INT_MAX, 1);
                if (score < bestMoveScore)
                {
                    bestMoveScore = score;
                    bestMove = newBoard;
                }
            }
            mask <<= 2;
        }
        return bestMove;
    }

    std::vector<int> predictMaxDecisions(int board)
    {
        std::vector<int> bestMoves;
        int bestMoveScore = INT_MIN;
        int mask = 0b11;
        while (mask < MAXIMUM_MASK_VALUE)
        {
            if ((board & mask) == 0)
            {
                const int newBoard = (board | mask);
                const int score = predictMinTreeScore(newBoard, INT_MIN, INT_MAX, 1);
                if (score > bestMoveScore)
                {
                    bestMoveScore = score;
                    bestMoves.clear();
                    bestMoves.push_back(newBoard);
                }
                else if (score == bestMoveScore)
                {
                    bestMoves.push_back(newBoard);
                }
            }
            mask <<= 2;
        }
        return bestMoves;
    }

    std::vector<int> predictMinDecisions(int board)
    {
        std::vector<int> bestMoves;
        int bestMoveScore = INT_MAX;
        int mask = 0b10;
        while (mask < MAXIMUM_MASK_VALUE)
        {
            if ((board & mask) == 0)
            {
                const int newBoard = (board | mask);
                const int score = predictMaxTreeScore(newBoard, INT_MIN, INT_MAX, 1);
                if (score < bestMoveScore)
                {
                    bestMoveScore = score;
                    bestMoves.clear();
                    bestMoves.push_back(newBoard);
                }
                else if (score == bestMoveScore)
                {
                    bestMoves.push_back(newBoard);
                }
            }
            mask <<= 2;
        }
        return bestMoves;
    }

    int predict(int board, bool isMaxTurn, int maxDepth)
    {
        _maxDepth = maxDepth;
        if (isMaxTurn)
        {
            return predictMaxDecision(board);
        }
        return predictMinDecision(board);
    }

    std::vector<int> predictAll(int board, bool isMaxTurn, int maxDepth)
    {
        _maxDepth = maxDepth;
        if (isMaxTurn)
        {
            return predictMaxDecisions(board);
        }
        return predictMinDecisions(board);
    }

    int getState(int board)
    {
        for(int winnerMask : winnerMasks)
        {
            if ((board & winnerMask) == winnerMask)
            {
                winnerMask = winnerMask >> 1;
                int piecesXor = (winnerMask ^ board) & winnerMask;
                if (piecesXor == 0)
                    return CROSS_WINS;
                if (piecesXor == winnerMask)
                    return CIRCLE_WINS;
            }
        }
        if ((board & DRAW_BOARD_STATE) == DRAW_BOARD_STATE)
            return DRAW;
        return PLAYING;
    }
}
