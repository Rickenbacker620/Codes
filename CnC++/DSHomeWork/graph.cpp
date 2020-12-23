#include <iostream>
#include <cstring>
#include <algorithm>
#define INF 0x3f
using namespace std;

const int N = 100;
int g[N][N];
int dist[N];
bool st[N];
int n ,m;
int res;

int Prim()
{
    int t = -1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 1; j <= n; j++)
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        st[t] = true;

        if (i != 0 && dist[t] == INF)
            return INF;

        if (i != 0)
            res += dist[t];

        for (int j = 1; j <= n; j++)
            dist[j] = min(dist[j],g[t][j]);
    }


}

int main()
{
    cin >> m >> n;
    int a, b, c;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i == j) g[i][j] = 0;
            else g[i][j] = INF;
    while (m--)
    {
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = c;
    }

    int t = Prim();
    if (t == INF)
        cout << "impossible";
    else
        cout << "最小生成树" << t;

}