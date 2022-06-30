/**
 * @file templateStack.h
 * (test)
 * @author ToyosatomimonoMiko (you@domain.com)
 * @brief 泛型栈(测试)
 * @version 0.1
 * @date 2022-06-29
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef STACK_H //!< 头文件保护符，防止多重调用
#define STACK_H
#include <iostream>
#define MAXSIZE 10
using namespace std;

template <typename T>
class Stack
{
public:
    T stack[MAXSIZE];
    int top = -1;
    Stack()
    {
        cout << "Stack (object [" << this << "]) ";
        cout << "is initialized." << endl;
    }
    ~Stack(void)
    {
        cout << "Stack (Object [" << this << "]) ";
        cout << "Memory release!" << endl;
    }
    void push(T a)
    {
        int p = top + 1;
        if (p > MAXSIZE)
        {
            cout << "Stack (Object [" << this << "]) push failed.";
            cout << "Full stack!" << endl;
        }
        else
        {
            stack[p] = a;
            cout << "Stack (Object [" << this << "]) pushes successfully.";
            cout << "value = " << a << endl;
            top = p;
        }
    }
    T pop(void)
    {
        if (top == -1)
        {
            cout << "Stack (Object [" << this << "]) pop failed.";
            cout << "Empty stack!" << endl;
            return NULL;
        }
        else
        {
            T temp = stack[top];
            stack[top] = 0;
            cout << "Stack (Object [" << this << "]) pops successfully.";
            cout << "value = " << temp << endl;
            top = top - 1;
            return temp;
        }
    }
    void display()
    {
        cout << "button[";
        for (int i = 0; i < MAXSIZE; i++)
        {
            cout << stack[i] << ",";
        }
        cout << "]" << endl;
    }
};
#endif
/*
int main()
{

    Stack<int> *s0 = new Stack<int>();
    s0->push(1);
    s0->display();

    return 0;
}
*/

