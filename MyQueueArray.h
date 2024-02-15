#ifndef MYQUEUEARRAY_H
#define MYQUEUEARRAY_H

#include <iostream>
#include "TestClass.h"

template <typename T>
class MyQueueArray
{
private:

    T *m_array;
    size_t m_firstIndex;
    size_t m_nextIndex;
    size_t m_capacity;
    size_t m_size;

public:
    MyQueueArray()
    {
        m_firstIndex = 0;
        m_nextIndex = 0;
        m_capacity = 5;
        m_size = 0;
        m_array = new T[m_capacity];
    }

    ~MyQueueArray()
    {
        delete[] m_array;
        m_firstIndex = 0;
        m_nextIndex = 0;
        m_capacity = 0;
    }

    size_t size() { return m_size; }
    bool isEmpty() { return m_size == 0; }

    void push(T dataInsert)
    {
        if (m_size == m_capacity)
        {
            T *newArray = new T[m_capacity * 2];
            size_t j = 0;
            for (size_t i {m_firstIndex}; i < m_capacity; i++)
            {
                newArray[j] = m_array[i];
                j++;
            }
            for (int i = 0; i < m_firstIndex; i++)
            {
                newArray[j] = m_array[i];
            }

            m_firstIndex = 0;
            m_nextIndex = m_capacity;
            m_capacity = 2 * m_capacity;
            delete[] m_array;
            m_array = newArray;
        }
        m_array[m_nextIndex] = dataInsert;
        m_nextIndex = (m_nextIndex + 1) % m_capacity;
        m_size++;
    }

    void pop()
    {
        if (isEmpty())
            return;
        m_firstIndex = (m_firstIndex + 1) % m_capacity;
        m_size--;
    }

    T front()
    {
        if (isEmpty())
        { return -1;}
        return m_array[m_firstIndex];
    }

    void printQueueArray()
    {
        std::cout << "Queue elem - ";
        for (size_t i{m_firstIndex}; i < size(); i++)
        {
            std::cout << m_array[i] << " ";

        }
        std::cout << std::endl;
    }

    T at(size_t i)
    {
        return m_array[i];
    }
};

void runMyQueueArray()
{
    MyQueueArray <int> queueu;

    std::cout << "Size = " << queueu.size() << std::endl;
    std::cout << "isEmpty = " << queueu.isEmpty() << std::endl;
    std::cout << "Top = " << queueu.front() << std::endl;
    queueu.printQueueArray();
    std::cout << "===========\n" << std::endl;

    queueu.push(10);
    std::cout << "Size = " << queueu.size() << std::endl;
    std::cout << "isEmpty = " << queueu.isEmpty() << std::endl;
    std::cout << "Top = " << queueu.front() << std::endl;
    queueu.printQueueArray();
    std::cout << "===========\n" << std::endl;

    queueu.push(20);
    std::cout << "Size = " << queueu.size() << std::endl;
    std::cout << "isEmpty = " << queueu.isEmpty() << std::endl;
    std::cout << "Top = " << queueu.front() << std::endl;
    queueu.printQueueArray();
    std::cout << "===========\n" << std::endl;

    queueu.push(30);
    queueu.push(40);
    queueu.push(50);
    std::cout << "Size = " << queueu.size() << std::endl;
    std::cout << "isEmpty = " << queueu.isEmpty() << std::endl;
    std::cout << "Top = " << queueu.front() << std::endl;
    queueu.printQueueArray();
    std::cout << "===========\n" << std::endl;

    for (size_t i{0}; i < 5; i++)
    {
        std::cout << queueu.at(i) << " ";
        queueu.pop();
    }
    std::cout << std::endl;

    std::cout << "Size = " << queueu.size() << std::endl;
    std::cout << "isEmpty = " << queueu.isEmpty() << std::endl;
    std::cout << "Top = " << queueu.front() << std::endl;
    queueu.printQueueArray();
    std::cout << "===========\n" << std::endl;



}

#endif // MYQUEUEARRAY_H
