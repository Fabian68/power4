#include "Canvas.h"
#include "graphics.h"
#include "Board.h"
#include "Bouton.h"
#include "Connect4.h"
#include <iostream>

Canvas::Canvas()
{
	//todo
}

// Save a ptr of the board to draw, init the window and the buttons, and draw all the components (board, buttons and player name)
Canvas::Canvas(Board& board): _board{&board}
{
	int sizeX = 1400;
	int sizeY = 850;
	initwindow(sizeX, sizeY, "Game de ouf");
	setbkcolor(0);
	setcolor(RED);
	_buttons.resize(_board->getCols());
	for (int i = 0; i < _board->getCols(); i++) {
		setfillstyle(1, RED);
		setcolor(RED);
		_buttons[i] = Bouton{ i * 100 + 100, 150, "        ", RED, WHITE, WHITE };
	}

}

void Canvas::drawMenu(int & choixJoueur1,int & choixJoueur2)const {

	const int RANDOM_IA=1;
	const int GOOD_IA = 2;
	const int HUMAN_PLAYER = 0;

	choixJoueur1=RANDOM_IA;
	choixJoueur2=RANDOM_IA;
	int x = 100;
	int y = 200;
	int pasY = 100;
	int pasX = 150;
	bool choixFait=false;
	bool clique;
	int DELAY = 50;
	int xc, yc;
	do {
		clique = false;
		displayText(x, y, "ChoixJoueur1");
		Bouton randomIAButtonP1 = Bouton(x + pasX, y, "Choix ia aléatoire");
		Bouton goodIAButtonP1 = Bouton(x + pasX * 2, y, "Choix ia moyenne");
		Bouton humanPlayerButtonP1 = Bouton(x + pasX * 3, y, "Choix joueur humain");

		randomIAButtonP1.afficher();
		goodIAButtonP1.afficher();
		humanPlayerButtonP1.afficher();

		displayText(x, y + pasY, "ChoixJoueur2");
		Bouton randomIAButtonP2 = Bouton(x + pasX, y + pasY, "Choix ia aléatoire");
		Bouton goodIAButtonP2 = Bouton(x + pasX * 2, y + pasY, "Choix ia moyenne");
		Bouton humanPlayerButtonP2 = Bouton(x + pasX * 3, y + pasY, "Choix joueur humain");

		randomIAButtonP2.afficher();
		goodIAButtonP2.afficher();
		humanPlayerButtonP2.afficher();

		Bouton jouer = Bouton(x + pasX * 2, y + pasY * 2, "Jouer");
		jouer.afficher();


		switch (choixJoueur1) {
		case RANDOM_IA:
			displayText(x+pasX*5, y, "Choix actuelle : Random IA");
			break;
		case GOOD_IA:
			displayText(x + pasX * 5, y, "Choix actuelle : Good IA");
			break;
		case HUMAN_PLAYER:
			displayText(x + pasX * 5, y, "Choix actuelle :Joueur Humain ");
			break;
		}

		switch (choixJoueur2) {
		case RANDOM_IA:
			displayText(x + pasX * 5, y+pasY, "Choix actuelle :Random IA ");
			break;
		case GOOD_IA:
			displayText(x + pasX * 5, y + pasY, "Choix actuelle :Good IA ");
			break;
		case HUMAN_PLAYER:
			displayText(x + pasX * 5, y + pasY, "Choix actuelle :Joueur Humain");
			break;
		}



		do {
			while (!ismouseclick(WM_LBUTTONDOWN)) {
				delay(DELAY);
			}

			getmouseclick(WM_LBUTTONDOWN, xc, yc);
			if (jouer.comprendLesCoord(xc, yc)) { choixFait = true;clique = true; }
			else if (randomIAButtonP1.comprendLesCoord(xc, yc)) {
				clique = true;
				choixJoueur1 = RANDOM_IA;
			}
			else if (goodIAButtonP1.comprendLesCoord(xc, yc)) {
				clique = true;
				choixJoueur1 = GOOD_IA;
			}
			else if (humanPlayerButtonP1.comprendLesCoord(xc, yc)) {
				clique = true;
				choixJoueur1 = HUMAN_PLAYER;
			}
			else if (randomIAButtonP2.comprendLesCoord(xc, yc)) {
				clique = true;
				choixJoueur2 = RANDOM_IA;
			}
			else if (goodIAButtonP2.comprendLesCoord(xc, yc)) {
				clique = true;
				choixJoueur2 = GOOD_IA;
			}
			else if (humanPlayerButtonP2.comprendLesCoord(xc, yc)) {
				clique = true;
				choixJoueur2 = HUMAN_PLAYER;
			}
		} while (!clique);
		//cleardevice();
	} while (!choixFait);
}

int Canvas::humanTurn()const {
	int DELAY = 50;
	int xc, yc;
	int index;
	do {
		while (!ismouseclick(WM_LBUTTONDOWN)) {
			delay(DELAY);
		}
		
	getmouseclick(WM_LBUTTONDOWN, xc, yc);
	index = buttonWhoIsCliked(xc,yc);
	} while (index<0);
	return index;
}
//ajouter getter des bouton
int Canvas::buttonWhoIsCliked(int x, int y)const {
	int index = -1;

	for (int i = 0;i < _buttons.size();i++) {
		if (_buttons[i].comprendLesCoord(x, y)) {
			index = i;
		}
	}
	return index;
}
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
	cleardevice();
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
	int baseX = 100;
	int baseY = 200;
	int baseWidth = 100;
	int Tab[8] = { baseX,baseY,baseX+_board->getCols()*baseWidth,baseY,baseX + _board->getCols() * baseWidth,baseY + _board->getRows() * baseWidth,baseX,baseY+ _board->getRows() *baseWidth };
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

