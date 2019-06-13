#include "pch.h"
#include <queue>
#include <stack>
#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

struct Edge {
	int begin;
	int end;
};

std::vector<std::vector<int>>* createMatrix(std::map<int, std::vector<int>>* dict, int count)
{
	auto matrix = new std::vector<std::vector<int>>(count);

	for (auto i = 0; i < count; i++)
	{
		matrix->push_back(std::vector<int>());
		for (auto j = 0; j < count; j++)
			matrix->at(i).push_back(0);
	}

	for (size_t i = 0; i < dict->size(); i++)
		for (size_t j = 0; j < dict->at(i).size(); j++)
			matrix->at(i).at(dict->at(i).at(j)) = 1;

	return matrix;
}

std::map<int, std::vector<int>>* makeDict(int numberOfVertices)
{
	auto dict = new std::map<int, std::vector<int>>();
	cout << endl << "Доступные вершины от 0 до " << numberOfVertices - 1 << endl;
	cout << "Введите пару через пробел" << endl;
	cout << "Пример пары: 0 1 это (0,1)" << endl;
	for (auto i = 0; i < numberOfVertices; i++)
	{
		cout << "Введите " << i + 1 << " пару : ";

		int a, b;
		cin >> a >> b;

		if (dict->find(a) == dict->end())
			dict->emplace(a, vector<int>());

		if (dict->find(b) == dict->end())
			dict->emplace(b, vector<int>());

		dict->at(a).push_back(b);
		dict->at(b).push_back(a);
	}

	return dict;
}

void getGraph(int count, int startVertex, int endVertex, std::vector<std::vector<int>>* linkedPoints, std::map<int, std::vector<int>>* dict)
{
	queue<int> queue;
	stack<Edge> edges;
	Edge e;

	auto nodes = std::vector<int>(count);
	for (auto& node : nodes)
		node = 0;

	queue.push(startVertex);
	while (!queue.empty())
	{
		auto node = queue.front();
		queue.pop();
		nodes[node] = 2;
		for (int j = 0; j < count; j++)
		{
			if (linkedPoints->at(node).at(j) == 1 && nodes[j] == 0)
			{
				queue.push(j);
				nodes[j] = 1;
				e.begin = node;
				e.end = j;
				edges.push(e);
				if (node == endVertex) break;
			}
		}
	}

	cout << "Путь из вершины " << startVertex << " в вершину " << endVertex << endl;
	string str = to_string(endVertex);

	while (!edges.empty())
	{
		e = edges.top();
		edges.pop();
		if (e.end == endVertex)
		{
			endVertex = e.begin;
			str += " >= " + to_string(e.begin);
		}
	}
	reverse(str.begin(), str.end());
	cout << str;
	cin.get(); cin.get();
}

void laba5()
{
	system("cls");
	cout << "Количество вершин в графе: ";
	int numberOfVertices;
	cin >> numberOfVertices;

	auto dict = makeDict(numberOfVertices);
	auto linkedPoints = createMatrix(dict, numberOfVertices);

	cout << endl;
	cout << "Путь в вершину: ";
	int endVertice;
	cin >> endVertice;

	cout << "Из вершины: ";
	int startVertice;
	cin >> startVertice;	

	getGraph(numberOfVertices, startVertice, endVertice, linkedPoints, dict);
}