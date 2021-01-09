#include <queue>
#include <stack>
#include <iostream>
#define Elemtype char
using namespace std;

struct BNode
{
    Elemtype data;
    BNode *lc, *rc;
    BNode(Elemtype value)
    {
        data = value;
        lc = nullptr;
        rc = nullptr;
    }
};

class BTree
{
public:
    BTree()
    {
        root = CreatBTree();
    }
    BNode* CreatBTree();
    BNode* getRoot() { return root; };
    void PreOrderTraverse(BNode* t);
    void PreOrderTraverse();
    void InOrderTraverse(BNode* t);
    void InOrderTraverse();
    void PostOrderTraverse(BNode* t);
    void PostOrderTraverse();
    void LevelTraverse();

private:
    BNode* root;

};

BNode* BTree::CreatBTree()
{
    BNode* cur;
    Elemtype ch;
    cin >> ch;
    if (ch == '#')
        cur = nullptr;
    else
    {
        cur = new BNode(ch);
        cur->lc = CreatBTree();
        cur->rc = CreatBTree();
    }
    return cur;
}

void BTree::PreOrderTraverse(BNode* t)
{
    if (t == nullptr)
        return;
    cout << t->data << "->";
    PreOrderTraverse(t->lc);
    PreOrderTraverse(t->rc);
}

void BTree::PreOrderTraverse()
{
    cout << "preoder:";
    PreOrderTraverse(root);
}

void BTree::InOrderTraverse(BNode* t)
{
    if (t == nullptr)
        return;
    InOrderTraverse(t->lc);
    cout << t->data << "->";
    InOrderTraverse(t->rc);
}

void BTree::InOrderTraverse()
{
    cout << "inorder:";
    InOrderTraverse(root);
}

void BTree::PostOrderTraverse(BNode* t)
{
    if (t == nullptr)
        return;
    PostOrderTraverse(t->lc);
    PostOrderTraverse(t->rc);
    cout << t->data << "->";
}

void BTree::PostOrderTraverse()
{
    cout << "postorder:";
    PostOrderTraverse(root);
}

void BTree::LevelTraverse()
{
    cout << "level:";
    queue<BNode*> q;
    q.push(root);
    while (!q.empty())
    {
        auto t = q.front();
        q.pop();
        cout << t->data << "->";
        if (t->lc != nullptr)
            q.push(t->lc);
        if (t->rc != nullptr)
            q.push(t->rc);
    }
}

int main()
{
    BTree A;
    A.PreOrderTraverse();
    cout << endl;
    A.InOrderTraverse();
    cout << endl;
    A.PostOrderTraverse();
    cout << endl;
    A.LevelTraverse();
    system("pause");
}


//ABD##E##C#F##