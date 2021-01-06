#include <iostream>
using namespace std;

int counter = 0;

struct Node
{
    Node(int data) : data(data) {}
    int data;
    Node *lchild;
    Node *rchild;
};

void
CreateTree(Node *&root)
{
    if (counter >= 4)
        return;
    root = new Node(counter++);
    CreateTree(root->lchild);
    CreateTree(root->rchild);
}

int
main()
{
    Node *root;
    CreateTree(root);
    return 0;
}