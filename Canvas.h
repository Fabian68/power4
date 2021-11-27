#pragma once

#include <string>
#include "Bouton.h"
#include <vector>

class Board;

class Canvas
{
public:
	Canvas();
	Canvas(Board& board);
	~Canvas();
	Board* getBoard() const;
	void drawBoard()const;
	void drawDisc(int column, int row, int color)const;
	void displayText(int x, int y, std::string texte) const;
	const Bouton& operator[](std::size_t idx) const { return _button[idx]; }
	
private:
	std::vector<Bouton> _button;
	Board* _board;
};

