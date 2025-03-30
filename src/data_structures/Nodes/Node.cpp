#include "Node.h"

Node::Node()
{
	value = 0;
	next = nullptr;
}

Node::Node(int value)
{
	this->value = value;
	this->next = nullptr;
}

Node::Node(int value, Node* next)
{
	this->value = value;
	this->next = next;
}