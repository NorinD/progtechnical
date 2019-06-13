#pragma once

class Node
{
public:
	Node* next;
	int value;

	Node(Node* next, int value);
};