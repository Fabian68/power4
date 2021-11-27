#pragma once

class Board;

// An abstract Player
class Player
{
protected:
	Board* _board;

public:
	Player();
	Player(Board* board);
	virtual ~Player();

	// We do not know how is he playing
	virtual void playTurn()=0;

};

