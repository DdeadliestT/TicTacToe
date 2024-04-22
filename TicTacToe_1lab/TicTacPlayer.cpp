#include "pch.h"
#include "TicTacPlayer.h"

void TicTacPlayer::SetupPlayer(std::string name, CellType cellType)
{
	this->name = name;
	this->cellType = cellType;
}

void TicTacPlayer::SetBoard(TicTacBoard* board)
{
	this->board = board;
}

std::string TicTacPlayer::GetName()
{
	return this->name;
}

bool TicTacPlayer::MakeMove()
{
	unsigned int row, col;
	std::cout << "����� " << name << ", ��� ���..." << std::endl;
	std::cout << "������� ������: ";
	std::cin >> row;
	std::cout << "������� �������: ";
	std::cin >> col;

	if (this->board->CheckLegal(col - 1, row - 1))
	{
		this->board->SetCells(col - 1, row - 1, this->cellType);
		return true;
	}

	return false;
}