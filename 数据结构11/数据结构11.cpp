// 数据结构11.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>




#include <stdio.h>
#include <malloc.h>




typedef int ElemType;

typedef struct LNode     //定义单链表结点类型
{
	ElemType data;
	struct LNode* next;     //指向后继结点
}  LinkNode, * LinkList;


void CreateListF(LinkNode*& L, ElemType a[], int n); //头部插入创建链表
void CreateListR(LinkNode*& L, ElemType a[], int n); //尾部插入创建链表
void InitList(LinkNode*& L);   //初始化链表
void DestroyList(LinkNode*& L);   //销毁链表
bool ListEmpty(LinkNode*& L);   //判断链表为空
int ListLength(LinkNode*& L);  //计算线性表的长度
void DispList(LinkNode*& L); //输出线性表L的数据元素
bool GetElem(LinkNode*& L, int i, ElemType& e);  //线性表L中位置i的数据元素
bool ListInsert(LinkNode*& L, int i, ElemType e);  //插入数据元素
bool ListDelete(LinkNode*& L, int i, ElemType& e);  //删除数据元素

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


void CreateListR(LinkNode*& H, ElemType a[], int n)  //尾部插入创建链表
{
	LinkNode* s, * r;
	int i;
	H = (LinkNode*)malloc(sizeof(LinkNode));  //创建头结点
	r = H;			//r始终指向尾结点，开始时指向头结点   
	for (i = 0;i < n;i++)		//循环建立数据结点
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = a[i];		//创建数据结点s
		r->next = s;		//将s插入r之后
		r = s;
	}
	r->next = NULL;		//尾结点next域置为NULL
}


void InitList(LinkNode*& L)   //初始化链表
{
	L = (LinkNode*)malloc(sizeof(LinkNode));    //创建头结点
	L->next = NULL;
}


void DestroyList(LinkNode*& L)   //销毁链表
{
	LinkNode* pre = L, * p = L->next;    //pre指向p的前驱结点

	while (p != NULL)	//扫描单链表L
	{
		free(pre);	//释放pre结点
		pre = p;		//pre、p同步后移一个结点
		p = pre->next;
	}
	free(pre);     //循环结束时，p为NULL，pre指向尾结点，释放它
}


bool ListEmpty(LinkNode*& L)   //判断链表为空
{
	return (L->next == NULL);
}


int ListLength(LinkNode*& L)  //计算线性表的长度
{
	int n = 0;
	LinkNode* p = L;	//p指向头结点，n置为0（即头结点的序号为0）

	while (p->next != NULL)
	{
		n++;
		p = p->next;
	}
	return(n);	//循环结束，p指向尾结点，其序号n为结点个数
}


void DispList(LinkNode*& L) //输出线性表L的数据元素
{
	LinkNode* p = L->next;	//p指向开始结点
	while (p != NULL)		//p不为NULL,输出p的data域
	{
		printf("%d ", p->data);
		p = p->next;		//p移向下一个结点
	}
	printf("\n");
}


bool GetElem(LinkNode*& L, int i, ElemType& e)  //线性表L中位置i的数据元素
{
	int j = 0;
	LinkNode* p = L;	 //p指向头结点，j置为0（即头结点的序号为0）

	while (j < i && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)	//不存在第i个数据结点，返回false
		return false;
	else			//存在第i个数据结点，返回true
	{
		e = p->data;
		return true;
	}
}


bool ListInsert(LinkNode*& L, int i, ElemType e)  //插入数据元素
{
	int j = 0;
	LinkNode* p = L, * s;  //p指向头结点,j置为0

	while (j < i - 1 && p != NULL)
	{
		j++;
		p = p->next;
	}

	if (p == NULL)	//未找到第i-1个结点，返回false
		return false;
	else			//找到第i-1个结点p，插入新结点并返回true
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = e;		//创建新结点s，其data域置为e
		s->next = p->next;	//将s插入到p之后
		p->next = s;
		return true;
	}
}


bool ListDelete(LinkNode*& L, int i, ElemType& e)  //删除数据元素
{
	int j = 0;
	LinkNode* p = L, * q;		//p指向头结点，j置为0

	while (j < i - 1 && p != NULL)	//查找第i-1个结点
	{
		j++;
		p = p->next;
	}

	if (p == NULL)		//未找到第i-1个结点，返回false
		return false;
	else				//找到第i-1个结点p
	{
		q = p->next;		//q指向第i个结点
		if (q == NULL)		//若不存在第i个结点，返回false
			return false;
		e = q->data;
		p->next = q->next;	//从单链表中删除q结点
		free(q);			//释放q结点
		return true;		//返回true表示成功删除第i个结点
	}
}

void Sort(LinkNode*& L)
{
	LinkNode* p, * q, * pre;
	int s = 0;
	p = L->next->next;
	L->next->next = NULL;
	q = p;
	pre = L->next;
	for (;p != NULL;)
	{
		if (pre->data > p->data)
		{
			s = pre->data;
			pre->data = p->data;
			p->data = s;
		}
		pre = p;
		p = p->next;
	}
	p = q;
}

void main() {
	ElemType a[] = { 2,6,9,8,4,7 };  LinkList L;
	CreateListF(L, a, 6);
	printf("L元素： ");
	DispList(L);
	Sort(L);
	printf("排序后单链表 L:");
	DispList(L);
	printf("释放单链表 L\n");
	DestroyList(L);
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
