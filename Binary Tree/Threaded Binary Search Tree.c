#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct tNodes tNode;
typedef struct tNodes
{
	int data;
	tNode *l, *r;
	bool rt;
}tNode;

tNode *root;

tNode *createNode(int val)
{
	tNode *n = (tNode*) malloc(sizeof(tNode));
	if(!n) printf("\nNode could not be created.\n");
	else
	{
		n->data = val;
		n->l = n->r = NULL;
		n->rt = true;
	}
}

int main()
{
	int ch,input;
	tNode *n;
	int p,i;
	printf("enter the values\n");
	for(i=0;i<7;i++)
	{
	scanf("%d",&p);
	n=createNode(p);
	insertNode(n);
	}
	printf("inorder traversal is:-    \n");
	io();
}

void insertNode(tNode *n)
{
	if(!root) 
	{
		root = n;
		return;
	}
	
	tNode *p, *tmp;
	tmp = root;
	while(tmp)
	{
		if(tmp->data == n->data)
		{
			printf("\nDuplicate key.\n");
			return;
		}
		
		p = tmp;
		
		if(n->data < tmp->data)
		{
			if(tmp->l) 
			tmp = tmp->l;
			else break;
		}else{
			if(tmp->rt)
			 break;
			 else 
			 tmp = tmp->r;
		}
	}
	
	if(n->data < p->data)
	{
		p->l = n;
		n->r = p;
	}else
	{
		n->r = p->r;
		p->r = n;
		p->rt = false;
	}
}

tNode *is(tNode *n)
{
	tNode *tmp = n->r;
	if( !(n->rt) )
		while(tmp->l) tmp = tmp->l;
	return tmp;
}

void io()
{
	tNode *tmp = root;
	while(tmp->l) tmp = tmp->l;
	while(tmp)
	{
		printf("%d ", tmp->data);
		tmp = is(tmp);
	}
}
