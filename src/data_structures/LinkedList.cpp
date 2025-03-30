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
	Node* newNode = new Node(value);
	if (length == 0)
	{
		head = newNode;
		tail = head;
	}
	else
	{
		newNode->next = head;
		head = newNode;
	}
	length++;
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
	if (length == 0) return;

	Node* temp = head;
	if (length == 1)
	{
		head = nullptr;
		tail = nullptr;
	}
	else
	{
		Node* pre = head;
		while (temp->next)
		{
			pre = temp;
			temp = temp->next;
		}
		tail = pre;
		tail->next = nullptr;
	}
	length--;
	delete temp;
}

void LinkedList::DeleteFirst()
{
	if (length == 0) return;

	Node* temp = head;
	if (length == 1)
	{
		head = nullptr;
		tail = nullptr;
	}
	else
	{
		head = head->next;
	}
	delete temp;
	length--;
}

Node* LinkedList::get(int index)
{
	if (index < 0 || index >= length)
		return nullptr;

	Node* temp = head;
	for (int i = 0; i < index; i++)
	{
		temp = temp->next;
	}
	return temp;
}

bool LinkedList::set(int index, int value)
{
	Node* temp = get(index);
	if (temp)
	{
		temp->value = value;
		return true;
	}
	return false;
}

bool LinkedList::Insert(int index, int value)
{
	if (index == 0)
	{
		Prepend(value);
		return true;
	}

	if (index == length)
	{
		Append(value);
		return true;
	}

	Node* temp = get(index - 1);
	if (temp)
	{
		Node* newNode = new Node(value);
		newNode->next = temp->next;
		temp->next = newNode;
		length++;
		return true;
	}
	return false;
}

void LinkedList::DeleteNode(int index)
{
	if (index < 0 || index >= length) return;
	if (index == 0)
	{
		DeleteFirst();
		return;
	}

	if (index == length - 1)
	{
		DeleteLast();
		return;
	}

	Node* pre = get(index - 1);
	Node* temp = pre->next;

	pre->next = temp->next;
	delete temp;
	length--;
}

void LinkedList::Reverse()
{
	if (length <= 1) return;
	Node* temp = head;
	head = tail;
	tail = temp;

	Node* before = nullptr;
	Node* after = temp->next;

	for (int i = 0; i < length; i++)
	{
		after = temp->next;
		temp->next = before;
		before = temp;
		temp = after;
	}
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
