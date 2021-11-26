#include "AI.h"
#include "Board.h"


AI::AI()
{
	AI(&Board());
}

AI::AI(Board* board): _board{board}
{

}

AI::~AI()
{
	delete _board;
}