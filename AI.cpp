#include "AI.h"
#include "Board.h"


AI::AI(Board* board): _board{board}
{

}

AI::~AI()
{
	delete _board;
}