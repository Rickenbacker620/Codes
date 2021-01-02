#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e2;
int dist[N];
bool st[N];
int g[N][N];
int n, m;

int
Djistra(int source, int destination)
{
    memset(dist, 0x3f, sizeof(dist));
    dist[source] = 0;

    for (int i = 0; i < n; i++)
    {
        int t = -1;
        for (int j = 0; j <= n; j++)
            if (!st[j] && (t == -1 || dist[j] < dist[t]))
            {
                t = j;
            }
        cout << t << endl;

        for (int j = 0; j <= n; j++)
            dist[j] = min(dist[j], dist[t] + g[t][j]);

        st[t] = true;
    }
    if (dist[destination] == 0x3f3f3f3f)
        return -1;
    return dist[destination];
}

int
main()
{
    cin >> n >> m;
    memset(g, 0x3f, sizeof(g));
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c);
    }
    cout << Djistra(1, n);
}

/*

5 10
1 2 2
5 3 3
4 1 8
2 4 3
4 5 7
5 2 3
3 4 1
1 2 9
3 2 3
1 2 8

*/