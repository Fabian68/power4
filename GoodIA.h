#pragma once
#include "Player.h"
class GoodIA :
    public Player
{
private:


public:
	GoodIA();
	GoodIA(Board* board);
	~GoodIA();

	// Plays by itself with calcul
	virtual void playTurn() override;

	virtual string hello() const override;
};

