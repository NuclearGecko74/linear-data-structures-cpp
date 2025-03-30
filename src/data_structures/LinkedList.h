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
	void DeleteFirst();

	Node* get(int index);
	bool set(int index, int value);

	bool Insert(int index, int value);
	void DeleteNode(int index);

	void Reverse();

	void PrintList();

public:
	// Getters
	int getHead() const { return head->value; }
	int getTail() const { return tail->value; }
	const size_t getLength() const { return length; }
};

