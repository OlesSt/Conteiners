#ifndef MYBINARYTREE_H
#define MYBINARYTREE_H

#include <iostream>
#include <queue>
#include <vector>

template <typename T>
class MyBinaryTree
{
public:
    T m_data;
    MyBinaryTree *m_left;
    MyBinaryTree *m_right;

public:
    MyBinaryTree(T data)
        : m_data(data)
    {
        m_left = nullptr;
        m_right = nullptr;
    }

    ~MyBinaryTree()
    {
        delete m_left;
        delete m_right;
    }

    void insert(T insertData)
    {
        MyBinaryTree<T> *newNode = new MyBinaryTree<T>(insertData);
        if (this->m_data > insertData)
        {
            this->m_left = newNode;
        }
        else if (this->m_data < insertData)
        {
            this->m_right = newNode;
        }
        else
        {
            std::cout << "!!! value exist !!!" << std:: endl;
            delete newNode;
            return;
        }
    }
};

template <typename T>
void printBinaryTree(MyBinaryTree<T> *root)
{
    if (root == nullptr) { return; }

    std::cout << root->m_data << " : ";

    if (root->m_left)
    {
        std::cout << "L" << root->m_left->m_data;
    }

    if (root->m_right)
    {
        std::cout << "R" << root->m_right->m_data;
    }
    std::cout << std::endl;

    printBinaryTree(root->m_left);
    printBinaryTree(root->m_right);
}

template <typename T>
std::vector<T> levelOrderTraversal(MyBinaryTree<T> *root)
{
    std::vector<std::vector<int> > v;               // - this is future answer

    if(root == nullptr) { return v; }               // - basic case

    std:: vector<int> temp;                         // storing is storing result of current level

    std::queue <MyBinaryTree<int>> q;

    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        MyBinaryTree <T> *f = q.front();

        q.pop();

        if(f == nullptr)
        {
            ///cout<<endl;
            v.push_back(temp);
            temp.clear();

            if(!q.empty())
            {
                q.push(NULL);
            }

        }
        else
        {
            temp.push_back(f->val);
            if(f->left)
            {
                q.push(f->left);
            }
            if(f->right)
            {
                q.push(f->right);
            }
        }
    }
    return v;
}

// COUNT NODEs AMOUNT
template <typename T>
int countNodes(MyBinaryTree<T> *root)
{
    if (root == nullptr)
    { return 0;}

    return countNodes(root->m_left) + countNodes(root->m_right + 1);
}

template <typename T>
int depthHeight(MyBinaryTree<T> *root)
{
    int left =  depthHeight(root->m_left);
    int right = depthHeight(root->m_right);
    return std::max(left, right) + 1;
}

template <typename T>
bool findNode(MyBinaryTree<T> *root, T x)
{
    if (root == nullptr) return false;
    if (root->m_data == x) return true;

    return findNode(root->m_left, x) || findNode(root->m_right, x);
}

template <typename T>
T minValue(MyBinaryTree<T> *root)
{
    if (root == nullptr) return INT_MAX;

    int leftMin = minValue(root->m_left);
    int rightMin = minValue(root->m_right);

    return std::min(root->m_data, std::min(leftMin, rightMin));
}

template <typename T>
T maxValue(MyBinaryTree<T> *root)
{
    if (root == nullptr) return INT_MAX;

    int leftMax = maxValue(root->m_left);
    int rightMax = maxValue(root->m_right);

    return std::max(root->m_data, std::max(leftMax, rightMax));
}

void runMyBinaryTree()
{
    MyBinaryTree<int>* root = new MyBinaryTree<int>(1);
    MyBinaryTree<int>* n1 = new MyBinaryTree<int>(2);
    MyBinaryTree<int>* n2 = new MyBinaryTree<int>(3);

    root->m_left = n1;
    root->m_right = n2;

    printBinaryTree(root);



    delete root;

}
#endif // MYBINARYTREE_H
