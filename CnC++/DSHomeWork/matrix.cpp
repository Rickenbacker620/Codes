#define DEBUG 0
#if DEBUG
#define cin input
#define FILEOPEN ifstream input("input.dat");
#define SEP cout << endl \
                 << "-------------------------------------";
#define LOG(x) cout << #x << " = " << x
#define FORM(k, n, m)                    \
    for (int i = 0; i <= 2 * m + 2; i++) \
        cout << '+';                     \
    cout << endl;                        \
    for (int i = 0; i <= n; i++)         \
    {                                    \
        cout << '|';                     \
        for (int j = 0; j <= m; j++)     \
            cout << k[i][j] << '|';      \
        cout << endl;                    \
    }                                    \
    for (int i = 0; i <= 2 * m + 2; i++) \
        cout << '+';
#else
#define cin cin
#define FILEOPEN
#endif

#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>
#include <Windows.h>
#define MAX_SIZE 100
#define MAX_ROW 10
using namespace std;

int gr(int l, int r)
{
    return rand() % (r - l + 1) + l;
}

template <typename T>
struct Triple
{
    int row, col;
    T e;
};

class Matrix
{
public:
    Matrix();
    Matrix operator+(Matrix &M);
    Matrix operator*(Matrix &M);

    template <typename T>
    int getPos(Triple<T> t)
    {
        return n * (t.row - 1) + t.col;
    }
    void printM();
    void inputM();

private:
    Triple<int> data[MAX_SIZE + 1];
    int position[MAX_ROW + 1];
    int m, n, len;
};

Matrix::Matrix()
{
    memset(position, 0, sizeof(position));
}

Matrix Matrix::operator*(Matrix &X)
{
    Matrix Y;
    Y.m = m;
    Y.n = X.n;
    Y.len = 0;
    int ctemp[MAX_ROW + 1];
    for (int arow = 1; arow <= m; arow++)
    {
        memset(ctemp, 0, sizeof(ctemp));
        Y.position[arow] = Y.len + 1;
        int aend = (arow < m) ? (position[arow + 1]) : (len + 1);
        for (int p = position[arow]; p < aend; p++)
        {
            int brow = data[p].col;
            int bend = (brow < X.m) ? (X.position[brow + 1]) : (X.len + 1);
            for (int q = X.position[brow]; q < bend; q++)
            {
                int ccol = X.data[q].col;
                ctemp[ccol] += data[p].e * X.data[q].e;
            }
        }
        for (int ccol = 1; ccol <= Y.n; ccol++)
        {
            if (ctemp[ccol] != 0)
            {
                Y.len++;
                Y.data[Y.len].row = arow;
                Y.data[Y.len].col = ccol;
                Y.data[Y.len].e = ctemp[ccol];
            }
        }
    }
    return Y;
}

Matrix Matrix::operator+(Matrix &M)
{
    Matrix C;
    C.m = m;
    C.n = n;
    int ca = 1, cb = 1, p = 1;
    while (ca <= len || cb <= M.len)
    {
        auto &a = data[ca], &b = M.data[cb];
        if (getPos(a) < M.getPos(b))
        {
            C.data[p++] = a;
            ca++;
        }
        else if (getPos(a) > getPos(b))
        {
            C.data[p++] = b;
            cb++;
        }
        else
        {
            C.data[p].col = a.col;
            C.data[p].row = a.row;
            C.data[p].e = a.e + b.e;
            p++;
            ca++;
            cb++;
        }
        C.len++;
    }
    if (ca > len)
    {
        auto &b = M.data[cb];
        while (cb <= M.len)
        {
            C.data[p++] = b;
            cb++;
            C.len++;
        }
    }
    else
    {
        auto &a = M.data[ca];
        while (ca <= len)
        {
            C.data[p++] = a;
            ca++;
            C.len++;
        }
    }
    return C;
}

void Matrix::inputM()
{
    int number[MAX_ROW + 1];
    memset(number, 0, sizeof(number));
    cout << "input rows & lines & count of element" << endl;
    cin >> m >> n >> len;
    cout << "input the matrix one line at a time:" << endl;
    cout << " row | col | element " << endl;
    for (int i = 1; i <= len; i++)
    {
        auto &now = data[i];
        cout << "element" << i << ":" << endl;
        cin >> now.row;
        cin >> now.col;
        cin >> now.e;
        number[now.row]++;
    }
    position[1] = 1;
    for (int i = 2; i <= m; i++)
    {
        position[i] = number[i - 1] + position[i - 1];
    }
}

void Matrix::printM()
{
    int p = 1;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (data[p].row == i && data[p].col == j)
            {
                cout << data[p].e << '|';
                p++;
            }
            else
            {
                cout << 0 << '|';
            }
        }
        cout << endl;
    }
}

int main()
{
    Matrix A;
    A.inputM();
    Matrix B;
    B.inputM();
    Matrix C = A+B;
    C.printM();

    system("pause");
    return 0;
}

/*
3 2 6
1 1 1
1 2 2
2 1 3
2 2 4
3 1 5
3 2 6

2 3 6
1 1 1
1 2 2
1 3 3
2 1 4
2 2 5
2 3 6
*/

/*
3 2 6
1 1 1
1 2 2
2 1 3
2 2 4
3 1 5
3 2 6
*/