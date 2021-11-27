#include "Human.h"

Human::Human() : Player{}
{
	std::cout << hello();
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

string Human::hello() const
{
	return "Hello by Human";
}
