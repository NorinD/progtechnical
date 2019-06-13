#include "pch.h"
#include <iostream>
#include <math.h>
#include <map>
#include <Windows.h>
#include <cstring>
#include <conio.h>

using namespace std;

template<typename T>
void task1(T x, T y, T z)
{
	auto ans1 = x + y + z;
	auto ans2 = x * y * z;
	cout << "Сумма = " << ans1 << endl;
	cout << "Произведение  = " << ans2 << endl;
	if (ans1 == ans2)
	{
		cout << "Сумма равна произведению";
	}
	else
		cout << (ans1 > ans2 ? "Сумма больше" : "Произведение больше");
}

template<typename T>
void task2(T a, T b, T c)
{
	auto gip = a > b ? (a > c ? a : c) : (b > c ? b : c);
	auto piph = std::sqrt(a * a + b * b);

	cout << "Треугольник" << (piph == gip ? "прямоугольный" : "не прямоугольный") << endl;
	cout << "Гипотенуза = " << gip;
}


int task3(char& a, int size1, char& b, int size2)
{
	auto ans = true;
	for (auto i = 0; i < size1; ++i)
	{
		for (auto j = 0; j < size2; ++j)
		{
			auto val1 = *(&a + i);
			auto val2 = *(&b + j);
			if (val1 == val2)
				ans = false;
		}
	}
	return ans;
}

void task4(int** a, int m, int n)
{
	auto count = 0;	
	for (auto i = 0; i < m; i++)
	{
		auto isNotZero = false;
		for (auto j = 0; j < n; j++)
		{
			auto val = a[i][j];
			if (val != 0)
				isNotZero = true;
		}
		if (!isNotZero)
			count++;
	}
	if (count == 0)
		cout << "Массив не содержит нулевых строк";
	else
		cout << "Массив содержит " << count << " строк";
}

void task5(char* a, const int lenA, char* b, const int lenB)
{
	auto counter = std::map<char, int>();
	for (auto i = 0; i < lenA; i++)
	{
		counter.insert_or_assign(a[i], ++counter[a[i]]);
	}
	auto isValid = true;
	for (auto i = 0; i < lenB; i++)
	{
		auto val = counter[b[i]];
		if (val <= 0) {
			isValid = false;
			break;
		}
		--counter[b[i]];
	}
	std::cout << ((isValid) ? "Можно составить" : "Нельзя составить");

}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int state=-1;

	cout << "Лабораторная работа №1. Вариант 14." << endl;

	enterNumber:
	cout << "1 задание - вычислить значения выражений xyz" << endl;
	cout << "2 задание - проверка треугольника и выявление гипотенузы" << endl;
	cout << "3 задание - сравнение массивов" << endl;
	cout << "4 задание - проверка матрицы на 0 строки" << endl;
	cout << "5 задание - проверка на составление одного слова из другого" << endl;
	cout << "0 - выход" << endl;

	while (state != 0)
	{
		cout << endl;
		cout << "Введите номер задания ";
		cin >> state;
		switch (state)
		{
		case 1:
			{
				int x, y, z;
				cout << "Введите значение X: ";
				cin >> x;
				cout << "Введите значение Y: ";
				cin >> y;
				cout << "Введите значение Z: ";
				cin >> z;
				task1(x, y, z);
				cout << endl;
				break;
			}
		case 2:
			{
				int a, b, c;
				cout << "Введите сторону a: ";
				cin >> a;
				cout << "Введите сторону b: ";
				cin >> b;
				cout << "Введите сторону c: ";
				cin >> c;
				task2(a, b, c);
				cout << endl;
				break;
			}
		case 3:
			{
				int bn, cm;

				cout << "Введите количество элементов массива B ";
				cin >> bn;
				cout << "Введите элементы массива B" << endl;
				char* massB = new char[bn];
				for (int i = 0; i < bn; i++)
					cin >> massB[i];

				cout << "Введите количество элементов массива C ";
				cin >> cm;
				cout << "Введите элементы массива C" << endl;
				char* massC = new char[cm];
				for (int i = 0; i < cm; i++)
					cin >> massC[i];

				cout << "A = " << task3(*massB, bn, *massC, cm) << endl;
				break;
			}
		case 4:
			{
				int n, m;
				cout << "Введите количество строк ";
				cin >> n;
				cout << "Введите количество столбцов ";
				cin >> m;
				int** mas = new int*[n];
				for (int i = 0; i < n; i++)
					mas[i] = new int[m];
				for (int i = 0; i < n; i++)
					for (int j = 0; j < m; j++)
						cin >> mas[i][j];
				task4(mas, m, n);
				cout << endl;
				break;
			}
		case 5:
			{
				char* str_a = new char [80];
				char* str_b = new char [80];
				cout << "Введите слово А" << endl;
				cin >> str_a;
				cout << "Введите слово В" << endl;
				cin >> str_b;
				int collA = strlen(str_a);
				int collB = strlen(str_b);
				task5(str_a, collA, str_b, collB);
				cout << endl;
				break;
			}
		default:
			system("cls");
			cout << "Неверный номер задания. Попробуйте еще раз!" << endl << endl;
			goto enterNumber;
		}
	}

	return 0;
}
