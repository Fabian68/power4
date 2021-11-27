#include "Human.h"

Human::Human() : Player{}
{
}

Human::Human(Board* board): Player{board}
{
}

Human::~Human()
{
	_board = nullptr;
}

void Human::playTurn()
{

}
