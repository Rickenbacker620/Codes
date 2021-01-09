#include "utils.h"

void swap(Unit &a, Unit &b)
{
    Unit temp;
    temp = a;
    a = b;
    b = temp;
}

void shuffle(vector<Unit> &a)
{
    int i = 0;
    generate(a.begin(), a.end(), [&i]() {
        int rnum = (rand() * rand()) % 999;
        if (i % 30 == 0)
            rnum = 10;
        return Unit{rnum, ++i};
    });
}

bool check_sort(vector<Unit> &nums)
{
    for (int i = 0; i < nums.size() - 1; i++)
        if (nums[i].data > nums[i + 1].data)
            return false;
    return true;
}

bool check_stable(vector<Unit> &nums)
{
    int t = -1;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i].data == 10)
        {
            if (nums[i].mark < t)
                return false;
            t = nums[i].mark;
        }
    }
    return true;
}

void show(vector<Unit> &nums)
{
    for (auto i : nums)
        cout << i.data << '|';
    cout << endl;
}