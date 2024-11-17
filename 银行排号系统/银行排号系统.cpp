// 银行排号系统.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef struct node
{
	int data;
	struct node* next;
}LinkQnode;//链表节点定义

typedef struct
{
	LinkQnode* front;
	LinkQnode* rear;//队尾指针
}LinkQueue;//队列定义

typedef struct
{
	int* base;
	int* top;
	int Stacksize;
}SeqStack;//顺序栈的结构定义

void InitLinkQueue(LinkQueue *Q1)
{
	Q1->front = (LinkQnode*)malloc(sizeof(LinkQnode));
	Q1->rear = Q1->front;
	Q1->front->next = NULL;
}

void InitStack(SeqStack* s)
{
	s->base = (int*)malloc(100 * sizeof(int));
	if (!s->base)
		printf("空间已满\n");
	else
	{
		s->top = s->base;
		s->Stacksize = 100;
	}
}

bool EnLinkQueue(LinkQueue *Q, int x)
{
	LinkQnode* Newnode;
	Newnode = (LinkQnode*)malloc(sizeof(LinkQnode));
	if (Newnode != NULL)
	{
		Newnode->data = x;
		Newnode->next = NULL;
		Q->rear->next = Newnode;
		Q->rear->next = Newnode;
		Q->rear = Newnode;
		printf("序号为%d 的顾客进入\n",Q->rear->data);
		return true;
	}
	else
		return false;
}

bool DelinkQueue(LinkQueue* Q, int* x)
{
	LinkQnode* p;
	if (Q->front == Q->rear)
		return false;
	p = Q->front->next;
	Q->front->next = p->next;
	if (Q->rear == p)
	{
		Q->rear = Q->front;
	}
	*x = p->data;
	free(p);
	return true;
}
int Push(SeqStack* s, int x)
{
	if (s->top - s->base == s->Stacksize)
	{
		s->base = (int*)realloc(s->base, (s->Stacksize + 10) * sizeof(int));
		if (s->base == NULL)
			return false;
		s->top = s->base + s->Stacksize;
		s->Stacksize = s->Stacksize + 10;		 
	}
	*s->top = x;
	s->top++;
	return true;
}

bool IsLQEmpty(LinkQueue* Q)
{
	if (Q->front == Q->rear)
		return true;
	else
		return false;
}

bool Pop(SeqStack* s,int *x)
{
	if (s->top == s->base)
		return false;
	else
	{
		s->top--;
		*x = *s->top;
		return true;
	}
}

bool IsEmpty(SeqStack* s)
{
	if (s->top == s->base)
		return true;
	else
		return false;
}


void Process(LinkQueue* Q, SeqStack* S)
{
	char ch;
	int flag, sum = 0, ans = 1, cnt = 0;
	int num1 = 0, num2 = 0, num = 0;
	printf("------------------银行排队系统模拟------------------\n");
	printf("  A--表示顾客到达\n  D--表示顾客离开\n  P--表示停止顾客进入\n");
	printf("请输入：A/D/P\n");
	flag = 1;
	while (flag)
	{
		cin >> ch;
		switch (ch)
		{
		case 'A':
			
				num1++;
				num2++;
				num++;
				EnLinkQueue(Q, num);
				Push(S, num);
				printf("序号为%d的顾客正在办理业务\n", num);
				ans++;
				printf("请序号为%d的顾客等待\n", num);
			break;
		case 'D':
			if (!IsLQEmpty(Q))
			{
				DelinkQueue(Q, &num);
				sum = sum + 1;
				printf("请序号为%d的顾客离开\n", num);
				Push(S, num);
			}
			else if (IsLQEmpty(Q))
				printf("无顾客排队\n");
			break;
         
		case 'P':
			printf("顾客请停止进入\n");
			printf("还在排队的顾客有:\n");
			while (!IsLQEmpty(Q))
			{
				DelinkQueue(Q, &num);
				printf("还在排队的顾客号:%d\n", num);
				sum = sum + 1;
				Push(S, num);
			}
			flag = 0;
			break;
		}
	}
	printf("到银行的总人数为%d\n",sum);
	while (!IsEmpty(S))
	{
		Pop(S, &num);
		printf("第%d位顾客，序号为%d\n", sum, num);
		sum--;
	}
}

int main()
{
	LinkQueue* Q;
	SeqStack* s;
	Q = (LinkQueue*)malloc(sizeof(LinkQueue));
	s = (SeqStack*)malloc(sizeof(SeqStack));
	InitLinkQueue(Q);
	InitStack(s);
	Process(Q, s);
	return 0;
}