#include "Canvas.h"
#include "graphics.h"
#include "Board.h"
#include "Bouton.h"

Canvas::Canvas()
{
	//todo
}

// Save a ptr of the board to draw, init the window and the buttons, and draw all the components (board, buttons and player name)
Canvas::Canvas(Board& board): _board{&board}
{
	initwindow(1400, 850, "First Sample");
	setbkcolor(0);
	setcolor(RED);
	_buttons.resize(_board->getCols());
	for (int i = 0; i < _board->getCols(); i++) {
		setfillstyle(1, RED);
		setcolor(RED);
		_buttons[i] = Bouton{ i * 100 + 100, 150, "        ", RED, WHITE, WHITE };
	}
	//drawMenu()
	redraw();
	
	
	//cleardevice(); pour nettoyer l'ecran
}

//ajouter getter des bouton
//fonction renvoyer id bouton cliquer
Canvas::~Canvas()
{
	_board = nullptr;
}

Board* Canvas::getBoard() const
{
	return _board;
}

// Draw all the canvas elements
void Canvas::redraw() const
{
	displayText(700, 20, "Tour du joueur : ");
	drawButtons();
	drawBoard();
}

// Draw the buttons to put a token
void Canvas::drawButtons() const
{
	for (int i = 0; i < _board->getCols(); i++) {
		_buttons[i].afficher();
	}
}

// Draw the board and tokens
void Canvas::drawBoard() const
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

// Draw a disc
void Canvas::drawDisc(int column, int row, int color)const {
	setfillstyle(1, color);
	setcolor(color);
	int maxRow = getBoard()->getRows();
	fillellipse(column*100+150, (maxRow-row-1)*100+250, 45, 45);
}

// Display the current player name
void Canvas::displayText(int x, int y, std::string texte)const {
	setcolor(WHITE);
	char* txt = const_cast<char*>(texte.c_str());
	outtextxy(x, y, txt);
}

