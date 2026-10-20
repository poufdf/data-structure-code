#define _CRT_SECURE_NO_WARNINGS
#include"BinaryTree.h"

//创建新结点
BTnode* Buynode(char data)
{
	BTnode* newnode = (BTnode*)malloc(sizeof(BTnode));
	if (newnode == NULL)
	{
		printf("Buynode malloc失败");
		exit(-1);
	}

	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}



//前序遍历
void Preorder(BTnode* root)
{   
	if (root == NULL)
		return;
	printf("%c ", root->data);
	Preorder(root->left);
	Preorder(root->right);
}

//中序遍历
void Inorder(BTnode* root)
{
	if (root == NULL)
		return;
	Inorder(root->left);
	printf("%c ", root->data);
	Inorder(root->right);
}

//后序遍历
void Postorder(BTnode* root)
{
	if (root == NULL)
		return;
	Postorder(root->left);
	Postorder(root->right);
	printf("%c ", root->data);
}