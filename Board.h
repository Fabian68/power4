#pragma once

#include <vector>
class Board
{
private:
	std::vector<std::vector<int>> _board;

	//pour connaitre en temps réel le remplissage du plateau
	std::vector<int> _discsHeights;

	int _numbersOfColumn;
	int _numbersOfLine;

public:
	//L'affichage devra se faire a l'envers pour correspondre 
	Board(int numbersOfColumn=7,int numbersOfLine=6 );
	void addDisc(int columnNumber, int value);
	bool isFilled(int columnNumber);

	//We need the coordonates in order to only around the last coordonate played and not on all the board
	bool checkVerticalLine(int columnNumber, int lineNumber,int value);
	bool checkHorizontalLine(int columnNumber, int lineNumber,int value);
	bool checkDiagonals(int columnNumber, int lineNumber,int value);

	int value(int columnNuumber, int lineNumber);//testing purpose

	int numbersOfColumn();
	int numbersOfLine();

};

