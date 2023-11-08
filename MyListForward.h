#ifndef MYLISTFORWARD_H
#define MYLISTFORWARD_H

#include <iostream>
#include "TestClass.h"

template<typename T>
class MyListForward
{
private:
    struct Node
    {
        T data;
        Node* next;
    };
    Node *head;
    Node *tail;
    size_t m_size;

public:
    class Iterator
    {
    public:
        Iterator(Node *node)
            : m_node(node) {}
        bool operator!=(const Iterator& other)
        {
            return m_node != other.m_node;
        }

        Iterator &operator++()
        {
            m_node = m_node->next;
            return *this;
        }

        Iterator operator++(int)
        {
            Iterator temp(*this);
            m_node = m_node->next;
            return temp;
        }
        T &operator*()
        {
            return m_node->data;
        }

    private:
        Node *m_node;

    };

    // CONSTRUCTOR
    MyListForward()
        : head(nullptr), tail(nullptr), m_size(0) {}        // Head is nullptr by default

    MyListForward(const MyListForward &other)                             // SPEED = O(N)
        : head(nullptr), tail(nullptr), m_size(0)           // Head is null
    { сopy(other); }                                        // call copy method from private section

    MyListForward (MyListForward &&other)                                 // SPEED = o(1)
        : head(other.head),
          tail(other.tail),                                 // Head is now head of Node to move
          m_size(other.m_size)

    {
        other.head = nullptr;
        other.tail = nullptr;
        other.m_size = 0;
    }                                                       // ...and head of Node to move is Null

    ~MyListForward()   {clear_All();}                              // Destructor call clear_All method, wich deletes all element


    // INSERT METHODS
    void push_back(const T &value)                          // Method to insert new Node to the end, SPEED O(1)
    {
        if (head == nullptr)                                // if List is empty...
        {
            head = new Node {value, nullptr};               // ... just create a first Node with value
            tail = head;                                    // tail is the same as head
        }
        else
        {
            tail->next = new Node{value, nullptr};
            tail = tail->next;
            /*
            Node *current = head;                           // else create a temp Node to iterate
            while(current->next != nullptr)                 // go through the list with temp Node until end...
            {
                current = current->next;
            }
            current->next = new Node {value, nullptr};     //...and create a new Node at the end
            */
        }
        m_size++;
    }

    void push_front(const T &value)                     // Method to insert new Node to the begin
    {
        if (head == nullptr)
        {
            head = new Node {value, nullptr};           // Check if list exist and just create a first Node if it's not
            tail = head;
        }
        else if (head == tail)
        {
            Node *newHead = new Node {value, head};     // or create a new Node for future head with value as data and current head as next Node
            head = newHead;                             // asing to make Head as newHead
            tail = head;
        }
        else
        {
            Node *newHead = new Node{value, head};
            head = newHead;
        }
        m_size++;
    }

    // REMOVE METHODS
    void pop_back()                                     // Method to delete last element, SPEED - O(N)
    {
        if (head == nullptr)                            // 01 - check if list exist
        { return; }
        else if (head->next == nullptr)                 // 02 - check if list lenth is 1, than delete head
        {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else                                            // 03 - create a temp Nodes to iterate
        {
            Node *previous = head;                      // - suggest current - is head->next elem
            Node *current = head->next;

            while (current->next != nullptr)            // 04 - go to the end of List through the loop
            {
                previous = current;
                current = current->next;
            }
            delete current;                             // 05 - delete elem
            previous->next = nullptr;                   // 06 - point last elem to the nullptr
            tail = previous;
        }
        m_size--;
    }

    void pop_front()                                    // Method to delete first element
    {
        if (head == nullptr)                            // 01 - check if list exist
        { return; }
        else if (head->next == nullptr)                 // 02 - check if list lenth is 1, than delete head
        {
            delete head;
            head = nullptr;
            tail = nullptr;
        }

        else
        {
            Node *newHead = head->next;                 // 03 - create a new head of list with next (second) elem
            delete head;                                // 04 - delete current head
            head = newHead;                             // 05 - make a new head as first elem of list, like a head
        }
        m_size--;
    }

    void remove(const T &value)                         // Method to delete element by value
    {
        Node *previous = nullptr;                       // 01 - create a temp Nodes to iterate list
        Node *current = head;

        while(current != nullptr)
        {
            if (current->data == value)                 // 02 - check if list contains value to delete
            {
                if (previous == nullptr)                // 03 - check, if it's start of list...
                {
                    head = head->next;                  // ... and if it is make head to nullptr (for one node list)
                    if (head == nullptr)
                    {
                        tail = nullptr;
                    }
                }
                else
                {
                    previous->next = current->next;     // 04 - connect prev Node to Node after the deleted one
                    if (current == tail)
                    {
                        tail = previous;
                    }
                }
                delete current;                         // 05 - delete Node and break the loop
                m_size--;
                return;
            }
            previous = current;                         // 06 - iterate List to move forward
            current = current->next;
        }
    }

    void clear_All()                            // Method to delete all element in the List
    {
        while (head != nullptr)
        {
            Node *current = head;               // Create temp Node to take a head role
            head = head->next;                  // Move real head to the next Node
            delete current;                     // Delete previous head through the current Node
        }
        tail = nullptr;
        m_size = 0;
    }

    // UTILITY
    bool find(const T &value)                   // Method to find element
    {
        if (head == nullptr) {return false;}    // 01 - check if list exist

        Node *current = head;                   // 01 - create a Node to iterate list
        while (current != nullptr)
        {
            if (current->data == value)         // 03 - check if value is in list
            {
                return true;
            }
            current = current->next;            // 04 - move forward
        }
        return false;
    }

    bool isEmpty()                              // Method to check if list is empty
    {
        return head == nullptr;                 // if head is null - list ia empty
    }

    size_t size() const                         // Method to get list size
    {
        return m_size;
    }

    MyListForward &operator=(const MyListForward &other)      // Overload operator= as Copy
    {
        if (this != &other)                      // 01 - check, if current obj isn't the same as copy obj
        {
            clear_All();                        // 02 - erase all Nodes of current obj
            сopy(other);                        // 03 - copy all Nodes of copy obj to current obj
        }
        return *this;                           // 04 - return current obj
    }

    MyListForward &operator=(MyListForward &&other)           // Overload operator= as Move
    {
        if (this != &other)                      // 01 - check if current obj isn't the same to move obj
        {
            clear_All();                        // 02 - erase all Nodes in current obj
            head = other.head;                  // 03 - make current obj as move obj
            tail = other.tail;
            m_size = other.m_size;
            other.head = nullptr;               // 04 - kill obj to move
            other.tail = nullptr;
            other.m_size = 0;
        }
        return *this;
    }

    T& operator[](size_t DONT_USE_IT)
    {
        if (DONT_USE_IT > m_size)
        { std::cerr << "OUT OF RANGE" << std::endl;}

        Node *current = head;
        size_t i{0};
        while (i != DONT_USE_IT)
        {
            current = current->next;
            i++;
        }
        return current->data;
    }

    const T &operator[](size_t DONT_USE_IT) const
    {
        if (DONT_USE_IT > m_size)
        { std::cerr << "OUT OF RANGE" << std::endl;}

        Node *current = head;
        size_t i{0};
        while (i != DONT_USE_IT)
        {
            current = current->next;
            i++;
        }
        return current->data;
    }

    // ITERATORS
    Iterator begin()
    {
        Iterator it(head);
        return it;
    }

    Iterator end()
    {
        Iterator it(tail->next);
        return it;
    }

    void print() const                                  // Print List in console
    {
        if (head == nullptr)
        {
            std::cout << "List is empty" << std::endl;  // 01 - heck, if list is empty
        }
        else
        {
            Node *current = head;                       // 02 - reate temp Node to iterate
            while(current)
            {
                std::cout << current->data << " ";      // 03 - while Node is not NULL shot the element
                current = current->next;                // 04 - go to the next Node
            }
            std::cout << std::endl;
        }
    }

private:
    void сopy(const MyListForward &other)
    {
        if (other.head == nullptr)                                      // 01 - Check, if the list to copy exist
        {
            head = nullptr;
            tail = nullptr;
            m_size = 0;
        }
        else
        {
            head = new Node{other.head->data, nullptr};                 // 02 - Copy data from head of Copy List to current List

            Node *current = head;
            Node *other_current = other.head;                           // 03 - Crate temp Nodes to iterate through current List and Copy List

            while (other_current->next != nullptr)
            {
                current->next = new Node{ other_current->next->data,    // 04 - Assign next Node of current list to new Node with Copy List data
                                         nullptr};
                current = current->next;                                // 05 - Set both list iterators to a next Node
                other_current = other_current->next;
            }
            tail = current;
            m_size = other.m_size;
        }
    }
};

void runMyListForward()
{
    std::cout << "\n=== TEST LIST ===" << std::endl;
    MyListForward<int> list01;
    list01.print();

    std::cout << "\n=== TEST PUSH BACK METHOD ===" << std::endl;
    list01.push_back(10);
    list01.push_back(20);
    list01.push_back(30);
    list01.print();

    std::cout << "\n=== TEST PUSH FRONT METHOD ===" << std::endl;
    list01.push_front(90);
    list01.push_front(80);
    list01.push_front(70);
    list01.print();
    std::cout <<list01.size() << std::endl;

    std::cout << "\n=== TEST MOVE CONSTUCTOR ===" << std::endl;
    MyListForward<int>list02 (std::move(list01));
    list01.print();
    list02.print();

    std::cout << "\n=== TEST COPY CONSTUCTOR ===" << std::endl;
    MyListForward<int>list03 (list02);
    list02.print();
    list03.print();


    std::cout << "\n=== TEST POP BACK METHOD ===" << std::endl;
    list02.pop_back();
    list02.pop_back();
    list02.print();
    std::cout <<list02.size() << std::endl;

    std::cout << "\n=== TEST POP FRONT METHOD ===" << std::endl;
    list02.pop_front();
    list02.pop_front();
    list02.print();
    std::cout <<list02.size() << std::endl;

    std::cout << "\n=== TEST REMOVE METHOD ===" << std::endl;
    list02.remove(10);
    list02.print();

    std::cout << "\n=== TEST SIZE METHOD ===" << std::endl;
    list03.print();
    std::cout <<list03.size() << std::endl;

    std::cout << "\n=== TEST OPERATOR= COPY ===" << std::endl;
    MyListForward<int>list04;
    MyListForward<int>list05;
    list04.push_back(10);
    list04.push_back(20);
    list05 = list04;
    list04.print();
    list05.print();

    std::cout << "\n=== TEST OPERATOR= MOVE ===" << std::endl;
    list04 = std::move(list05);
    list04.print();
    list05.print();

    std::cout << "\n=== TEST OPERATOR[] GET ELEM ===" << std::endl;
    list03.print();
    std::cout << list03[3] << std::endl;

    std::cout << "\n=== TEST WITH OBJECTs ===" << std::endl;
    TestClass t01("obj01", 1);
    TestClass t02("obj02", 2);
    TestClass t03("obj03", 3);
    MyListForward<TestClass> objects;
    objects.push_back(t01);
    objects.push_back(t02);
    objects.push_back(t03);
    for (size_t i{0}; i < objects.size(); i++)
    {
        objects[i].doStuff();
    }

    std::cout << "\n=== TEST CLEAR ALL METHOD ===" << std::endl;
    objects.clear_All();
    std::cout << objects.size() << std::endl;

    std::cout << "\n=== TEST ITERATOR ===" << std::endl;
    MyListForward<int>list06;
    for (int i {0}; i < 10; i++)
    {list06.push_back(i);}
    list06.print();

    for (MyListForward<int>::Iterator it = list06.begin(); it != list06.end(); ++it)
    {
        *it +=10;
        std::cout << *it<< " ";
    }
    std::cout << std::endl;


}
#endif // MYLISTFORWARD_H
