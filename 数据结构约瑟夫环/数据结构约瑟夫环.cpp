// 数据结构约瑟夫环.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

#include <stdio.h>
#include <malloc.h>
#define MaxSize 50

typedef int ElemType;

typedef struct
{
	ElemType data[MaxSize];
	int front, rear;		//队首和队尾指针
} SqQueue;

void InitQueue(SqQueue*& q)
{
	q = (SqQueue*)malloc(sizeof(SqQueue));
	q->front = q->rear = 0;
}
void DestroyQueue(SqQueue*& q)
{
	free(q);
}
bool QueueEmpty(SqQueue* q)
{
	return(q->front == q->rear);
}
bool enQueue(SqQueue*& q, ElemType e)
{
	if ((q->rear + 1) % MaxSize == q->front)	//队满上溢出
		return false;
	q->rear = (q->rear + 1) % MaxSize;
	q->data[q->rear] = e;
	return true;
}
bool deQueue(SqQueue*& q, ElemType& e)
{
	if (q->front == q->rear)		//队空下溢出
		return false;
	q->front = (q->front + 1) % MaxSize;
	e = q->data[q->front];
	return true;
}

int QueueLength(SqQueue* q) {
	return (q->rear - q->front + MaxSize) % MaxSize;
}


//约瑟夫环（约瑟夫问题）是一个数学的应用问题：已知n个人（以编号1，2，3...n分别表示）围坐在一张圆桌周围。
//从编号为k的人开始报数，数到m的那个人出列；他的下一个人又从1开始报数，数到m的那个人又出列；
//依此规律重复下去，直到圆桌周围的人全部出列
void joseph(SqQueue* q, int m)
{
	ElemType e;
	while (q->front!=q->rear)//判断是否队空
	{    

		for (int i = 1;i <= m;i++)
		{
			deQueue(q, e);
			if (i != m)
			{
				enQueue(q, e);
			}
			else
			{
				printf("%d", e);
			}
		}
	}
	

}

int main()
{
	int i;
	SqQueue* q;					//环形队列指针
	InitQueue(q);				//初始化队列
	for (i = 1;i <= 8;i++)			//构建初始序列
		enQueue(q, i);
	int m = 3;
	joseph(q, m);   //报m的出队
	return 1;
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
