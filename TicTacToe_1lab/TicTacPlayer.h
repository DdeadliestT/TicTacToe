#pragma once
#include "TicTacBoard.h"

class TicTacPlayer
{
private:
	TicTacBoard* board;
	CellType cellType;
	std::string name;
public:
	TicTacPlayer() {};
	virtual ~TicTacPlayer() { delete board; };
	void SetupPlayer(std::string name, CellType cellType);
	void SetBoard(TicTacBoard* board);
	std::string GetName();
	bool MakeMove();
};