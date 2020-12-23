#ifndef QUEUE_2_H
#define QUEUE_2_H

#include <iostream>
#define MAX_SIZE 1024
using namespace std;

template <typename T>
struct Node
{
    T data;
    Node* next;
    Node(T d)
    {
        data = d;
    }
};

template <typename T>
class Myqueue
{
public:
    Myqueue() {
        Node<T>* p = new Node<T>(0);
        p->next = nullptr;
        front = rear = p;
        length = 0;
    }
    bool queueEmpty() { return front == rear; }
    void push(T x)
    {
        Node<T>* p = new Node<T>(x);
        p->next = nullptr;
        rear->next = p;
        rear = p;
        length++;
    }
    T pop()
    {
        if (front == rear) {
            cout << "empty" << endl;
            exit(0);
        }
        Node<T>* p = front->next;
        front->next = p->next;
        T x = p->data;
        if (p == rear)
            rear = front;
        delete p;
        length--;
        return x;
    }
    T getHead()
    {
        if (front == rear) {
            cout << "empty" << endl;
            exit(0);
        }
        return front->next->data;
    }
    int getLen()
    {
        return length;
    }
private:
    Node<T>* front, *rear;
    int length;
};

#endif