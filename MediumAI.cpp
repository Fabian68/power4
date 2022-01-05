#include "MediumAI.h"

#include "Board.h"
#include <vector>

MediumAI::MediumAI() : Player{}
{
}

MediumAI::MediumAI(Board* board,int playerId,int secondPlayerId) : Player { board }, _playerId{playerId}, _secondPlayerId{ secondPlayerId }
{
}

MediumAI::~MediumAI()
{
	_board = nullptr;
}

void MediumAI::playTurn()
{
	//bool played = false;
	int cols = _board->getCols();
	


	std::vector<int> indexOfPlayableColumn;

	int col = 0;
	int row;
	while (col < cols) {
		row = _board->getHeight(col);
		if (checkAlllinesPossible(col,row,_playerId)) {
			indexOfPlayableColumn.push_back(col);
		}
		
		if (checkAllColumnPossible(col, row, _playerId)) {
			indexOfPlayableColumn.push_back(col);
		}
		if (checkAllLeftDiagonalPossible(col, row, _playerId)) {
			indexOfPlayableColumn.push_back(col);
		}
		if (checkAllRightDiagonalPossible(col, row, _playerId)) {
			indexOfPlayableColumn.push_back(col);
		}
		col++;
	}
	col = 0;
	if (indexOfPlayableColumn.size() == 0) {
		while (col < cols) {
			row = _board->getHeight(col);
			if (checkAlllinesPossible(col, row, _secondPlayerId)) {
				indexOfPlayableColumn.push_back(col);
			}
			if (checkAllColumnPossible(col, row, _secondPlayerId)) {
				indexOfPlayableColumn.push_back(col);
			}
			if (checkAllLeftDiagonalPossible(col, row, _secondPlayerId)) {
				indexOfPlayableColumn.push_back(col);
			}
			if (checkAllRightDiagonalPossible(col, row, _secondPlayerId)) {
				indexOfPlayableColumn.push_back(col);
			}
			col++;
		}
	}
	col = 0;
	if (indexOfPlayableColumn.size() == 0) {
		while (col < cols) {
			row = _board->getHeight(col);
			if (checkAlllinesPossible(col, row, _playerId,2)) {
				indexOfPlayableColumn.push_back(col);
			}
			if (checkAllColumnPossible(col, row, _playerId,2)) {
				indexOfPlayableColumn.push_back(col);
			}
			if (checkAllLeftDiagonalPossible(col, row, _playerId,2)) {
				indexOfPlayableColumn.push_back(col);
			}
			if (checkAllRightDiagonalPossible(col, row, _playerId,2)) {
				indexOfPlayableColumn.push_back(col);
			}
			col++;
		}
	}
	col = 0;
	if (indexOfPlayableColumn.size() == 0) {
		while (col < cols) {
			row = _board->getHeight(col);
			if (checkAlllinesPossible(col, row, _secondPlayerId,2)) {
				indexOfPlayableColumn.push_back(col);
			}
			if (checkAllColumnPossible(col, row, _secondPlayerId,2)) {
				indexOfPlayableColumn.push_back(col);
			}
			if (checkAllLeftDiagonalPossible(col, row, _secondPlayerId,2)) {
				indexOfPlayableColumn.push_back(col);
			}
			if (checkAllRightDiagonalPossible(col, row, _secondPlayerId,2)) {
				indexOfPlayableColumn.push_back(col);
			}
			col++;
		}
	}
	col = 0;
	if (indexOfPlayableColumn.size() == 0) {
		while (col < cols) {
			row = _board->getHeight(col);
			if (checkAlllinesPossible(col, row, _playerId, 3)) {
				indexOfPlayableColumn.push_back(col);
			}
			if (checkAllColumnPossible(col, row, _playerId, 3)) {
				indexOfPlayableColumn.push_back(col);
			}
			if (checkAllLeftDiagonalPossible(col, row, _playerId, 3)) {
				indexOfPlayableColumn.push_back(col);
			}
			if (checkAllRightDiagonalPossible(col, row, _playerId, 3)) {
				indexOfPlayableColumn.push_back(col);
			}
			col++;
		}
	}
	col = 0;
	if (indexOfPlayableColumn.size() == 0) {
		while (col < cols) {
			row = _board->getHeight(col);
			if (checkAlllinesPossible(col, row, _secondPlayerId, 3)) {
				indexOfPlayableColumn.push_back(col);
			}
			if (checkAllColumnPossible(col, row, _secondPlayerId, 3)) {
				indexOfPlayableColumn.push_back(col);
			}
			if (checkAllLeftDiagonalPossible(col, row, _secondPlayerId, 3)) {
				indexOfPlayableColumn.push_back(col);
			}
			if (checkAllRightDiagonalPossible(col, row, _secondPlayerId, 3)) {
				indexOfPlayableColumn.push_back(col);
			}
			col++;
		}
	}

	int playedCol;
	std::cout << indexOfPlayableColumn.size() << std::endl;
	if (indexOfPlayableColumn.size() == 0) {
		do
		{
			playedCol = rand() % cols;
		} while (!_board->addDisc(playedCol));
	}
	else {
		playedCol = indexOfPlayableColumn[0];
		_board->addDisc(playedCol);
	}

	_lastColPlayed = playedCol;
}

/*
This function Return if a line is possible with the number of space ( 1 = a possible victory for the given player
*/
bool MediumAI::linePossible(int beginCol, int beginRow,int playerId, int freeSpace , int size )const {
	bool possible = true;
	if (_board->inBound(beginCol,beginRow) && _board->inBound(beginCol+size-1, beginRow)) {
		for (int col = beginCol;col < beginCol + size;col++) {
			if (_board->getValue(col, beginRow) != playerId && _board->getValue(col, beginRow) != PLAYER_NONE) {
				possible=false;
			}
			else if (_board->getValue(col, beginRow) == PLAYER_NONE) {
				freeSpace--;
			}
		}
		if (freeSpace != 0) {
			possible = false;
		}
	}
	else {
		possible = false;
	}
	return possible;
}


/*
This function Return if a line is possible with the number of space ( 1 = a possible victory for the given player
*/
bool MediumAI::checkAlllinesPossible(int  col, int  row, int playerId, int freeSpace , int size )const {
	bool possible = false;

	for (int c = col; c >= 0;c--) {
		if (linePossible(c, row, playerId, freeSpace, size)) {
			possible =true;
		
		}
	}
	return possible;
}

/*
Same as line but for column
*/
bool MediumAI::columnPossible(int beginCol, int beginRow, int playerId, int freeSpace , int size )const {
	bool possible = true;
	if (_board->inBound(beginCol, beginRow) && _board->inBound(beginCol, beginRow+size -1)) {
		for (int row = beginRow;row < beginRow + size;row++) {
			if (_board->getValue(beginCol, row) != playerId && _board->getValue(beginCol, row) != PLAYER_NONE) {
				possible = false;
			}
			else if (_board->getValue(beginCol, row) == PLAYER_NONE) {
				freeSpace--;
			}
		}
		if (freeSpace != 0) {
			possible = false;
		}
	}
	else {
		possible = false;
	}
	return possible;
}

/*
This function Return if a line is possible with the number of space ( 1 = a possible victory for the given player
*/
bool MediumAI::checkAllColumnPossible(int col, int row, int playerId, int freeSpace , int size )const {
	bool possible = false;

	for (int r = row; r >= 0;r--) {
		if (columnPossible(col, r, playerId, freeSpace, size)) {
			possible = true;
		
		}
	}
	return possible;
}

/*
Same as line but for column
*/
bool MediumAI::leftDiagonalPossible(int beginCol, int beginRow, int playerId, int freeSpace , int size )const {
	bool possible = true;
	if (_board->inBound(beginCol, beginRow) && _board->inBound(beginCol-size+1, beginRow + size - 1)) {
		for (int col=beginCol, row = beginRow;col>=0 || row < beginRow + size;col--,row++) {
			if (_board->getValue(col, row) != playerId && _board->getValue(col, row) != PLAYER_NONE) {
				possible = false;
			}
			else if (_board->getValue(col, row) == PLAYER_NONE) {
				freeSpace--;
			}
		}
		if (freeSpace != 0) {
			possible = false;
		}
	}
	else {
		possible = false;
	}
	return possible;
}

/*
This function Return if a line is possible with the number of space ( 1 = a possible victory for the given player
*/
bool MediumAI::checkAllLeftDiagonalPossible(int col, int row, int playerId, int freeSpace , int size )const {
	bool possible = false;

	for (int c=col,r = row; r >= 0;c++,r--) {
		if (columnPossible(col, r, playerId, freeSpace, size)) {
			possible = true;
			
		}
	}
	return possible;
}

/*
Same as line but for column
*/
bool MediumAI::rightDiagonalPossible(int beginCol, int beginRow, int playerId, int freeSpace , int size )const {
	bool possible = true;
	if (_board->inBound(beginCol, beginRow) && _board->inBound(beginCol+size-1, beginRow + size - 1)) {
		for (int col=beginCol, row = beginRow;col< beginCol + size || row < beginRow + size;col++,row++) {
			if (_board->getValue(col, row) != playerId && _board->getValue(col, row) != PLAYER_NONE) {
				possible = false;
			}
			else if (_board->getValue(col, row) == PLAYER_NONE) {
				freeSpace--;
			}
		}
		if (freeSpace != 0) {
			possible = false;
		}
	}
	else {
		possible = false;
	}
	return possible;
}

/*
This function Return if a line is possible with the number of space ( 1 = a possible victory for the given player
*/
bool MediumAI::checkAllRightDiagonalPossible(int col, int row, int playerId, int freeSpace , int size )const {
	bool possible = false;

	for (int c = col, r = row; c >= 0 && r >= 0;c--, r--) {
		if (columnPossible(col, r, playerId, freeSpace, size)) {
			possible = true;
			
		}
	}
	return possible;
}
string MediumAI::hello() const
{
	return string();
}
