#include "Canvas.h"
#include "graphics.h"
#include "Board.h"

Canvas::Canvas(int numbersOColumn, int numbersOfLine)
{
	initwindow(1400, 1000, "First Sample");
	setbkcolor(0);
	setcolor(RED);
	drawBoard(numbersOColumn, numbersOfLine);
	displayText(700, 20, "Tour du joueur : ");
	_button.resize(numbersOColumn);
	for (int i = 0;i < numbersOColumn;i++) {
		_button[i] = Bouton(i * 100 + 100, 150,"Not a Name", 0, WHITE, WHITE);
		_button[i].afficher();
	}
}

Canvas::Canvas(const Board& b)
{	
	Canvas(b.numbersOfColumn(), b.numbersOfLine());
}

void Canvas::drawBoard(int numbersOfColumn, int numbersOfLine)const
{
	setfillstyle(1, LIGHTGRAY);
	setcolor(BLACK);
	int Tab[8] = { 100,200,100+numbersOfColumn*100,200,100 + numbersOfColumn * 100,200 + numbersOfLine * 100,100,200+numbersOfLine*100 };
	fillpoly(4, Tab);
	for (int i = 0;i < numbersOfColumn;i++) {
		for (int j = 0;j < numbersOfLine;j++) {
			drawDisc(i, j, WHITE);
		}
	}
}

void Canvas::drawDisc(int column, int line, int color)const {
	setfillstyle(1, color);
	setcolor(color);

	fillellipse(column*100+150, line*100+250, 45, 45);
}

void Canvas::displayText(int x, int y, std::string texte)const {
	setcolor(WHITE);
	char* txt = const_cast<char*>(texte.c_str());
	outtextxy(x, y, txt);
}