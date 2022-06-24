/**
 * @file 01.cpp
 * @author ToyosatomiminoMiko (you@domain.com)
 * @brief 链表实现(C++) 节点对象
 * @version 0.1
 * @date 2022-06-23
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node *next;

    // 构造函数
    Node(int v, Node *next)
    {
        value = v;
        cout << "Node (object [" << this << "]) value 初始化为:" << value << endl;
    }
    // 析构函数没有参数
    ~Node(void)
    {
        cout << "Node (Object [" << this << "]) " << value << "内存被释放!" << endl;
    }

    //改变节点的值
    void setValue(int v)
    {
        value = v;
        cout << "Node (Object [" << this << "]) value 被设置为:" << value << endl;
    }
};

//链表查找
void search(Node *node, int x) // node 待查找链表 x目标值
{
    if (node->value == x)
    {
        cout << "Node [" << x << "] is in linked list." << endl;
    }
    else if (node->next == NULL)
    {
        cout << "Node [" << x << "] is not found." << endl;
    }
    else
    {
        return search(node->next, x);
    }
}

//插入 node 待查找链表 a目标插入点 i待插入值
Node *insert(Node *node, int a, int i)
{
    if (node->value == a)
    {
        Node *nodeTemp = NULL;        // 准备指针
        nodeTemp = new Node(i, NULL); // 指针接收新建的节点
        nodeTemp->next = node->next;  // 新节点指向下一个节点
        node->next = nodeTemp;        // 上一个节点指向此处
        cout << "Node [" << i << "] inserted." << endl;
        cout << "New value:" << nodeTemp->value << endl;
        return nodeTemp;
    }
    else if (node->next == NULL)
    {
        cout << "Node [" << a << "] is not found." << endl;
        return node;
    }
    else
    {
        return insert(node->next, a, i);
    }
}

void display(Node *node) // 遍历链表
{

    if (node->next == NULL)
    {
        cout << node->value << "-->Null" << endl;
        cout << "End..." << endl;
    }
    else
    {
        cout << node->value << "-->";
        return display(node->next);
    }
}

//释放内存
void deallocate(Node *node)
{
    if (node->next == NULL)
    {
        delete node;
        cout << "Linked list cleared..." << endl;
    }
    else
    {
        Node *p = node->next;
        delete node;
        return deallocate(p);
    }
    Node *p = NULL;
}
//删除节点
Node *remove(Node *node, int m)
{
    Node *p = node->next;
    if (p->value == m)
    {
        node->next = p->next; // 上一个节点指向下一个节点
        delete p;             //删除节点
        cout << "Node [" << m << "] removed." << endl;
        return node;
    }
    else if (p == NULL)
    {
        cout << "Node [" << m << "] is not found." << endl;
        return node;
    }
    else
    {
        return remove(p, m);
    }
}

// 程序的主函数
int main()
{
    //头节点
    Node *head = NULL;
    head = new Node(0, NULL);
    //(*head).value = NULL;
    //节点1
    Node *node1 = NULL;        // 准备指针
    node1 = new Node(1, NULL); // 指针接收新建的节点
    head->next = node1;        // 上一个节点指向此处

    Node *node2 = NULL;
    node2 = new Node(2, NULL);
    node1->next = node2;

    Node *node3 = NULL;
    node3 = new Node(3, NULL);
    node2->next = node3;

    //末端
    node3->next = NULL;

    // cout << "head:" << head << endl;
    /*
        // 设置值
        node1->setValue(6);
        cout << "Object [" << node1 << "] value =" << node1->value << endl;
    */

    // 查找值
    search(head, 2);

    //插入链表
    insert(head, 2, 4);

    //查看链表
    display(head);

    //删除节点
    remove(head, 2);
    display(head);

    //清除链表
    deallocate(head);
}
