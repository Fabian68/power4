#include "GoodIA.h"

#include "Board.h"
#include <vector>

GoodIA::GoodIA() : Player{}
{
}

GoodIA::GoodIA(Board* board) : Player { board }
{
}

GoodIA::~GoodIA()
{
	_board = nullptr;
}

void GoodIA::playTurn()
{
	bool played = false;
	int cols = _board->getCols();
	
	int col;

	std::vector<int> indexOfPlayableColumn;

	//check winable column

	//if result =0 check winable column for the second player in order to block him

	//check line of 3 and 2 ( can be more if we need more than 4 coin for win)

	//if still no result block lines of 3 and 2 of second player

	//if still nothing just choose a random column

	_lastColPlayed = col;
}

string GoodIA::hello() const
{
	return string();
}
