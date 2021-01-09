#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

struct TNode
{
    TNode(int data)
    {
        this->data = data;
    }
    TNode(int data, TNode *lchild, TNode *rchild)
    {
        this->data = data;
        this->lchild = lchild;
        this->rchild = rchild;
    }
    char data;
    TNode *lchild;
    TNode *rchild;
};

class BiTree
{
  public:
    void CreateTree()
    {
        char ch;
        cin >> ch;
    }

  private:
    TNode *root;
};

int
main()
{
}