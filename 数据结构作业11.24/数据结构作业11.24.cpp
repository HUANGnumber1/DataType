//假设二叉树中每个结点值为单个字符， 采用二叉链存储结构存储。 设计一个算法，求二叉树 b 中第 k 层上叶子结点个数。
//完成下面代码的LevelkCount函数，实现上述功能
//======================================
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#define MaxSize 100
typedef char ElemType;
typedef struct node
{
	ElemType data;			//数据元素
	struct node* lchild;	//指向左孩子节点
	struct node* rchild;	//指向右孩子节点
} BTNode;


//习题7-15
//参数说明：
//b：指向当前子树的根结点； h：当前子树根结点的层次
//k: 需要统计哪一层的叶子结点  n: 用来统计k层叶子结点个数
void LevelkCount(BTNode* b, int h, int k, int& n)
{

	int nr = 0;
	int nl = 0;
	if (b == NULL)//整个树为空树时
		return;
	else if (b->lchild == NULL && b->rchild == NULL)//只有一个节点时
		n = 1;
	else if (h == k)
		return;
	else
	{
		LevelkCount(b->lchild, h + 1, k , nl);
		LevelkCount(b->rchild, h + 1, k , nr);
		n = nr + nl;
	}

	//该函数需要同学补充完成
	//功能是：需要统计该二叉树第k层上叶子结点数目，并保存在n整形变量中。
}

void CreateBTree2(BTNode*& b, char*& str)	//以递归方式创建二叉树
{
	char ch = *str++;
	if ('#' == ch) b = NULL;
	else {
		b = (BTNode*)malloc(sizeof(BTNode));
		b->data = ch;
		CreateBTree2(b->lchild, str);
		CreateBTree2(b->rchild, str);
	}
}


void DispBTree(BTNode* b)
{
	if (b != NULL)
	{
		printf("%c", b->data);
		if (b->lchild != NULL || b->rchild != NULL)
		{
			printf("(");					//有孩子节点时才输出(
			DispBTree(b->lchild);			//递归处理左子树
			if (b->rchild != NULL) printf(",");//有右孩子节点时才输出,
			DispBTree(b->rchild);			//递归处理右子树
			printf(")");				//有孩子节点时才输出)
		}
	}
}

void main() {
	BTNode* b;
	char a[20]= "EBD#A###CE##F##";
	char* str = a;

	CreateBTree2(b, str);

	printf("二叉树: ");
	DispBTree(b);

	//习题7-15测试结果
	int count = 0;
	int k = 3;
	LevelkCount(b, 1, k, count);   //统计k=3层的叶子节点

	printf("\n第k=%d层,叶子结点数量:%d\n", k, count);
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
