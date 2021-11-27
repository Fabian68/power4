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
	const Bouton& operator[](std::size_t idx) const { return _buttons[idx]; }

	// draw methods
	void drawButtons() const;
	void drawBoard()const;
	void drawDisc(int column, int row, int color)const;
	void displayText(int x, int y, std::string texte) const;
	void redraw() const;

	
private:
	std::vector<Bouton> _buttons;
	Board* _board;
};

