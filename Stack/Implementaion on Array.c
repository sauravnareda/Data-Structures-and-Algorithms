#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 5

int stack[CAPACITY], top = -1;
void push(int);
int pop(void);
int isFull(void);
int isEmpty(void);
void traverse(void);
void peek();


void main(void){
	while(1){
	int ch,item;
	printf("\n|  Stack Implementation Program in Array  |\n");
	printf("---------------------------------------------\n");
	printf("1.Push\n");
	printf("2.Pop\n");
	printf("3.Peek\n");
	printf("4.Traverse\n");
	printf("5.Quit\n");
	printf("---------------------------------------------\n");
	printf("Enter Your Choice :\n");
	scanf("%d",&ch);
	
	switch(ch){
		case 1: push(item);
		break;
		case 2: pop();
		break;
		case 3: peek();
		break;
		case 4: traverse();
		break;
		case 5: exit(0);
		break;
		default : printf("\nInvalid Input\n");
	}
  }
}

void push (int x){
	int item;
	printf("\nEnter Element You Want To Push:\n");
	scanf("%d",&item);
	if(isFull()){
	printf("\nStack is Overflow\n");
   }
	else{
	top++;
	stack[top] = item;
	printf("\n%d Pushed \n",item);	
   }
}

int isFull(){
	if(top == CAPACITY-1){
		return 1;
   }
	else{
		return 0;
  }
}

int pop(){
	int item;
	if(item==0){
		printf("\nStack is Underflow\n");
	}
	else{
		printf("\nDone Popping Item\n");
	}
	if(isEmpty()){
		return 0;
	}
	else{
		return stack[--top];
	}
}

int isEmpty(){
	if(top == -1){
		return 1;
	}
	else{
		return 0;
	}
}

void peek(){
	if(isEmpty())
	{
		printf("\nStack is Underflow\n");
	}
	else{
		printf("\nPeek Element : %d \n",stack[top]);
	}
}

void traverse(){
	if(isEmpty())
	{
		printf("\nStack is Underflow\n");
	}
	else{
		 int i;
		 printf("\nStack Elements are = \n");
		 for(i=0; i<=top; i++){
		 	printf("%d ",stack[i]);
	  }
   }
}
