#include "TicTacToeMinimax.h"

#define MAX(a, b) (a > b) ? a : b
#define MIN(a, b) (a < b) ? a : b

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

int TicTacToeMinimax::evaluate(int board, bool isMaxTurn)
{
    return (isMaxTurn) ? evaluateMaxDecision(board)
                   : evaluateMinDecision(board);
};

std::vector<int> TicTacToeMinimax::evaluateAll(int board, bool isMaxTurn)
{
    return isMaxTurn ? evaluateMaxDecisions(board)
                 : evaluateMinDecisions(board);
};

std::vector<int> TicTacToeMinimax::evaluateMaxDecisions(int board)
{
    std::vector<int> bestMoves;
    int bestMoveScore = INT_MIN;
    int mask = 3;
    
    for (int x = 0; x < 9; x++)
    {
        if ((board & mask) == 0)
        {
            int newBoard = (board | mask);
            int score = getMinTreeScore(newBoard, -100, 100);
            
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

std::vector<int> TicTacToeMinimax::evaluateMinDecisions(int board)
{
    std::vector<int> bestMoves;
    int bestMoveScore = INT_MAX;
    int mask = 2;
    
    for (int x = 0; x < 9; x++)
    {
        if ((board & mask) == 0)
        {
            int newBoard = (board | mask);
            int score = getMaxTreeScore(newBoard, -100, 100);
            
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

int TicTacToeMinimax::evaluateMaxDecision(int board)
{
    int bestMove = 0;
    int bestMoveScore = INT_MIN;
    int mask = 3;
    
    for (int x = 0; x < 9; x++)
    {
        if ((board & mask) == 0)
        {
            int score = getMinTreeScore(board | mask, -100, 100);

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

int TicTacToeMinimax::evaluateMinDecision(int board)
{
    int bestMove = 0;
    int bestMoveScore = INT_MAX;
    int mask = 2;
    
    for (int x = 0; x < 9; x++)
    {
        if ((board & mask) == 0)
        {
            int score = getMaxTreeScore(board | mask, -100, 100);

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

int TicTacToeMinimax::getMaxTreeScore(int board, int alpha, int beta)
{
    int state = getState(board);
    if (state != Playing)
    {
        return getScore(state);
    }
    
    int bestScore = INT_MIN;
    int mask = 3;

    for (int x = 0; x < 9; x++)
    {
        if ((board & mask) == 0)
        {
            int score = getMinTreeScore(board | mask, alpha, beta);

            if (score > alpha) alpha = score;
            if (alpha >= beta) return score;

            bestScore = MAX(bestScore, score);
        }
        mask <<= 2;
    }
    return bestScore;
};

int TicTacToeMinimax::getMinTreeScore(int board, int alpha, int beta)
{
    int state = getState(board);
    if (state != Playing)
    {
        return getScore(state);
    }
    
    int bestScore = INT_MAX;
    int mask = 2;
    
    for (int x = 0; x < 9; x++)
    {
        if ((board & mask) == 0)
        {
            int score = getMaxTreeScore(board | mask, alpha, beta);
            
            if (score < beta) beta = score;
            if (alpha >= beta) return score;
            
            bestScore = MIN(bestScore, score);
        }
        mask <<= 2;
    }
    return bestScore;
};

int TicTacToeMinimax::getState(int board)
{
    for(int x = 0; x < 8; x++)
    {
        // check if the board is at a winner state
        int winnerMask = winnerMasks[x];
        if ((winnerMask & board) != winnerMask) continue;

        // check if pieces are the same
        winnerMask = winnerMask >> 1;
        int piecesXor = (winnerMask ^ board) & winnerMask;
        
        if (piecesXor == 0) return CrossWins;
        if (piecesXor == winnerMask) return CircleWins;
    }
    if ((board & DrawBoardState) == DrawBoardState) return Draw;
    return Playing;
};

int TicTacToeMinimax::getScore(int state)
{
    if (state == CrossWins) return 1;
    if (state == CircleWins) return -1;
    return 0;
};
