#include <iostream>

#include "data_structures/LinkedList.h"

int main()
{
    LinkedList ll(1);
    ll.Append(2);
    ll.Append(3);
    ll.Append(4);
    ll.Append(5);

    ll.Reverse();

    ll.PrintList();
}