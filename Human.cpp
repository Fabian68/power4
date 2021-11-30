#include "Human.h"
#include "Board.h"

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
	// Console (temporary)
	cout << "Column ? : ";
	int col;
	cin >> col;
	while (!_board->addDisc(col))
	{
		cout << "Already filled, column ? : ";
		cin >> col;
	}
	
	_lastColPlayed = col;

	// Button clicks

	
}

string Human::hello() const
{
	return "Hello by Human";
}
