#include "TicTacToeMinimax.h"

unsigned int Playing = 0;
unsigned int Draw = 1;
unsigned int CrossWins = 2;
unsigned int CircleWins = 3;
const unsigned int DrawBoardState = 0b101010101010101010;
const unsigned int winnerMasks[8] =
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
const unsigned int ONE = 1;

unsigned int TicTacToeMinimax::evaluate(const unsigned int board, const bool isMaxTurn)
{
    return isMaxTurn ? evaluateMaxDecision(board)
                     : evaluateMinDecision(board);
}

std::vector<unsigned int> TicTacToeMinimax::evaluateAll(const unsigned int board, const bool isMaxTurn)
{
    return isMaxTurn ? evaluateMaxDecisions(board)
                     : evaluateMinDecisions(board);
}

std::vector<unsigned int> TicTacToeMinimax::evaluateMaxDecisions(const unsigned int board)
{
    std::vector<unsigned int> bestMoves;
    float bestMoveScore = -999.0f;
    unsigned int mask = 3;

    for (int x = 0; x < 9; x++)
    {
        if ((board & mask) == 0)
        {
            const unsigned int newBoard = (board | mask);
            float score = getMinTreeScore((unsigned int) newBoard, -999.0f, 999.0f, 1);
            
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

std::vector<unsigned int> TicTacToeMinimax::evaluateMinDecisions(const unsigned int board)
{
    std::vector<unsigned int> bestMoves;
    float bestMoveScore = 999.0f;
    unsigned int mask = 2;

    for (int x = 0; x < 9; x++)
    {
        if ((board & mask) == 0)
        {
            const unsigned int newBoard = (board | mask);
            float score = getMaxTreeScore(newBoard, -999.0f, 999.0f, 1);
	    
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

unsigned int TicTacToeMinimax::evaluateMaxDecision(const unsigned int board)
{
    int bestMove = 0;
    float bestMoveScore = -999.0f;
    unsigned int mask = 3;
    
    for (int x = 0; x < 9; x++)
    {
        if ((board & mask) == 0)
        {
            float score = getMinTreeScore(board | mask, -999.0f, 999.0f, 1);
            if (score > bestMoveScore)
            {
                bestMoveScore = score;
                bestMove = (board | mask);
            }
        }
        mask <<= 2;
    }
    return bestMove;
}

unsigned int TicTacToeMinimax::evaluateMinDecision(const unsigned int board)
{
    unsigned int bestMove = 0;
    float bestMoveScore = 999.0f;
    unsigned int mask = 2;
    
    for (int x = 0; x < 9; x++)
    {
        if ((board & mask) == 0)
        {
            float score = getMaxTreeScore(board | mask, -999.0f, 999.0f, 1);
            if (score < bestMoveScore)
            {
                bestMoveScore = score;
                bestMove = (board | mask);
            }
        }
        mask <<= 2;
    }
    return bestMove;
}

float TicTacToeMinimax::getMaxTreeScore(const unsigned int board, float alpha, float beta, int depth)
{
    const unsigned int state = getState(board);
    if (state != Playing)
    {
	    return (getScore(state) / (float)depth);
    }
    
    float bestScore = -999.0f;
    unsigned int mask = 3;

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
}

float TicTacToeMinimax::getMinTreeScore(const unsigned int board, float alpha, float beta, int depth)
{
    const unsigned int state = getState(board);
    if (state != Playing)
    {
	    return (getScore(state) / (float)depth);
    }
    
    float bestScore = 999.0;
    unsigned int mask = 2;
    
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
}

int TicTacToeMinimax::getState(const unsigned int &board)
{
    if ((board & DrawBoardState) == DrawBoardState)
        return Draw;
    for(unsigned int winnerMask : winnerMasks)
    {
        // check if the board represent a winner state
        if ((winnerMask & board) != winnerMask)
            continue;

        // check if all pieces are the same
        winnerMask = winnerMask >> ONE;
        unsigned int piecesXor = (winnerMask ^ board) & winnerMask;

        if (piecesXor == 0)
            return CrossWins;
        if (piecesXor == winnerMask)
            return CircleWins;
    }
    return Playing;
}

int TicTacToeMinimax::getScore(const unsigned int &state)
{
    if (state == CrossWins)
        return 1;
    if (state == CircleWins)
        return -1;
    return 0;
}
