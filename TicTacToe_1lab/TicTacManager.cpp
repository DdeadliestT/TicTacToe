#include "pch.h"
#include "TicTacManager.h"

TicTacManager::~TicTacManager()
{
	delete this->player1;
	delete this->player2;
	delete this->board;
}

bool TicTacManager::Init()
{
	unsigned int boardsize;
	std::string playerName;
	std::cout << "������� ����� ������ (3-6): ";
	std::cin >> boardsize;
	if ((boardsize < 3) || (boardsize > 6))
	{
		std::cout << "������� �������� ����� ������ ����\n";
		return false;
	}

	this->board = new TicTacBoard(boardsize);
	this->player1 = new TicTacPlayer;
	this->player2 = new TicTacPlayer;
	std::cin.ignore();
	std::cout << "������� ��� ������, ��������� X: ";
	std::getline(std::cin, playerName);
	player1->SetupPlayer(playerName, CellType_X);
	std::cout << "������� ��� ������, ��������� O: ";
	std::getline(std::cin, playerName);
	player2->SetupPlayer(playerName, CellType_O);

	player1->SetBoard(this->board);
	player2->SetBoard(this->board);

	currentPlayer = player1;

	return true;
}

void TicTacManager::MakeMove()
{
	ShowBoard();
	while (!currentPlayer->MakeMove())
	{
		std::cout << "������������ ���, ���������� ��� ���\n";
		ShowBoard();
	}

	if (this->board->CheckEndCondition())
	{
		if (this->board->IsVictory())
			std::cout << "����� " << currentPlayer->GetName() << " �������!" << std::endl;
		else
			std::cout << "�����!\n";
		this->bGameFinished = true;
		ShowBoard();
		return;
	}
	currentPlayer = (currentPlayer == player1) ? player2 : player1;
}