#include <iostream>
#include <Windows.h>

using namespace std;

int calculateDeterminant(int** matrix);
void printDeterminant(int** matrix);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "Введите матрицу A 3x3: " << endl;
	int** matrix = new int*[3];
	for (auto i = 0; i < 3; ++i)
	{
		matrix[i] = new int[3];
		for (auto j = 0; j < 3; ++j)
		{
			cout << "Введит значение A(" << i + 1 << "," << j + 1 << "): ";
			cin >> matrix[i][j];
		}
	}
	printDeterminant(matrix);

	for (auto i = 0; i < 3; ++i)
		delete[] matrix[i];
	delete[] matrix;
}

void printDeterminant(int** matrix)
{
	for (auto i = 0; i < 3; i++)
	{
		cout << "| ";
		for (auto j = 0; j < 3; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << "|";
		if (i == 1) cout << " = " << calculateDeterminant(matrix);
		cout << endl;
	}
};

int calculateDeterminant(int** matrix)
{
	auto triangle1 = matrix[0][0] * matrix[1][1] * matrix[2][2];
	auto triangle2 = matrix[0][1] * matrix[1][2] * matrix[2][1];
	auto triangle3 = matrix[0][2] * matrix[1][0] * matrix[2][1];
	auto triangle4 = matrix[2][0] * matrix[1][1] * matrix[0][2];
	auto triangle5 = matrix[2][1] * matrix[1][2] * matrix[0][0];
	auto triangle6 = matrix[1][1] * matrix[1][0] * matrix[0][1];

	return triangle1 + triangle2 + triangle3 - triangle4 - triangle5 - triangle6;
};
