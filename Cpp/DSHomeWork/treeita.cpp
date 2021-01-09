#include <stack>
#include <queue>
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
        CreatBTree();
    }
    void CreatBTree();
    BNode *getRoot() { return root; };
    void PreOrderTraverse(BNode *t);
    void PreOrderTraverse();
    void InOrderTraverse(BNode *t);
    void InOrderTraverse();
    void PostOrderTraverse(BNode *t);
    void PostOrderTraverse();
    void LevelTraverse();

private:
    BNode *root;
};

void BTree::CreatBTree()
{
    BNode *s[200];
    BNode *cur;
    int num, parent;
    Elemtype ch;
    cout << "num, ch = :";
    cin >> num >> ch;
    while (num != 0)
    {
        cur = new BNode(ch);
        s[num] = cur;
        if (num == 1)
            root = cur;
        else
        {
            parent = num / 2;
            if (num % 2 == 0)
                s[parent]->lc = cur;
            else
                s[parent]->rc = cur;
        }
        cout << "num, ch = :";
        cin >> num >> ch;
    }
}

void BTree::PreOrderTraverse(BNode *t)
{
    stack<BNode*> s;
    s.push(t);
    while (!s.empty())
    {
        auto t = s.top();
        s.pop();
        cout << t->data;
        if (t->rc != nullptr)
            s.push(t->rc);
        if (t->lc != nullptr)
            s.push(t->lc);
    }
}

void BTree::PreOrderTraverse()
{
    cout << "preoder:";
    PreOrderTraverse(root);
}

void BTree::InOrderTraverse(BNode *t)
{
    stack<BNode *> s;
    while (t != nullptr || !s.empty())
    {
        while (t != nullptr)
        {
            s.push(t);
            t = t->lc;
        }
        if (!s.empty())
        {
            t = s.top();
            s.pop();
            cout << t->data;
            t = t->rc;
        }
    }
}

void BTree::InOrderTraverse()
{
    cout << "inorder:";
    InOrderTraverse(root);
}

void BTree::PostOrderTraverse(BNode *t)
{
    struct tnode
    {
        BNode* tn;
        int tag;
    };
    stack<tnode> s;
    while (t != nullptr || !s.empty())
    {
        while (t != nullptr)
        {
            s.push({t, 0});
            t = t->lc;
        }
        while (!s.empty() && s.top().tag == 1)
        {
            cout << s.top().tn->data;
            s.pop();
        }
        if (!s.empty())
        {
            s.top().tag = 1;
            t = s.top().tn->rc;
        }
    }
}

void BTree::PostOrderTraverse()
{
    cout << "postorder:";
    PostOrderTraverse(root);
}

void BTree::LevelTraverse()
{
    cout << "level:";
    queue<BNode *> q;
    q.push(root);
    while (!q.empty())
    {
        auto t = q.front();
        q.pop();
        cout << t->data;
        if (t->lc != nullptr)
            q.push(t->lc);
        if (t->rc != nullptr)
            q.push(t->rc);
    }
}

int main()
{
    BTree A;
    cout << endl;
    A.PreOrderTraverse();
    cout << endl;
    A.InOrderTraverse();
    cout << endl;
    A.PostOrderTraverse();
    cout << endl;
    A.LevelTraverse();
    system("pause");
    return 0;
}

//1 A 2 B 3 C 4 D 5 E 7 F 0 0