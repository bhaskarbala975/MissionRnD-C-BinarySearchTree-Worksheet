/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>

struct node
{
	struct node * left;
	int data;
	struct node *right;
};
void inorder(struct node *root, int *arr)
{
	if (root==NULL)
	{
		arr = NULL;
	}
	int *i = 0,j=0;
	if (root != NULL)
	{
		inorder(root->left, arr);
		arr[j][i] = root->data;
		i++;
		inorder(root->right, arr);
	}
	
}
void preorder(struct node *root, int *arr)
{
	int *i = 0, j = 1;
	if (root == NULL)
	{
		arr = NULL;
	}

	if (root != NULL)
	{
		arr[j][i] = root->data;
		i++;
		preorder(root->left, arr);
		preorder(root->right, arr);
	}
}
void postorder(struct node *root, int *arr)
{
	int *i = 0, j = 2;
	if (root == NULL)
	{
		arr = NULL;
	}
	if (root != NULL)
	{
		postorder(root->left, arr);
		postorder(root->right, arr);
		arr[j][i] = root->data;
		i++;
	}
}

