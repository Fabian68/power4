#include "RandomPlayer.h"

#include "AI.h"
#include "Board.h"
#include <ctime>
#include <cstdlib>

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
	int cols = _board->getCols();
	int col;
	do
	{
		col = rand() % cols;
	} while (!_board->addDisc(col));

	_lastColPlayed = col;
}

string RandomPlayer::hello() const
{
	return "Hello by Random AI";
}