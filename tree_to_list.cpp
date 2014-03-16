/*
	This program demostrates the conversion of a binary tree into a singly linked list. This program can eaily be modified for doubly linked list as well. For conversion we make use of the inorder tree traversal.

	Time Complexity: O(n);
*/

#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <ctime>
#include <vector>
#include <iterator>


struct node
{
	int data;
	node *right;
	node *left;
	node *next;
};

node * createNode(int n)
{
	node *new_node = (node *)malloc(sizeof(node));
	new_node->data = n;
	new_node->right = NULL;
	new_node->left = NULL;
	new_node->next = NULL;

	return new_node;
}

void inOrder(node *n)
{
	if(n==NULL)
		return;
	inOrder(n->left);
	printf("%d\n",n->data);
	inOrder(n->right);
}

void  bstToList(node *root, node **head)
{
	//Edge case
	if(root == NULL)
		return;

	//prev pointer keeps trac of the last visited node.
	static node *prev = NULL;

	//Traverse the left sub tree.
	bstToList(root->left, head);

	//Initialize head pointer of linked list if prev pointer is NULL. This will be the left most leaft node of tree.
	if(prev == NULL)
	{
		*head=root;
	}
	else
	{
		//Otherwise connect the previous node to present node.
		prev->next = root;

	}
	//Shift prev pointer to current node.
	prev=root;

	//Traverse the right sub tree
	bstToList(root->right, head);
}

void printList(node *node)
{
    while (node!=NULL)
    {
    	printf("%d ",node->data );
        node = node->next;
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
	struct node *root = createNode(10);

	// creating a sample binary tree.
	root->left = createNode(8);
	root->right = createNode(12);
	root->left->left = createNode(6);
	root->left->right = createNode(9);
	root->right->left = createNode(11);
	root->right->right = createNode(13);

	inOrder(root);

	node *head = NULL;

	bstToList(root, &head);

	printList(head);

	return 0;
}