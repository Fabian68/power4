#pragma once

class Board;

class Player
{
protected:
	Board* _board;

public:
	Player();
	Player(Board* board);
	virtual ~Player();

	virtual void playTurn()=0;

};

