#include "Human.h"
#include "Board.h"

Human::Human() : Player{}
{
	std::cout << hello();
}

Human::Human(Board* board, Canvas* canvas): Player{board}
{
	_canvas = canvas;
}

Human::~Human()
{
	_board = nullptr;
	_canvas = nullptr;
}

void Human::playTurn()
{
	// Console (temporary)
	/*cout << "Column ? : ";
	int col;
	cin >> col;
	while (!_board->addDisc(col))
	{
		cout << "Already filled or invalid, column ? : ";
		cin >> col;
	}
	_lastColPlayed = col;*/
	
	int col;
	do
	{
		col = _canvas->humanTurn();
	} while (!_board->addDisc(col));
	
	_lastColPlayed = col;
}

string Human::hello() const
{
	return "Hello by Human";
}
