#include "AI.h"
#include "Board.h"
#include <climits>
#include <cmath>

AI::AI() : Player{}
{
	std::cout << hello();
}

AI::AI(Board* board): Player{board}, _allPaths(0)
{

}

AI::~AI()
{
	_board = nullptr;
}

AI::PossiblePath::PossiblePath(const vector<int>& playedCols, int score): _playedCols{playedCols}, _score{score}
{}

AI::PossiblePath::PossiblePath()
{}


int AI::minmax(Board& b, int depth, const vector<int>& playedCols)
{
	// if max depth or a player can win, evaluate
	if (depth == MINMAX_DEPTH || (playedCols.size()>0 && b.checkConnect(playedCols.back())))
	{
		int eval = evaluation(b,depth);
		_allPaths.push_back(PossiblePath(playedCols,eval));
		return eval;
	}	

	// otherwise, if this AI must play find best evaluation
	if (b.getNextPlayer() == _playerNum)
	{
		int maxEval = INT_MIN;
		for (int i = 0; i < b.getCols(); i++)
		{
			Board nextB = Board{ b };
			vector<int> nextPlayedCols(playedCols);
			if (nextB.addDisc(i))
			{
				nextPlayedCols.push_back(i);
				int eval = minmax(nextB, depth + 1, nextPlayedCols);
				maxEval = std::max(maxEval, eval);
			}
		}
		return maxEval;
	}

	// or if this is the other player turn, find worst evaluation
	else
	{
		int minEval = INT_MAX;
		for (int i = 0; i < b.getCols(); i++)
		{
			Board nextB = Board{ b };
			vector<int> nextPlayedCols(playedCols);

			if (nextB.addDisc(i))
			{
				nextPlayedCols.push_back(i);
				int eval = minmax(nextB, depth + 1, nextPlayedCols);
				minEval = std::min(minEval, eval);
			}
		}
		return minEval;
	}
}

int AI::evaluation(const Board& b, int depth)
{
	int winner = b.getWinner();

	if (winner == _playerNum)
		return 1000 - depth;

	else if (winner != PLAYER_NONE)
		return depth - 1000;

	else return 0;
}

void AI::playTurn()
{
    _playerNum = _board->getNextPlayer();

	// copy of board to compute and played cols for each turn
	Board b = Board{*_board};
	vector<int> playedCols(MINMAX_DEPTH, -1);

	// minmax launched
	int bestScore = minmax(b,0,playedCols);

	// searching played cols for best score
	int path = 0;
	while (path < _allPaths.size() && _allPaths[path]._score != bestScore)
		++path;

	// plays
	int col = _allPaths[path]._playedCols[0];

	_board->addDisc(col);
	_lastColPlayed = col;
}

string AI::hello() const
{
	return "Hello by AI";
}