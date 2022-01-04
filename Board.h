#pragma once

#include <vector>
#include <iostream>
using std::cout;
using std::vector;

const int PLAYER_NONE = 0;
const int PLAYER_1 = 1;
const int PLAYER_2 = 2;

class Board {

private:
	vector<vector<int>> _board;

	// Pour connaitre en temps réel le remplissage du plateau
	vector<int> _discHeights;

	// nb of rows and cols
	int _rows;
	int _cols;

	// the num of the winner if exists, the player num who must play, and the number of tokens to align to win
	int _winner;
	int _nextPlayer;
	int _connectedTokensToWin;

public:
	// L'affichage devra se faire a l'envers pour correspondre 
	Board(int cols=7, int rows=6, int connectedTokensToWin=4);

	// getters
	int getCols() const;
	int getRows() const;
	int getNextPlayer() const;
	int getWinner() const;
	int getConnectedTokensToWin() const;
	int getHeight(int column)const;

	bool isThereAWinner() const;

	int getValue(int col, int row) const; //testing purpose
	bool isFilled(int col) const;
	bool allFilled() const;

	// Check winning lines for the last play
	bool checkVerticalLine(int col, int row) ;
	bool inBound(int col, int row) const;
	bool checkHorizontalLine(int col, int row) ;
	bool checkDiagonals(int col, int row) ;
	bool checkConnect(int col);

	bool addDisc(int columnNumber);

	// Clear the board
	void clear();
	void reset();
};

