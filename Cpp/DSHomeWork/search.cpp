#include <iostream>
using namespace std;
#define N 9
int a[N] = {1, 22, 44, 67, 89, 101, 202, 430, 560};

int recur(int a[], int key, int l, int r)
{
    if (l > r)
        return -1;
    int mid = (l + r) / 2;
    if (a[mid] == key)
        return mid;
    else if (a[mid] < key)
        return recur(a, key, mid + 1, r);
    else
        return recur(a, key, l, mid - 1);
}

int norecur(int a[], int key)
{
    int l = 0, r = N - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (a[mid] == key)
            return mid;
        else if (key > a[mid])
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

int normal(int a[], int key)
{
    for (int i = 0; i < N - 1; i++)
        if (a[i] == key)
            return i;
    return -1;
}

int main()
{
    cout << "array:" << endl;
    for (int i = 0; i < N; i++)
        cout << a[i] << ' ';
    cout << endl;
    while (1)
    {
        int op, k, ans;
        cout << "--------------------------------------------" << endl;
        cout << "input the number you want to search:" << endl;
        cin >> k;
        cout << "choose mode (1.recursive, 2.norecursive, 3.normal)" << endl;
        cin >> op;
        if (op == 1)
        {
            cout << endl
                 << "recursive binary search" << endl;
            ans = recur(a, k, 0, N - 1);
        }
        else if (op == 2)
        {
            cout << endl
                 << "norecursive binary search" << endl;
            ans = norecur(a, k);
        }
        else if (op == 3)
        {
            cout << endl
                 << "normal search" << endl;
            ans = normal(a, k);
        }
        else
            continue;
        if (ans == -1)
            cout << "not found!" << endl;
        else
            cout << "found key in index" << ans << endl;
    }
    system("pause");
    return 0;
}