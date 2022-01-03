#include "AI.h"
#include "Board.h"


AI::AI() : Player{}
{
	std::cout << hello();
}

AI::AI(Board* board): Player{board}
{

}

AI::~AI()
{
	_board = nullptr;
}

int AI::minmax(int depth)
{
	
	return 0;
}

int AI::eval()
{
	return 0;
}

void AI::playTurn()
{
	int col = minmax(MINMAX_DEPTH);
	_board->addDisc(col);
	_lastColPlayed = col;
}

string AI::hello() const
{
	return "Hello by AI";
}