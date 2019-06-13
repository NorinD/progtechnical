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

	cout << "������������ ������ 4, ������� 8" << std::endl << std::endl;
	cout << "������� ������������������ ����� ��� �������� ������������ ������:" << std::endl;

	auto linkedList = new LinkedList(createVector());

	cout << std::endl << std::endl;



	while (true)
	{
		system("cls");
		cout << "�������� ��������: " << std::endl;

		cout << "1. �������� �������" << std::endl;
		cout << "2. ������� �������" << std::endl;
		cout << "3. ����� ������� �� �������" << std::endl;
		cout << "4. ����� ������� �� ��������" << std::endl;
		cout << "5. ����������� ������ ������� � ����� ������" << std::endl;
		cout << "6. ������� ��� ��������� ������" << std::endl;
		cout << "7. ������� � ��������� ������������ ������" << std::endl << std::endl;
		char symbol;
		cin >> symbol;
		cout << std::endl << std::endl;

		switch (symbol)
		{
		case '1':
		{
			cout << "������� �������� � ������ �������� ����� ������: " << std::endl;
			int index;
			int value;

			cin >> value >> index;
			linkedList->addNode(new Node(nullptr, value), index);
			break;
		}
		case '2':
		{
			cout << "������� ������ �������� ��� ��������: " << std::endl;
			int index;
			cin >> index;

			linkedList->removeNode(index);
			break;
		}
		case '3':
		{
			cout << "������� ������ �������� ��� ������: " << std::endl;
			int index;
			cin >> index;
			LinkedList::printNode(linkedList->findNode(index));
			break;
		}
		case '4':
		{
			cout << "������� �������� �������� ��� ������: " << std::endl;
			int value;
			cin >> value;
			cout << "������� ��������: " << linkedList->findPosition(value) << std::endl;
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