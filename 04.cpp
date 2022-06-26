/**
 * @file 04.cpp
 * @author ToyosatomiminoMiko (you@domain.com)
 * @brief 双向链表 Doubly linked list
 * @version 0.1
 * @date 2022-06-26
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>

using namespace std;

//每个节点都是对象
class DoublyNode
{
public:
    //节点值
    int value;
    //下一个节点
    DoublyNode *next;
    //上一个节点
    DoublyNode *prev;

    // 构造函数
    DoublyNode(int v, DoublyNode *next, DoublyNode *prev)
    {
        value = v;
        cout << "DoublyNode (object [" << this << "]) 初始化 value=" << value << endl;
    }
    // 析构函数没有参数
    ~DoublyNode(void)
    {
        cout << "DoublyNode (Object [" << this << "]) ";
        cout << "memory release! value=" << value << endl;
    }

    //改变节点的值
    void setValue(int v)
    {
        value = v;
        cout << "DoublyNode (Object [" << this << "]) value 被设置为:" << value << endl;
    }
};

//链表类
class DoublyLinkedList
{
public:
    DoublyNode *head = NULL;
    DoublyNode *foot = NULL;
    //初始化 创建头节点
    DoublyLinkedList()
    {
        head = new DoublyNode(0, NULL, NULL);
    }
    ~DoublyLinkedList(void)
    {
        cout << "LinkedList (Object [" << this << "]) ";
        cout << "memory release!" << endl;
    }
    //添加节点
    void append(int i)
    {
        for (DoublyNode *p = head; p != 0; p = p->next) //当p不为空时
        {
            if (p->next == 0) //如果下一个值为空
            {
                DoublyNode *node0 = NULL;
                node0 = new DoublyNode(i, NULL, NULL); // 指针接收新建的节点
                p->next = node0;                       // 上一个节点指向此处
                node0->prev = p;                       // 此处指向上一个节点
                foot = node0;
                break;
            }
        }
    }
    //遍历链表
    void display()
    {
        for (DoublyNode *p = head; p != NULL; p = p->next)
        {
            cout << p->value << "-->";
        }
        cout << "Null" << endl;
    }
    //反向遍历链表
    void re_display()
    {
        cout << "Null";

        for (DoublyNode *p = foot; p != NULL; p = p->prev)
        {
            cout << "<--" << p->value;
        }
        cout << endl;
    }
    //查找节点 i插入位置,a插入值
    void insert(int i, int a)
    {
        for (DoublyNode *p = head->next; p != NULL; p = p->next) //当p不为空时
        {
            if (p->value == i) //如果下一个值为空
            {
                DoublyNode *insertnode = NULL;        // 准备指针
                insertnode = new DoublyNode(a, NULL,NULL); // 指针接收新建的节点
                insertnode->next = p->next;     // 新节点指向下一个节点
                p->next->prev=insertnode;
                insertnode->prev=p;
                p->next = insertnode;           // 上一个节点指向此处
                cout << "Node [" << a << "] inserted." << endl;
                break;
            }
        }
    }
    //删除节点
    void remove(int i)
    {
        for (DoublyNode *p = head; p != NULL; p = p->next) //当p不为空时
        {
            DoublyNode *d = p->next;
            if (d->value == i) //如果下一个值为i
            {
                d->next->prev=p;
                p->next = d->next; // 上一个节点指向下一个节点
                delete d;
                cout << "Node [" << i << "] removed." << endl;
                break;
            }
        }
    }
};

int main()
{
    DoublyLinkedList *DLL0 = new DoublyLinkedList();
    DLL0->append(1);
    DLL0->append(2);
    DLL0->append(3);
    DLL0->re_display();
    DLL0->insert(2,4);
    DLL0->remove(2);
    DLL0->display();
    delete DLL0;
    return 0;
}
