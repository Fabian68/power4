#pragma once

#include "Board.h"

class Player;
#include "Canvas.h"; //class Canvas;

class Connect4 {

private:
	// The board of the game
	Board _board;

	// The Canvas/Window to draw the board
	Canvas _canvas;

	// Two players to play the game (humans or IA)
	Player* _p1, *_p2;

public:
	Connect4();
	Connect4(int cols, int rows, int connectedTokensToWin);
	~Connect4();

	void play();
	void displayWinner();
	void replay();
};

