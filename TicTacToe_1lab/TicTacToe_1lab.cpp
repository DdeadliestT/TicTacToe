// TicTacToe_1lab.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include "TicTacManager.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    TicTacManager manager;
    if (!manager.Init())
    {
        std::cout << "Неверные данные, выходим...";
        _getch();
        return 0;
    }

    while (!manager.IsGameFinished())
        manager.MakeMove();
    _getch();
}