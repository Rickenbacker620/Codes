#include <cstring>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <queue>

using namespace std;
const int N = 100010;

struct ChildNode
{
    ChildNode(int adjvex)
    {
        this->adjvex = adjvex;
    }
    int adjvex;
    struct ChildNode *next;
};

struct VertexNode
{
    int indegree;
    int vertex;
    ChildNode *firstarc;
};

int n, m;
int ans[N];
queue<int> q;
int counter = 0;
VertexNode ver[20];

void add(int a, int b)
{
    ChildNode *t = new ChildNode(b);
    t->next = ver[a].firstarc;
    ver[a].firstarc = t;
}

bool topsort()
{
    for (int i = 1; i <= n; i++)
        if (!ver[i].indegree)
        {
            q.push(i);
            ans[counter++] = i;
        }
    while (q.size())
    {
        int t = q.front();
        q.pop();
        for (ChildNode *i = ver[t].firstarc; i != nullptr; i = i->next)
        {
            int j = i->adjvex;
            ver[j].indegree--;
            if (ver[j].indegree == 0)
            {
                q.push(j);
                ans[counter++] = j;
            }
        }
    }
    return counter == n;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i <= n; i++)
    {
        ver[i].firstarc = nullptr;
        ver[i].vertex = i;
        ver[i].indegree = 0;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
        ver[b].indegree++;
    }
    if (!topsort())
        puts("cannot be sorted");
    else
    {
        for (int i = 0; i < n; i++)
            cout << ans[i] << ' ';
    }
    cout << endl;
    system("pause");
    return 0;
}

/*
3 3
1 2
2 3
1 3
*/