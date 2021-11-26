#include "Connect4.h"
#include "Board.h"
#include "AI.h"

Connect4::Connect4() : _board{Board()}
{
	_AIPlayer = AI(&_board);
}

void Connect4::play()
{

}