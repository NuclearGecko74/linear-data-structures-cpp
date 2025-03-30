#pragma once
class Node
{
private:
	int value;
	Node* next;

public:
	Node();
	Node(int value);
	Node(int value, Node* next);

	inline int getValue() const { return value; }

public:
	friend class LinkedList;
};