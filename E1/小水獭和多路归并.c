#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node
{
	int num;
	struct Node *next;
} LinkNode,*LinkList;


void InitList(LinkList *L)
{
	(*L)=(LinkNode *)malloc(sizeof(LinkNode));
	(*L)->next=NULL;
}

LinkList Node[100005];
LinkList TOP[100005];

int main()
{
	
    int time=0;
    scanf("%d",&time);
    int arr_num,arr_length;
    for(int t=0;t<time;t++)
    {
        scanf("%d %d",&arr_num,&arr_length);
        for(int k=0;k<arr_num;k++)
        {
            int temp;
            if(Node[k]==NULL)
            {
				InitList(&Node[k]);
				Node[k]->next=NULL;
			}
            TOP[k]=Node[k];
            scanf("%d",&Node[k]->num);
            LinkList end=Node[k];
            for(int i=1;i<arr_length;i++)
            {
                scanf("%d",&temp);
                if(end->next==NULL)
                {
                	LinkList h;
                	InitList(&h);
                	h->num=temp;
                	end->next=h;
                	end=h;
				}
				else
				{
					end->next->num=temp;
					end=end->next;
				} 
            }
        }

        for(int i=0;i<arr_length*arr_num;i++)
        {
            int min=INT_MAX;
            int code=INT_MAX;
            for(int k=0;k<arr_num;k++)
            {
                if(TOP[k]!=NULL && TOP[k]->num<min)
                {
                    code=k;
                    min=TOP[k]->num;
                }
            }
            printf("%d ",min);
            TOP[code]=TOP[code]->next;

        }
        printf("\n");
    }

    return 0;
}
