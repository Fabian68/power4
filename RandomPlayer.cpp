#include "RandomPlayer.h"

#include "AI.h"
#include "Board.h"
#include <ctime>
#include <cstdlib>
//#include <stdio.h>

RandomPlayer::RandomPlayer() : Player{}
{
	std::cout << hello();
}

RandomPlayer::RandomPlayer(Board* board) : Player{ board }
{

}

RandomPlayer::~RandomPlayer()
{
	_board = nullptr;
}

void RandomPlayer::playTurn()
{
	bool played = false;
	int cols = _board->getCols();
	int col;
	do
	{
		col = rand() % cols;
		played = _board->addDisc(col);
	} while (!played);

	_lastColPlayed = col;
}

string RandomPlayer::hello() const
{
	return "Hello by Random AI";
}