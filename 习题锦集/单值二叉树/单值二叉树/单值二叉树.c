/*
如果二叉树每个节点都具有相同的值，那么该二叉树就是单值二叉树。

只有给定的树是单值二叉树时，才返回 true；否则返回 false。
*/


// Definition for a binary tree node.
 struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};

/*

题目分析：实际上就是二叉树的遍历问题，判断节点的值是否一致
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