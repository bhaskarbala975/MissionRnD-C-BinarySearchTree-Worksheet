/*
Given a Binary Search Tree and a Node(temp).Find the Closest Distance from the Node to 
any leaf of the Tree.
(Least number of Edges needed to be travelled to go to the Node )

Ex : Consider the below tree .
      2
     / \
,   1   3
         \
         14
For 3 ,Output is 1 . As its closest leaf is 14 and 3 is at a distance of 1 to 14 .

Ex 2: Consider the below tree .
    2
   / \
  1   3
       \
        14
        / \
       9   20
      /      \
     6       25
For 3 ,Output is now 2 . As closest leaf to 3 is 1 and 3 is at a distance of 2 to 1 .
(through root 2 )

For 14 ,O/P : 2
For 2 , O/P : 1

Return -1 ,for Invalid Inputs
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
  struct node * left;
  int data;
  struct node *right;
};
int nearestLeafNode(struct node *root);
void findLeafNode(struct node *root, struct node *temp, int *nearestLeafValue, int *edgeCount);
int get_closest_leaf_distance(struct node *root, struct node *temp)
{
	if (root == NULL || temp == NULL)
		return -1;
	int nearestLeafValue = -1;
	int edgeCount = 0;
	findLeafNode(root, temp, &nearestLeafValue, &edgeCount);
	return nearestLeafValue;
}
int nearestLeafNode(struct node *root)
{
	int leftTreeHeight;
	int rightTreeHeight;

	if (root == NULL)
		return -1;
	leftTreeHeight = nearestLeafNode(root->left);
	rightTreeHeight = nearestLeafNode(root->right);

	if (leftTreeHeight == -1 && rightTreeHeight != -1)
		return rightTreeHeight + 1;
	else if (leftTreeHeight != -1 && rightTreeHeight == -1)
		return leftTreeHeight + 1;
	else if (leftTreeHeight > rightTreeHeight)
		return rightTreeHeight + 1;
	else
		return leftTreeHeight + 1;
}

void findLeafNode(struct node *root, struct node *temp, int *nearestLeafValue, int *edgeCount) {
	int cur_Leaf;

	if (root == NULL)
		return;
	if (root == temp)
	{
		*edgeCount = 1;
		*nearestLeafValue = nearestLeafNode(root);
	}
	else
	{
		findLeafNode(root->left, temp, nearestLeafValue, edgeCount);
		if (*edgeCount != 0)
		{
			cur_Leaf = nearestLeafNode(root);
			if (*nearestLeafValue > *edgeCount + cur_Leaf)
			{
				*nearestLeafValue = *edgeCount + cur_Leaf;
			}
		}
		else
		{
			findLeafNode(root->right, temp, nearestLeafValue, edgeCount);
			if (*edgeCount != 0)
			{
				cur_Leaf = nearestLeafNode(root);
				if (*nearestLeafValue > *edgeCount + cur_Leaf)
				{
					*nearestLeafValue = *edgeCount + cur_Leaf;
				}
			}
		}
	}
}