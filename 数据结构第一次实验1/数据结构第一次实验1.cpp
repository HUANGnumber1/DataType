// 数据结构第一次实验1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include <malloc.h>

typedef int ElemType;
typedef struct LNode     //定义单链表结点类型
{
	ElemType data;
	struct LNode* next;     //指向后继结点
}  LinkNode, * LinkList;

bool IntList(LinkList & head)//初始化单链表
{
	head = new LNode;
	head->next = NULL;
	return true;
}

bool insertList(LinkList& L ,ElemType n)//在链表中插入新的节点
{
	LinkList p = L, Pnew;
	int i;
	for (i = 0;i < n;i++)
	{
		p = p->next;
	}
	Pnew = new LNode;
	Pnew->next = p->next;
	p->next = Pnew;
	return true;
}

bool deletenode(LinkList& L, ElemType n)   //在链表La中删除某一个节点
{
	LinkList p = L,q;
	int i;
	if (p->next == NULL)
	{
		return false;
	}
	if (p->next != NULL)
	{
		for (i = 0;i <n ;i++)
		{
			p = p->next;
		}
		q = p->next;
		p->next = p->next->next;
		free(q);
	}
}

int search_List(LinkList& L, ElemType n)//在La中查找节点并返回其数值
{
	LinkList p = L;
	int i;
	for (i = 0;i < n;i++)
	{
		p = p->next;
	}
	return (p->data);
}

bool printList(LinkList& L)//打印输出La中的节点元素值
{
	LinkList p = L;
	p = p->next;//p带头节点
	if (p->next == NULL)
		return false;
	while (p != NULL)
	{
		printf("%d  ", p->data);
		p = p->next;
	}
	return true;
}


//辅助函数，将链表中的节点赋值
bool datainList(LinkList& L, ElemType e,ElemType n)
{
	LinkList p = L;
	p = p->next;
	int i;
	for (i = 0;i < n;i++)
		p = p->next;
	p->data = e;
	return true;
}


void CreateListF(LinkNode*& L, ElemType a[], int n)  //头部插入创建链表
{
	LinkNode* s;
	int i;
	L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = NULL;		//创建头结点，其next域置为NULL
	for (i = 0;i < n;i++)		//循环建立数据结点
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = a[i];		//创建数据结点s
		s->next = L->next;		//将s插在原开始结点之前，头结点之后
		L->next = s;
	}
}









//第一大题的第二题，合并单链表

bool Union_List(LinkList& L1, LinkList& L2)
{
	LinkList pa, pb, pc,Lout;
	pa = L1->next, pb = L2->next;
	IntList(pc);
	Lout = pc;
	pc = pc->next;
	if (pa->next == NULL && pb->next == NULL)
		return false;
	while (pa->next != NULL || pb->next != NULL)
	{
		if (pa->data == pb->data)
		{
			pc->data = pa->data;
			pa = pa->next;
			pb = pb->next;
		}
		else if (pa->data < pb->data)
		{
			pc->data = pa->data;
			pa = pa->next;
		}
		else if (pa->data > pb->data)
		{
			pc->data = pb->data;
			pb = pb->next;
		}
			pc = pc->next;
	}
	while (pa->next != NULL && pb->next == NULL)
	{
		pc->next = pa;
	}
	while (pb->next != NULL && pa->next == NULL)
	{
		pc->next = pb;
	}
	return true;
}

//实验第一大题第二小题第二问，逆置单链表
bool turndownList(LinkList& L)
{
	if (L->next == NULL)
		return L;
	LNode* q = L, * p = L->next, * temp;
	q->next = NULL;
	while (p != NULL)
	{
		q->data = p->data;
		temp = p->next;
		p->next = q;
		q = p;
		p = temp;
	}
	q->data = 0;
	L = q;
	return L;
}

int  main()
{
	int data[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int i = 0;
	LinkList L;
	IntList(L);//初始化链表
	
	CreateListF(L, data,10);//数据输入
	//插入元素
	insertList(L, 2);
	datainList(L, 2, 2);
	//删除第i个元素
	
	printList(L);
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
