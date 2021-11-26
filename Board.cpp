#include "Board.h"

Board::Board(int colNumber, int rowNumber, int connectedTokensToWin) : _cols{colNumber}, _rows{rowNumber},_connectedTokensToWin{connectedTokensToWin},
	_winner{PLAYER_NONE}, _currentPlayer{PLAYER_1}
{
	_board.resize(_cols);
	_discHeights.resize(_cols, 0);

	for (int i = 0;i < _cols;i++) {
		_board[i].resize(_rows, 0);
	}

}

int Board::getCols() const
{
	return _cols;
}

int Board::getRows() const
{
	return _rows;
}

int Board::getPlayer() const
{
	return _currentPlayer;
}

int Board::getWinner() const
{
	return _winner;
}

int Board::getConnectedTokensToWin() const
{
	return _connectedTokensToWin;
}

bool Board::isThereAWinner() const
{
	return _winner!=PLAYER_NONE;
}

int Board::getValue(int col, int row) const
{
	return _board[col][row];
}

bool Board::isFilled(int col) const
{
	return _rows <= (_discHeights[col]);
}

bool Board::checkVerticalLine(int col, int row)
{
	int playedColor = _board[col][row];
	int connectedTokens = 0;
	int i = 0;

	while (i<_rows && connectedTokens < _connectedTokensToWin)
	{
		if (_board[col][i] == playedColor) ++connectedTokens;
		else connectedTokens = 0;
		++i;
	}

	if (connectedTokens == _connectedTokensToWin)
	{
		_winner = playedColor;
		return true;
	}

	else return false;
}

bool Board::checkHorizontalLine(int col, int row)
{
	int playedColor = _board[col][row];
	int connectedTokens = 0;
	int i = 0;

	while (i < _cols && connectedTokens < _connectedTokensToWin)
	{
		if (_board[i][row] == playedColor) ++connectedTokens;
		else connectedTokens = 0;
		++i;
	}

	if (connectedTokens == _connectedTokensToWin)
	{
		_winner = playedColor;
		return true;
	}

	else return false;
}


bool Board::checkDiagonals(int col, int row)
{
	int playedColor = _board[col][row];
	int connectedTokens = 0;

	// First diagonal
	int k = 0;
	while (col - k >= 0 && row - k >= 0 && _board[col - k][row - k] == playedColor)
	{
		++connectedTokens;
		++k;
	}

	int k = 1;
	while (col + k < _cols && row + k < _rows && _board[col + k][row + k] == playedColor)
	{
		++connectedTokens;
		++k;
	}

	if (connectedTokens == _connectedTokensToWin)
	{
		_winner = playedColor;
		return true;
	}

	// Second diagonal
	connectedTokens = 0;
	int k = 0;
	while (col - k >= 0 && row + k < _rows && _board[col + k][row - k] == playedColor)
	{
		++connectedTokens;
		++k;
	}

	int k = 1;
	while (col + k < _cols && row - k >= 0 && _board[col + k][row - k] == playedColor)
	{
		++connectedTokens;
		++k;
	}

	if (connectedTokens == _connectedTokensToWin)
	{
		_winner = playedColor;
		return true;
	}

	else return false;
}

void Board::addDisc(int col)
{
	if (!isFilled(col)) {
		_board[col][_discHeights[col]] = _currentPlayer;
		++_discHeights[col];
	}
}
