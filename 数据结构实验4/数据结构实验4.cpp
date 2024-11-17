// 数据结构实验4.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<stdio.h>
#define MAXL 100
typedef int KeyType;
typedef char InfoType;

typedef struct
{
    KeyType key;
    InfoType data;
}RecType;

void CreateList(RecType R[], KeyType keys[], int n);
void DispList(RecType R[], int n);

void InsertSort(RecType R[], int n);
void ShellSort(RecType R[], int n);

void BubbleSort(RecType R[], int n);
int partition(RecType R[], int s, int t);
void QuickSort(RecType R[], int s, int t);

void SelectSort(RecType R[], int n);
void CreateList1(RecType R[], KeyType keys[], int n);
void DispList1(RecType R[], int n);

///////////////////////////////////////


void InsertSort(RecType R[], int n)//直接插入
{
    int i, j;
    RecType tmp;
    for (i = 1;i < n;i++)
    {
        if (R[i].key < R[i - 1].key)
        {
            tmp = R[i];
            j = i - 1;
            do
            {
                R[j + 1] = R[j];
                j--;
            } while (j >= 0 && R[j].key > tmp.key);
            R[j + 1] = tmp;
        }
        printf(" i=%d: ", i);
        DispList(R, n);
    }
}


void ShellSort(RecType R[], int n)//希尔
{
    int i, j, d;
    RecType tmp;
    d = n / 2;
    while (d > 0)
    {
        for (i = d;i < n;i++)
        {
            tmp = R[i];
            j = i - d;
            while (j>=0 && tmp.key < R[j].key)
            {
                R[j + d] = R[j];
                j = j - d;
            }
            R[j + d] = tmp;
        }
        printf(" d=%d:", d);
        DispList(R, n);
        d = d / 2;
    }
}


void CreateList(RecType R[], KeyType keys[], int n)
{
    for (int i = 0;i < n;i++)
        R[i].key = keys[i];
}

void DispList(RecType R[], int n)
{
    for (int i = 0;i < n;i++)
        printf("%d ", R[i].key);
    printf("\n");
}




void SlelectSort(RecType R[], int n)//简单选择排序
{
    int i, j, k;
    RecType temp;
    for (j = i + 1;j < n;j++)
    {
        k = i;
        for (i = i + 1;j < n;j++)
        {
            k = i;
            for (j = i + 1;j < n;j++)
                if (R[j].key < R[k].key)
                    k = j;
            if (k != i)
            {
                temp = R[i];
                R[i] = R[k];
                R[k] = temp;
            }
            printf(" i=%d: ", i);
            DispList(R, n);
        }
    }
}





//堆排序
void sift(RecType R[], int low, int high)
{
    int i = low, j = 2 * i;
    RecType temp = R[i];
    while (j <= high)
    {
        if (j < high && R[j].key < R[j + 1].key)
            j++;
        if (temp.key < R[j].key)
        {
            R[i] = R[j];
            i = j;
            j = 2 * i;
        }
        else break;
    }
    R[i] = temp;
}
void HeapSort(RecType R[], int n)
{
    int i;
    RecType tmp;
    for (i = n / 2;i >= 1;i--)
        sift(R, i, n);
    printf("初始堆:");
    DispList1(R, n);
    for (i = n;i >= 2;i--)
    {
        tmp = R[1];
        R[1] = R[i];
        R[i] = tmp;
        printf("第%d趟: ", n - i + 1);
        DispList1(R, n);
        sift(R, 1, i - 1);
        printf("筛选为:");
        DispList1(R, n);
    }
}

void CreateList1(RecType R[], KeyType keys[], int n)
{
    for (int i = 1;i <= n;i++)
        R[i].key = keys[i - 1];
}
void DispList1(RecType R[], int n)
{
    for (int i = 1;i <= n;i++)
        printf("%d ", R[i].key);
    printf("\n");
}



























int main()
{
    std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
