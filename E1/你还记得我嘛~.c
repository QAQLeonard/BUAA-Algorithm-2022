#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int a[200000],A[200000],b[200000],B[200000];

typedef struct Node
{
	int k;
	int n;
	struct Node *next;
} LinkNode,*LinkList;

void InitList(LinkList *L)
{
	(*L)=(LinkNode *)malloc(sizeof(LinkNode));
	(*L)->k=0;
	(*L)->next=NULL;
}

void readin(int a0[],int A0[],int n,LinkList temp)
{
	LinkList end=temp;
	LinkList ftmp;
	for(int i=0; i<n; i++)
	{
		while (end!=NULL&&end->n<A0[i])
		{

			ftmp=end;
			end=end->next;
		}
		if(end==NULL)
		{
			LinkList h;
			//printf("rrrrnmd");
			InitList(&h);

			ftmp->next=h;
			end=h;
			h->k+=a0[i];
			h->n=A0[i];
			end=h;
			continue;
		}
		else if(end->n==A0[i])
		{
			end->k+=a0[i];
			continue;
		}
		else if(end->n>A0[i])
		{
			LinkList h;
			InitList(&h);
			h->k+=a0[i];
			h->n=A0[i];
			h->next=end;
			ftmp->next=h;
			end=h;
			continue;
		}
	}
}


int main()
{
	int t=0;
	int n=0,m=0;
	scanf("%d",&t);
	LinkNode temp;
	for(int time=0; time<t; time++)
	{
		scanf("%d",&n);
		for(int i=0; i<n; i++)
		{
			scanf("%d",&a[i]);
		}
		for(int i=0; i<n; i++)
		{
			scanf("%d",&A[i]);
		}
		temp.k=0;//存好第一项
		temp.n=A[0];
		temp.next=NULL;
		readin(a,A,n,&temp);
		scanf("%d",&m);
		for(int i=0; i<m; i++)
		{
			scanf("%d",&b[i]);
		}
		for(int i=0; i<m; i++)
		{
			scanf("%d",&B[i]);
		}
		readin(b,B,m,&temp);
		int K=0;
	LinkList end=&temp;
	while(end!=NULL)
	{
		if(end->k!=0)
		{
			K++;
			
		}
		end=end->next;
	}
	printf("%d\n",K);

	end=&temp;
	while(end!=NULL)
	{
		if(end->k!=0)
		{
			printf("%d ",end->k);
			
		}
		end=end->next;
	}
	printf("\n");

	end=&temp;
	while(end!=NULL)
	{
		if(end->k!=0)
		{
			printf("%d ",end->n);
			
		}
		end=end->next;
	}
	printf("\n");
	}
	


	return 0;
}
