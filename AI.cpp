#include "AI.h"
#include "Board.h"


AI::AI() : Player{}
{}

AI::AI(Board* board): Player{board}
{}

AI::~AI()
{
	_board = nullptr;
}

void AI::playTurn()
{

}