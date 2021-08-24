#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct node{
	int data;
	struct node* left;
	struct node* right;
}node;

node* root = NULL;

node* insertion(node* root, int data);
node* delete(node* root, int data);
void displayInOrder(node* root);
void displayPreOrder(node* root);
void displayPostOrder(node* root);
void search(node *root, int data);
int FindMin(node *root);

int main()
{
  int data, ch;
  while(1) 
  {
    printf("1. Insert\n");
    printf("2. Search\n");
    printf("3. Display In Order\n");
    printf("4. Display Pre Order\n");
    printf("5. Display Post Order\n");
    printf("6. Delete\n");
		printf("7. Exit\n");
    printf("\nEnter your choice:\n");
    scanf("%d", &ch);
    switch (ch)
	{
		case 1: printf("\nEnter The Data:\n");
				scanf("%d",&data);
				root = insertion(root, data);
				printf("\n");
		break;
		
		case 2: printf("\nEnter value to search:\n");
    			scanf("%d", &data);
    			search(root, data);
    	break;
    	
    	case 3: printf("\nIn Order:\n");
    			displayInOrder(root);
    			printf("\n");
    	break;
    	
    	case 4: printf("\nPre Order:\n");
    			displayPreOrder(root);
    			printf("\n");
    	break;
    	
    	case 5: printf("\nPost Order:\n");
    			displayPostOrder(root);
    			printf("\n");
    	break;
    			
    	case 6: printf("\nEnter value to delete:\n");
    			scanf("%d", &data);
    			root = delete(root, data);
		break;
				
    	case 7: exit(0);
    	break;
    	
    	default: printf("\nInvalid Input\n");
    	break;
    }
  }
return 0;
}

node* createNode(int data){
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return(newNode);
}

node* insertion(node* root, int data){
	if(root==NULL){
		root = createNode(data);
		return root;
	}
	else if(data <= root->data){
		root->left = insertion(root->left,data);
	}
	else{
		root->right = insertion(root->right,data);
	}
	return root;
}

void search(node* root, int data){
	if(!root)
	return;
	else if(data < root->data){
		search(root->left,data);
	}
	else if(data > root->data){
		search(root->right,data);
	}
	else printf("\nThe Value %d is present:\n", root->data);
 	return;
}

void displayInOrder(node* root){
	if(root != NULL)
 	{
  		displayInOrder(root->left);
  		printf("%d ", root->data);
  		displayInOrder(root->right);
 	}
 return;
}

void displayPreOrder(node* root){
	if(root != NULL)
 	{
  		printf("%d ", root->data);
  		displayPreOrder(root->left);
  		displayPreOrder(root->right);
 	}
 return;	
}

void displayPostOrder(node* root){
	if(root != NULL)
 	{
  		displayPostOrder(root->left);
  		displayPostOrder(root->right);
  		printf("%d ", root->data);
 	}
 return;	
}

int FindMin(node *root){
	if(root==NULL){
		printf("\nTree is Empty\n");
		return -1;
	}
	else if(root->left==NULL){
		return root->data;
	}
	return FindMin(root->left);
}

node* delete(node* root, int data)
{
	if( root == NULL )
	{ 
	printf("\nThe Tree is Empty\n");
	printf("\n");
	return root;
	}
	else if(data < root->data) 
	{
		root->left = delete(root->left, data);
	}
	else if(data > root->data)
	{
		root->right = delete(root->right, data);
	}
	else
	{
		// Case 1: No Child
		if(root->left == NULL && root->right == NULL)
		{
			free(root);
			root = NULL;
			return root;
		}
		// Case 2: One Child
		else if(root->left == NULL)
		{
			node* temp = root;
			root = root->right;
			free(temp);
			return root;
		}
		else if(root->right == NULL)
		{
			node* temp = root;
			root = root->left;
			free(temp);
			return root;
		}
		// Case 3: Two Children
		else
		{
			node* temp = FindMin(root->right);
			root->data = temp->data;
			root->right = delete(root->right,temp->data);
	}
	return root;
}
}
