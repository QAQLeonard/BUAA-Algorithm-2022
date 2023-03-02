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

LinkList mergeTwoLists(LinkList a, LinkList b) 
{
    if ((a==NULL) || (b==NULL)) return a ? a : b;
    LinkNode head;
    LinkList tail = &head, aPtr = a, bPtr = b;
    while (aPtr!=NULL && bPtr!=NULL) 
    {
        if (aPtr->num < bPtr->num) 
        {
            tail->next = aPtr; aPtr = aPtr->next;
        } 
        else 
        {
            tail->next = bPtr; bPtr = bPtr->next;
        }
        tail = tail->next;
    }

    tail->next = (aPtr ? aPtr : bPtr);
    return head.next;
}

LinkList merge(LinkList lists[], int left, int right) 
{
    if (left == right) return lists[right];
    if (left > right) return NULL;
    int mid = (left + right) /2;
    //printf("ccc%dccc\n",mid);
    return mergeTwoLists(merge(lists, left, mid), merge(lists, mid + 1, right));
}

LinkList mergeKLists(LinkList lists[],int arr_num) 
{
    return merge(lists, 0, arr_num - 1);
}



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
			InitList(&Node[k]);
			Node[k]->next=NULL;
            scanf("%d",&Node[k]->num);
            LinkList end=Node[k];
            for(int i=1;i<arr_length;i++)
            {
                scanf("%d",&temp);
                LinkList h;
                InitList(&h);
                h->num=temp;
                end->next=h;
                end=h;
            }
        }
        LinkList ans;
        ans=mergeKLists(Node,arr_num);
        while(ans!=NULL)
        {
            printf("%d ",ans->num);
            //LinkList tmp=ans;
            ans=ans->next;
            //free(tmp);
        }
        printf("\n");
        /*for(int k=0;k=arr_num;k++)
        {
            LinkList end=Node[k];
            LinkList tmp;
        }*/
    }

    return 0;
}
