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

void AI::playTurn()
{

}

string AI::hello() const
{
	return "Hello by AI";
}