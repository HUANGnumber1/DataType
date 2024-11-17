/*批阅名单（0）
作业 / 测练
剩余答题时长：04 : 07 : 56 : 00
简答题（20分）
1 / 1（共1题）
补充完成下面代码中的UnionList函数，实现将两个有序的单链表归并一个有序单链表LC，要求空间复杂度为O（1）。

将UnionList函数的代码实现和运行结果（可以修改main函数中的测试数据）截图提交。*/

#include <stdio.h>
#include <malloc.h>

#include <iostream>
typedef int ElemType;

typedef struct LNode     //定义单链表结点类型
{
	ElemType data;
	struct LNode* next;     //指向后继结点
}  LinkNode, * LinkList;


void InitList(LinkList& L)   //初始化链表
{
	L = (LinkNode*)malloc(sizeof(LinkNode));    //创建头结点
	L->next = NULL;
}



void DispList(LinkList& L) //输出线性表L的数据元素
{
	LinkNode* p = L->next;	//p指向开始结点
	while (p != NULL)		//p不为NULL,输出p的data域
	{
		printf("%d ", p->data);
		p = p->next;		//p移向下一个结点
	}
	printf("\n");
}


//递增插入元素
void ListInsert(LinkList& L, ElemType e) {
	LinkNode* pre = L, * p;
	while (pre->next != NULL && pre->next->data < e)
		pre = pre->next;   //查找插入结点的前驱结点*pre
	p = (LinkNode*)malloc(sizeof(LinkNode));
	p->data = e;   //创建存放e的数据结点*p
	p->next = pre->next;  //在*pre结点之后插入*p结点
	pre->next = p;
}


//实现两个有序单链表归并算法，要求空间复杂度为O（1）
void UnionList(LinkNode* LA, LinkNode* LB, LinkNode*& LC) {
	LinkNode* pa = LA->next, * pb = LB->next, * r, * s;
	LC = (LinkNode*)malloc(sizeof(LinkNode)); //创建LC的头结点
	r = LC;			
	s = r;	//r始终指向LC的尾结点
	//补充后续代码
	while (pa && pb)
	{
		if (pa->data < pb->data)
		{
 			r->next = pa;
			pa = pa->next;
			
			r = r->next;
		}
		else if (pa->data > pb->data)
		{
			r->next = pb;
			pb = pb->next;
			r = r->next;
		}
		else if (pa->data == pb->data)
		{
			r->next = pa;
			pa = pa->next;
			pb = pb->next;
		}
	}

		while (pb)
		{
			r->next = pb;
			pb = pb->next;
			r = r->next;
		}
		while (pa)
		{
			r->next = pa;
			pa = pa->next;
			r = r->next;
		}
	
}

void main() {
	printf("hello world\n");

	int a[] = { 3,1,5 };
	int b[] = { 4,2,8,6,9 };

	LinkNode* LA, * LB;

	InitList(LA);
	InitList(LB);

	for (int i = 0;i < 3;i++)
		ListInsert(LA, a[i]);

	for (int j = 0;j < 4;j++)
		ListInsert(LB, b[j]);

	printf("输出有序表：\n");
	DispList(LA);
	DispList(LB);

	LinkNode* LC;
	UnionList(LA, LB, LC);
	printf("输出合并后的有序表：\n");
	DispList(LC);


}
