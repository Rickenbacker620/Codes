#include <iomanip>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

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
        return (rand() * rand()) % 999;
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

void runsort(vector<int> &nums, void (*mysort)(vector<int> &))
{
    cout << endl;
    shuffle(nums);
    cout << "before:" << endl;
    show(nums);

    mysort(nums);

    cout << "after:" << endl;
    show(nums);

    if (check(nums))
        cout << "sorted!" << endl;
    else
        cout << "unsorted" << endl;
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

void qsubsort(vector<int> &nums, int lo, int hi)
{
    if (lo >= hi)
        return;

    int i = lo - 1, j = hi + 1, x = nums[lo + hi >> 1];
    while (i < j)
    {
        do
            i++;
        while (nums[i] < x);
        do
            j--;
        while (nums[j] > x);
        if (i < j)
            swap(nums[i], nums[j]);
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

vector<int> a(30);

int main()
{
    int op;
    while (1)
    {
        cout << "please choose a sorting method:" << endl
             << "1)bubble sort" << endl
             << "2)selection sort" << endl
             << "3)insertion sort" << endl
             << "4)quick sort" << endl
             << "===============================" << endl;
        cin >> op;
        switch (op)
        {
        case 1:
            runsort(a, bubble);
            break;
        case 2:
            runsort(a, selection);
            break;
        case 3:
            runsort(a, insertion);
            break;
        case 4:
            runsort(a, quicksort);
            break;

        default:
            break;
        }
    }
    system("pause");
    return 0;
}