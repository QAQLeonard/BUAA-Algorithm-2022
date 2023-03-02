#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct Node
{
    int game_code;//记录该单词在第几轮出现;
    bool flag[3];//flag0:the_ignorant; flag1:Zhoues; flag2:2sozx;
    int p_num;
	struct Node *letter[26];
    bool isword;
} LinkNode, *LinkList;

char buffer[10];

int score[5];

void read(char word[],int f,LinkList *Root)
{
    LinkList end=*Root;
	int i=0;
	while(word[i]!='\0')
	{
        if(end->letter[word[i]-'a']==NULL)
		{
			LinkList p=(LinkList)malloc(sizeof(LinkNode));
			memset(p->letter,0,sizeof(p->letter));
            p->isword=false;
            p->p_num=0;
            p->flag[0]=false;
            p->flag[1]=false;
            p->flag[2]=false;
			end->letter[word[i]-'a']=p;
		}
		end=end->letter[word[i]-'a'];
		i++;
	}

	if(word[0]!='\0') 
    {
        end->flag[f] = true;
        end->p_num++;
        end->isword=true;
    }
}

void PREORDER_TREE(LinkList ROOT) //前序遍历
{

    if (ROOT != NULL)
	{
        if(ROOT->isword)
        {
            switch (ROOT->p_num)
            {
            case 0:
                printf("ERROR in p_num=0!");
                return ;
                break;
            
            case 1:
                for(int i=0;i<3;i++)
                {
                    if(ROOT->flag[i])
                    {
                        score[i]+=3;
                        break;
                    }
                }
                break;
            
            case 2:
                for(int i=0;i<3;i++)
                {
                    if(ROOT->flag[i])
                    {
                        score[i]+=1;
                    }
                }
                break;
            
            case 3:
                break;

            default:
                printf("ERRER IN READ");
                return ;
                break;
            }
        }
            for(int i=0;i<26;i++)
            {
                PREORDER_TREE(ROOT->letter[i]);
            }
	}
}

void DELETE_TREE(LinkList ROOT)
{
	if (ROOT != NULL)
	{
		for(int i=0;i<26;i++)
        {
            DELETE_TREE(ROOT->letter[i]);
        }		
		free(ROOT);
	}
}

int main()
{
    int game_time=0;
    scanf("%d",&game_time);

    int word_num=0;
    
    

    for(int i=0;i<game_time;i++)
    {
        LinkList Root = (LinkList)malloc(sizeof(LinkNode));
        memset(Root->letter,0,sizeof(Root->letter));
        Root->isword=false;
        Root->p_num=0;
        Root->flag[0]=false;
        Root->flag[1]=false;
        Root->flag[2]=false;

        scanf("%d",&word_num);
        for(int j=0;j<3;j++)//j=flag
        {
            for(int k=0;k<word_num;k++)
            {
                scanf("%s",buffer);
                read(buffer,j,&Root);
            }
        }

        PREORDER_TREE(Root);
        printf("%d %d %d\n",score[0],score[1],score[2]);

        score[0]=0;
        score[1]=0;
        score[2]=0;
        DELETE_TREE(Root);
    }
    
    return 0;
}