#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include"queue.h"
#include"btree.h"



typedef struct BTree
{
	//二叉树的根节点
	BNode* _root;
}BTree;

/*void creatBinaryTree(BTree* bt)
{
	bt->_root = NULL;
}*/
//创建一个二叉树，返回二叉树的根指针节点
//数组的顺序为前序遍历
//前序遍历的数组“ABD##E#H##CF##G##
BNode* creatBinaryTree(DataType arr[], int* idx)//idx 当前位置 要通过地址，不然无法实时进行修改
{
 	if (arr[*idx] == '#')
	{
		(*idx)++;
		return NULL;
	}
	//当前树的根节点
	BNode* root = (BNode*)malloc(sizeof(BNode));
	root->_data = arr[(*idx)++];
	root->_left = creatBinaryTree(arr, idx);
	root->_right = creatBinaryTree(arr, idx);
	return root;
}
//三种常见的遍历方式
//前序遍历
void preOrder(BNode* root)
{
//根 左子树 右子树
	if (root)
	{
		printf("%c", root->_data);
		preOrder(root->_left);
		preOrder(root->_right);

	}

}


//中序遍历
void inOrder(BNode* root)
{
	if (root)
	{
		inOrder(root->_left);
		printf("%c ", root->_data);
		inOrder(root->_right);
	}

}

//后序遍历 
void postOrder(BNode* root)
{
	if (root)
	{
		postOrder(root->_left);
		postOrder(root->_right);
		printf("%c ", root->_data);
	}
}
//二叉树节点数
int bTreeSize(BNode* root)//树的size
{
	if (root == NULL)
		return 0;
	//左子树节点个数 + 右子树节点个数 + 当前节点
	return bTreeSize(root->_left) + bTreeSize(root->_right) + 1;
}
//二叉树的高
int bTreeHight(BNode* root)//左右子树高度最大值加当前节点
{
	if (root == NULL)
		return 0;
	int left = bTreeHight(root->_left);
	int right = bTreeHight(root->_right);
	return left > right ? left + 1 : right + 1;


}

//二叉树叶子节点个数
int bTreeLeafSize(BNode* root)
{
	//若为空树
	if (root == NULL)
		return 0;
	//若为叶子节点
	if (root->_left == NULL&&root->_right == NULL)
		return 1;
	//若不为叶子节点
	return bTreeLeafSize(root->_left) + bTreeLeafSize(root->_right);
}

//第k层节点个数
int bTreeKSize(BNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return bTreeKSize(root->_left, k - 1) + bTreeKSize(root->_right, k - 1);
}

//二叉树查找某一个节点
BNode* bTreeFind(BNode* root, char ch)
{
	if (root)
	{
		BNode* node;
		if (root->_data == ch)
			return root;
		node = bTreeFind(root->_left, ch);
		if (node)
			return node;
		else
			return bTreeFind(root->_right, ch);
	}
	else
		return NULL;
}

//销毁二叉树，存在野指针
void bTreeDestory(BNode* root)
{
	if (root)
	{
		
		bTreeDestory(root->_left);
		bTreeDestory(root->_right);
		free(root);
		root = NULL;
	} 
}
//销毁二叉树，指针全部置空，没有野指针
void bTreeDestory1(BNode** root)
{
	if (*root)
	{

		bTreeDestory(&((*root)->_left));
		bTreeDestory(&((*root)->_right));
		free(*root);
		*root = NULL;
	}
}

//层序遍历
void bTreeLevelOrder(BNode* root)
{
	Queue q;
	initQueue(&q);
	if (root)
		queuepush(&q, root);  
	//遍历队列中的没一个节点
	while (!queueEmpty(&q))
	{
		BNode* node = queueFront(&q);
		//出队
		queqePop(&q);
		printf("%c  ", node->_data);
		//保存对头元素的左右孩子节点
		if (node->_left)
			queuepush(&q, node->_left);
		if (node->_right)
			queuepush(&q, node->_right);
	}
}

//判断是否为完全二叉树
/*
层序遍历，当队列中出现第一个NULL时停止插入，依次遍历，若出现非NULL元素则不是完全二叉树
*/

int isCompleteBtree(BNode* root)
{
	Queue q;
	initQueue(&q);
	if (root)
		queuepush(&q, root);
	while (!queueEmpty(&q))
	{
		BNode* node = queueFront(&q);
		queqePop(&q);
		if (node)
		{
			queuepush(&q, node->_left);
			queuepush(&q, node->_right);
		}
		else
			break;

	}
	while (!queueEmpty(&q))
	{
		BNode* node = queueFront(&q);
		queqePop(&q);
		if (node)
			return 0;
	}
	return 1;
}
void test()
{
	char arr[] = "ABD##E#H##CF##G##";
	int idx = 0;
	BNode* nodle;
	BNode* roota = creatBinaryTree(arr, &idx);
	preOrder(roota);
	printf("\n");
	inOrder(roota);
	printf("\n");
	postOrder(roota);
	printf("\nfinal");
	printf("\n");

	nodle = bTreeFind(roota, 'G');
	printf("%c", nodle->_data);
	printf("\n");

	bTreeLevelOrder(roota);

}
int main()
{
	test();
	return 0;
}