#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CLOCKS_PER_SEC ((clock_t)1000)
#define N 25000 //随机生成20000个测试数据

#define MAXSIZE 100000 //用于要排序数组个数最大值
typedef struct
{
    int r[MAXSIZE + 1]; //用于存储要排序数组，r[0]用作哨兵或临时变量
    int length;         //用于记录顺序表的长度
} SqList;

//交换L中数组r的下标为i和j的值
void
swap(SqList *L, int i, int j)
{
    int temp = L->r[i];
    L->r[i] = L->r[j];
    L->r[j] = temp;
}

void
BubbleSort(SqList *L) //冒泡排序
{
    int i, j;
    for (i = 1; i < L->length; i++)
    {
        for (j = L->length - 1; j >= i; j--) // j是从后往前循环
        {
            if (L->r[j] > L->r[j + 1]) //若前者大于后者
            {
                swap(L, j, j + 1); //交换L->r[j]与L->r[j+1]的值
            }
        }
    }
}

void
SelectSort(SqList *L) //选择排序
{
    int i, j, min;

    for (i = 1; i < L->length; i++)
    {
        min = i;
        for (j = i + 1; j <= L->length; j++)
        {
            if (L->r[min] > L->r[j]) //如果有小于当前最小值的关键字
            {
                min = j; //将此关键字的下标赋值给min
            }
        }
        if (i != min) //若min不等于i，说明找到最小值，交换
        {
            swap(L, i, min); //交换
        }
    }
}

void
InsertSort(SqList *L) //直接插入排序（从后向前查找位置）
{
    int i, j;
    for (i = 2; i <= L->length; i++)
    {
        if (L->r[i] < L->r[i - 1])
        {
            L->r[0] = L->r[i]; //设置哨兵
            for (j = i - 1; L->r[j] > L->r[0]; j--)
            {
                L->r[j + 1] = L->r[j]; //大于待排序记录 后移
            }
            L->r[j + 1] = L->r[0]; //插入到正确位置
        }
    }
}

void
InsertSortTwo(SqList *L) //二分插入排序
{
    int low, high, mid;
    int i, j;
    int n = L->length;
    for (i = 2; i <= n; i++)
    {
        L->r[0] = L->r[i];
        low = 1;
        high = i - 1;
        while (low <= high)
        {
            mid = (low + high) / 2;  //找到中间元素
            if (L->r[mid] > L->r[0]) //中间元素比当前元素大 当前元素插到中间元素左边
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        for (j = i - 1; j >= high + 1; j--)
        {
            L->r[j + 1] = L->r[j]; //找到当前元素的插入位置后，后移插入
        }
        L->r[high + 1] = L->r[0];
    }
}

//交换顺序表L中子表的记录，使枢轴记录到位，并返回其所在位置
//此时在它之前(后)的记录均不大(小)于它
int
Partition(SqList *L, int low, int high)
{
    int pivotkey;

    pivotkey = L->r[low]; //用子表的第一个记录作枢轴记录
    while (low < high)    //从表的两端交替地向中间扫描
    {
        while (low < high && L->r[high] >= pivotkey)
        {
            high--;
        }
        swap(L, low, high); //将比枢轴记录小的记录交换到低端
        while (low < high && L->r[low] <= pivotkey)
        {
            low++;
        }
        swap(L, low, high); //将比枢轴记录大的记录交换到高端
    }
    return low; //返回枢轴所在位置
}

void
QSort(SqList *L, int low, int high) //对子序列快速排序
{
    int pivot;
    if (low < high)
    {
        pivot = Partition(L, low, high); //将L->r[low..high]一分为二，算出枢轴值pivot
        QSort(L, low, pivot - 1);        //对低子表递归排序
        QSort(L, pivot + 1, high);       //对高子表递归排序
    }
}

void
QuickSort(SqList *L) //快速排序
{
    QSort(L, 1, L->length);
}

void
sift(SqList *L, int i, int m)
{
    L->r[0] = L->r[i];
    int j;
    for (j = 2 * i; j <= m; j *= 2)
    {
        if (j < m && L->r[j] < L->r[j + 1])
            j++;
        //从两个孩子结点中选择一个较大的
        if (L->r[0] < L->r[j])
        {
            L->r[i] = L->r[j];
            i = j; //以当前的j为起点再继续
        }
        else
            break;
    }
    L->r[i] = L->r[0];
}

void
HeapSort(SqList *L) //堆排序
{
    int i;
    int n = N;
    int temp;

    for (i = n / 2; i >= 1; i--) //（1）循环建立初始堆
        sift(L, i, n);

    for (i = n; i >= 2; i--) //(2)进行n-1次循环,完成推排序
    {
        temp = L->r[1]; //将第一个元素同当前区间内R[1]对换
        L->r[1] = L->r[i];
        L->r[i] = temp;
        sift(L, 1, i - 1); //筛选R[1]结点,得到i-1个结点的堆
    }
}

void
Merge(SqList *L, int low, int mid, int high)
{
    int len = high - low + 1;
    int *temp = new int[len];
    int i = low, j = mid + 1; // i，j分别为两个子序列的游标
    int k = 0;                //为新合并序列的游标
    while (i <= mid && j <= high)
    {
        if (L->r[i] <= L->r[j])
        {
            temp[k] = L->r[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = L->r[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    { //若第一个子序列有剩余，则直接接到尾部
        temp[k] = L->r[i];
        k++;
        i++;
    }
    while (j <= high)
    { //若第二个子序列有剩余，则直接接到尾部
        temp[k] = L->r[j];
        k++;
        j++;
    }
    // copy到a[]
    for (k = 0; k < len; k++)
        L->r[low + k] = temp[k]; //将排序好的temp放入L
}

// low high为待排序列左右边界
void
Mergepess(SqList *L, int low, int high)
{

    if (low < high)
    {
        int mid = (low + high) / 2;
        Mergepess(L, low, mid); //递归的划分左右两个子序列
        Mergepess(L, mid + 1, high);

        Merge(L, low, mid, high); //合并
    }
}

void
MergeSort(SqList *L)
{
    Mergepess(L, 1, L->length);
}

int data[N];
SqList L1, L2, L3, L4, L5, L6, L7; // 七个序列，一种排序一个

int
main()
{
    int i;
    clock_t start_time, end_time;
    double work_time;

    srand((int)time(0)); //以当前时间对应的int值为随机序列起点
    for (i = 0; i < N; i++)
    {
        data[i] = rand() % N; //随机数
    }

    for (i = 0; i < N; i++)
    {
        L1.r[i + 1] = data[i];
    }
    L1.length = N;                    //序列的长度为2000,有两千个元素
    L2 = L3 = L4 = L5 = L6 = L7 = L1; //相同
    printf("***********七种排序运行时间比较***********\n");
    printf("        随机生成 %d 个测试数据\n", N);
    printf("\n");

    start_time = clock(); //获取程序开始运算时间
    printf("冒泡排序     ");
    BubbleSort(&L1);
    end_time = clock();                                           //获取程序结束运算时间
    work_time = (double)(end_time - start_time) / CLOCKS_PER_SEC; //计算程序运算时间，转化为秒
    printf("运行时间 %.4f 秒 \n", work_time);
    printf("\n");

    start_time = clock();
    printf("直接插入排序 ");
    InsertSort(&L2);
    end_time = clock();
    work_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("运行时间 %.4f 秒 \n", work_time);
    printf("\n");

    start_time = clock();
    printf("二分插入排序 ");
    InsertSortTwo(&L3);
    end_time = clock();
    work_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("运行时间 %.4f 秒 \n", work_time);
    printf("\n");

    start_time = clock();
    printf("选择排序     ");
    SelectSort(&L4);
    end_time = clock();
    work_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("运行时间 %.4f 秒 \n", work_time);
    printf("\n");

    start_time = clock();
    printf("快速排序     ");
    QuickSort(&L5);
    end_time = clock();
    work_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("运行时间 %.4f 秒 \n", work_time);
    printf("\n");

    start_time = clock();
    printf("堆排序     ");
    HeapSort(&L6);
    end_time = clock();
    work_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("  运行时间 %.4f 秒 \n", work_time);
    printf("\n");

    start_time = clock();
    printf("归并排序     ");
    MergeSort(&L7);
    end_time = clock();
    work_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("运行时间 %.4f 秒 \n", work_time);
    printf("\n");

    system("pause");

    return 0;
}
