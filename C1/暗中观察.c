#include<stdio.h>

int main()
{
    int t;
    int n,k;
    scanf("%d",&t);
    
    for(int i=0;i<t;i++)
    {
        scanf("%d %d",&n,&k);
        if(k>n)
        {
            if(n%2==0) printf("~B~\n");
            else printf("~A~\n");
            
            continue;
        }
        else
        {
            printf("~B~\n");
            continue;
        }
    }
}