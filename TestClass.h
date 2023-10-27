#ifndef TESTCLASS_H
#define TESTCLASS_H

#include <iostream>

class TestClass
{
public:
    TestClass()
    { std::cout << "Test Class Constructor" << std::endl; }

    TestClass(std::string name, int id)
        : m_name(name), m_id(id)
    { std::cout << "Test Class Parameter Constructor" << std::endl; }

    ~TestClass()
    { std::cout << "Test Class Destructor" << std::endl; }

    void doStuff()
    { std::cout << "Object - " << m_name << " - " << m_id << " do Stuff" << std::endl; }

    void setName(const std::string name) { m_name = name;}
    void setId(const int id) {m_id = id;}

    std::string getName() const { return m_name;}
    int getId() { return m_id; }

private:
    std::string m_name;
    int m_id;
};

#endif // TESTCLASS_H
