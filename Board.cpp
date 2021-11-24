#include "Board.h"

Board::Board(int numbersOfColumn, int numbersOfLine) : _numbersOfColumn{numbersOfColumn}, _numbersOfLine{numbersOfLine}
{
	_board.resize(numbersOfColumn);
	_discsHeights.resize(numbersOfColumn, 0);

	for (int i = 0;i < numbersOfColumn;i++) {
		_board[i].resize(numbersOfLine, 0);
	}

}

void Board::addDisc(int columnNumber, int value)
{
	if (!isFilled(columnNumber)) {
		_board[columnNumber][_discsHeights[columnNumber]] = value;
		_discsHeights[columnNumber]+=1;
	}
}

bool Board::isFilled(int columnNumber)
{
	return _numbersOfLine<=(_discsHeights[columnNumber]);
}

int Board::value(int columnNuumber, int lineNumber)
{
	return _board[columnNuumber][lineNumber];
}

int Board::numbersOfColumn()
{
	return _numbersOfColumn;
}

int Board::numbersOfLine()
{
	return _numbersOfLine;
}
