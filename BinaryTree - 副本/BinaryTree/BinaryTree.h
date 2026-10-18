#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef char BTDataType;

typedef struct BinaryTree
{
	struct BinaryTree* left;
	struct BinaryTree* right;
	BTDataType data;
}BTnode;

//创建新结点
BTnode* Buynode(char data);

//前序遍历
void Preorder(BTnode* root);

//中序遍历
void Inorder(BTnode* root);

//后序遍历
void Postorder(BTnode* root);