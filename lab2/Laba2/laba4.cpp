#include "pch.h"
#include <iostream>
#include <deque>


class CycledList
{
	std::deque<int>* deque;
public:
	CycledList()
	{
		deque = new std::deque<int>();
	}

	void pushFront(int e)
	{
		deque->push_front(e);
	}

	void pushBack(int e)
	{
		deque->push_back(e);
	}

	void popFront()
	{
		deque->pop_front();
	}

	void popBack()
	{
		deque->pop_back();
	}

	int getFront()
	{
		return deque->front();
	}

	int getBack()
	{
		return deque->back();
	}

	void sdvinutVpered()
	{
		auto a = deque->back();
		deque->pop_back();

		deque->push_front(a);
	}

	void sdvinutNazad()
	{
		auto a = deque->front();
		deque->pop_front();

		deque->push_back(a);
	}

	void print()
	{
		for (auto e = deque->begin(); e != deque->end(); ++e)
		{
			std::cout << *e << " ";
		}
		std::cout << "\n";
	}
};


void laba4()
{
	system("cls");
	auto list = new CycledList();
	std::cout << "Введите количество элементов в списке: ";
	int size;
	std::cin >> size;
	
	for (auto i = 0; i < size; ++i)
	{
		std::cout << "Введите " << i + 1 << " элемент: ";
		int a;
		std::cin >> a;
		list->pushBack(a);
	}

	system("cls");
	std::cout << "Ваш лист:       ";
	list->print();


	std::cout << "Введите сдвиг: ";
	int power;
	std::cin >> power;

	for (auto i = 0; i < power; ++i)
	{
		list->sdvinutVpered();
	}	
	std::cout << "Сдвинутый лист: ";
	list->print();
}