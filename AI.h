#pragma once

#include "Player.h"

class Board;

class AI : public Player
{
private :


public:
	AI();
	AI(Board* board);
	~AI();

	virtual void playTurn() override;

};

