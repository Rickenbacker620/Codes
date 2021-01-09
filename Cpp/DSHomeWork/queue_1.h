#ifndef QUEUE_1_H
#define QUEUE_1_H

#include <iostream>
#define MAX_SIZE 1024
using namespace std;

template <typename T>
class Myqueue
{
public:
    Myqueue() { front = rear = 0; }
    bool queueEmpty() { return front == rear; }
    void push(T x)
    {
        if ((rear+1)%MAX_SIZE == front) {
            cout << "overflow" << endl;
            exit(0);
        }
        rear = (rear+1)%MAX_SIZE;
        queue[rear] = x;
    }
    T pop()
    {
        if (front == rear) {
            cout << "empty" << endl;
            exit(0);
        }
        front = (front+1)%MAX_SIZE;
        T x = queue[front];
        return x;
    }
    T getHead()
    {
        if (front == rear) {
            cout << "empty" << endl;
            exit(0);
        }
        return queue[(front+1)%MAX_SIZE];
    }
    int getLen()
    {
        return (rear-front+MAX_SIZE)%MAX_SIZE;
    }
private:
    T queue[MAX_SIZE];
    int front, rear;
};

#endif