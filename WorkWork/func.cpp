#define DEBUG 1
#if DEBUG
#define cin input
#define FILEOPEN ifstream input("input.dat");
#define SEP cout << endl \
								 << "-------------------------------------";
#define LOG(x) cout << #x << " = " << x
#define FORM(k, n, m)                  \
	for (int i = 0; i <= 2 * m + 2; i++) \
		cout << '+';                       \
	cout << endl;                        \
	for (int i = 0; i <= n; i++)         \
	{                                    \
		cout << '|';                       \
		for (int j = 0; j <= m; j++)       \
			cout << k[i][j] << '|';          \
		cout << endl;                      \
	}                                    \
	for (int i = 0; i <= 2 * m + 2; i++) \
		cout << '+';
#else
#define cin cin
#define FILEOPEN
#endif

//https://www.luogu.com.cn/problem/P4447

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

const int N = 1e6+10;
int a[N];
int n;

bool check(int mid)
{

}

int main()
{
	FILEOPEN
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a+n);
	for (int i = 0; i < n; i++)
	{
		cout << a[i];
	}
	int l = 1, r = n;
	while (l < r)
	{
		int mid = l+r+1>>1;
		if (check(mid))
			l = mid;
		else
			r = mid-1;
	}

	return 0;
}