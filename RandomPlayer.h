#pragma once

#include "Player.h"


class RandomPlayer : public Player
{
private:


public:
	RandomPlayer();
	RandomPlayer(Board* board);
	~RandomPlayer();

	// Plays by itself with calcul
	virtual void playTurn() override;

	virtual string hello() const override;

};

