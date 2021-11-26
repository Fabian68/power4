#pragma once

#include <vector>

using std::vector;


const int PLAYER_NONE = 0;
const int PLAYER_1 = 1;
const int PLAYER_2 = 2;


class Board {

private:
	vector<vector<int>> _board;

	// Pour connaitre en temps réel le remplissage du plateau
	vector<int> _discHeights;

	int _rows;
	int _cols;
	int _winner;
	int _currentPlayer;
	int _connectedTokensToWin;

public:
	// L'affichage devra se faire a l'envers pour correspondre 
	Board(int cols=7, int rows=6, int connectedTokensToWin=4);

	int getCols() const;
	int getRows() const;
	int getPlayer() const;
	int getWinner() const;
	int getConnectedTokensToWin() const;

	bool isThereAWinner() const;

	int getValue(int columnNuumber, int lineNumber) const; //testing purpose
	bool isFilled(int columnNumber) const;

	// Check winning lines for the last play
	bool checkVerticalLine(int col, int row) ;
	bool checkHorizontalLine(int col, int row) ;
	bool checkDiagonals(int col, int row) ;

	void addDisc(int columnNumber);




};

