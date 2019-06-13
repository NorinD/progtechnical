#include "pch.h"
#include "Node.h"

Node::Node(Node* next, int value)
{
	this->next = next;
	this->value = value;
}