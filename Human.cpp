#include "Human.h"
#include "Board.h"

Human::Human() : Player{}
{
	std::cout << hello();
}

Human::Human(Board* board,Canvas * C): Player{board}
{
	_canvas = C;
}

Human::~Human()
{
	_board = nullptr;
}

void Human::playTurn()
{
	// Console (temporary)
	_canvas->redraw();
	
	int col = _canvas->humanTurn();
	while (!_board->addDisc(col))
	{
		col = _canvas->humanTurn();
	}
	
	_lastColPlayed = col;

	// Button clicks

	
}

string Human::hello() const
{
	return "Hello by Human";
}
