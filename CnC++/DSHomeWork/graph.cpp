#include <iostream>
#include <cstring>
#include <algorithm>
#define INF 0x3f
using namespace std;

struct Info
{
    int dist;
    int point;
};
const int N = 100;
int g[N][N];
Info infos[N];
bool st[N];
int n, m;
int res;

int Prim()
{
    for (int i = 0; i < n; i++)
    {
        int minpoint = -1;
        for (int j = 1; j <= n; j++)
            if (!st[j] && (minpoint == -1 || infos[minpoint].dist > infos[j].dist))
                minpoint = j;
        if (infos[minpoint].point != minpoint)
            cout << "from " << infos[minpoint].point << " to " << minpoint << ", weight:" << infos[minpoint].dist << endl;

        st[minpoint] = true;

        if (i != 0 && infos[minpoint].dist == INF)
            return INF;

        if (i != 0)
            res += infos[minpoint].dist;

        for (int j = 1; j <= n; j++)
        {
            if (!st[j] && infos[j].dist >= g[minpoint][j])
            {
                infos[j].dist = g[minpoint][j];
                infos[j].point = minpoint;
            }
        }
    }
    return res;
}

int main()
{
    cin >> n >> m;
    int a, b, c;
    for (int i = 1; i <= n; i++)
    {
        infos[i].dist = INF;
        infos[i].point = i;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i == j)
                g[i][j] = 0;
            else
                g[i][j] = INF;
    while (m--)
    {
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = c;
    }

    int t = Prim();
    if (t == INF)
        cout << "impossible";
    else
        cout << "tree size:" << t << endl;
    system("pause");
}