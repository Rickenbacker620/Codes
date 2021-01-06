#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
#define INF 0x3f3f3f3f

const int N = 1e2;
int graph[N][N];
int n, m;

struct Park
{
    int distance;
    int prevPark;
    bool visited;
};

Park parks[N];

void
DeletePath(int x, int y)
{
    if (graph[x][y] == INF)
    {
        cout << "No path to delete !" << endl;
        return;
    }
    graph[x][y] = INF;
    graph[y][x] = INF;
}

void
ModifyPath()
{
    int x, y, value;
    cout << "please input the two vertex and the distance" << endl;
    cin >> x >> y >> value;
    if (x > n || y > n)
        cout << "invalid vertex!" << endl;
    graph[x][y] = graph[y][x] = value;
    cout << x << "---" << y << "distance : " << graph[x][y] << endl;
}

void
SearchDistance(int x, int y)
{
    for (int i = 0; i <= n; i++)
    {
        parks[i].distance = INF;
        parks[i].prevPark = i;
        parks[i].visited = false;
    }
    parks[x].distance = 0;

    for (int i = 0; i < n; i++)
    {
        int t = -1;
        for (int j = 0; j <= n; j++)
            if (!parks[j].visited && (t == -1 || parks[j].distance < parks[t].distance))
                t = j;

        for (int j = 0; j <= n; j++)
        {
            if (parks[t].distance + graph[t][j] < parks[j].distance)
            {
                parks[j].distance = parks[t].distance + graph[t][j];
                parks[j].prevPark = t;
            }
        }

        parks[t].visited = true;
    }

    if (y != -1)
    {
        if (parks[y].distance == 0x3f3f3f3f)
        {
            cout << "no connected!" << endl;
            return;
        }
        cout << "path : ";
        for (int i = y; i != parks[i].prevPark; i = parks[i].prevPark)
            cout << i << "->";
        cout << x << endl;
        cout << "distance : " << parks[y].distance << endl;
    }
    if (y == -1)
    {
        for (int i = 0; i <= n; i++)
        {
            if (i == x || parks[i].distance == 0x3f3f3f3f)
                continue;

            cout << "path : ";
            for (int j = i; j != parks[j].prevPark; j = parks[j].prevPark)
                cout << j << "---";
            cout << x << endl;

            cout << "distance : " << parks[i].distance << endl;
        }
    }
}

void
ShowPathInfo()
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (graph[i][j] != INF)
                cout << i << "---" << j << "distance : " << graph[i][j] << endl;
        }
    }
}

void
ShowParkInfo()
{
    for (int i = 1; i <= n; i++)
        cout << i;
    cout << endl;
}

int
main()
{
    cin >> n >> m;
    memset(graph, 0x3f, sizeof(graph));
    while (m--)
    {
        int x, y, value;
        cin >> x >> y >> value;
        graph[x][y] = graph[y][x] = value;
    }

    bool exitFlag = false;
    while (!exitFlag)
    {
        int x, y, op;
        cout << "Choose operation: " << endl
             << "1) Show parks information" << endl
             << "2) Show paths information" << endl
             << "3) Modify path" << endl
             << "4) Search shortest path" << endl
             << "5) Delete edge" << endl
             << "6) exit" << endl;
        cin >> op;
        switch (op)
        {
        case 1:
            ShowParkInfo();
            break;
        case 2:
            ShowPathInfo();
            break;
        case 3:
            ModifyPath();
            break;
        case 4:
            cout << "please input the query parks : " << endl;
            cin >> x >> y;
            SearchDistance(x, y);
            break;
        case 5:
            cout << "please input the edge you want to delete : " << endl;
            cin >> x >> y;
            DeletePath(x, y);
            break;
        case 6:
            exitFlag = true;
            break;
        }
    }
}

/*

5 8
1 2 2
5 3 3
4 1 8
2 4 3
4 5 7
5 2 3
3 4 1
3 2 3

*/