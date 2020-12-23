#include <iomanip>
#include "utils.h"
#include "timer.h"
using namespace std;

void runsort(vector<int> &nums, void (*mysort)(vector<int> &))
{
    cout << endl;
    if (nums.size() > 20)
        shuffle(nums);
    {
        Timer time;
        mysort(nums);
    }
    if (nums.size() < 200)
        show(nums);
    if (check(nums))
        cout << "sorted!!!!!!!!!!!" << endl;
    else
        cout << "unsorted:-(" << endl;
    cout << "-------------------------" << endl;
    cout << endl;
}

///////////////////////////////////////////////////////////////////////////////////

void bubble(vector<int> &nums)
{
    cout << "bubble:" << endl;
    int len = nums.size();
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (nums[j] > nums[j + 1])
                swap(nums[j], nums[j + 1]);
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////

void selection(vector<int> &nums)
{
    cout << "selection" << endl;
    int count = 0;
    int len = nums.size();
    for (int i = 0; i < len - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < len; j++)
        {
            if (nums[min] > nums[j])
                min = j;
        }
        swap(nums[i], nums[min]);
    }
}

///////////////////////////////////////////////////////////////////////////////////

void insertion(vector<int> &nums)
{
    cout << "insertion:" << endl;
    int len = nums.size();
    int j, key;
    for (int i = 1; i < len; i++)
    {
        key = nums[i];
        for (j = i; j > 0 && nums[j - 1] > key; j--)
            nums[j] = nums[j - 1];
        nums[j] = key;
    }
}

///////////////////////////////////////////////////////////////////////////////////

void shell(vector<int> &nums)
{
    cout << "shell:" << endl;
    int len = nums.size();
    int h = 1;
    while (h < len / 3)
        h = 3 * h + 1;
    while (h >= 1)
    {
        for (int i = h; i < len; i++)
        {
            for (int j = i; j >= h && nums[j - h] > nums[j]; j -= h)
                swap(nums[j], nums[j - h]);
        }
        h = h / 3;
    }
}

///////////////////////////////////////////////////////////////////////////////////

void merge(vector<int> &nums, vector<int> &temp, int lo, int mid, int hi)
{
    if (temp[mid] <= temp[mid + 1])
    {
        for (int k = lo; k <= hi; k++)
            nums[k] = temp[k];
        return;
    }
    int i = lo, j = mid + 1;
    for (int k = lo; k <= hi; k++)
        if (i > mid)
            nums[k] = temp[j++];
        else if (j > hi)
            nums[k] = temp[i++];
        else if (temp[i] <= temp[j])
            nums[k] = temp[i++];
        else if (temp[j] < temp[i])
            nums[k] = temp[j++];
}

void msubsort(vector<int> &nums, vector<int> &temp, int lo, int hi)
{
    if (lo >= hi)
        return;
    int mid = lo + (hi - lo) / 2;
    msubsort(temp, nums, lo, mid);
    msubsort(temp, nums, mid + 1, hi);
    merge(nums, temp, lo, mid, hi);
}

void mergesort(vector<int> &nums)
{
    vector<int> temp = nums;
    msubsort(nums, temp, 0, nums.size() - 1);
}

///////////////////////////////////////////////////////////////////////////////////

void qsubsort(vector<int> &nums, int lo, int hi)
{
    if (lo >= hi) return;

    int i = lo - 1, j = hi + 1, x = nums[lo + hi >> 1];
    while (i < j)
    {
        do i ++ ; while (nums[i] < x);
        do j -- ; while (nums[j] > x);
        if (i < j) swap(nums[i], nums[j]);
    }
    qsubsort(nums, lo, j);
    qsubsort(nums, j + 1, hi);
}

void quicksort(vector<int> &nums)
{
    int lo = 0, hi = nums.size() - 1;
    qsubsort(nums, lo, hi);
}

///////////////////////////////////////////////////////////////////////////////////

vector<int> a(1000000);
vector<int> b = {4, 4};
vector<int> temp = {4, 5, 6, 7, 1, 2, 4, 5};
vector<int> c = {1, 3, 5, 2, 12, 3, 4, 34, 123, 4, 32, 823, 78423, 1, 23, 4, 5, 9, 7, 8, 6, 3, 8, 0};

int main()
{
    runsort(c, quicksort);
    return 0;
}