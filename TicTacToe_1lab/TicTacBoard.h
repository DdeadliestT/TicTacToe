#pragma once
#include "CellType.h"

class TicTacBoard
{
private:
	unsigned int boardsize;
	CellType** cells;
	bool bVictory = false;
	bool IsRowMade(unsigned int row);
	bool IsColumnMade(unsigned int col);
	bool IsDiagMade();
	bool IsBoardFull();
public:
	TicTacBoard(unsigned int size);
	virtual ~TicTacBoard();

	void Show();
	void SetCells(unsigned int xpos, unsigned int ypos, CellType ct) { cells[ypos][xpos] = ct; };
	bool CheckLegal(unsigned int xpos, unsigned int ypos);
	bool CheckEndCondition();
	bool IsVictory() { return bVictory; };
};