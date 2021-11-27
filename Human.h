#pragma once

#include "Player.h"


class Human : public Player
{
private:


public:
	Human();
	Human(Board* board);
	~Human();

	virtual void playTurn() override;

};

