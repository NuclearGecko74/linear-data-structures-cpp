#pragma once

#include "Nodes/Node.h"

class LinkedList
{
private:
	Node* head;
	Node* tail;
	size_t length;

public:
	LinkedList();
	LinkedList(int value);
	~LinkedList();

	void Prepend(int value);
	void Append(int value);

	void DeleteLast();

	void PrintList();

public:
	// Getters
	int getHead() const { return head->value; }
	int getTail() const { return tail->value; }
	const size_t getLength() const { return length; }
};

