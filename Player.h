#pragma once

#include <string>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Board;

// An abstract Player
class Player
{
protected:
	Board* _board;
	int _lastColPlayed;

public:
	Player();
	Player(Board* board);
	virtual ~Player();

	int getLastColPlayed() const;

	// We do not know how is he playing
	virtual void playTurn()=0;

	virtual string hello() const;

};

