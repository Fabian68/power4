#include "Connect4.h"
#include "Board.h"
#include "Player.h"
#include "Canvas.h"

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

}