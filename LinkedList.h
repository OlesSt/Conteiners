#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

class Node
{
public:
    int m_data;
    Node *m_next;

    Node(int data)
        : m_data(data)
    {
        m_next = nullptr;
    }
};

namespace LinkedList
{



void runLinkedList()
{

}

}

#endif // LINKEDLIST_H
