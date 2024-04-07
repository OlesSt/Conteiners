#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

template<class T>
class BinarySearchTree
{
private:
    struct Node
    {
        T m_data;
        Node *m_left;
        Node *m_right;

        Node(T data) : m_data(data), m_left(nullptr), m_right(nullptr){}
        ~Node() { delete m_left; delete m_right;}



    };

    Node *m_root;


public:
    BinarySearchTree() {m_root = nullptr;}
    ~BinarySearchTree(){delete m_root;}

    void deleteData(T data)
    {
        if (m_root == nullptr)
        {

        }

    }

    void insertData(T data)
    {
        if (m_root == nullptr)
        {
            BinarySearchTree *root = new BinarySearchTree(data);
        }

        if (m_root->m_data == data){ return; }

        if (m_root->m_data < data)
        {
            m_root->m_left = new BinarySearchTree(data);
        }
        else
        {
            m_root->m_right = new BinarySearchTree(data);
        }
    }

    bool isData(T data)
    {
        if (m_root == nullptr) { return false;}
        if (m_root->m_data == data) {return true;}

        if (m_root->m_data > data)
        {
            return isData(this->m_root->m_right, data);
        }
        else
        {
            return isData(this->m_root->m_left, data);
        }



    }

    void print()
    {

    }

};

template<class T>
bool find(BinarySearchTree *tree, T key)
{

}

template<class T>
T getMin(BinarySearchTree *tree)
{
    while (tree->m_left != nullptr)
    {
        tree = tree->m_left;
    }
    return tree->m_data;
}

template<class T>
T getMax(BinarySearchTree *tree)
{
    while (tree->m_right != nullptr)
    {
        tree = tree->m_right;
    }
    return tree->m_data;
}

#endif // BINARYSEARCHTREE_H
