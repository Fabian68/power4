#pragma once

#include "Player.h"
#include <vector>
using std::vector;

class Board;

// An AI player
class AI : public Player
{
private :
	const int MINMAX_DEPTH = 7;
	int _playerNum;

public:
	AI();
	AI(Board* board);
	~AI();

	// Plays by itself with calcul
	int minmax(Board& b, int depth, const vector<int>& playedCols);
	int evaluation(int depth);
	virtual void playTurn() override;

	virtual string hello() const override;

};

