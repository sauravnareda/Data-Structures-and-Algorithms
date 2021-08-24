#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node{
	int num;
	struct node *pre;
	struct node *nxt;
}*head,*tail;

void DlListcreation(int n);
void displayDlList();

int main(){
	int s,insPlc,num1;
	printf("###################");
	printf("\nSelect Your Choice :\n");
	printf(" 1.Create Doubly Linked List\n 2.Delete Element in Doubly Linked List\n 3.Search Element in Doubly Linked List\n 4.Insert Element in Doubly Linked List\n");
	printf("###################\n");
	printf("Enter Your Choice :\n");
	scanf("%d",&s);
	int n;
	head = NULL;
	tail = NULL;
	printf("\n\n Doubly Linked List : Create and display a doubly linked list :\n");
	printf("-------------------------------------------------------------------\n");	   	
    printf(" Input the number of nodes : ");
    scanf("%d", &n);
    switch(s){
    case 1:
    DlListcreation(n);
    displayDlList();
    break;

	case 5: 
    displayDlList();
    break;
    return 0;
}
}
void DlListcreation(int n){
	int i, num;
	struct node *tmp;
	if(n>=1){
		head = (struct node*)malloc(sizeof(struct node));
		if(head!=NULL){
			printf("Input Data for Node 1 :");
			scanf("%d",&num);
			head->num = num;
			head->pre = NULL;
			head->nxt = NULL;
			tail = head;
			for(i=2;i<=n;i++){
				tmp = (struct node*)malloc(sizeof(struct node));
				if(tmp!=NULL){
					printf("Input Data for node %d :\n", i);
                    scanf("%d", &num);
                    
                    tmp->num = num;
                    tmp->pre = tail;
                    tmp->nxt = NULL;
                    tail->nxt = tmp;
                    tail = tmp;
                }
                else
                {
                	printf("\nMemory Can't be Allocated :\n");
				}
                    
				}
			}
		}
	}
	
	void displayDlList(){
		struct node *temp;
		int n = 1;
		if(head==NULL){
			printf(" No data found in the List yet.");
		}
		else{
			temp = head;
			printf("\n\n Data entered on the list are :\n");
			while(temp!=NULL){
				printf(" node %d : %d\n", n, temp->num);
            n++;
            temp = temp->nxt;
			}
		}	 
	}
/*void DlLinsertNodeAtAny(int num, int pos){
    int i;
    struct node * newnode, *tmp;
    if(tail == NULL)
    {
        printf(" No data found in the list!\n");
    }
    else
    {
        tmp = head;
        i=1;
        while(i<pos-1 && tmp!=NULL)
        {
            tmp = tmp->nxt;
            i++;
        }
        if(pos == 1)
        {
            DlLinsertNodeAtBeginning(num);
        }
        else if(tmp == tail)
        {
            DlLinsertNodeAtEnd(num);
        }
        else if(tmp!=NULL)
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            newnode->num = num;           
            newnode->nxt = tmp->nxt;             
            newnode->pre = tmp;              
            if(tmp->nxt != NULL)
            {
                tmp->nxt->pre = newnode;
            tmp->nxt = newnode; 
        }
        else
        {
            printf(" The position you entered, is invalid.\n");
        }
    }
}
}
*/
