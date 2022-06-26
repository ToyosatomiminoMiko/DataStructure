/**
 * @file 03.cpp
 * @author ToyosatomiminoMiko (you@domain.com)
 * @brief 循环链表 Circular linked list
 * @version 0.1
 * @date 2022-06-25
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>

using namespace std;

//每个节点都是对象
class Node
{
public:
    int value;
    Node *next;

    // 构造函数
    Node(int v, Node *next)
    {
        value = v;
        cout << "Node (object [" << this << "]) 初始化 value=" << value << endl;
    }
    // 析构函数没有参数
    ~Node(void)
    {
        cout << "Node (Object [" << this << "]) "
             << "内存被释放! value=" << value << endl;
    }

    //改变节点的值
    void setValue(int v)
    {
        value = v;
        cout << "Node (Object [" << this << "]) value 被设置为:" << value << endl;
    }
};

//循环链表类
class CircularLinkedList
{
public:
    Node *head = NULL;
    //初始化 创建头节点
    CircularLinkedList()
    {
        head = new Node(0, NULL);
        head->next = head; //头节点指向自己
        cout << "CircularLinkedList (object [" << this << "]) 初始化" << endl;
    }
    ~CircularLinkedList(void)
    {
        cout << "CircularLinkedList (Object [" << this << "]) ";
        cout << "内存被释放!" << endl;
    }
    //添加节点
    void append(int i)
    {
        for (Node *p = head; p != 0; p = p->next) //当p不为空时
        {
            if ((p->next)->value == 0) //如果下一个值为空
            {
                Node *node0 = NULL;
                node0 = new Node(i, NULL); // 指针接收新建的节点
                p->next = node0;           // 上一个节点指向此处
                node0->next = head;
                break;
            }
        }
    }
    //显示
    void display()
    {
        cout << "head-->";
        for (Node *p = head->next; p != 0; p = p->next)
        {
            if (p->value == 0)
            {
                break;
            }
            cout << p->value << "-->";
        }
        cout << "head" << endl;
    }
    //查找节点 i插入位置,a插入值
    void insert(int i, int a)
    {
        for (Node *p = head->next; p != NULL; p = p->next) //当p不为空时
        {
            if (p->value == i) //如果下一个值为空
            {
                Node *insertnode = NULL;        // 准备指针
                insertnode = new Node(a, NULL); // 指针接收新建的节点
                insertnode->next = p->next;     // 新节点指向下一个节点
                p->next = insertnode;           // 上一个节点指向此处
                cout << "Node [" << a << "] inserted." << endl;
                break;
            }
        }
    }
    //删除节点
    void remove(int i)
    {
        for (Node *p = head; p != NULL; p = p->next) //当p不为空时
        {
            Node *d = p->next;
            if (d->value == i) //如果下一个值为i
            {
                p->next = d->next; // 上一个节点指向下一个节点
                // cout << p << "\n" << d << "\n" << p->next->next << "\n"<< p->next << "\n" << endl;
                delete d;
                cout << "Node [" << i << "] removed." << endl;
                break;
            }
        }
    }
};

int main()
{

    CircularLinkedList *CLL0 = new CircularLinkedList();
    CLL0->append(1);
    CLL0->append(2);
    CLL0->display();
    CLL0->insert(1, 3);
    CLL0->display();
    CLL0->remove(2);
    CLL0->display();
    delete CLL0;
    return 0;
}

// CVE-2022-30190
