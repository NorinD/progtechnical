#include "pch.h"
#include "LinkedList.h"
#include <stdexcept>
#include <array>
#include <iostream>

LinkedList::LinkedList() : LinkedList(new Node(nullptr, 0))
{
}

LinkedList::LinkedList(Node* node)
{
	Root = node;
	LastNode = node;
	count = 1;
}

LinkedList::LinkedList(std::vector<int> numbers)
{
	if (numbers.empty())
		throw std::invalid_argument("The array points to a null");

	auto currentNode = new Node(nullptr, numbers[0]);
	Root = currentNode;
	LastNode = currentNode;
	count = 1;

	for (auto i = 1; i < numbers.size(); i++)
	{
		auto nextNode = new Node(nullptr, numbers[i]);
		currentNode->next = nextNode;
		currentNode = nextNode;
		LastNode = currentNode;
		count++;
	}
}

void LinkedList::addNode(Node* node, int index)
{
	if (index > count || index < 0)
		throw std::out_of_range("Index out of range");

	Node* currentNode;
	if (index == 0)
		currentNode = Root;
	else if (index == count - 1)
		currentNode = LastNode;
	else
		currentNode = findNode(index - 1);

	node->next = currentNode->next;
	currentNode->next = node;
}

void LinkedList::removeNode(int index)
{
	if (index >= count || index < 0)
		throw std::out_of_range("Index out of range");
	
	if (index == 0)
	{
		auto node = Root;
		Root = Root->next;
		node->next = nullptr;
	}
	else if (index == count - 1)
	{
		auto previousNode = findNode(index - 1);

		if (previousNode == nullptr)
			throw "Object reference not set to an instance of an object";

		LastNode = previousNode;
		previousNode->next = nullptr;
	}
	else
	{
		const auto previousNode = findNode(index - 1);

		if (previousNode == nullptr)
			throw "Object reference not set to an instance of an object";

		const auto currentNode = previousNode->next;
		previousNode->next = currentNode->next;
		currentNode->next = nullptr;
	}
}

int LinkedList::findPosition(int value)
{
	auto index = -1;
	auto currentIndex = 0;
	auto currentNode = Root;

	while (currentNode != nullptr)
	{
		if (currentNode->value == value)
		{
			index = currentIndex;
			break;
		}

		currentNode = currentNode->next;
		currentIndex++;
	}

	return index;
}

Node* LinkedList::findNode(int index)
{
	auto currentIndex = 0;
	auto currentNode = Root;

	if (index >= this->count || index < 0)
		throw std::out_of_range("Index out of range");

	while (currentNode->next != nullptr && currentIndex < this->count)
	{
		if (currentIndex == index)
			return currentNode;

		currentNode = currentNode->next;
		currentIndex++;
	}

	return nullptr;
}

void LinkedList::shiftFirstToEnd()
{
	LastNode->next = Root;
	Root = Root->next;
	LastNode->next->next = nullptr;
}

void LinkedList::printLinkedList()
{
	auto currentNode = Root;
	while (currentNode != nullptr)
	{
		std::cout << currentNode->value << " ";
		currentNode = currentNode->next;
	}
	std::cout << std::endl;
}

void LinkedList::printNode(Node* node)
{
	std::cout << "Значение элемента - " << node->value << std::endl;
}