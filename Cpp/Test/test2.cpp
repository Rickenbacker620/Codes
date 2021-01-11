#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CLOCKS_PER_SEC ((clock_t)1000)
#define N 25000 //�������20000����������

#define MAXSIZE 100000 //����Ҫ��������������ֵ
typedef struct
{
    int r[MAXSIZE + 1]; //���ڴ洢Ҫ�������飬r[0]�����ڱ�����ʱ����
    int length;         //���ڼ�¼˳���ĳ���
} SqList;

//����L������r���±�Ϊi��j��ֵ
void
swap(SqList *L, int i, int j)
{
    int temp = L->r[i];
    L->r[i] = L->r[j];
    L->r[j] = temp;
}

void
BubbleSort(SqList *L) //ð������
{
    int i, j;
    for (i = 1; i < L->length; i++)
    {
        for (j = L->length - 1; j >= i; j--) // j�ǴӺ���ǰѭ��
        {
            if (L->r[j] > L->r[j + 1]) //��ǰ�ߴ��ں���
            {
                swap(L, j, j + 1); //����L->r[j]��L->r[j+1]��ֵ
            }
        }
    }
}

void
SelectSort(SqList *L) //ѡ������
{
    int i, j, min;

    for (i = 1; i < L->length; i++)
    {
        min = i;
        for (j = i + 1; j <= L->length; j++)
        {
            if (L->r[min] > L->r[j]) //�����С�ڵ�ǰ��Сֵ�Ĺؼ���
            {
                min = j; //���˹ؼ��ֵ��±긳ֵ��min
            }
        }
        if (i != min) //��min������i��˵���ҵ���Сֵ������
        {
            swap(L, i, min); //����
        }
    }
}

void
InsertSort(SqList *L) //ֱ�Ӳ������򣨴Ӻ���ǰ����λ�ã�
{
    int i, j;
    for (i = 2; i <= L->length; i++)
    {
        if (L->r[i] < L->r[i - 1])
        {
            L->r[0] = L->r[i]; //�����ڱ�
            for (j = i - 1; L->r[j] > L->r[0]; j--)
            {
                L->r[j + 1] = L->r[j]; //���ڴ������¼ ����
            }
            L->r[j + 1] = L->r[0]; //���뵽��ȷλ��
        }
    }
}

void
InsertSortTwo(SqList *L) //���ֲ�������
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
            mid = (low + high) / 2;  //�ҵ��м�Ԫ��
            if (L->r[mid] > L->r[0]) //�м�Ԫ�رȵ�ǰԪ�ش� ��ǰԪ�ز嵽�м�Ԫ�����
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
            L->r[j + 1] = L->r[j]; //�ҵ���ǰԪ�صĲ���λ�ú󣬺��Ʋ���
        }
        L->r[high + 1] = L->r[0];
    }
}

//����˳���L���ӱ�ļ�¼��ʹ�����¼��λ��������������λ��
//��ʱ����֮ǰ(��)�ļ�¼������(С)����
int
Partition(SqList *L, int low, int high)
{
    int pivotkey;

    pivotkey = L->r[low]; //���ӱ�ĵ�һ����¼�������¼
    while (low < high)    //�ӱ�����˽�������м�ɨ��
    {
        while (low < high && L->r[high] >= pivotkey)
        {
            high--;
        }
        swap(L, low, high); //���������¼С�ļ�¼�������Ͷ�
        while (low < high && L->r[low] <= pivotkey)
        {
            low++;
        }
        swap(L, low, high); //���������¼��ļ�¼�������߶�
    }
    return low; //������������λ��
}

void
QSort(SqList *L, int low, int high) //�������п�������
{
    int pivot;
    if (low < high)
    {
        pivot = Partition(L, low, high); //��L->r[low..high]һ��Ϊ�����������ֵpivot
        QSort(L, low, pivot - 1);        //�Ե��ӱ�ݹ�����
        QSort(L, pivot + 1, high);       //�Ը��ӱ�ݹ�����
    }
}

void
QuickSort(SqList *L) //��������
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
        //���������ӽ����ѡ��һ���ϴ��
        if (L->r[0] < L->r[j])
        {
            L->r[i] = L->r[j];
            i = j; //�Ե�ǰ��jΪ����ټ���
        }
        else
            break;
    }
    L->r[i] = L->r[0];
}

void
HeapSort(SqList *L) //������
{
    int i;
    int n = N;
    int temp;

    for (i = n / 2; i >= 1; i--) //��1��ѭ��������ʼ��
        sift(L, i, n);

    for (i = n; i >= 2; i--) //(2)����n-1��ѭ��,���������
    {
        temp = L->r[1]; //����һ��Ԫ��ͬ��ǰ������R[1]�Ի�
        L->r[1] = L->r[i];
        L->r[i] = temp;
        sift(L, 1, i - 1); //ɸѡR[1]���,�õ�i-1�����Ķ�
    }
}

void
Merge(SqList *L, int low, int mid, int high)
{
    int len = high - low + 1;
    int *temp = new int[len];
    int i = low, j = mid + 1; // i��j�ֱ�Ϊ���������е��α�
    int k = 0;                //Ϊ�ºϲ����е��α�
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
    { //����һ����������ʣ�࣬��ֱ�ӽӵ�β��
        temp[k] = L->r[i];
        k++;
        i++;
    }
    while (j <= high)
    { //���ڶ�����������ʣ�࣬��ֱ�ӽӵ�β��
        temp[k] = L->r[j];
        k++;
        j++;
    }
    // copy��a[]
    for (k = 0; k < len; k++)
        L->r[low + k] = temp[k]; //������õ�temp����L
}

// low highΪ�����������ұ߽�
void
Mergepess(SqList *L, int low, int high)
{

    if (low < high)
    {
        int mid = (low + high) / 2;
        Mergepess(L, low, mid); //�ݹ�Ļ�����������������
        Mergepess(L, mid + 1, high);

        Merge(L, low, mid, high); //�ϲ�
    }
}

void
MergeSort(SqList *L)
{
    Mergepess(L, 1, L->length);
}

int data[N];
SqList L1, L2, L3, L4, L5, L6, L7; // �߸����У�һ������һ��

int
main()
{
    int i;
    clock_t start_time, end_time;
    double work_time;

    srand((int)time(0)); //�Ե�ǰʱ���Ӧ��intֵΪ����������
    for (i = 0; i < N; i++)
    {
        data[i] = rand() % N; //�����
    }

    for (i = 0; i < N; i++)
    {
        L1.r[i + 1] = data[i];
    }
    L1.length = N;                    //���еĳ���Ϊ2000,����ǧ��Ԫ��
    L2 = L3 = L4 = L5 = L6 = L7 = L1; //��ͬ
    printf("***********������������ʱ��Ƚ�***********\n");
    printf("        ������� %d ����������\n", N);
    printf("\n");

    start_time = clock(); //��ȡ����ʼ����ʱ��
    printf("ð������     ");
    BubbleSort(&L1);
    end_time = clock();                                           //��ȡ�����������ʱ��
    work_time = (double)(end_time - start_time) / CLOCKS_PER_SEC; //�����������ʱ�䣬ת��Ϊ��
    printf("����ʱ�� %.4f �� \n", work_time);
    printf("\n");

    start_time = clock();
    printf("ֱ�Ӳ������� ");
    InsertSort(&L2);
    end_time = clock();
    work_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("����ʱ�� %.4f �� \n", work_time);
    printf("\n");

    start_time = clock();
    printf("���ֲ������� ");
    InsertSortTwo(&L3);
    end_time = clock();
    work_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("����ʱ�� %.4f �� \n", work_time);
    printf("\n");

    start_time = clock();
    printf("ѡ������     ");
    SelectSort(&L4);
    end_time = clock();
    work_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("����ʱ�� %.4f �� \n", work_time);
    printf("\n");

    start_time = clock();
    printf("��������     ");
    QuickSort(&L5);
    end_time = clock();
    work_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("����ʱ�� %.4f �� \n", work_time);
    printf("\n");

    start_time = clock();
    printf("������     ");
    HeapSort(&L6);
    end_time = clock();
    work_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("  ����ʱ�� %.4f �� \n", work_time);
    printf("\n");

    start_time = clock();
    printf("�鲢����     ");
    MergeSort(&L7);
    end_time = clock();
    work_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("����ʱ�� %.4f �� \n", work_time);
    printf("\n");

    system("pause");

    return 0;
}
