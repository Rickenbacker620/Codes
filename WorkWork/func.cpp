#define DEBUG 1
#if DEBUG
#define cin input
#define FILEOPEN ifstream input("input.dat");
#define SEP cout << endl << "-------------------------------------";
#define LOG(x) cout << #x << " = " << x
#define FORM(k, n, m)                                                                                                  \
    for (int i = 0; i <= 2 * m + 2; i++)                                                                               \
        cout << '+';                                                                                                   \
    cout << endl;                                                                                                      \
    for (int i = 0; i <= n; i++)                                                                                       \
    {                                                                                                                  \
        cout << '|';                                                                                                   \
        for (int j = 0; j <= m; j++)                                                                                   \
            cout << k[i][j] << '|';                                                                                    \
        cout << endl;                                                                                                  \
    }                                                                                                                  \
    for (int i = 0; i <= 2 * m + 2; i++)                                                                               \
        cout << '+';
#else
#define cin cin
#define FILEOPEN
#endif

// https://www.luogu.com.cn/problem/P4447

#include <fstream>
#include <iostream>
using namespace std;

const int N = 10e5 + 10;
int col[N], x[N], y[N], n;
bool used[N];

void
dfs(int j)
{
    for (int i = 0; i < n; i++)
    {
        if (true)
        {
            col[i] = j;
            dfs(j + 1);
        }
    }
}

int
main()
{
    FILEOPEN
    cin >> n;
    dfs(0);
    return 0;
}
