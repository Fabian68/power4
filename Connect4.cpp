#include "Connect4.h"
#include "Board.h"
#include "Player.h"
#include "Canvas.h"
#include <iostream>
#include "Human.h"
#include "RandomPlayer.h"
#include "AI.h"
#include "MediumAI.h"

// init the board, the canvas with the board and the players todo
Connect4::Connect4() : _board{}, _canvas{ _board }, _p1{ nullptr }, _p2{ nullptr }
{
	_p1 = createPlayer(HUMAN_PLAYER);
	_p2 = createPlayer(RANDOM_PLAYER,2);
}

Connect4::Connect4(int cols, int rows, int connectedTokensToWin) : _p1{ nullptr }, _p2{ nullptr }
{
	_board = Board(cols, rows, connectedTokensToWin);
	_canvas = Canvas(_board);
	int p1Type, p2Type;
	_canvas.drawMenu(p1Type,p2Type);
	_p1 = createPlayer(p1Type);
	_p2 = createPlayer(p2Type,2);
	_cptWinnerPlayer1 = 0;
	_cptWinnerPlayer2 = 0;
	play();
}

Connect4::~Connect4()
{
	delete _p1;
	delete _p2;
}

Player* Connect4::createPlayer(int playerType,int player)
{
	switch (playerType)
	{
		case HUMAN_PLAYER:
			return new Human(&_board,&_canvas);
			break;
		case AI_PLAYER:
			return new AI(&_board);
			break;
		case MEDIUM_AI_PLAYER:
			if (player == 2) {
				return new MediumAI(&_board,PLAYER_2,PLAYER_1);
			}
			else {
				return new MediumAI(&_board, PLAYER_1, PLAYER_2);
			}
			
		default :
			return new RandomPlayer(&_board);
			break;
	}
}

void Connect4::play()
{
	_canvas.redraw();
	while (!_board.isThereAWinner() && !_board.allFilled())
	{
		delay(500);
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

		_canvas.redraw();

		// Update the winner
		_board.checkConnect(colPlayed);
	}

	int winner = _board.getWinner();
	if (winner == PLAYER_1) {
		_cptWinnerPlayer1++;
	}
	else {
		_cptWinnerPlayer2++;
	}
	if ((_cptWinnerPlayer1 + _cptWinnerPlayer2) % 20 == 0) {
		std::cout<<std::endl;
		std::cout << "Joueur 1 : " << _cptWinnerPlayer1 << " victoires." << std::endl;
		std::cout << "Joueur 2 : " << _cptWinnerPlayer2 << " victoires." << std::endl;
	}
	displayWinner();

	rematch();
}

void Connect4::displayWinner()
{
	// draw the winner on canvas instead
	_canvas.displayWinner();
}

void Connect4::rematch()
{
	// rematch ?
	delay(3000);
	_board.reset();
	play();
}
