#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct node{
	int data;
	struct node* next;
}node;

node* head = NULL; // Empty List //
node* temp = NULL;
node* p;

void insert();
void traverse(node* head);
node* search(head, data);
node* delete(head, data);

int main(){
	int data, ch;
	while(1){
		printf("\n1.Insert");
		printf("\n2.Traverse");
		printf("\n3.Search");
		printf("\n4.Delete");
		printf("\n5.Exit");
		printf("\nEnter Your Choice:\n");
		scanf("%d",&ch);
		switch(ch){
			case 1: insert();
					break;
			case 2: traverse(head);
					break;
			case 3: search(head,data);
			        break;
			case 4: delete(head,data);
					break;
			case 5: exit(0);
					break;
			default: printf("\nInvalid Input\n");
		}
	}
}

void insert(){
	p = (node*)malloc(sizeof(node));
        if(p==NULL){
                printf("\nOut of Memory Space\n");
                exit(0);
        }
        printf("\nEnter the data value for the node:\t");
        scanf("%d",&p->data);
        p->next=NULL;
        if(head==NULL){
                head=p;
        }
        else{
                temp=head;
                while(temp->next!=NULL){
                        temp=temp->next;
                }
                temp->next=p;
        }
}

void traverse(node* head){
	if(head==NULL){
		printf("\nList is Empty\n");
		return;
	}
	else
	temp = head;
	printf("\nThe List is:\n");
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}
}

node* search(node* head, int data){
	int d;
	printf("\nEnter the Data you want to search\n");
	scanf("%d",&d);
	while(head!=NULL){
		if(head->data==d){
		printf("\nElement Found\n");
		return;
	}
	head = head->next;
	}
	printf("No element found");
}

node* delete(node* head, int data){
	int d;
	printf("\nEnter The Element to Delete\n");
	scanf("%d",&d);
	if(head==NULL){
		printf("\nThe List is Empty\n");
	}
	temp = head;
	while(temp!=NULL){
		if(temp->data==d){
			temp = temp->next;
			temp->data = temp->next->data;
			temp->next = head->next;
			free(temp);
		}
		return head;
	}
}
