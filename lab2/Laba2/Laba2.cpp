#include "pch.h"
#include <Windows.h>
#include "laba4.h"
#include "laba5.h"
#include <iostream>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	enterNumber:

	std::cout << "Выберите лабораторную:" << std::endl;
	std::cout << "0. Выход" << std::endl;
	std::cout << "1. 4 Лабораторная (Вариант 14)" << std::endl;
	std::cout << "2. 5 Лабораторная (Вариант 1)" << std::endl;

	int number;
	std::cin >> number;

	if (number != 0) 
	{
		switch (number)
		{
		case 1:
			laba4();
			break;
		case 2:
			laba5();
			break;

		default:
			system("cls");
			goto enterNumber;
		}
	}

	return 0;
}
