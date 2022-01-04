#include "AI.h"
#include "Board.h"
#include <climits>
#include <cmath>

AI::AI() : Player{}
{
	std::cout << hello();
}

AI::AI(Board* board): Player{board}
{

}

AI::~AI()
{
	_board = nullptr;
}

int AI::minmax(Board& b, int depth, const vector<int>& playedCols)
{
	// if max depth or a player can win, evaluate
	if (depth == MINMAX_DEPTH || b.checkConnect(playedCols.back()))
		return evaluation(depth);

	// otherwise, if this AI must play find best evaluation
	if (b.getNextPlayer() == _playerNum)
	{
		int maxEval = INT_MIN;
		for (int i = 0; i < b.getCols(); i++)
		{
			// todo jouer

			int eval = minmax(b, depth + 1, playedCols);
			return std::max(maxEval, eval);
		}
	}

	// or if this is the other player turn, find worst evaluation
	else
	{
		int minEval = INT_MAX;
		for (int i = 0; i < b.getCols(); i++)
		{
			// todo jouer

			int eval = minmax(b, depth + 1, playedCols);
			return std::min(minEval, eval);
		}
	}
}

int AI::evaluation(int depth)
{
	int winner = _board->getWinner();

    if (winner == _playerNum) 
		return 1000-depth;

	else if (winner != PLAYER_NONE)
		return depth - 1000;

    else return 0;
}

void AI::playTurn()
{
    _playerNum = _board->getNextPlayer();
	Board b = Board{*_board};
	vector<int> playedCols(0);
	int col = minmax(b,0,playedCols);
	_board->addDisc(col);
	_lastColPlayed = col;
}

string AI::hello() const
{
	return "Hello by AI";
}