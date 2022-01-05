#pragma once

#include "Player.h"
#include <vector>
using std::vector;

class Board;

// An AI player
class AI : public Player
{
private :

	class PossiblePath
	{
	public :
		PossiblePath(const vector<int>& playedCols, int score);
		PossiblePath();
		vector<int> _playedCols;
		int _score;
	};

	class PossibleCol
	{
	public:
		PossibleCol();
		PossibleCol(int col, int score);
		int _possibleCol;
		int _score;
	};

	const int MINMAX_DEPTH = 3;
	const int EPSILON = 5;
	int _playerNum;
	//vector<PossiblePath> _allPaths;
	vector<PossibleCol> _allPossibleCols;

public:
	AI();
	AI(Board* board);
	~AI();

	// Plays by itself with calcul
	int minmax(Board& b, int depth, const vector<int>& playedCols);
	int evaluation(const Board& b, int depth);
	virtual void playTurn() override;

	virtual string hello() const override;

};

