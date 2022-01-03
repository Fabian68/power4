#pragma once

#include "Board.h"

class Player;
#include "Canvas.h"; //class Canvas;

const int HUMAN_PLAYER = 0;
const int RANDOM_PLAYER = 1;
const int AI_PLAYER = 2;

class Connect4 {

private:
	// The board of the game
	Board _board;

	// The Canvas/Window to draw the board
	Canvas _canvas;

	// Two players to play the game (humans or IA)
	Player* _p1, *_p2;

	// Create (return) a random player by default
	Player* createPlayer(int playerType) const;


public:
	Connect4();
	Connect4(int cols, int rows, int connectedTokensToWin);
	~Connect4();


	// Launch the game
	void play();
	// Display the winner on canvas
	void displayWinner();
	// Ask for playing one more time
	void replay();
};

