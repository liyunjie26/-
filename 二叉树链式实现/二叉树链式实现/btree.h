
#pragma once
//��������ʽ�ṹ�ı�����ʹ�ñ����ķ���
typedef char DataType;
//�������ڵ� ������
typedef struct BNode
{
	struct BNode* _left;
	struct BNode* _right;
	DataType _data;
}BNode;