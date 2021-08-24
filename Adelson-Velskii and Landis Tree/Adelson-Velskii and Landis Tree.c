// AVL TREE PROGRAM //

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct node{
	int data;
	struct node* left; 
	struct node* right;
	int ht;
}node;

node *insert(node *, int);
node *Delete(node *, int);
void preorder(node *);
void inorder(node *);
int height(node *);
node *rotateright(node *);
node *rotateleft(node *);
node *RR(node *);
node *LL(node *);
node *LR(node *);
node *RL(node *);
int BF(node *); 				// Balancing Factor //

int main(){
	node* root = NULL;
	int x, n, i, ch;
	while(1){
		printf("\n1)Create:");
        printf("\n2)Insert:");
        printf("\n3)Delete:");
        printf("\n4)Print:");
        printf("\n5)Quit:");
        printf("\n\nEnter Your Choice:");
        scanf("%d",&ch);
        
        switch(ch){
        	case 1: printf("\nEnter no. of elements:");
                    scanf("%d",&n);
                    printf("\nEnter tree data:");
                    root=NULL;
                    for(i=0;i<n;i++)
                    {
                        scanf("%d",&x);
                        root=insert(root,x);
                    }
            break;
                
            case 2: printf("\nEnter a data:");
                    scanf("%d",&x);
                    root=insert(root,x);
            break;
                    
            case 3: printf("\nEnter a data:");
                    scanf("%d",&x);
                    root=Delete(root,x);
            break;
            
            case 4: printf("\nPreorder sequence:\n");
                    preorder(root);
                    printf("\n\nInorder sequence:\n");
                    inorder(root);
                    printf("\n");
            break;            
		}
	}
	return 0;
}

node* insert(node* T, int x){
	if(T==NULL){
		T = (node*)malloc(sizeof(node));
		T->data = x;
		T->left = NULL;
		T->right = NULL;
	}
	else
		if(x > T->data){
			T->right = insert(T->right, x);
			if(BF(T)==-2)
				if(x > T->right->data)
					T = RR(T);
				else
					T = RL(T);
		}
		else
			if(x < T->data){
				T->left = insert(T->left, x);
					if(BF(T)==2)
						if(x < T->left->data)
							T = LL(T);
						else
							T = LR(T);
			}
		T->ht = height(T);        
        return(T);
}

int height(node* T){
	int lh, rh;
	if(T == NULL)
		return(0);
	if(T->left == NULL)
		lh = 0;
	else
		lh = 1+T->left->ht;
	if(T->right == NULL)
		rh = 0;
	else
		rh = 1+T->right->ht;
	if(lh>rh)
		return(lh);
	
	return(rh);
}

node* rotateright(node* x){
	node* y;
	y = x->left;
	x->left = y->right;
	y->right = x;
	x->ht = height(x);
	y->ht = height(y);
	return(y);
}

node* rotateleft(node* x){
	node* y;
	y = x->right;
	x->right = y->left;
	y->left = x;
	x->ht = height(x);
	y->ht = height(y);
	return(y);
}

node* RR(node* T){
	T = rotateleft(T);
	return(T);
}

node* LL(node* T){
	T = rotateright(T);
	return(T);
}

node* LR(node* T){
	T->left = rotateleft(T->left);
	T = rotateright(T);
	return(T);
}

node* RL(node* T){
	T->right = rotateright(T->right);
	T = rotateleft(T);
	return(T);
}

