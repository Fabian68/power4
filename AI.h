#pragma once

#include "Player.h"

class Board;

// An AI player
class AI : public Player
{
private :
	const int MINMAX_DEPTH = 7;

public:
	AI();
	AI(Board* board);
	~AI();

	// Plays by itself with calcul
	int minmax(int depth);
	int eval();
	virtual void playTurn() override;

	virtual string hello() const override;

};

