#ifndef MYGENERICTREE_H
#define MYGENERICTREE_H
#include <iostream>
#include <queue>
#include <vector>

template <typename T>
struct TreeNode
{
    T m_data;
    std::vector<TreeNode*> m_child;
    TreeNode(T data) : m_data(data){}

};

// ===== COUNT NODES =====
int countNodes(TreeNode<int>* root){
    if(root == NULL){  /// edge case
        return 0;
    }
    int ans = 1;
    for(int i=0; i < root->m_child.size(); i++)
    {
        ans += countNodes(root->m_child[i]);
    }
    return ans;
}

// ===== HEIGHT =====
int height(TreeNode <int>* root)
{
    if (root == NULL)
    {  /// edge case
        return 0;
    }
    int mx = 0;   /// maximum height
    for (int i=0; i < root->m_child.size(); i++)
    {
        mx = fmax(mx, height(root->m_child[i]));
    }
    return mx + 1;
}

// ===== PRINT LEVEL K =====
void printAtLevelK(TreeNode <int>* root, int k)
{
    if(root == NULL)
    {  /// edge case
        return ;
    }
    if (k == 0)
    {
        std::cout<<root->m_data<<std::endl;
        return;
    }
    for(int i=0; i<root->m_child.size(); i++){
        printAtLevelK(root->m_child[i], k-1);
    }
}

// ===== COUNT NODES =====
int countLeafNodes(TreeNode <int>* root){
    if(root == NULL)
    {
        return 0;
      }
    if(root->m_child.size() == 0)
      {
        return 1;
      }
      int ans = 0;
      for(int i=0; i < root->m_child.size(); i++)
      {
        ans +=  countLeafNodes(root->m_child[i]);
      }
      return ans;
}

template <typename T>
void printTree(TreeNode<T> *root)
{
    std::cout << root->m_data << " : ";

    for (int i{}; i < root->m_child.size(); i++)
    {
        std::cout << root->m_child[i]->m_data << ", ";
    }
    std::cout << std::endl;

    for (int i{}; i < root->m_child.size(); i++)
    {
        printTree(root->m_child[i]);
    }
}

// PRINT ALL ROOT AND CHID PRE ORDER
template <typename T>
void preOrderPrint(TreeNode<T>* root)
{
    if (root == nullptr)
    {return;}

    std::cout << root->m_data << " ";
    for (int i{}; i < root->m_child.size(); i++)
    {
        preOrderPrint(root->m_child[i]);
    }
}

// PRINT POST ORDER first child, then root
template <typename T>
void postOrderPrint(TreeNode<T>* root)
{
    if (root == nullptr)
    {return;}

    for (int i{}; i < root->m_child.size(); i++)
    {
        preOrderPrint(root->m_child[i]);
    }
    std::cout << root->m_data << " ";

}

// DELETE TREE
template <typename T>
void deleteTree(TreeNode<T>* root)
{
    if (root == nullptr)
    {return;}

    for (int i{}; i < root->m_child.size(); i++)
    {
        deleteTree(root->m_child[i]);
    }
    delete root;

}

void runMyGenericTree()
{
    TreeNode<int> *root = new TreeNode(1);          // create root
    TreeNode<int> *child_01 = new TreeNode(11);     // create 2 childs
    TreeNode<int> *child_02 = new TreeNode(111);

    root->m_child.push_back(child_01);              // connect 2 childs to root
    root->m_child.push_back(child_02);

    printTree(root);
}
#endif // MYGENERICTREE_H
