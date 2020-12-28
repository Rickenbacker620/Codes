#include <iomanip>
#include "utils.h"
#include "timer.h"
using namespace std;

void runsort(vector<Unit> &nums, void (*mysort)(vector<Unit> &))
{
    cout << endl;
    if (nums.size() > 20)
        shuffle(nums);
    cout << "initial order:" << endl;
    show(nums);
    {
        Timer time;
        mysort(nums);
    }
    if (nums.size() < 200)
        show(nums);
    if (check_sort(nums))
        cout << "sorted!" << endl;
    else
        cout << "unsorted:-(" << endl;
    if (check_stable(nums))
        cout << "stable" << endl;
    else
        cout << "not stable" << endl;
    cout << "-------------------------" << endl;
    cout << endl;
}

///////////////////////////////////////////////////////////////////////////////////

void bubble(vector<Unit> &nums)
{
    cout << "bubble:" << endl;
    int len = nums.size();
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (nums[j].data > nums[j + 1].data)
                swap(nums[j], nums[j + 1]);
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////

void selection(vector<Unit> &nums)
{
    cout << "selection sort" << endl;
    int count = 0;
    int len = nums.size();
    for (int i = 0; i < len - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < len; j++)
        {
            if (nums[min].data >= nums[j].data)
                min = j;
        }
        swap(nums[i], nums[min]);
    }
}

///////////////////////////////////////////////////////////////////////////////////

void insertion(vector<Unit> &nums)
{
    cout << "insertion sort:" << endl;
    int len = nums.size();
    int j;
    Unit key;
    for (int i = 1; i < len; i++)
    {
        key = nums[i];
        for (j = i; j > 0 && nums[j - 1].data > key.data; j--)
            nums[j] = nums[j - 1];
        nums[j] = key;
    }
}

///////////////////////////////////////////////////////////////////////////////////

void shell(vector<Unit> &nums)
{
    cout << "shell sort:" << endl;
    int len = nums.size();
    int h = 1;
    while (h < len / 3)
        h = 3 * h + 1;
    while (h >= 1)
    {
        for (int i = h; i < len; i++)
        {
            for (int j = i; j >= h && nums[j - h].data > nums[j].data; j -= h)
                swap(nums[j], nums[j - h]);
        }
        h = h / 3;
    }
}

///////////////////////////////////////////////////////////////////////////////////

void merge(vector<Unit> &nums, vector<Unit> &temp, int lo, int mid, int hi)
{
    if (temp[mid].data <= temp[mid + 1].data)
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
        else if (temp[i].data <= temp[j].data)
            nums[k] = temp[i++];
        else if (temp[j].data < temp[i].data)
            nums[k] = temp[j++];
}

void msubsort(vector<Unit> &nums, vector<Unit> &temp, int lo, int hi)
{
    if (lo >= hi)
        return;
    int mid = lo + (hi - lo) / 2;
    msubsort(temp, nums, lo, mid);
    msubsort(temp, nums, mid + 1, hi);
    merge(nums, temp, lo, mid, hi);
}

void mergesort(vector<Unit> &nums)
{
    cout << "merge sort:" << endl;
    vector<Unit> temp = nums;
    msubsort(nums, temp, 0, nums.size() - 1);
}

///////////////////////////////////////////////////////////////////////////////////

void qsubsort(vector<Unit> &nums, int lo, int hi)
{
    if (lo >= hi)
        return;

    int i = lo - 1, j = hi + 1;
    Unit x = nums[lo + hi >> 1];
    while (i < j)
    {
        do
            i++;
        while (nums[i].data < x.data);
        do
            j--;
        while (nums[j].data > x.data);
        if (i < j)
            swap(nums[i], nums[j]);
    }
    qsubsort(nums, lo, j);
    qsubsort(nums, j + 1, hi);
}

void quicksort(vector<Unit> &nums)
{
    cout << "quick sort:" << endl;
    int lo = 0, hi = nums.size() - 1;
    qsubsort(nums, lo, hi);
}

///////////////////////////////////////////////////////////////////////////////////

vector<Unit> a(100);

int main()
{
    srand(1);
    runsort(a, selection);
    srand(2);
    runsort(a, quicksort);
    return 0;
}