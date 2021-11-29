#include "RandomAI.h"

#include "AI.h"
#include "Board.h"
#include <ctime>
#include <cstdlib>
//#include <stdio.h>

RandomAI::RandomAI() : Player{}
{
	std::cout << hello();
}

RandomAI::RandomAI(Board* board) : Player{ board }
{

}

RandomAI::~RandomAI()
{
	_board = nullptr;
}

void RandomAI::playTurn()
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

string RandomAI::hello() const
{
	return "Hello by Random AI";
}