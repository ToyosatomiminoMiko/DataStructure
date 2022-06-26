/**
 * @file l03.cpp
 * @author ToyosatomiminoMiko (you@domain.com)
 * @brief 链表实现(C++) 节点和链表对象
 * @version 0.1
 * @date 2022-06-24
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

//链表类
class LinkedList
{
public:
    Node *head = NULL;
    //初始化 创建头节点
    LinkedList()
    {
        head = new Node(0, NULL);
    }
    ~LinkedList(void)
    {
        cout << "LinkedList (Object [" << this << "]) ";
        cout << "内存被释放!" << endl;
    }
    //添加节点
    void append(int i)
    {
        for (Node *p = head; p != NULL; p = p->next) //当p不为空时
        {
            if (p->next == NULL) //如果下一个值为空
            {
                Node *node0 = NULL;
                node0 = new Node(i, NULL); // 指针接收新建的节点
                p->next = node0;           // 上一个节点指向此处
                break;
            }
        }
    }
    //查找节点 i插入位置,a插入值
    void insert(int i, int a)
    {
        for (Node *p = head; p != NULL; p = p->next) //当p不为空时
        {
            if (p->value == i) //如果下一个值为空
            {
                Node *insertnode = NULL;        // 准备指针
                insertnode = new Node(a, NULL); // 指针接收新建的节点
                insertnode->next = p->next;     // 新节点指向下一个节点
                p->next = insertnode;           // 上一个节点指向此处
                cout << "Node [" << a << "] inserted." << endl;
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

    //遍历链表
    void display()
    {
        for (Node *p = head; p != NULL; p = p->next)
        {
            cout << p->value << "-->";
        }
        cout << "Null" << endl;
    }
};

int main()
{

    LinkedList *link1 = NULL;
    link1 = new LinkedList();
    link1->append(1);
    // cout << ((link1->head)->next == NULL) << endl;
    link1->append(4);
    link1->append(5);
    link1->display();
    link1->insert(4, 6);
    link1->display();
    link1->remove(1);
    link1->display();
    delete link1;

    return 0;
}
