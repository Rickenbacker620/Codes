#include "utils.h"

void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void shuffle(vector<int> &a)
{
    srand(time(0));
    generate(a.begin(), a.end(), []() {
        return (rand() * rand()) % 999999;
    });
}

bool check(vector<int> &nums)
{
    for (int i = 0; i < nums.size() - 1; i++)
        if (nums[i] > nums[i + 1])
            return false;
    return true;
}

void show(vector<int> &nums)
{
    for (auto i : nums)
        cout << i << '|';
    cout << endl;
}