#ifndef MYSTACKARRAY_H
#define MYSTACKARRAY_H

#include <iostream>
#include "TestClass.h"

template <typename T>
class MyStackArray
{
private:
    T *m_array;
    size_t m_nextIndex;
    size_t m_capacity;

public:
    MyStackArray()
    {
        m_capacity = 5;
        m_array = new T[m_capacity];
        m_nextIndex = 0;
    }

//    MyStackArray(size_t size) : m_capacity(size)
//    {
//        m_array = new T[m_capacity];
//        m_nextIndex = 0;
//    }

    ~MyStackArray()
    {
        delete[] m_array;
        m_nextIndex = 0;
        m_capacity = 0;
    }

    size_t size() const { return m_nextIndex; }                    // value of nextIndex is size
    size_t capacity() const {return m_capacity; }

    bool isEmpty()                                              // if nextIndex is 0 - it's empty
    {
        return m_nextIndex == 0;
                                                                //        if (nextIndex == 0)
                                                                //        {
                                                                //            return true;
                                                                //        }
                                                                //        else
                                                                //        {
                                                                //            return false;
                                                                //        }
    }

    T top()
    {
        if (isEmpty())
            return 0;
        return m_array[m_nextIndex - 1];
    }

    void push(T dataInsert)                                     // insert data to the current nextIndex and move nextIndex to the next
    {
        if (m_nextIndex == m_capacity)
        {
            T *new_array = new T[m_capacity * 2];

            for (size_t i{}; i < m_capacity; i++)
            {
                new_array[i] = std::move(m_array[i]);
            }

            delete[] m_array;

            m_array = new_array;
            m_capacity = m_capacity * 2;
        }

            m_array[m_nextIndex] = dataInsert;
            m_nextIndex++;
    }

    void pop()
    {
        if (isEmpty())
            return;
        m_nextIndex--;
    }                  // decrement nextIndex to remove Top element

    void printStack() const
    {
        std::cout << "Stack' elements - ";
        for (int i{}; i < size(); i++)
        {
            std::cout << m_array[i] << " ";
        }
        std::cout << std::endl;
    }


};

void runMyStackArray()
{
    MyStackArray<int> stack;
    std::cout << "Size = " << stack.size() << std::endl;
    std::cout << "Capacity = " << stack.capacity() << std::endl;
    std::cout << "Top = " << stack.top() << std::endl;
    stack.printStack();
    std::cout << "==========" << std::endl;

    stack.push(10);
    std::cout << "Size = " << stack.size() << std::endl;
    std::cout << "Capacity = " << stack.capacity() << std::endl;
    std::cout << "Top = " << stack.top() << std::endl;
    stack.printStack();
    std::cout << "==========" << std::endl;

    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);
    std::cout << "Size = " << stack.size() << std::endl;
    std::cout << "Capacity = " << stack.capacity() << std::endl;
    std::cout << "Top = " << stack.top() << std::endl;
    stack.printStack();
    std::cout << "==========" << std::endl;

    stack.pop();
    std::cout << "Size = " << stack.size() << std::endl;
    std::cout << "Capacity = " << stack.capacity() << std::endl;
    std::cout << "Top = " << stack.top() << std::endl;
    stack.printStack();
    std::cout << "==========" << std::endl;

    stack.pop();
    stack.pop();
    stack.pop();
    std::cout << "Size = " << stack.size() << std::endl;
    std::cout << "Capacity = " << stack.capacity() << std::endl;
    std::cout << "Top = " << stack.top() << std::endl;
    stack.printStack();
    std::cout << "==========" << std::endl;

    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);
    stack.push(60);
    stack.push(70);
    stack.push(80);
    stack.push(90);
    std::cout << "Size = " << stack.size() << std::endl;
    std::cout << "Capacity = " << stack.capacity() << std::endl;
    std::cout << "Top = " << stack.top() << std::endl;
    stack.printStack();
    std::cout << "==========" << std::endl;

    stack.push(100);
    stack.push(200);
    stack.push(400);
    stack.push(500);
    std::cout << "Size = " << stack.size() << std::endl;
    std::cout << "Capacity = " << stack.capacity() << std::endl;
    std::cout << "Top = " << stack.top() << std::endl;
    stack.printStack();
    std::cout << "==========" << std::endl;





}

#endif // MYSTACKARRAY_H
