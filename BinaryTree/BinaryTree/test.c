#define _CRT_SECURE_NO_WARNINGS
#include"BinaryTree.h"

BTnode* Creatnode()
{
	BTnode* nodea = Buynode('A');
	BTnode* nodeb = Buynode('B');
	BTnode* nodec = Buynode('C');
	BTnode* noded = Buynode('D');
	BTnode* nodee = Buynode('E');
	BTnode* nodef = Buynode('F');
	BTnode* nodeg = Buynode('G');
	nodea->left = nodeb;
	nodea->right = nodec;
	nodeb->left = noded;
	nodeb->right = nodee;
	nodec->left = nodef;
	nodec->right = nodeg;
	return nodea;
}
int main()
{
	BTnode* root = Creatnode();
	Preorder(root);
	printf("\n");
	Inorder(root);
	printf("\n");
	Postorder(root);



	return 0;
}