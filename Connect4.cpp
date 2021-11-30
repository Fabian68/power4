#include "Connect4.h"
#include "Board.h"
#include "Player.h"
#include "Canvas.h"
#include <iostream>
using std::cout;
using std::endl;

// init the board, the canvas with the board and the players todo
Connect4::Connect4() : _board{}, _canvas{ _board }, _p1{ nullptr }, _p2{ nullptr }
{
}

Connect4::Connect4(int cols, int rows, int connectedTokensToWin) : _board{ cols,rows,connectedTokensToWin }, _canvas{ _board },_p1{ nullptr }, _p2{ nullptr }
{
}

Connect4::~Connect4()
{
	delete _p1;
	delete _p2;
}

void Connect4::play()
{
	while (!_board.isThereAWinner() && !_board.allFilled())
	{
		// Current player plays its turn
		int colPlayed;
		if (_board.getNextPlayer() == PLAYER_1) {
			_p1->playTurn();
			colPlayed = _p1->getLastColPlayed();
		}
		else {
			_p2->playTurn();
			colPlayed = _p2->getLastColPlayed();
		}

		// Update the winner
		_board.checkConnect(colPlayed);
	}

	displayWinner();
	replay();
}

void Connect4::displayWinner()
{
	// draw the winner on canvas instead
	if (_board.isThereAWinner()) cout << "Player " << _board.getWinner() << "WINS" << endl;
	else cout << "It's a draw !" << endl;
}

void Connect4::replay()
{
	// rematch ?
	_board.reset();

}
