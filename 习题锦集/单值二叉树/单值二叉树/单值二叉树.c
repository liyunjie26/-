/*
���������ÿ���ڵ㶼������ͬ��ֵ����ô�ö��������ǵ�ֵ��������

ֻ�и��������ǵ�ֵ������ʱ���ŷ��� true�����򷵻� false��
*/


// Definition for a binary tree node.
 struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};

/*

��Ŀ������ʵ���Ͼ��Ƕ������ı������⣬�жϽڵ��ֵ�Ƿ�һ��
*/
#include<stdio.h>
#include<stdbool.h>
bool _isUnivalTree(struct TreeNode* root, int val)
{
	if (root)
	{
		return root->val == val
			&& _isUnivalTree(root->left, val)
			&& _isUnivalTree(root->right, val);
	}
	else
		return true;
}
bool isUnivalTree(struct TreeNode* root){
	if (root == NULL)
		return true;
	return _isUnivalTree(root, root->val);
}