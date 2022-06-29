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
        cout << "TreeNode (object [" << this << "]) is initialized. value= " << value << endl;
    }
    // 析构函数没有参数
    ~TreeNode(void)
    {
        cout << "TreeNode (Object [" << this << "]) ";
        cout << "Memory release! value= " << value << endl;
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
        rootNode = new TreeNode(1, NULL, NULL);
        cout << "BinaryTree (Object [" << this << "]) has been created. " << endl;
    }
    ~BinaryTree(void)
    {
        cout << "BinaryTree (Object [" << this << "]) ";
        cout << "Memory release!" << endl;
    }
    void display_clr(TreeNode *node)
    {
        if (node)
        {
            cout << node->value << endl;
            display_clr(node->left);
            display_clr(node->right);
        }
    }
    void display_lcr(TreeNode *node)
    {
        if (node)
        {
            display_clr(node->left);
            cout << node->value << endl;
            display_clr(node->right);
        }
    }
    void display_lrc(TreeNode *node)
    {
        if (node)
        {
            display_clr(node->left);
            display_clr(node->right);
            cout << node->value << endl;
        }
    }
    // l:插入位置,v:插入值,d:插入方向
    void insert(TreeNode *node, int l, int v, int d)
    {
        if (node)
        {
            if (node->value == l)
            {
                TreeNode *node0 = new TreeNode(v, NULL, NULL);
                if (d)
                {
                    node->left = node0;
                    return;
                }
                else
                {
                    node->right = node0;
                    return;
                }
            }
            insert(node->left, l, v, d);
            insert(node->right, l, v, d);
        }
    }
};

int main()
{
    BinaryTree *BTree0 = new BinaryTree();
    int l = 1;
    int d = 1;
    for (int v = 2; v < 10; v++)
    {
        BTree0->insert(BTree0->rootNode, l, v, d);
        l++;
        if (d)
        {
            d--;
        }
        else
        {
            d++;
        }
    }

    BTree0->display_lcr(BTree0->rootNode);
    delete BTree0;
    return 0;
}
