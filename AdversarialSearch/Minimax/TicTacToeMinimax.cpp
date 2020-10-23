#include "TicTacToeMinimax.h"

#define WINNER_MASK_LENGTH 8
#define MAXIMUM_MASK_VALUE 0b1'00'00'00'00'00'00'00'00'00
const int DRAW_BOARD_STATE = 0b10'10'10'10'10'10'10'10'10;
const int winnerMasks[WINNER_MASK_LENGTH] =
{
    0b10'10'10'00'00'00'00'00'00,
    0b00'00'00'10'10'10'00'00'00,
    0b00'00'00'00'00'00'10'10'10,
    0b10'00'00'10'00'00'10'00'00,
    0b00'10'00'00'10'00'00'10'00,
    0b00'00'10'00'00'10'00'00'10,
    0b10'00'00'00'10'00'00'00'10,
    0b00'00'10'00'10'00'10'00'00
};

int TicTacToeMinimax::evaluate(const int board, const bool isMaxTurn)
{
    if (isMaxTurn)
    {
        return evaluateMaxDecision(board);
    }
    return evaluateMinDecision(board);
}

std::vector<int> TicTacToeMinimax::evaluateAll(const int board, const bool isMaxTurn)
{
    if (isMaxTurn)
    {
        return evaluateMaxDecisions(board);
    }
    return evaluateMinDecisions(board);
}

std::vector<int> TicTacToeMinimax::evaluateMaxDecisions(const int board)
{
    std::vector<int> bestMoves;
    int bestMoveScore = -999;
    int mask = 0b11;
    while (mask < MAXIMUM_MASK_VALUE)
    {
        if ((board & mask) == 0)
        {
            const int newBoard = (board | mask);
            const int score = getMinTreeScore(newBoard, -999, 999);
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

std::vector<int> TicTacToeMinimax::evaluateMinDecisions(const int board)
{
    std::vector<int> bestMoves;
    int bestMoveScore = 999;
    int mask = 0b10;
    while (mask < MAXIMUM_MASK_VALUE)
    {
        if ((board & mask) == 0)
        {
            const int newBoard = (board | mask);
            const int score = getMaxTreeScore(newBoard, -999, 999);
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

int TicTacToeMinimax::evaluateMaxDecision(const int board)
{
    int bestMove = 0;
    int bestMoveScore = -999;
    int mask = 0b11;
    while (mask < MAXIMUM_MASK_VALUE)
    {
        if ((board & mask) == 0)
        {
            const int newBoard = board | mask;
            const int score = getMinTreeScore(newBoard, -999, 999);
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

int TicTacToeMinimax::evaluateMinDecision(const int board)
{
    int bestMove = 0;
    int bestMoveScore = 999;
    int mask = 0b10;
    while (mask < MAXIMUM_MASK_VALUE)
    {
        if ((board & mask) == 0)
        {
            const int newBoard = board | mask;
            const int score = getMaxTreeScore(newBoard, -999, 999);
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

int TicTacToeMinimax::getMaxTreeScore(const int board, int alpha, int beta)
{
    const int state = getState(board);
    if (state != PLAYING)
    {
	    return state;
    }
    int bestScore = -999;
    int mask = 0b11;
    while (mask < MAXIMUM_MASK_VALUE)
    {
        if ((board & mask) == 0)
        {
            const int newBoard = board | mask;
            const int score = getMinTreeScore(newBoard, alpha, beta);
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

int TicTacToeMinimax::getMinTreeScore(const int board, int alpha, int beta)
{
    const int state = getState(board);
    if (state != PLAYING)
    {
	    return state;
    }
    int bestScore = 999;
    int mask = 0b10;
    while (mask < MAXIMUM_MASK_VALUE)
    {
        if ((board & mask) == 0)
        {
            const int newBoard = board | mask;
            const int score = getMaxTreeScore(newBoard, alpha, beta);
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

inline int TicTacToeMinimax::getState(const int board)
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
