#pragma once

class Board;
class AI;

class Connect4 {

private:
	Board _board;
	AI _AIPlayer;

public:
	Connect4();

	void play();
};

