/**
 * @file 05.cpp
 * @author ToyosatomiminoMiko (you@domain.com)
 * @brief 栈
 * @version 0.1
 * @date 2022-06-28
 *
 * @copyright Copyright (c) 2022
 *
 */

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

int main()
{
    Stack *stack0 = NULL;
    stack0 = new Stack();
    stack0->push(1);
    stack0->push(2);
    stack0->push(3);
    stack0->display();
    stack0->pop();
    stack0->display();
    return 0;
}

/*
<>从编译器钦定的目录寻找
""从当前的目录寻找
*/
