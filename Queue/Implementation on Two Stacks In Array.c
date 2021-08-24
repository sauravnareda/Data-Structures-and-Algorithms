#include<stdio.h>
#define size1 5
#define size2 5

int stack1[size1], stack2[size2], top1 = -1, top2 = -1;
void push1(int);
int pop1(void);
int isFull1(void);
int isEmpty1(void);
void traverse1(void);
void peek1();
void push2(int);
int pop2(void);
int isFull2(void);
int isEmpty2(void);
void traverse2(void);
void peek2();


void main(void){
	while(1){
	int ch,item;
	printf("\n| Two Stacks Implementation Program in Array  |\n");
	printf("---------------------------------------------\n");
	printf("1.Push in Stack 1\n");
	printf("2.Pop in Stack 1\n");
	printf("3.Peek in Stack 1\n");
	printf("4.Traverse in Stack 1\n");
	printf("5.Push in Stack 2\n");
	printf("6.Pop in Stack 2\n");
	printf("7.Peek in Stack 2\n");
	printf("8.Traverse in Stack 2\n");
	printf("9.Quit\n");
	printf("---------------------------------------------\n");
	printf("Enter Your Choice :\n");
	scanf("%d",&ch);
	
	switch(ch){
		case 1: push1(item);
		break;
		case 2: pop1();
		break;
		case 3: peek1();
		break;
		case 4: traverse1();
		break;
		case 5: push2(item);
		break;
		case 6: pop2();
		break;
		case 7: peek2();
		break;
		case 8: traverse2();
		break;
		case 9: exit(0);
		break;
		default : printf("\nInvalid Input\n");
	}
  }
}

void push1 (int x){
	int item;
	printf("\nEnter Element You Want To Push:\n");
	scanf("%d",&item);
	if(isFull1()){
	printf("\nStack 1 is Overflow\n");
   }
	else{
	top1++;
	stack1[top1] = item;
	printf("\n%d Pushed \n",item);	
   }
}

void push2 (int x){
	int item;
	printf("\nEnter Element You Want To Push:\n");
	scanf("%d",&item);
	if(isFull2()){
	printf("\nStack 2 is Overflow\n");
   }
	else{
	top2++;
	stack2[top2] = item;
	printf("\n%d Pushed \n",item);	
   }
}

int isFull1(){
	if(top1 == size1 - 1){
		return 1;
   }
	else{
		return 0;
  }
}

int isFull2(){
	if(top2 == size2 - 1){
		return 1;
   }
	else{
		return 0;
  }
}

int pop1(){
	int item;
	item = pop1();
	if(item==0){
		printf("\nStack 1 is Underflow\n");
	}
	else{
		printf("\nPopped Item : %d\n",item);
	}
	if(isEmpty1()){
		return 0;
	}
	else{
		return stack1[top1--];
	}
}

int pop2(){
	int item;
	item = pop2();
	if(item==0){
		printf("\nStack 2 is Underflow\n");
	}
	else{
		printf("\nPopped Item : %d\n",item);
	}
	if(isEmpty2()){
		return 0;
	}
	else{
		return stack2[top2--];
	}
}

int isEmpty1(){
	if(top1 == -1){
		return 1;
	}
	else{
		return 0;
	}
}

int isEmpty2(){
	if(top2 == -1){
		return 1;
	}
	else{
		return 0;
	}
}

void peek1(){
	if(isEmpty1())
	{
		printf("\nStack 1 is Underflow\n");
	}
	else{
		printf("\nPeek Element : %d \n",stack1[top1]);
	}
}

void peek2(){
	if(isEmpty2())
	{
		printf("\nStack 2 is Underflow\n");
	}
	else{
		printf("\nPeek Element : %d \n",stack2[top2]);
	}
}

void traverse1(){
	if(isEmpty1())
	{
		printf("\nStack 1 is Underflow\n");
	}
	else{
		 int i;
		 printf("\nStack Elements are = \n");
		 for(i=0; i<=top1; i++){
		 	printf("%d\n",stack1[i]);
	  }
   }
}

void traverse2(){
	if(isEmpty2())
	{
		printf("\nStack 2 is Underflow\n");
	}
	else{
		 int i;
		 printf("\nStack Elements are = \n");
		 for(i=0; i<=top2; i++){
		 	printf("%d\n",stack2[i]);
	  }
   }
}
