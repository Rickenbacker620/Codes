#pragma once
#include <ctime>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct Unit
{
    int data;
    int mark;
};

void shuffle(vector<Unit> &a);
void swap(Unit &a, Unit &b);
bool check_sort(vector<Unit> &nums);
bool check_stable(vector<Unit> &nums);
void show(vector<Unit> &nums);
