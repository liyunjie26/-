
#pragma once
//二叉树链式结构的遍历，使用遍历的方法
typedef char DataType;
//二叉树节点 二叉链
typedef struct BNode
{
	struct BNode* _left;
	struct BNode* _right;
	DataType _data;
}BNode;