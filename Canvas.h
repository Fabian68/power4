#pragma once
class Board;
#include<string>
#include "Bouton.h"
#include <vector>
class Canvas
{
public:
	Canvas(int numbersOColumn=7, int numbersOfLine=6);
	Canvas(const Board& b);
	void drawBoard(int numbersOfColumn,int numbersOfLine)const;
	void drawDisc(int column, int line, int color)const;
	void displayText(int x, int y, std::string texte) const;
	const Bouton& operator[](std::size_t idx) const { return _button[idx]; }
private:
	std::vector<Bouton> _button;
};

