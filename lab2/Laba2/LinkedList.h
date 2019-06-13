#pragma once
#include "Node.h"
#include <vector>

class LinkedList
{
public:
	Node* Root;
	Node* LastNode;

	LinkedList();
	LinkedList(Node* node);
	LinkedList(std::vector<int> numbers);

	void addNode(Node* node, int index);
	void removeNode(int index);
	int findPosition(int value);
	Node* findNode(int index);
	void shiftFirstToEnd();
	void printLinkedList();
	static void printNode(Node* node);

	int getCount() { return count; }
private:
	int count;
};
