/**
 * @file TowerOfHanoi.cpp
 * @author ToyosatomimonoMiko (you@domain.com)
 * @brief 河内塔(汉诺塔)
 * @version 0.1
 * @date 2022-06-28
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
using namespace std;
#include "stacklib.h"

void all_display(Stack *a,Stack *b,Stack *c){
    a->display();
    b->display();
    c->display();
}

int main()
{
    Stack *t0 = NULL;
    t0 = new Stack();
    Stack *t1 = NULL;
    t1 = new Stack();
    Stack *t2 = NULL;
    t2 = new Stack();

    //创建
    for (int i = 7; i > 0; i--)
    {
        t0->push(i);
    }
    all_display(t0,t1,t2);
    t1->push(t0->pop());
    all_display(t0,t1,t2);
    t2->push(t0->pop());
    all_display(t0,t1,t2);
    return 0;
}
