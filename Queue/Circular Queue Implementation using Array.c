#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define CAPACITY 5

int front = -1; rear = -1; cqueue[CAPACITY];

void insert(int);
int yolo(void);
void display(void);
int isEmpty(void);
int isFull(void);

void main(void){
	while(1){
	int ch,item;
	printf("\n|  Circular Queue Implementation Program in Array  |\n");
	printf("---------------------------------------------\n");
	printf("1.Insert\n");
	printf("2.Delete\n");
	printf("3.Display\n");
	printf("4.Quit\n");
	printf("---------------------------------------------\n");
	printf("Enter Your Choice :\n");
	scanf("%d",&ch);
	
	switch(ch){
		case 1: insert(item);
		break;
		case 2: yolo();
		break;
		case 3: display();
		break;
		case 4: exit(0);
		break;
		default : printf("\nInvalid Input\n");
	}
  }
}

int isEmpty(){
	if(front == -1 && rear == -1){
		printf("\nCircular Queue is Empty\n");
		return 1;
	}
	else{
		return 0;
	}
}

int isFull(){
	if(rear == CAPACITY - 1){
		printf("\nCircular Queue is Full\n");
   }
	else{
		return 0;
  }
}
