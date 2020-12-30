#include <iostream>
using namespace std;

int main()
{
    int a[2][2] = {{1, 2}, {3, 4}};
    auto p = &a;
    for (int i = 0; i < 2; i++)
        cout << **p++ << endl;
    return 0;
}