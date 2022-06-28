/**
 * @file 06.cpp
 * @author ToyosatomiminoMiko (you@domain.com)
 * @brief 队列(Queue)
 * @version 0.1
 * @date 2022-06-28
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#define MAXSIZE 5
using namespace std;

class Queue
{
public:
    int queue[MAXSIZE];
    int head = 0;
    int tail = 0;
    Queue()
    {
        cout << "Queue (object [" << this << "]) 初始化." << endl;
    }
    ~Queue()
    {
        cout << "Queue (Object [" << this << "]) ";
        cout << "Memory release!" << endl;
    }
    void enqueue(int a)
    {
        queue[head] = a;
        head++;
        cout << "Queue (Object [" << this << "]) enqueue successfully. ";
        cout << "value=" << a << endl;
    }
    int dequeue()
    {
        int temp= queue[tail];
        queue[tail]=0;
        cout << "Queue (Object [" << this << "]) dequeue successfully. ";
        cout << "value=" << temp << endl;
        return temp;
    }
    void display()
    {
        for (int i = 0; i < MAXSIZE; i++)
        {
            cout << queue[i] << endl;
        }
    }
};
int main()
{
    Queue *q0 = new Queue();
    q0->enqueue(1);
    q0->enqueue(2);
    q0->enqueue(3);
    q0->enqueue(4);
    q0->enqueue(5);
    q0->display();
    q0->dequeue();
    q0->enqueue(6);
    q0->display();
    return 0;
}

/*飞机爱好者--101*/
