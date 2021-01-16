#include <iostream>
#include <map>
#include <string>
#include <list>
#include <vector>
using namespace std;

using mymap = multimap<string, int>;

void
bubble(vector<int> &nums)
{
    int len = nums.size();
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
            if (auto &&[pre, next] = make_pair(nums[j], nums[j + 1]); pre >= next)
                swap(pre, next);
        for (auto i : nums)
            cout << i << '|';
        cout << endl;
    }
}

int
main()
{
    vector<int> a{56, 39, 66, 98, 77, 139, 28, 50};
    bubble(a);
    return 0;
}