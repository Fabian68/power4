#include "Board.h"

vector<vector<int>> Board::getBoard() const
{
	return vector<vector<int>>();
}

vector<int> Board::getDiscHeights() const
{
	return vector<int>();
}

// Init params and board with the empty value, num of player and none winner 
Board::Board(int cols, int rows, int connectedTokensToWin) : _cols{cols}, _rows{rows}, _connectedTokensToWin{connectedTokensToWin},
	_winner{PLAYER_NONE}, _nextPlayer{PLAYER_1}
{
	_board.resize(cols);
	_discHeights.resize(cols, 0);

	for (int i = 0;i < cols;i++) {
		_board[i].resize(rows, PLAYER_NONE);
	}
}

Board::Board(const Board& b): _cols{b.getCols()}, _rows{b.getRows()}, _connectedTokensToWin{b.getConnectedTokensToWin()},
	_winner{b.getWinner()}, _nextPlayer{b.getNextPlayer()}, _board{b.getBoard()}, _discHeights{b.getDiscHeights()}
{}

int Board::getCols() const
{
	return _cols;
}

int Board::getRows() const
{
	return _rows;
}

int Board::getNextPlayer() const
{
	return _nextPlayer;
}

int Board::getWinner() const
{
	return _winner;
}

int Board::getConnectedTokensToWin() const
{
	return _connectedTokensToWin;
}

int Board::getHeight(int column) const
{
	return _discHeights[column];
}

bool Board::isThereAWinner() const
{
	return _winner!=PLAYER_NONE;
}

int Board::getValue(int col, int row) const
{
	return _board[col][row];
}

int Board::getLastValue(int col) const
{
	return getValue(col, getHeight(col) - 1);
}

bool Board::isFilled(int col) const
{
	return _discHeights[col] >= _rows;
}

bool Board::allFilled() const
{
	int i = 0;
	while (i < _cols && isFilled(i))
		++i;
	return i == _cols;
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

bool Board::inBound(int col, int row)const {
	bool inBound = true;
	if (col < 0 || col >= _cols) {
		inBound = false;
	}
	else if (row < 0 || row >= _rows) {
		inBound = false;
	}
	return inBound;
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

	k = 1;
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
	k = 0;
	while (col - k >= 0 && row + k < _rows && _board[col - k][row + k] == playedColor)
	{
		++connectedTokens;
		++k;
	}

	k = 1;
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

bool Board::checkConnect(int col)
{
	if (col < 0 || col >= _cols)
		return false;
	int row = _discHeights[col]-1;
	return (checkVerticalLine(col, row) || checkHorizontalLine(col, row) || checkDiagonals(col, row));
}

bool Board::addDisc(int col)
{
	if (col >= 0 && col < _cols && !isFilled(col)) {
		_board[col][_discHeights[col]] = _nextPlayer;
		++_discHeights[col];
		if (_nextPlayer == PLAYER_1) _nextPlayer = PLAYER_2;
		else _nextPlayer = PLAYER_1;
		return true;
	}

	else return false;
}

// Clear the board and put the empty value everywhere (PLAYER_NONE)
void Board::clear()
{
	for (int i = 0; i < _cols; i++)
	{
		_discHeights[i] = 0;
		for (int j = 0; j < _rows; j++)
		{
			_board[i][j] = PLAYER_NONE;
		}
	}
}

void Board::reset()
{
	clear();
	_nextPlayer = _winner;
	_winner = PLAYER_NONE;
}
