#include "pch.h"
#include "TicTacBoard.h"

bool TicTacBoard::CheckEndCondition() {
	for (unsigned int i = 0; i < boardsize; i++){
		if (IsRowMade(i) || IsColumnMade(i))
			return true;
	}
	if (IsDiagMade() || IsBoardFull())
		return true;

	return false;
}

bool TicTacBoard::IsRowMade(unsigned int row)
{
	int numX = 0, numO = 0;
	for (unsigned int i = 0; i < boardsize; i++)
	{
		if (cells[row][i] == CellType_O)
			numO++;
		if (cells[row][i] == CellType_X)
			numX++;
	}

	if (numX == boardsize || numO == boardsize)
	{
		bVictory = true;
		return true;
	}
	return false;
}

bool TicTacBoard::IsColumnMade(unsigned int col)
{
	int numX = 0, numO = 0;
	for (unsigned int i = 0; i < boardsize; i++)
	{
		if (cells[i][col] == CellType_O)
			numO++;
		if (cells[i][col] == CellType_X)
			numX++;
	}

	if (numX == boardsize || numO == boardsize)
	{
		bVictory = true;
		return true;
	}
	return false;
}

bool TicTacBoard::IsDiagMade()
{
	int numX = 0, numO = 0;
	for (unsigned int i = 0; i < boardsize; i++)
	{
		if (cells[i][i] == CellType_O)
			numO++;
		if (cells[i][i] == CellType_X)
			numX++;
	}
	if (numX == boardsize || numO == boardsize)
	{
		bVictory = true;
		return true;
	}

	numX = numO = 0;
	for (unsigned int i = 0; i < boardsize; i++)
	{
		if (cells[i][boardsize - i - 1] == CellType_O)
			numO++;
		if (cells[i][boardsize - i - 1] == CellType_X)
			numX++;
	}
	if (numX == boardsize || numO == boardsize)
	{
		bVictory = true;
		return true;
	}

	return false;
}

bool TicTacBoard::IsBoardFull()
{
	int numX = 0, numO = 0;
	for (unsigned int i = 0; i < boardsize; i++)
	{
		for (unsigned int j = 0; j < boardsize; j++)
			{
				if (cells[i][j] == CellType_O)
					numO++;
				if (cells[i][j] == CellType_X)
					numX++;
			}
	}
	
	if ((numX + numO) == (boardsize * boardsize))
		return true;

	return false;
}

TicTacBoard::TicTacBoard(unsigned int size)
{
	this->boardsize = size;
	cells = new CellType*[size];
	for (unsigned int i = 0; i < size; i++)
		cells[i] = new CellType[size];
	for (unsigned int i = 0; i < size; i++)
		for (unsigned int j = 0; j < size; j++)
			cells[i][j] = CellType_Empty;
}

TicTacBoard::~TicTacBoard()
{
	for (unsigned int i = 0; i < boardsize; i++)
		delete[] cells[i];
	delete[] cells;
}

void TicTacBoard::Show()
{
	std::cout << "  ";
	for (unsigned int j = 0; j < boardsize; j++)
		std::cout << j + 1 << " ";
	std::cout << std::endl;

	for (unsigned int i = 0; i < boardsize; i++)
	{
		std::cout << i + 1 << " ";
		for (unsigned int j = 0; j < boardsize; j++)
		{
			switch (cells[i][j])
			{
			case CellType_X:
				std::cout << "X";
				break;
			case CellType_O:
				std::cout << "O";
				break;
			case CellType_Empty:
					std::cout << "-";
					break;
			}
			std::cout << " ";
		}
		std::cout << std::endl;
	}
}

bool TicTacBoard::CheckLegal(unsigned int xpos, unsigned int ypos)
{
	if ((xpos < 0) || (xpos > boardsize - 1) || (ypos < 0) || (ypos > boardsize - 1))
		return false;
	return (cells[ypos][xpos] == CellType_Empty);
}