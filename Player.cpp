#include "Player.h"
#include "Board.h"

Player::Player(): _lastColPlayed{ -1 }
{}

Player::Player(Board* board) : _board{board}, _lastColPlayed{-1}
{}

Player::~Player()
{
	_board = nullptr;
}

int Player::getLastColPlayed() const
{
	return _lastColPlayed;
}

string Player::hello() const
{
	return "Hello by Player";
}
