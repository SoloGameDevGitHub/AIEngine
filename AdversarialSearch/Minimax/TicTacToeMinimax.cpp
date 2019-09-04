#include "TicTacToeMinimax.h"

const int DrawBoardState = 0b101010101010101010;

const int winnerMasks[8] =
{
    0b101010000000000000,
    0b000000101010000000,
    0b000000000000101010,
    0b100000100000100000,
    0b001000001000001000,
    0b000010000010000010,
    0b100000001000000010,
    0b000010001000100000
};

int TicTacToeMinimax::evaluate(const int board, const bool isMaxTurn)
{
    return isMaxTurn ? evaluateMaxDecision(board)
                     : evaluateMinDecision(board);
};

std::vector<int> TicTacToeMinimax::evaluateAll(const int board, const bool isMaxTurn)
{
    return isMaxTurn ? evaluateMaxDecisions(board)
                     : evaluateMinDecisions(board);
};

std::vector<int> TicTacToeMinimax::evaluateMaxDecisions(const int board)
{
    std::vector<int> bestMoves;
    float bestMoveScore = -999.0;
    int mask = 3;

    for (int x = 0; x < 9; x++)
    {
        if ((board & mask) == 0)
        {
            const int newBoard = (board | mask);
            float score = getMinTreeScore(newBoard, -999.0, 999.0, 1);
            
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
};

std::vector<int> TicTacToeMinimax::evaluateMinDecisions(const int board)
{
    std::vector<int> bestMoves;
    float bestMoveScore = 999.0;
    int mask = 2;

    for (int x = 0; x < 9; x++)
    {
        if ((board & mask) == 0)
        {
            const int newBoard = (board | mask);
            float score = getMaxTreeScore(newBoard, -999.0, 999.0, 1);
	    
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
};

int TicTacToeMinimax::evaluateMaxDecision(const int board)
{
    int bestMove = 0;
    float bestMoveScore = -999.0;
    int mask = 3;
    
    for (int x = 0; x < 9; x++)
    {
        if ((board & mask) == 0)
        {
            float score = getMinTreeScore(board | mask, -999.0, 999.0, 1);

            if (score > bestMoveScore)
            {
                bestMoveScore = score;
                bestMove = (board | mask);
            }
        }
        mask <<= 2;
    }
    return bestMove;
};

int TicTacToeMinimax::evaluateMinDecision(const int board)
{
    int bestMove = 0;
    float bestMoveScore = 999.0;
    int mask = 2;
    
    for (int x = 0; x < 9; x++)
    {
        if ((board & mask) == 0)
        {
            float score = getMaxTreeScore(board | mask, -999.0, 999.0, 1);
            if (score < bestMoveScore)
            {
                bestMoveScore = score;
                bestMove = (board | mask);
            }
        }
        mask <<= 2;
    }
    return bestMove;
};

float TicTacToeMinimax::getMaxTreeScore(const int board, float alpha, float beta, int depth)
{
    int state = getState(board);
    if (state != Playing)
    {
	    return ((float) getScore(state) / depth);
    }
    
    float bestScore = -999.0;
    int mask = 3;

    for (int x = 0; x < 9; x++)
    {
        if ((board & mask) == 0)
        {
            float score = getMinTreeScore(board | mask, alpha, beta, depth + 1);
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
};

float TicTacToeMinimax::getMinTreeScore(const int board, float alpha, float beta, int depth)
{
    int state = getState(board);
    if (state != Playing)
    {
	    return ((float) getScore(state) / depth);
    }
    
    float bestScore = 999.0;
    int mask = 2;
    
    for (int x = 0; x < 9; x++)
    {
        if ((board & mask) == 0)
        {
            float score = getMaxTreeScore(board | mask, alpha, beta, depth + 1);
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
};

int TicTacToeMinimax::getState(const int board)
{
    for(int x = 0; x < 8; x++)
    {
        // check if the board represent a winner state
        int winnerMask = winnerMasks[x];
        if ((winnerMask & board) != winnerMask)
            continue;

        // check if all pieces are the same
        winnerMask = winnerMask >> 1;
        int piecesXor = (winnerMask ^ board) & winnerMask;

        if (piecesXor == 0)
            return CrossWins;
        if (piecesXor == winnerMask)
            return CircleWins;
    }
    if ((board & DrawBoardState) == DrawBoardState)
        return Draw;
    return Playing;
};

int TicTacToeMinimax::getScore(const int state)
{
    if (state == CrossWins)
        return 1;
    if (state == CircleWins)
        return -1;
    return 0;
};
