// 数据结构第二次实验.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stdlib.h>
#include<time.h>
#define MAXSIZE 50



//辅助函数







typedef struct {
    int data[MAXSIZE];
    int top;
}SeqStack;

//初始化栈
void InitStack(SeqStack* s)
{
    s->top = -1;
};

//判断栈是否为空
int IsEmpty(SeqStack* s)
{
    return s->top == -1;
};

int IsFull(SeqStack* s)
{
    return s->top == MAXSIZE;
};

void Push(SeqStack* s, int x)
{
    if (IsFull(s))
    {
        printf("Stack is full.\n");
        return;
    }
    s->top++;
    s->data[s->top] = x;
}

//出栈
int Pop(SeqStack* s)
{
    if (IsEmpty(s))
    {
        printf("Stack is empty.\n");
        return -1;
    }
    int x = s->data[s->top];
    s->top--;
    return x;
}

//队列相关函数API
typedef int ElemType;
typedef struct
{
    ElemType data[MAXSIZE];
    int front;
    int rear;
}SqQueue;


//初始化
void InitQueue(SqQueue*& q)
{
    q = (SqQueue*)malloc(sizeof(SqQueue));
    q->front = q->rear = -1;
};

//销毁队列
void DestroyQueue(SqQueue*& q)
{
    free(q);
}
//判断队列是否为空
bool deQueue(SqQueue*& q, ElemType& e)
{
    if (q->front == q->rear)
        return false;
    q->front++;
    e = q->data[q->front];
    printf("%d", e);
    return true;
}
//进队
bool enQueue(SqQueue*& q, ElemType e)
{
    if (q->rear == MAXSIZE - 1)
        return false;
    q->rear++;
    q->data[q->rear] = e;
    return true;
}
//打印队列
bool printQueue(SqQueue*& q)
{

}

void Print(SeqStack* s)
{
    if (IsEmpty(s))
        return;
    while (!IsEmpty(s))
    {
        int x = Pop(s);
        printf("%d\n", x);
    }
    printf("\n");
}


//进制转换
void Conversion(int N)
{
    int e=0;
    SeqStack* s = (SeqStack*)malloc(sizeof(SeqStack));

    InitStack(s);
    while (N)
    {
        Push(s, N % 2);
        N = N / 2;
    }
    while (!IsEmpty(s))
    {
        e=Pop(s);

        printf("%d", e);
    }
}




int main()
{

    int n=7;

    SeqStack s;
    InitStack(&s);


    for (int i = 1;i <= n;i++)
    {
        Push(&s, i);
    }
  //将栈中的元素取出并打印
    Print(&s);

    //将输入元素进行进制转化
    int m = 0;
    printf("请输入待转换的数值");
    scanf_s("%d", &m);
    printf("转换为二进制为：");
        Conversion(m);

 //将队列中的元素取出并且打印
        SqQueue* q;
        InitQueue(q);
        for (int j = 1;j <= 7;j++)
        {
            enQueue(q, j);
        }

        printQueue(q);


}
