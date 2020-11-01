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

int TicTacToeMinimax::predict(int board, bool isMaxTurn)
{
    if (isMaxTurn)
    {
        return predictMaxDecision(board);
    }
    return predictMinDecision(board);
}

std::vector<int> TicTacToeMinimax::evaluateAll(int board, bool isMaxTurn)
{
    if (isMaxTurn)
    {
        return predictMaxDecisions(board);
    }
    return predictMinDecisions(board);
}

std::vector<int> TicTacToeMinimax::predictMaxDecisions(int board)
{
    std::vector<int> bestMoves;
    int bestMoveScore = -999;
    int mask = 0b11;
    while (mask < MAXIMUM_MASK_VALUE)
    {
        if ((board & mask) == 0)
        {
            const int newBoard = (board | mask);
            const int score = predictMinTreeScore(newBoard, -999, 999);
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

std::vector<int> TicTacToeMinimax::predictMinDecisions(int board)
{
    std::vector<int> bestMoves;
    int bestMoveScore = 999;
    int mask = 0b10;
    while (mask < MAXIMUM_MASK_VALUE)
    {
        if ((board & mask) == 0)
        {
            const int newBoard = (board | mask);
            const int score = predictMaxTreeScore(newBoard, -999, 999);
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

int TicTacToeMinimax::predictMaxDecision(int board)
{
    int bestMove = 0;
    int bestMoveScore = -999;
    int mask = 0b11;
    while (mask < MAXIMUM_MASK_VALUE)
    {
        if ((board & mask) == 0)
        {
            const int newBoard = board | mask;
            const int score = predictMinTreeScore(newBoard, -999, 999);
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

int TicTacToeMinimax::predictMinDecision(int board)
{
    int bestMove = 0;
    int bestMoveScore = 999;
    int mask = 0b10;
    while (mask < MAXIMUM_MASK_VALUE)
    {
        if ((board & mask) == 0)
        {
            const int newBoard = board | mask;
            const int score = predictMaxTreeScore(newBoard, -999, 999);
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

int TicTacToeMinimax::predictMaxTreeScore(int board, int alpha, int beta)
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
            const int score = predictMinTreeScore(newBoard, alpha, beta);
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

int TicTacToeMinimax::predictMinTreeScore(int board, int alpha, int beta)
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
            const int score = predictMaxTreeScore(newBoard, alpha, beta);
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

int TicTacToeMinimax::getState(int board)
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
