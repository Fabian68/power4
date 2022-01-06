#pragma once

#include "Player.h"
#include <vector>
using std::vector;

class Board;

// An AI player
class AI : public Player
{
private :

	class PossibleCol
	{
	public:
		PossibleCol();
		PossibleCol(int col, int score);
		int _possibleCol;
		int _score;
	};

	const int MINMAX_DEPTH = 6;
	const int EPSILON = 5;
	int _playerNum;
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

