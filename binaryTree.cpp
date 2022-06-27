/**
 * @file binaryTree.cpp
 * @author ToyosatomiminoMiko (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-06-27
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>

using namespace std;

//每个节点都是对象
class TreeNode
{
public:
    //节点值
    int value;
    //左节点
    TreeNode *left;
    //右节点
    TreeNode *right;

    // 构造函数
    TreeNode(int v, TreeNode *left, TreeNode *right)
    {
        value = v;
        cout << "TreeNode (object [" << this << "]) 初始化 value=" << value << endl;
    }
    // 析构函数没有参数
    ~TreeNode(void)
    {
        cout << "TreeNode (Object [" << this << "]) ";
        cout << "Memory release! value=" << value << endl;
    }

    //改变节点的值
    void setValue(int v)
    {
        value = v;
        cout << "TreeNode (Object [" << this << "]) value is set to:" << value << endl;
    }
};

class BinaryTree
{
public:
    TreeNode *rootNode = NULL;
    BinaryTree()
    {
        rootNode = new TreeNode(0, NULL, NULL);
        cout << "BinaryTree (Object [" << this << "]) has been created." << endl;
    }
    ~BinaryTree(void)
    {
        cout << "BinaryTree (Object [" << this << "]) ";
        cout << "Memory release!" << endl;
    }
};


int main(){
    BinaryTree *BTree0=NULL;
    BTree0=new BinaryTree();
    return 0;
}

