#ifndef STACK_1_H
#define STACK_1_H

#include <iostream>
#define MAX_SIZE 1024
using namespace std;

template <typename T>
class Mystack
{
public:
    Mystack() { top = 0; }
    bool stackEmpty() { return top == 0; }
    void push(T x)
    {
        if (top == MAX_SIZE-1) {
            cout << "overflow" << endl;
            exit(0);
        }
        stack[top++] = x;
    }
    T pop()
    {
        if (top == 0) {
            cout << "empty" << endl;
            exit(0);
        }
        top--;
        T x = stack[top];
        return x;
    }
    T getTop()
    {
        if (top == 0) {
            cout << "empty" << endl;
            exit(0);
        }
        return stack[top-1];
    }
private:
    T stack[MAX_SIZE];
    int top;
};

#endif
