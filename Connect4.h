#pragma once

#include "Board.h"

class Player;
#include "Canvas.h"; //class Canvas;

class Connect4 {

private:
	Board _board;
	Canvas _canvas;
	Player* _p1, *_p2;

public:
	Connect4();
	Connect4(int cols, int rows, int connectedTokensToWin);
	~Connect4();

	void play();
};

