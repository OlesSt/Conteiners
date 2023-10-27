#ifndef MYVECTOR_H
#define MYVECTOR_H
#include <iostream>
#include "TestClass.h"

template <typename T>
class MyVector
{
public:
    MyVector()
    {
        m_data = nullptr;
        m_size = 0;
        m_capacity = 2;
        ReAloc(m_capacity);
    }

    MyVector(std::initializer_list<T>)
    {
        m_data = nullptr;
        m_size = 0;
        m_capacity = 2;
        ReAloc(m_capacity);
    }

    ~MyVector()
    {
        clearAll();
        ::operator delete(m_data, m_capacity * sizeof(T));
    }

    void pushBack(const T &value)                   // Method to ADD new value to vector
    {
        if (m_size >= m_capacity)                   // - check, if size still fit to capacity and if it isn't = double capacity
        {
            ReAloc(m_capacity * 2);
        }

        m_data[m_size++] = value;                   // - add new value to the end of vector and increment size
    }

    void pushBack(const T &&value)                  // Method to MOVE new value to vector
    {
        if (m_size >= m_capacity)                   // - check, if size still fit to capacity and if it isn't = double capacity
        {
            ReAloc(m_capacity * 2);
        }

        m_data[m_size++] = std::move(value);        // move new value to the end of vector and increment size
    }

    MyVector(T data)
        : m_data(data)
    {
        m_size++;
        m_capacity = m_size * 2;
    }

    const T& operator[] (size_t index) const        // override operator [] to get value by index
    {
        if (index >= m_size)
        {}

        return m_data[index];
    }

    template <typename... Args>                     // Use ... to send any amount of parameters into the funtion
    T& emplaceBack(Args&&... args)                  // - &&... means that whatewher parameters come here - they will understood right by type
    {
        if (m_size >= m_capacity)                   // - method to add values to array, that will be connected to the right type and
        {
            ReAloc(m_capacity * 2);                 // - inserted to the constructor
        }

//        new(&m_data[m_size]) T(std::forward<Args>(args)...);
        m_data[m_size] = T(std::forward<Args>(args)...);
        return m_data[m_size++];
    }

    void popBack()                                  // Method to delete last element of vector
    {
        if (m_size > 0)                             // - check if vector isn't empty
        {
            m_size--;                               // - decrement size
            m_data[m_size].~T();                    // - call destructor for deleted element
        }
    }

    void clearAll()                                 // Method to delete all elements of vector
    {
        for (size_t i = 0; i < m_size; i++)         // - call destructor for each element
        {
            m_data[i].~T();
        }
        m_size = 0;                                 // - set size and capacity to 0
        m_capacity = m_size;
    }

    T& operator[] (size_t index)                    // override operator [] to modify value by index
    {
        if (index >= m_size)
        {}

        return m_data[index];
    }

    size_t getSize() const {return m_size;}

    void print()
    {
        if (m_size == 0)
        {std::cout << " - is Empty" << std::endl;}

        for (size_t i = 0; i < m_size; i++)
            std::cout << m_data[i] << " ";
        std::cout << std::endl;
    }

private:
    void ReAloc(size_t newCapacity)                 // Functoin realocate memory for new vector
    {
        T *newBlock = (T*)::operator new(newCapacity * sizeof(T));  // 1 - create new block of memory with new capacity depends on type size

        if(newCapacity < m_size)                                    // 2 - check if new capacity is less then current size
        {
            m_size = newCapacity;                                   //     and if it's less - size must be equal to new capacity
        }

        for(size_t i = 0; i < m_size; i++)                          // 3 - copy all element from current memory block to new memory clok
        {
            newBlock[i] = std::move(m_data[i]);                     //     or try to move it
        }

        for (size_t i = 0; i < m_size; i++)                         // - call destructor for each element
        {
            m_data[i].~T();
        }

        ::operator delete(m_data, m_capacity * sizeof(T));          // 4 - delete old memory block
        m_data = newBlock;                                          // 5 - assing old memory block to new memory block and old capacity to new one
        m_capacity = newCapacity;
    }
private:
    T* m_data;
    size_t m_size;
    size_t m_capacity;
};


void runMyVector()
{
    MyVector<int> vec01;
    vec01.pushBack(1);
    vec01.pushBack(2);
    vec01.pushBack(3);
    vec01.pushBack(4);
    vec01.print();

    vec01.emplaceBack(5);
    vec01.emplaceBack(6);
    vec01.emplaceBack(7);
    vec01.emplaceBack(8);
    vec01.print();

    std::cout << "Size is : " << vec01.getSize() << std::endl;

    vec01.popBack();
    vec01.popBack();
    vec01.popBack();
    vec01.print();

    vec01.clearAll();
    vec01.print();

    TestClass object01;
    object01.setName("Object 01");
    object01.setId(1);
    TestClass object02("Object 02", 2);
    TestClass object03("Object 03", 3);

    MyVector<TestClass> objects;

    objects.pushBack(object01);
    objects.pushBack(object02);
    objects.pushBack(object03);
    std::cout << "Test Class Size is : " << objects.getSize() << std::endl;

    for (size_t i {}; i < objects.getSize(); i++)
    {
        objects[i].doStuff();
    }
}

#endif // MYVECTOR_H
