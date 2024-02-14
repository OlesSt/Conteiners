#ifndef MYSTACKLIST_H
#define MYSTACKLIST_H

#include <iostream>
#include "TestClass.h"

template <typename T>
class MyStackList
{
private:
    struct Node
    {
        T m_data;
        Node *m_next;
        Node(T data) : m_data(data)
        {
            m_next = nullptr;
        }
    };
    Node *m_head;
    size_t m_size;


public:
    MyStackList()
    {
        m_head = nullptr;
        m_size = 0;
    }

    size_t size() const
    { return m_size; }

    bool isEmpty() const
    {
        return m_size == 0;
    }

    void push (T dataInsert)
    {
        if (m_head == nullptr)
        {
            m_head = new Node(dataInsert);
            m_head->m_next = nullptr;
            m_size++;
        }
        else
        {
            Node *temp = new Node(dataInsert);
            temp->m_next = m_head;
            m_head = temp;
            m_size++;
        }
    }

    void pop()
    {
        if(m_head == nullptr)
        {return;}
        Node *temp = m_head;
        m_head = m_head->m_next;
        temp->m_next = nullptr;
        delete temp;
        m_size--;
    }

    T top() const
    {
        if (m_head == nullptr)
        { return -1;}
        else
        { return m_head->m_data;}
    }

    void printStackList()
    {
        Node *temp = m_head;
        std::cout << "Stack List Data - ";
        while(temp != nullptr)
        {
            std::cout << temp->m_data << " ";
            temp = temp->m_next;
        }
        std::cout << std::endl;
    }

};


void runMyStackList()
{
    MyStackList<int> stackList;
    std::cout << "Size = " << stackList.size() << std::endl;
    std::cout << "isEmpty = " << stackList.isEmpty() << std::endl;
    std::cout << "Top = " << stackList.top() << std::endl;
    stackList.printStackList();
    std::cout << "===========\n" << std::endl;

    stackList.push(10);
    std::cout << "Size = " << stackList.size() << std::endl;
    std::cout << "isEmpty = " << stackList.isEmpty() << std::endl;
    std::cout << "Top = " << stackList.top() << std::endl;
    stackList.printStackList();
    std::cout << "===========\n" << std::endl;

    stackList.push(20);
    std::cout << "Size = " << stackList.size() << std::endl;
    std::cout << "isEmpty = " << stackList.isEmpty() << std::endl;
    std::cout << "Top = " << stackList.top() << std::endl;
    stackList.printStackList();
    std::cout << "===========\n" << std::endl;

    stackList.push(30);
    std::cout << "Size = " << stackList.size() << std::endl;
    std::cout << "isEmpty = " << stackList.isEmpty() << std::endl;
    std::cout << "Top = " << stackList.top() << std::endl;
    stackList.printStackList();
    std::cout << "===========\n" << std::endl;

    stackList.push(40);
    std::cout << "Size = " << stackList.size() << std::endl;
    std::cout << "isEmpty = " << stackList.isEmpty() << std::endl;
    std::cout << "Top = " << stackList.top() << std::endl;
    stackList.printStackList();
    std::cout << "===========\n" << std::endl;

    stackList.push(50);
    std::cout << "Size = " << stackList.size() << std::endl;
    std::cout << "isEmpty = " << stackList.isEmpty() << std::endl;
    std::cout << "Top = " << stackList.top() << std::endl;
    stackList.printStackList();
    std::cout << "===========\n" << std::endl;

    stackList.pop();
    std::cout << "Size = " << stackList.size() << std::endl;
    std::cout << "isEmpty = " << stackList.isEmpty() << std::endl;
    std::cout << "Top = " << stackList.top() << std::endl;
    stackList.printStackList();
    std::cout << "===========\n" << std::endl;

    stackList.pop();
    std::cout << "Size = " << stackList.size() << std::endl;
    std::cout << "isEmpty = " << stackList.isEmpty() << std::endl;
    std::cout << "Top = " << stackList.top() << std::endl;
    stackList.printStackList();
    std::cout << "===========\n" << std::endl;

    stackList.pop();
    std::cout << "Size = " << stackList.size() << std::endl;
    std::cout << "isEmpty = " << stackList.isEmpty() << std::endl;
    std::cout << "Top = " << stackList.top() << std::endl;
    stackList.printStackList();
    std::cout << "===========\n" << std::endl;

    stackList.pop();
    std::cout << "Size = " << stackList.size() << std::endl;
    std::cout << "isEmpty = " << stackList.isEmpty() << std::endl;
    std::cout << "Top = " << stackList.top() << std::endl;
    stackList.printStackList();
    std::cout << "===========\n" << std::endl;

    stackList.pop();
    std::cout << "Size = " << stackList.size() << std::endl;
    std::cout << "isEmpty = " << stackList.isEmpty() << std::endl;
    std::cout << "Top = " << stackList.top() << std::endl;
    stackList.printStackList();
    std::cout << "===========\n" << std::endl;




}



#endif // MYSTACKLIST_H
