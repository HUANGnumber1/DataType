// 数据结构十一月第一次作业2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <stdio.h>
#include <malloc.h>
typedef int ElemType;

typedef struct LNode     //定义单链表结点类型
{
	ElemType data;
	struct LNode* next;     //指向后继结点
}  LinkNode, * LinkList;


void CreateListF(LinkList& L, ElemType a[], int n)  //头部插入创建链表
{
	LinkNode* s;
	int i;
	for (i = 0;i < n;i++)		//循环建立数据结点
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = a[i];		//创建数据结点s
		if (L == NULL) {
			L = s;
			L->next = NULL;
		}
		else {
			s->next = L;		//将s插在原开始结点之前，头结点之后
			L = s;
		}
	}
}


void DispList(LinkList& L) //输出线性表L的数据元素
{
	LinkNode* p = L;	//p指向开始结点
	while (p != NULL)		//p不为NULL,输出p的data域
	{
		printf("%d ", p->data);
		p = p->next;		//p移向下一个结点
	}
	printf("\n");
}

void del(LinkNode*& L, ElemType x) {
	LinkNode* p;
	int flag = 0;
	if ((L == nullptr) || (flag == 1))
	{
		return;
	}
	if (L->data == x)
	{
		p = L;
		flag = 1;
		L = L->next;
		free(p);
		return;
	}
	else
	{
		del(L->next, x);
	}
	//使用递归程序设计，删除第1个值为x的元素
}

void delall(LinkNode*& L, ElemType x) {//使用递归程序设计，删除第所有值为x的元素
	LinkNode* p;
	if (L == nullptr)
		return;
	if (L->data == x)
	{
		p = L;
		L = L->next; 
		free(p);
		delall(L, x);//对于上一个stack中的函数来说，这里是L->next=L->next->next,实际上前节点和后节点连在一起了，但是形式上表现不出来
	}
	else
	{	
		delall(L->next, x);
	}
}

int main() {
	int a[] = { 2,5,3,3,3,6,3,8,3,9 };
	LinkNode* L1 = NULL;
	CreateListF(L1, a, 10);
	printf("原始链表元素:\n");
	DispList(L1);

	del(L1, 3);
	printf("删除第一个3后的链表元素:\n");
	DispList(L1);

	LinkNode* L2 = NULL;
	CreateListF(L2, a, 10);
	printf("原始链表元素:\n");
	DispList(L2);

	delall(L2, 3);
	printf("删除所有3后的链表元素:\n");
	DispList(L2);

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
