#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include"queue.h"
#include"btree.h"



typedef struct BTree
{
	//�������ĸ��ڵ�
	BNode* _root;
}BTree;

/*void creatBinaryTree(BTree* bt)
{
	bt->_root = NULL;
}*/
//����һ�������������ض������ĸ�ָ��ڵ�
//�����˳��Ϊǰ�����
//ǰ����������顰ABD##E#H##CF##G##
BNode* creatBinaryTree(DataType arr[], int* idx)//idx ��ǰλ�� Ҫͨ����ַ����Ȼ�޷�ʵʱ�����޸�
{
 	if (arr[*idx] == '#')
	{
		(*idx)++;
		return NULL;
	}
	//��ǰ���ĸ��ڵ�
	BNode* root = (BNode*)malloc(sizeof(BNode));
	root->_data = arr[(*idx)++];
	root->_left = creatBinaryTree(arr, idx);
	root->_right = creatBinaryTree(arr, idx);
	return root;
}
//���ֳ����ı�����ʽ
//ǰ�����
void preOrder(BNode* root)
{
//�� ������ ������
	if (root)
	{
		printf("%c", root->_data);
		preOrder(root->_left);
		preOrder(root->_right);

	}

}


//�������
void inOrder(BNode* root)
{
	if (root)
	{
		inOrder(root->_left);
		printf("%c ", root->_data);
		inOrder(root->_right);
	}

}

//������� 
void postOrder(BNode* root)
{
	if (root)
	{
		postOrder(root->_left);
		postOrder(root->_right);
		printf("%c ", root->_data);
	}
}
//�������ڵ���
int bTreeSize(BNode* root)//����size
{
	if (root == NULL)
		return 0;
	//�������ڵ���� + �������ڵ���� + ��ǰ�ڵ�
	return bTreeSize(root->_left) + bTreeSize(root->_right) + 1;
}
//�������ĸ�
int bTreeHight(BNode* root)//���������߶����ֵ�ӵ�ǰ�ڵ�
{
	if (root == NULL)
		return 0;
	int left = bTreeHight(root->_left);
	int right = bTreeHight(root->_right);
	return left > right ? left + 1 : right + 1;


}

//������Ҷ�ӽڵ����
int bTreeLeafSize(BNode* root)
{
	//��Ϊ����
	if (root == NULL)
		return 0;
	//��ΪҶ�ӽڵ�
	if (root->_left == NULL&&root->_right == NULL)
		return 1;
	//����ΪҶ�ӽڵ�
	return bTreeLeafSize(root->_left) + bTreeLeafSize(root->_right);
}

//��k��ڵ����
int bTreeKSize(BNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return bTreeKSize(root->_left, k - 1) + bTreeKSize(root->_right, k - 1);
}

//����������ĳһ���ڵ�
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

//���ٶ�����������Ұָ��
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
//���ٶ�������ָ��ȫ���ÿգ�û��Ұָ��
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

//�������
void bTreeLevelOrder(BNode* root)
{
	Queue q;
	initQueue(&q);
	if (root)
		queuepush(&q, root);  
	//���������е�ûһ���ڵ�
	while (!queueEmpty(&q))
	{
		BNode* node = queueFront(&q);
		//����
		queqePop(&q);
		printf("%c  ", node->_data);
		//�����ͷԪ�ص����Һ��ӽڵ�
		if (node->_left)
			queuepush(&q, node->_left);
		if (node->_right)
			queuepush(&q, node->_right);
	}
}

//�ж��Ƿ�Ϊ��ȫ������
/*
����������������г��ֵ�һ��NULLʱֹͣ���룬���α����������ַ�NULLԪ��������ȫ������
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