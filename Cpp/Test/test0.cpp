#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;

struct TNode
{
    TNode(int data)
    {
        this->data = data;
    }
    char data;
    TNode *lchild;
    TNode *rchild;
};

class BiTree
{
  public:
    BiTree()
    {
        CreateTree(root);
    }
    TNode *CreateTree(TNode *&root)
    {
        char ch;
        cin >> ch;
        if (ch == '#')
            root == nullptr;
        else
        {
            root = new TNode(ch);
            CreateTree(root->lchild);
            CreateTree(root->rchild);
        }
        return root;
    }

  private:
    TNode *root;
};

int
main()
{
    BiTree t;
}