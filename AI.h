#pragma once

#include "Player.h"

class Board;

// An AI player
class AI : public Player
{
private :


public:
	AI();
	AI(Board* board);
	~AI();

	// Plays by itself with calcul
	virtual void playTurn() override;

	virtual string hello() const override;

};

