#pragma once

#include "Board.h"
#include "AI.h"

class Connect4 {

private:
	Board _board;
	AI _AIPlayer;

public:
	Connect4();

	void play();
};

