#include <iostream>
#include <vector>
#include <sstream>
#include <queue>
#include <functional>

using namespace std;
stringstream input("ABD##E##C#F##");

struct TNode
{
    TNode(int data)
    {
        this->data = data;
        leftChild = nullptr;
        rightChild = nullptr;
    }
    char data;
    TNode *leftChild;
    TNode *rightChild;
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
        input >> ch;
        if (ch == '#')
        {
            root == nullptr;
        }
        else
        {
            root = new TNode(ch);
            CreateTree(root->leftChild);
            CreateTree(root->rightChild);
        }
        return root;
    }

    TNode *&GetRoot()
    {
        return root;
    }

    using ManipNode = function<void(TNode *&)>;
    using NullNode = function<void(void)>;
    void LevelTraverse(ManipNode NormalNode, NullNode EmptyNode)
    {
        int maxNode = 1;
        int nodeCount = 0;
        queue<TNode *> q;
        q.push(root);
        while (q.size())
        {
            nodeCount++;
            TNode *temp = q.front();
            q.pop();
            if (temp != nullptr)
            {
                NormalNode(temp);
                q.push(temp->leftChild);
                q.push(temp->rightChild);
            }
            else
            {
                EmptyNode();
            }
            if (nodeCount == maxNode)
            {
                cout << endl;
                nodeCount = 0;
                maxNode <<= 1;
            }
        }
    }

    void _SwapSubTree(TNode *&root)
    {
        swap(root->leftChild, root->rightChild);
        if (root->leftChild)
            _SwapSubTree(root->leftChild);
        if (root->rightChild)
            _SwapSubTree(root->rightChild);
    }

    void SwapSubTree()
    {
        _SwapSubTree(root);
    }

    int _GetLeafCount(TNode *&root)
    {
        if (root == nullptr)
            return 0;
        if (root->leftChild == nullptr && root->rightChild == nullptr)
            return 1;
        return _GetLeafCount(root->leftChild) + _GetLeafCount(root->rightChild);
    }

    int GetLeafCount()
    {
        return _GetLeafCount(root);
    }

    int _GetNodeCount(TNode *&root)
    {
        if (root == nullptr)
            return 0;
        return 1 + _GetNodeCount(root->leftChild) + _GetNodeCount(root->rightChild);
    }

    int GetNodeCount()
    {
        return _GetNodeCount(root);
    }

    int _GetDepth(TNode *&root)
    {
        if (root == nullptr)
            return 0;
        int depthLeft = _GetDepth(root->leftChild);
        int depthRight = _GetDepth(root->rightChild);
        return depthLeft > depthRight ? depthLeft + 1 : depthRight + 1;
    }

    int GetDepth()
    {
        return _GetDepth(root);
    }

    void PrintTree()
    {
        LevelTraverse([](TNode *&e) { cout << e->data; }, []() { cout << '#'; });
    }

  private:
    TNode *root;
};

int
main()
{
    BiTree t;
    t.SwapSubTree();
    t.PrintTree();
    cout << t.GetDepth();
}