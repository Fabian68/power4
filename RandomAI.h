#pragma once

#include "Player.h"


class RandomAI : public Player
{
private:


public:
	RandomAI();
	RandomAI(Board* board);
	~RandomAI();

	// Plays by itself with calcul
	virtual void playTurn() override;

	virtual string hello() const override;

};

