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
    TNode *CreateTree(TNode *root)
    {
        char ch;
        cin >> ch;
        if (ch == '#')
            root == nullptr;
        else
            root = new TNode(ch, CreateTree(root->lchild), CreateTree(root->rchild));
        return root;
    }

  private:
    TNode *root;
};

int
main()
{
    BiTree t;
    t.CreateTree();
}