#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int vertex;
	struct node* next;
}node;

node* G[20];
int visited[20];
int n;

void read_graph();
void insert(int,int);
void DFS(int);

void main(){
	int i;
	read_graph();
	for(i=0;i<n;i++){
		visited[i]=0;
	DFS(0);
	}
}

void DFS(int i){
	node* p;
	printf("\n%d",i);
	p = G[i];
	visited[i]=1;
	while(p!=NULL){
		i = p->vertex;
		if(!visited[i])
			DFS(i);
		p=p->next;
	}
}

void read_graph(){
	int i, vi, vj, e;
	printf("\nEnter number of Vertices\n");
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		G[i]=NULL;
		printf("\nEnter Number of Edges\n");
		scanf("%d",&e);
		
		for(i=0;i<e;i++){
			printf("\nEnter an Edge(u,v)\n");
			scanf("%d%d",&vi,&vj);
			insert(vi,vj);
		}
	}
}

void insert(int vi, int vj){
	node* p;
	node* q;
	
	q=(node*)malloc(sizeof(node));
    q->vertex=vj;
    q->next=NULL;
    if(G[vi]==NULL)
        G[vi]=q;
    else{
        p=G[vi];
        while(p->next!=NULL)
            p=p->next;
        p->next=q;
    }
}
