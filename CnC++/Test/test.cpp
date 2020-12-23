// #include <iostream>
// using namespace std;
// int arr[100001];
// void quick(int q[], int l, int r)
// {
//     if (l >=r)
//         return;
//     int i = l-1, j = r+1, x = q[l+(r-l)/2];
//     while (i < j)
//     {
//         do i++; while (q[i] < x);
//         do j--; while (q[j] > x);
//         if (i < j) swap(q[i], q[j]);
//     }
//     quick(q, l, j);
//     quick(q, j+1, r);
// }
// int main()
// {
//     int n;
//     cin >> n;
//     for (int i = 0; i < n; i++)
//         cin >> arr[i];
//     quick(arr, 0, n-1);
//     for (int i = 0; i < n; i++)
//         cout << arr[i] << ' ';
// }

//8,1,3,2,5,7,3,4

// #include <iostream>
// using namespace std;
// const int N = 1e5 + 10;
// int n;
// int a[N];
// int t[N];
// void merge(int a[], int l, int r)
// {
//     if (l >= r)
//         return;
//     int mid = l+(r-l)/2;
//     merge(a, l, mid);
//     merge(a, mid+1, r);
//     int k = 0, i = l, j = mid+1;
//     while (i <= mid && j <= r)
//         if (a[i] <= a[j])
//             t[k++] = a[i++];
//         else
//             t[k++] = a[j++];
//     while (i <= mid) t[k++] = a[i++];
//     while (j <= r) t[k++] = a[j++];
//     for (i = l, j = 0; i <= r; i++, j++)
//         a[i] = t[j];
// }
// int main()
// {
//     cin >> n;
//     for (int i = 0; i < n; i++){
//         cin >> a[i];
//     }
//     merge(a, 0, n-1);
//     for (int i = 0; i < n; i++)
//         cout << a[i] << ' ';
// }

// #include <iostream>
// using namespace std;

// int key = 1;

// int find(int a[], int l, int r)
// {
//     int mid = (l+r)/2;
//     if (l > r)
//         return -1;
//     if (a[mid] == key)
//         return mid;
//     if (a[mid] < key)
//         return find(a, mid+1, r);
//     else if (a[mid] > key)
//         return find(a, l, mid-1);
// }

template <typename T>
class tt
{
private:
    T a = 0;

public:
    tt() {}
    void show(T b)
    {
        c = a + b;
    }
};

int main()
{
    tt<int> a;
    a.show(10);
    for (int i = 1; i < 10; i++)
    {
    }
    // int arr[10] = {1,20,33,43,54,65,77,88,100,122};
    // int c = find(arr, 0, 9);
    // cout << c;
}