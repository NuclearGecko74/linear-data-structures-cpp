#include "LinkedList.h"

#include <iostream>

LinkedList::LinkedList()
{
	head = nullptr;
	tail = nullptr;
	length = 0;
}

LinkedList::LinkedList(int value)
{
	head = new Node(value);
	tail = head;
	length = 1;
}

LinkedList::~LinkedList()
{
	Node* temp = head;
	while (head)
	{
		head = head->next;
		delete temp;
		temp = head;
	}
}

void LinkedList::Prepend(int value)
{

}

void LinkedList::Append(int value)
{
	Node* newNode = new Node(value);
	if (length == 0)
	{
		head = newNode;
		tail = head;
	}
	else
	{
		tail->next = newNode;
		tail = tail->next;
	}
	length++;
}

void LinkedList::DeleteLast()
{

}

void LinkedList::PrintList()
{
	std::cout << "List:\n";
	Node* temp = head;
	while (temp)
	{
		std::cout << temp->value << '\n';
		temp = temp->next;
	}
}
