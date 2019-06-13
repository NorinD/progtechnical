#include "pch.h"
#include <iostream>
#include <vector>
#include "Node.h"
#include "LinkedList.h"

std::vector<int> createVector();

void laba4()
{
	using std::cout;
	using std::cin;

	cout << "Лабораторная работа 4, вариант 8" << std::endl << std::endl;
	cout << "Введите последовательность чисел для создания односвязного списка:" << std::endl;

	auto linkedList = new LinkedList(createVector());

	cout << std::endl << std::endl;



	while (true)
	{
		system("cls");
		cout << "Выберите операцию: " << std::endl;

		cout << "1. Добавить элемент" << std::endl;
		cout << "2. Удалить элемент" << std::endl;
		cout << "3. Найти элемент по индексу" << std::endl;
		cout << "4. Найти элемент по значению" << std::endl;
		cout << "5. Переместить первый элемент в конец списка" << std::endl;
		cout << "6. Вывести все эелементы списка" << std::endl;
		cout << "7. Перейти к следующей лабороторной работе" << std::endl << std::endl;
		char symbol;
		cin >> symbol;
		cout << std::endl << std::endl;

		switch (symbol)
		{
		case '1':
		{
			cout << "Введите значение и индекс элемента через пробел: " << std::endl;
			int index;
			int value;

			cin >> value >> index;
			linkedList->addNode(new Node(nullptr, value), index);
			break;
		}
		case '2':
		{
			cout << "Введите индекс элемента для удаления: " << std::endl;
			int index;
			cin >> index;

			linkedList->removeNode(index);
			break;
		}
		case '3':
		{
			cout << "Введите индекс элемента для поиска: " << std::endl;
			int index;
			cin >> index;
			LinkedList::printNode(linkedList->findNode(index));
			break;
		}
		case '4':
		{
			cout << "Введите значение элемента для поиска: " << std::endl;
			int value;
			cin >> value;
			cout << "позиция элемента: " << linkedList->findPosition(value) << std::endl;
			break;
		}
		case '5':
		{
			linkedList->shiftFirstToEnd();
			break;
		}
		case '6':
		{
			linkedList->printLinkedList();
			break;
		}
		case '7':
			return;
		}

		system("pause");
	}
}

std::vector<int> createVector()
{
	std::vector<int> numbers;

	while (true)
	{
		char symbol;
		std::cin.get(symbol);
		if (symbol == '\n')
			break;

		if (symbol == ' ')
			continue;

		numbers.push_back(symbol - 48);
	}

	return numbers;
}