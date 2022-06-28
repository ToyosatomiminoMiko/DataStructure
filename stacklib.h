#ifndef TEST_H //!< 头文件保护符，防止多重调用
#define TEST_H

#include <iostream>
#define MAXSIZE 10

using namespace std;

class Stack
{
public:
    int stack[MAXSIZE];
    int top = -1;
    Stack()
    {
        cout << "Stack (object [" << this << "]) 初始化." << endl;
    }
    ~Stack(void)
    {
        cout << "Stack (Object [" << this << "]) ";
        cout << "Memory release!" << endl;
    }
    int pop(void)
    {
        if (top == -1)
        {
            cout << "Stack (Object [" << this << "]) pop failed.";
            cout << "Empty stack!" << endl;
            return top;
        }
        else
        {
            int temp = stack[top];
            stack[top] = 0;
            cout << "Stack (Object [" << this << "]) pops successfully.";
            cout << "value =" << temp << endl;
            top = top - 1;
            return temp;
        }
    }
    void push(int a)
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
            cout << "value =" << a << endl;
            top = p;
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
