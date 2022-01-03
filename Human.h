#pragma once

#include "Player.h"
#include "Canvas.h"

// A human player
class Human : public Player
{
private:
	Canvas * _canvas;

public:
	Human();
	Human(Board* board,Canvas * C);
	~Human();

	// Plays by clicking on the screen to put a token in a column
	virtual void playTurn() override;

	virtual string hello() const override;

};

