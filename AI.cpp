#include "AI.h"
#include "Board.h"
#include <climits>
#include <ctime>
#include <cstdlib>

AI::AI() : Player{}
{
	std::cout << hello();
}

AI::AI(Board* board): Player{board},  _playerNum{-1}, _allPossibleCols(0)
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

AI::PossibleCol::PossibleCol() : _possibleCol{ -1 }, _score{INT_MIN}
{
}

AI::PossibleCol::PossibleCol(int col, int score) : _possibleCol{ col }, _score{ score }
{
}


void printBoard(const Board& b)
{
	for (int i = b.getRows()-1; i >=0; i--)
	{
		for (int j = 0; j < b.getCols(); j++)
			cout << b.getValue(j, i)<<" ";
		cout << endl;
	}
}


int AI::minmax(Board& b, int depth, const vector<int>& playedCols)
{
	// if max depth or a player can win, evaluate	
	if (depth == MINMAX_DEPTH || (playedCols.size() > 0 && (b.checkConnect(playedCols.back()) || b.allFilled())))
	{
		//cout << "eval " << depth << endl;
		b.checkConnect(playedCols.back());// << endl;
		//printBoard(b);
		//cout << "lastplayedcol " << playedCols.back() << "/" << b.getWinner() << endl << endl;
		int eval = evaluation(b, depth);
		//_allPaths.push_back(PossiblePath(playedCols, eval));
		return eval;
	}

	// otherwise, if this AI must play find best evaluation
	if (b.getNextPlayer() == _playerNum)
	{
		//cout << "max " << depth << endl;
		int maxEval = INT_MIN;
		vector<int> evals(0);
		for (int i = 0; i < b.getCols(); i++)
		{
			Board nextB = Board{ b };
			vector<int> nextPlayedCols(playedCols);
			//cout << "sizes : " << playedCols.size() << " " << nextPlayedCols.size() << endl;
			if (nextB.addDisc(i))
			{
				nextPlayedCols.push_back(i);
				int eval = minmax(nextB, depth + 1, nextPlayedCols);
				if (depth == 0) _allPossibleCols.push_back(PossibleCol{ i,eval });
				evals.push_back(eval);
				//maxEval = std::max(maxEval, eval);
			}
		}
		cout << "max of ";
		for (int e = 0; e < evals.size(); e++)
		{
			cout << evals[e] << " ";
			maxEval = std::max(maxEval, evals[e]);
		}
		cout << endl;
		return maxEval;
	}

	// or if this is the other player turn, find worst evaluation
	else
	{
		//cout << "min " << depth << endl;
		int minEval = INT_MAX;
		vector<int> evals(0);

		for (int i = 0; i < b.getCols(); i++)
		{
			Board nextB = Board{ b };
			vector<int> nextPlayedCols(playedCols);
			//cout << "sizes : ";
			//for(int k=0; k<playedCols.size();k++) cout<< playedCols[k] << "-" << nextPlayedCols[k] << " ";
			//cout << endl;

			if (nextB.addDisc(i))
			{
				nextPlayedCols.push_back(i);
				int eval = minmax(nextB, depth + 1, nextPlayedCols);
				evals.push_back(eval);
				//minEval = std::min(minEval, eval);
			}
		}
		cout << "min of ";
		for (int e = 0; e < evals.size(); e++)
		{
			cout << evals[e] << " ";
			minEval = std::min(minEval, evals[e]);
		}
		cout << endl;
		return minEval;
	}
}

/*
int AI::minmax2(Board& b, int depth, const vector<int>& playedCols)
{
	// if max depth or a player can win, evaluate	
	if (depth == MINMAX_DEPTH || (playedCols.size()>0 && (b.checkConnect(playedCols.back()) || b.allFilled())))
	{
		//cout << "eval " << depth << endl;
		b.checkConnect(playedCols.back());// << endl;
		//printBoard(b);
		//cout << "lastplayedcol " << playedCols.back() << "/" << b.getWinner() << endl << endl;
		int eval = evaluation(b,depth);
		_allPaths.push_back(PossiblePath(playedCols,eval));
		return eval;
	}

	// otherwise, if this AI must play find best evaluation
	if (b.getNextPlayer() == _playerNum)
	{
		//cout << "max " << depth << endl;
		int maxEval = INT_MIN;
		for (int i = 0; i < b.getCols(); i++)
		{
			Board nextB = Board{ b };
			vector<int> nextPlayedCols(playedCols);
			//cout << "sizes : " << playedCols.size() << " " << nextPlayedCols.size() << endl;
			if (nextB.addDisc(i))
			{
				nextPlayedCols.push_back(i);
				int eval = minmax(nextB, depth + 1, nextPlayedCols);
				maxEval = std::max(maxEval, eval);
			}
			/*
			else
			{
				int eval = evaluation(b, depth);
				_allPaths.push_back(PossiblePath(playedCols, eval));
				maxEval = std::max(maxEval, eval);
			}
		}
		return maxEval;
	}

	// or if this is the other player turn, find worst evaluation
	else
	{
		//cout << "min " << depth << endl;
		int minEval = INT_MAX;
		for (int i = 0; i < b.getCols(); i++)
		{
			Board nextB = Board{ b };
			vector<int> nextPlayedCols(playedCols);
			//cout << "sizes : ";
			//for(int k=0; k<playedCols.size();k++) cout<< playedCols[k] << "-" << nextPlayedCols[k] << " ";
			//cout << endl;

			if (nextB.addDisc(i))
			{
				nextPlayedCols.push_back(i);
				int eval = minmax(nextB, depth + 1, nextPlayedCols);
				minEval = std::min(minEval, eval);
			}
			/*
			else
			{
				int eval = evaluation(b, depth);
				_allPaths.push_back(PossiblePath(playedCols, eval));
				minEval = std::min(minEval, eval);
			}
		}
		return minEval;
	}
}
*/
int AI::evaluation(const Board& b, int depth)
{
	int winner = b.getWinner();
	//cout << "winner " << winner << endl;

	if (winner == _playerNum)
		return 1000 - depth;

	else if (winner != PLAYER_NONE)
		return depth - 1000;

	else return 0;
}

void AI::playTurn()
{
	cout <<endl<< "-------------------------------------------" << endl;
    _playerNum = _board->getNextPlayer();

	int col;

	//del
	Board b = Board{ *_board };
	vector<int> playedCols(0);

	// minmax launching
	minmax(b, 0, playedCols);

	/*
	for (int i = 0; i < _allPaths.size(); i++)
	{
		cout << "score " << _allPaths[i]._score << " for : ";
		for (int j = 0; j < _allPaths[i]._playedCols.size(); j++)
			cout << _allPaths[i]._playedCols[j]<<".";
		cout << endl << endl;
	}

	// searching played cols for best score
	int path = 0;
	while (path < _allPaths.size() && _allPaths[path]._score != bestScore)
		++path;*/
	int bestCol = -1;
	int bestScore = INT_MIN;
	for (int c = 0; c < _allPossibleCols.size(); c++)
		if (_allPossibleCols[c]._score > bestScore) bestCol = c;
	col = bestCol;

	// plays
	//col = _allPaths[path]._playedCols[0];
	_board->addDisc(col);
	//_allPaths.clear();
	_allPossibleCols.clear();
	//del
	cout << "AI played " << col << endl;
	/*
	// if does not play randomly, compute next plays
	if (rand() % 101 > EPSILON)
	{
		// copy of board to compute and played cols for each turn
		Board b = Board{ *_board };
		vector<int> playedCols(MINMAX_DEPTH, -1);

		// minmax launched
		int bestScore = minmax(b, 0, playedCols);

		// searching played cols for best score
		int path = 0;
		while (path < _allPaths.size() && _allPaths[path]._score != bestScore)
			++path;

		// plays
		col = _allPaths[path]._playedCols[0];
		_board->addDisc(col);
	}

	else
	{
		int cols = _board->getCols();
		do
		{
			col = rand() % cols;
		} while (!_board->addDisc(col));
	}*/

	_lastColPlayed = col;
}

string AI::hello() const
{
	return "Hello by AI";
}
