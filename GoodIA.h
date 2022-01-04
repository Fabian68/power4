#pragma once
#include "Player.h"
class GoodIA :
    public Player
{
private:
	int _playerId;
	int _secondPlayerId;

public:
	GoodIA();
	GoodIA(Board* board, int playerId,int secondPlayerId);
	~GoodIA();

	// Plays by itself with calcul
	virtual void playTurn() override;

	bool checkAlllinesPossible(int col, int row, int playerId, int freeSpace=1, int size=4) const;

	bool columnPossible(int beginCol, int beginRow, int playerId, int freeSpace, int size) const;

	bool checkAllColumnPossible(int col, int row, int playerId, int freeSpace=1, int size=4) const;

	bool linePossible(int beginCol, int beginRow,int playerId, int freeSpace, int size) const;

	bool leftDiagonalPossible(int beginCol, int beginRow, int playerId, int freeSpace, int size) const;

	bool checkAllLeftDiagonalPossible(int col, int row, int playerId, int freeSpace=1, int size=4) const;

	bool rightDiagonalPossible(int beginCol, int beginRow, int playerId, int freeSpace, int size) const;

	bool checkAllRightDiagonalPossible(int col, int row, int playerId, int freeSpace=1, int size=4) const;

	virtual string hello() const override;
};

