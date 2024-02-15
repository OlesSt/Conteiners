#ifndef MYQUEUELIST_H
#define MYQUEUELIST_H

#include <iostream>

template <typename T>
class MyQueueList
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
    Node *m_tail;
    size_t m_size;

public:
    MyQueueList()
    {
        m_head = nullptr;
        m_tail = nullptr;
        m_size = 0;
    }

    size_t size() {return m_size;}
    bool isEmpty() {return m_size == 0;}

    void push(T dataInsert)
    {
        if (m_head == nullptr)
        {
            m_head = new Node(dataInsert);
            m_tail = m_head;
            m_size++;
        }
        else
        {
            Node *temp = new Node(dataInsert);
            m_tail->m_next = temp;
            m_tail = temp;
            m_size++;
        }

    }

    void pop()
    {
        if(isEmpty())
        {return;}
        Node *temp = m_head;
        m_head = m_head->m_next;
        temp->m_next = nullptr;
        delete temp;
        m_size--;
    }

    T front()
    {
        if(m_head == nullptr)
            return 0;
        return m_head->m_data;
    }

//    void printQueue()
//    {
//        Node *temp = m_head;

//        std::cout << "Queue is - ";
//        for (size_t i{}; i < size(); i++)
//        {
//            std::cout << temp->m_data << " ";
//            temp = temp->m_next;
//        }
//        std::cout << std::endl;
//    }
};

void runMyQueueList()
{
    MyQueueList <int> queueu;

    std::cout << "Size = " << queueu.size() << std::endl;
    std::cout << "isEmpty = " << queueu.isEmpty() << std::endl;
    std::cout << "Top = " << queueu.front() << std::endl;
//    queueu.printQueue();
    std::cout << "===========\n" << std::endl;

    queueu.push(10);
    std::cout << "Size = " << queueu.size() << std::endl;
    std::cout << "isEmpty = " << queueu.isEmpty() << std::endl;
    std::cout << "Top = " << queueu.front() << std::endl;
//    queueu.printQueue();
    std::cout << "===========\n" << std::endl;

    queueu.push(20);
    std::cout << "Size = " << queueu.size() << std::endl;
    std::cout << "isEmpty = " << queueu.isEmpty() << std::endl;
    std::cout << "Top = " << queueu.front() << std::endl;
//    queueu.printQueue();
    std::cout << "===========\n" << std::endl;

    queueu.push(30);
    queueu.push(40);
    std::cout << "Size = " << queueu.size() << std::endl;
    std::cout << "isEmpty = " << queueu.isEmpty() << std::endl;
    std::cout << "Top = " << queueu.front() << std::endl;
//    queueu.printQueue();
    std::cout << "===========\n" << std::endl;



    std::cout << "Size = " << queueu.size() << std::endl;
    std::cout << "isEmpty = " << queueu.isEmpty() << std::endl;
    std::cout << "Top = " << queueu.front() << std::endl;
//    queueu.printQueue();
    std::cout << "===========\n" << std::endl;
}

#endif // MYQUEUELIST_H
