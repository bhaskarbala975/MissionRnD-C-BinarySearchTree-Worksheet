/*
Given a Sorted Array of integers .Create a new Balanced Binary Search Tree from the Array
and return the head of the new BST .

Ex : Input : [1,6,10]
Output : A new BST which structure is as follows 
  6
 / \
1  10

A BST is said to be balanced ,when it satisifes the following property 

Every node's Difference of Left subtree height and right-subtree height is not more than 1 .

Below Tree is Not a Balanced BST ,as 1's left subtree has height of 0 ,but 
right subtree height is 2 
(Diff >1)

  1
   \
    3
   / \
  10  5

Note : Return head of newly created BST
Note : Return Null for invalid Inputs
Note : Donot create a new BST .
*/
#include <stdlib.h>
struct node{
	struct node * left;
	int data;
	struct node *right;
};
struct node* modify(int arr[], int start, int end);
struct node * convert_array_to_bst(int *arr, int len)
{
	if (arr == NULL || len <= 0)
		return NULL;
	int start = 0, end = len - 1;
	return modify(arr, start, end);
}
struct node* modify(int arr[], int start, int end)
{
	int mid;
	if (start > end)
		return NULL;
	mid = (start + end) / 2;
	struct node* root;
	root = (struct node*)malloc(sizeof(struct  node));
	root->data = arr[mid];
	root->left = root->right = NULL;
	root->left = modify(arr, start, mid - 1);
	root->right = modify(arr, mid + 1, end);
	return root;
	/*here i used the technique similar to binary search and solved the problem recusively*/
	
}

