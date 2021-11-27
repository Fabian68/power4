#pragma once

#include "Player.h"

// A human player
class Human : public Player
{
private:


public:
	Human();
	Human(Board* board);
	~Human();

	// Plays by clicking on the screen to put a token in a column
	virtual void playTurn() override;

};

