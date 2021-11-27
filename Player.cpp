#include "Player.h"
#include "Board.h"

Player::Player()
{}

Player::Player(Board* board) : _board{board}
{}

Player::~Player()
{
	_board = nullptr;
}

string Player::hello() const
{
	return "Hello by Player";
}
