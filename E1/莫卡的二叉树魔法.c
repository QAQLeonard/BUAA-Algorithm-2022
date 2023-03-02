#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode
{
	int code;
    int color;
    int times;
	struct TreeNode *lchild;
	struct TreeNode *rchild;
} TreeNode,*Tree;

Tree tree[100005];

char colour[100005];

int cnt[100005];

Tree CREATE_TREE(int data) //创建一个树节点
{
	Tree T=(Tree)malloc(sizeof(TreeNode));
	T->code=data;
    T->color=-1;
    T->times=0;
	T->lchild=NULL;
	T->rchild=NULL;
	return T;
}

void PREORDER_TREE(Tree ROOT) //前序遍历
{
	if (ROOT != NULL)
	{
        if(ROOT->times%2==0)
        {
		    PREORDER_TREE(ROOT->lchild);
		    PREORDER_TREE(ROOT->rchild);
        }
        else
        {
            if(ROOT->lchild!=NULL) ROOT->lchild->times++;
			if(ROOT->rchild!=NULL) ROOT->rchild->times++;
            PREORDER_TREE(ROOT->lchild);
		    PREORDER_TREE(ROOT->rchild);
        }
	}
}

int main()
{
    int time=0;
    scanf("%d",&time);
    int node_num;
    for(int t=0;t<time;t++)
    {
        //对于每组数据，第一行一个正整数 n（1≤n≤105），表示二叉树的节点数量。
        memset(tree,0,sizeof(tree));
        scanf("%d",&node_num);
        for(int i=0;i<node_num;i++)
        {
            Tree T=CREATE_TREE(i);
            tree[i]=T;
        }
        
        
        //第二行 n?1 个正整数，第 i（1≤i≤n?1）个数表示编号为 i+1 的节点的父亲节点编号，数据保证是一棵二叉树。
        for(int i=1;i<node_num;i++)
        {
            int temp;
            scanf("%d",&temp);
            if(tree[temp-1]->lchild==NULL)
            {
                tree[temp-1]->lchild=tree[i];
            }
            else if(tree[temp-1]->rchild==NULL)
            {
                tree[temp-1]->rchild=tree[i];
            }
            else
            {
                printf("ERROR!!!");
                return 0;
            }
        }
        //printf("2 finished\n");
        
        //第三行一个长度为 n 的 01 串，从左到右第 i（1≤i≤n）位如果为 0，表示编号为 i 的节点颜色为白色，否则为黑色。
        scanf("%s",colour);
        for(int i=0;i<node_num;i++)
        {
            tree[i]->color=colour[i]-'0';
        }
        //printf("3 finished\n");
        //第四行一个正整数 q（1≤q≤105），表示魔法的释放次数。接下来 q 行每行一个正整数 ai（1≤ai≤n），表示第 i 次魔法选择的节点编号。
        for(int i=0;i<node_num;i++)
		{
		    if(tree[i]==NULL) printf("ERROR!!!\n");
		    
		}
		int q_time;
        scanf("%d",&q_time);
        for(int q=0;q<q_time;q++)
        {
            int tmp;
            scanf("%d",&tmp);
            cnt[tmp]++;
            if(cnt[tmp]==2) cnt[tmp]=0;
            tree[tmp-1]->times++;
            /*for(int i=0;i<node_num;i++)
			{
			        printf("%d ",tree[i]->color);
			        //free(tree[i]);
			}
			printf("\n");*/
        }
        PREORDER_TREE(tree[0]);
		//printf("4 finished\n");

        //输出
        for(int i=0;i<node_num;i++)
        {
            if(tree[i]->times%2!=0)
            {
                if(tree[i]->color==0) tree[i]->color=1;
                else tree[i]->color=0;
            }

            printf("%d",tree[i]->color);
            //free(tree[i]);
        }
        printf("\n");
        
    }

    return 0;
}
