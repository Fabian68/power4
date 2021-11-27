#include "Canvas.h"
#include "graphics.h"
#include "Board.h"

Canvas::Canvas()
{
	//todo
}

Canvas::Canvas(Board& board): _board{&board}
{
	initwindow(1400, 850, "First Sample");
	setbkcolor(0);
	setcolor(RED);
	drawBoard();
	displayText(700, 20, "Tour du joueur : ");
	_button.resize(_board->getCols());
	for (int i = 0; i < _board->getCols(); i++) {
		_button[i] = Bouton(i * 100 + 100, 150, "Not a Name", 0, WHITE, WHITE);
		_button[i].afficher();
	}
}

Canvas::~Canvas()
{
	_board = nullptr;
}

Board* Canvas::getBoard() const
{
	return _board;
}

void Canvas::drawBoard()const
{
	setfillstyle(1, LIGHTGRAY);
	setcolor(BLACK);
	int Tab[8] = { 100,200,100+_board->getCols()*100,200,100 + _board->getCols() * 100,200 + _board->getRows() * 100,100,200+ _board->getRows() *100 };
	fillpoly(4, Tab);
	for (int i = 0;i < _board->getCols();i++) {
		for (int j = 0;j < _board->getRows();j++) {
			drawDisc(i, j, WHITE);
		}
	}
}

void Canvas::drawDisc(int column, int row, int color)const {
	setfillstyle(1, color);
	setcolor(color);

	fillellipse(column*100+150, row*100+250, 45, 45);
}

void Canvas::displayText(int x, int y, std::string texte)const {
	setcolor(WHITE);
	char* txt = const_cast<char*>(texte.c_str());
	outtextxy(x, y, txt);
}