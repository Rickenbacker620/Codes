
#ifndef STACK_1_H
#define STACK_1_H

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
class Mystack
{
public:
    Mystack() { head = nullptr; }
    bool stackEmpty() { return head == nullptr; }
    void push(T x)
    {
        if (head == nullptr)
            head = new Node<T>(x);
        else
        {
            Node<T>* tmp = head;
            head = new Node<T>(x);
            head->next = tmp;
        }
    }
    T pop()
    {
        if (head == nullptr) {
            cout << "empty" << endl;
            exit(0);
        }
        Node<T>* tmp = head;
        T x = tmp->data;
        head = head->next;
        delete tmp;
        return x;
    }
    T getTop()
    {
        if (head == nullptr) {
            cout << "empty" << endl;
            exit(0);
        }
        return head->data;
    }
private:
    Node<T>* head;
};

#endif
