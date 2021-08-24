#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct node{
	int data;
	struct node* link;
}node;

node* top = NULL;

void main(){
	while(1){
	int ch;
	printf("\n\n|  Stack Implementation Program in Single Linked List  |\n\n");
	printf("-----------------------------------------------------------");
	printf("\n1. Push\n");
	printf("2. Pop\n");
	printf("3. Traverse\n");
	printf("4. Exit\n");
	printf("-----------------------------------------------------------\n");
	printf("\nEnter Your Choice :\n");
	scanf("%d",&ch);
	switch(ch){
	case 1: push();
	break;
	case 2: pop();
	break;
	case 3: traverse();
	break;
	case 4: exit(0);
	break;
	default : printf("\nInvalid Input\n");	
	}
  }
}

void push(){
	node* temp;
	temp = (node*)malloc(sizeof(node));
	printf("\nEnter Node Data : \n");
	scanf("%d",&temp->data);
	temp->link = top;
	top = temp;
}

void pop(){
	node* temp;
	temp = (node*)malloc(sizeof(node));
	if( top == NULL ){
		printf("\nNo Elements to Delete.\n");
	}
	else{
		temp = top;
		printf("\n%d will be Poped\n",temp->data);
		top = temp->link;
		top->link = NULL;
		free(temp);
	}
}

void traverse(){
	node* temp;
	if( top == NULL){
		printf("\nStack is Empty\n");
	}
	else{
		temp = top;
		while( temp != NULL){
			printf("\n\n%d",temp->data);
			temp = temp->link;
		}
	}
}
