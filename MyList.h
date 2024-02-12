#ifndef MYLIST_H
#define MYLIST_H

#include <iostream>

template <typename T>
class MyList
{
private:
    struct Node
    {
        T m_data;
        Node *m_prev;
        Node *m_next;
    };

    Node *m_head;
    Node *m_tail;
    size_t m_size;

    void m_Copy(const MyList &other)
    {
        if (other.m_size == 0)
        { return; }

        m_head = new Node{other.m_head->m_data, nullptr, nullptr};

        Node *current = m_head;
        Node *other_current = other.m_head->m_next;

        while (other_current != nullptr)
        {
            current->m_next = new Node{other_current->m_data, current, nullptr};
            current = current->m_next;
            other_current = other_current->m_next;
        }
        m_size = other.m_size;
    }

    void m_Move(MyList &&other)
    {
        m_head = other.m_head;
        m_tail = other.m_tail;
        m_size = other.m_size;

        other.m_head = nullptr;
        other.m_tail = nullptr;
        other.m_size = 0;
    }

    void pop_head()
    {
        Node *temp = m_head;
        m_head = m_head->m_next;
        m_tail->m_prev = nullptr;
        delete temp;
    }
    void pop_tail()
    {
        Node *temp = m_tail;
        m_tail = m_tail->m_prev;
        m_tail->m_next = nullptr;
        delete temp;
    }

public:
    class Iterator
    {
    public:
        Iterator(Node* ptr)
            : m_ptr(ptr) {}

        int& operator*() { return m_ptr->m_data; }
        Iterator& operator++()
        {
            m_ptr = m_ptr->m_next;
            return *this;
        }
        Iterator operator++(int)
        {
            Iterator temp(*this);
            m_ptr = m_ptr->m_next;
            return temp;
        }

        Iterator& operator--()
        {
            m_ptr = m_ptr->m_prev;
            return *this;
        }

        Iterator operator--(int)
        {
            Iterator temp(*this);
            m_ptr = m_ptr->m_prev;
            return temp;
        }

        bool operator==(const Iterator &other) { return m_ptr == other.m_ptr;}
        bool operator!=(const Iterator &other) { return m_ptr != other.m_ptr;}
    private:
        Node* m_ptr;
    };

public:
    MyList()
        : m_head(nullptr), m_tail(nullptr), m_size(0) {}

    MyList(const MyList &other)
        : m_head(nullptr), m_tail(nullptr), m_size(0)
    {
        if (other.m_size != 0)
        {
            m_Copy(other);
        }
    }

    MyList(MyList &&other)
    {
        m_Move(std::move(other));
    }

    ~MyList()
    {
        clear_All();
    }

    MyList& operator=(const MyList &other)
    {
        if (this != &other)
        {
            clear_All();
            m_Copy(other);
        }
        return *this;
    }

    Iterator i_begin() { return Iterator(m_head);}
    Iterator i_end() { return Iterator(nullptr);}


    MyList& operator=(MyList &&other)
    {
        if (this != &other)
        {
            clear_All();
            m_Move(std::move(other));
        }
        return *this;
    }


    void push_back(const T &value)                                      // METHOD TO INSERT VALUE TO END OF THE LIST
    {
        if (m_size == 0)                                                // 01 - if list is empty
        {
            m_head = new Node{value, nullptr, nullptr};                 // ... create a new Node with value
            m_tail = m_head;                                            // and tail points to the head
        }
        else                                                            // 02 - if it's not...
        {
            m_tail->m_next = new Node {value, m_tail, nullptr};         // ... create a new Node After the tail
            m_tail = m_tail->m_next;                                    // ... and move current tail to this new Node
        }
        m_size++;
    }

    void push_front(const T &value)                                     // METHOD TO INSERT VALUE TO THE BEGINING
    {
        if (m_size == 0)
        {
            m_head = new Node{value, nullptr, nullptr};
            m_tail = m_head;
        }
        else
        {
            m_head->m_prev = new Node{value, nullptr, m_head};
            m_head = m_head->m_prev;
        }
        m_size++;
    }

    void pop_back()                                                     // METHOD TO DELETE LAST ELEMENT
    {
        if (m_size == 0)                                                // 01 - check if empty
        { return; }
        else if (m_size == 1)                                           // 02 - check if only one Node...
        {
            delete m_tail;                                              // ... delete node and kill links
            m_head = nullptr;
            m_tail = nullptr;
        }
        else                                                            // 03 - create temp Node to iterate
        {
            Node *temp = m_tail;
            m_tail = m_tail->m_prev;                                    // 04 - move Node to 1 back
            m_tail->m_next = nullptr;                                   // 05 - kill link to next node
            delete temp;                                                // 06 - delete node
        }
        m_size--;
    }

    void pop_front()                                                    // METHOD TO DELETE FIRST ELEM
    {
        if (m_size == 0)
        { return; }
        else if (m_size == 1)
        {
            delete m_head;
            m_tail = nullptr;
            m_head = nullptr;
        }
        else
        {
            Node *temp = m_head;
            m_head = m_head->m_next;
            m_head->m_prev = nullptr;
            delete temp;
        }
        m_size--;
    }

    void remove(const T &value)                                         // METHID TO DELETE ELEM
    {
        Node *temp = m_head;                                            // 01 - create a new node to iterate

        while (temp != nullptr)                                         // ... and go to loop
        {
            if (temp->m_data == value)                                  // 02 - check if find value
            {
                if (m_head == temp)                                     // 03 - if it first elem
                {
                    if (m_size == 1)                                    // ... and size is 1 - kill head
                    {
                        delete m_head;
                        m_head = nullptr;
                        m_tail = nullptr;
                    }
                    else                                                // ... or use pop_head()
                    {
                        pop_head();
                    }

                }
                else if (m_tail == temp)                                // 04 - if item in the end
                {
                    pop_tail();                                         // ... kill tail
                }
                else
                {
                    temp->m_prev->m_next = temp->m_next;                // 05 - or connect prev to next and next to prev
                    temp->m_next->m_prev = temp->m_prev;
                    delete temp;                                        // ... and kill temp Node

                }
                m_size--;
                return;
            }
            temp = temp->m_next;
        }

    }

    void clear_All()                                                    // METHOD TO ERASE ALL LIST
    {
        while(m_head != nullptr)                                        // 01 - While head exist
        {
            Node *temp = m_head;                                        // 02 - iterate through list and delete every Node
            m_head = m_head->m_next;
            delete temp;
        }
        m_tail = nullptr;                                               // 03 - kill tail of the list and size
        m_size = 0;
    }

    bool find(const T& value)                                           // METHOD TO FIND ELEN BY VALUE
    {
        Node *temp = m_head;                                            // 01 - Create temp Node to iterate
        while(temp != nullptr)
        {
            if (temp->m_data == value)                                  // 02 - check all Nodes with the loop and return true if found
            {
                return true;
            }
            temp = temp->m_next;                                        // 03 - move focus to the next Node
        }
        return false;
    }

    void reverse()                                                      // METHOD TO REVERSE LIST
    {
        m_tail = m_head;
        Node *current = m_head;
        Node *temp = nullptr;

        while (current != nullptr)
        {
            temp = current->m_prev;
            current->m_prev = current->m_next;
            current->m_next = temp;
            current = current->m_prev;
        }
        if (temp != nullptr)
        {
            m_head = temp->m_prev;
        }
    }

    Node* remove_N_from_the_End(Node *node, int N)
    {
        Node *first = m_head;
        Node *second = m_head;

        while (N--)
        {
            first = first->m_next;
        }

        if (first == nullptr)
        {
            return second->m_next;
        }

        while (first->m_next != nullptr)
        {
            first = first->m_next;
            second = second->m_next;
        }

        second->m_next = second->m_next->m_next;
        return node;
    }

    Node *merge_Two_Sorted_Lists(Node *one, Node *two)
    {
        if (one == nullptr) { return two; }
        if (two == nullptr) { return one; }

        Node *finalHead = nullptr;
        if (one->m_data < two->m_data)
        {
            finalHead = one;
            one = one->m_next;
        }
        else
        {
            finalHead = two;
            two = two->m_next;
        }

        Node *p = finalHead;
        while(one && two)
        {
            if (one->m_data < two->m_data)
            {
                p->m_next = one;
                one = one->m_next;
            }
            else
            {
                p->m_next = two;
                two = two->m_next;
            }
            p = p->m_next;
        }
        if (one)
        {
            p->m_next = one;
        }
        else
        {
            p->m_next = two;
        }
        return finalHead;
    }

    Node *merge_Two_Sorted_Lists_Recursive(Node *one, Node *two)
    {
        if (one == nullptr) { return two; }
        if (two == nullptr) { return one; }

        Node *newHead = nullptr;

        if (one->m_data < two->m_data)
        {
            newHead = one;
            newHead->m_next = merge_Two_Sorted_Lists_Recursive(one->m_next, two);
        }
        else
        {
            newHead = two;
            newHead->m_next = merge_Two_Sorted_Lists_Recursive(one, two->m_next);
        }
        return newHead;
    }

    int length_recursion (Node *head)                                   // LENTH WITH RECURSION
    {
        if (head == nullptr) {return 0;}                                // - basic case
        int smallAnswwer = length_recursion(head->m_next);
        return smallAnswwer + 1;
    }

    bool find (Node *node, T data)
    {
        Node *current = m_head;
        while (current != nullptr)
        {
            if (current->m_data == data)
            {
                return true;
            }
            current = current->m_next;
        }
        return false;
    }

    bool find_recirsion (Node *node, T data)
    {
        Node *current = m_head;
        if (current == nullptr)
        {
            return false;
        }
        if (current->m_data == data)
        {
            return true;
        }
        else
        {
            find_recirsion(current->m_next, data);
        }
    }

    T Mid_Value_BySlowAndFastPointer(Node *node)
    {
        Node *slow = node;
        Node* fast = node->m_next;

        while(fast != nullptr && fast->m_next != nullptr)
        {
            slow = slow->m_next;
            fast = fast->m_next->m_next;
        }

        return slow->m_data;
    }

    T& begin()
    {
        return m_head->m_data;
    }

    T& end()
    {
        return m_tail->m_data;
    }

    bool isEmpty()
    {
        return m_size == 0;
    }

    size_t size()
    { return m_size;}

    void print()
    {
        if (m_size == 0)
        {
            std::cout << "LIST IS EMPTY" << std::endl;
        }
        else
        {
            Node *current = m_head;
            while (current)
            {
                std::cout << current->m_data << " ";
                current = current->m_next;
            }
            std::cout << std::endl;
        }
    }
};




void runMyList()
{
    std::cout << "\n=== TEST MY LIST ===" << std::endl;
    MyList<int> list01;
    list01.print();
    std::cout << "- Size = " << list01.size() << std::endl;

    std::cout << "\n=== TEST PUSH BACK ===" << std::endl;
    list01.push_back(30);
    list01.push_back(40);
    list01.push_back(50);
    list01.print();
    std::cout << "- Size = " << list01.size() << std::endl;

    std::cout << "\n=== TEST PUSH FRONT ===" << std::endl;
    list01.push_front(20);
    list01.push_front(10);
    list01.print();
    std::cout << "- Size = " << list01.size() << std::endl;

    std::cout << "\n=== TEST POP BACK ===" << std::endl;
    list01.pop_back();
    list01.print();
    std::cout << "- Size = " << list01.size() << std::endl;

    std::cout << "\n=== TEST POP FRONT ===" << std::endl;
    list01.pop_front();
    list01.print();
    std::cout << "- Size = " << list01.size() << std::endl;

    std::cout << "\n=== TEST BEGIND AND END ===" << std::endl;
    list01.print();
    std::cout << "Begin = " << list01.begin() << std::endl;
    std::cout << "End = " << list01.end() << std::endl;

    std::cout << "\n=== TEST COPY ===" << std::endl;
    list01.print();
    MyList<int> list02 (list01);
    list02.print();

    std::cout << "\n=== TEST MOVE ===" << std::endl;
    list01 = std::move(list02);
    list01.print();
    list02.print();

    std::cout << "\n=== TEST REMOVE ===" << std::endl;
    list01.print();
    list01.remove(30);
    list01.print();
    std::cout << "- Size = " << list01.size() << std::endl;

    std::cout << "\n=== TEST REVERSE ===" << std::endl;
    MyList<int>list03;
    list03.push_back(1);
    list03.push_back(2);
    list03.push_back(3);
    list03.push_back(4);
    list03.push_back(5);
    list03.print();
    list03.reverse();
    list03.print();
    list03.reverse();
    list03.print();

    std::cout << "\n=== TEST ITERATOR ===" << std::endl;
    for (MyList<int>::Iterator i = list03.i_begin(); i != list03.i_end(); ++i)
    {
        *i += 10;
    }
    list03.print();

    std::cout << "\n=== TEST CLEAR ALL ===" << std::endl;
    list01.clear_All();
    list01.print();
    std::cout << "- Size = " << list01.size() << std::endl;



}

#endif // MYLIST_H
