#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct node{
	int data;
	struct node* left;
	struct node* right;
}node;

node* rootptr = NULL;                     // Pointer to Root Node and Setting Binary Tree as Empty //

node* insert(rootptr, data);

void traverse(node *rootptr);

int main()
{
		int n,ch; 
		printf("\n            Binary Search Tree          \n");
		printf("-------------------------------------------\n");
		printf("\n1.Insert\n");
		printf("\n2.Display\n");
		printf("\n3.Search\n");
		printf("\n4.Exit\n");
		while(1)
		{
		printf("\n\nEnter Your Choice: \n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: 
			printf("\nEnter The Data You Want To Insert: \n");
			scanf("%d",&n);
			rootptr = insert(&rootptr, n);
			break;
			case 2: 
			printf("\nInorder Tree:\n");
    		traverse(rootptr);
    		printf("\n");
    		break;
    		case 3: printf("\nEnter value you want to Search:\n");
    		scanf("%d", &n);
    		rootptr = search(rootptr, n);
    		break;
			case 4: exit(0);
			break;
			default: printf("\nInvalid Input\n");
	}
}
}


node* GetNewNode(int data)
{
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

node* insert(node* rootptr, int data)
{
	if(rootptr == NULL)                   // Empty Tree //
	{
		rootptr = GetNewNode(data);
		return rootptr;
	}
	else if(data <= rootptr->data)
	{
		rootptr->left = insert(rootptr->left, data);
	}
	else
	{
		rootptr->right = insert(rootptr->right, data);
	}
	return rootptr;
}

void traverse(node *rootptr)
{
  if(rootptr != NULL)
  {
  	traverse(rootptr->left);
  	printf("%d ", rootptr->data);
  	traverse(rootptr->right);
  	return;
  }
}

void search(node *rootptr, int data)
{
 if (!rootptr)
 return;
 else if(data < rootptr->data)
 {
 search(rootptr->left, data);
 } 
 else if(data > rootptr->data)
 {
 search(rootptr->right, data);
 }
 else
 printf("\nThe Value %d is present:\n", rootptr->data);
 return;
}
