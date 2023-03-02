#include <stdio.h>
#include <math.h>

double c(int m,int n)
{
    double sa,sb,sc;
    sa=sb=sc=0.0;
    for(int i=2;i<=m;i++)
    {
        sa+=log((double)i);
    }
    sb=sa;
    for(int i=m+1;i<=n;i++)
    {
        sb+=log((double)i);
    }
    for(int i=2;i<=n-m;i++)
    {
        sc+=log((double)i);
    }
 
    return sb-sa-sc;
}
 
int main()
{
    int time=0;
    scanf("%d",&time);
    for(int t=0;t<time;t++)
    {
        int m,n;
        scanf("%d %d",&n,&m);  //n>=m!!!
        if(n>44721)
        {
            if(m>1&&m<n-1)
            {
                printf("-1\n");
                continue;
            }
            else if(m==1||m==n-1)
            {
                printf("%d\n",n);
                continue;
            }
            else
            {
                printf("1\n");
                continue;
            }
        }
        else if(n>1830)
        {
            if(m>2&&m<n-2)
            {
                printf("-1\n");
                continue;
            }
            else if(m==1||m==n-1)
            {
                printf("%d\n",n);
                continue;
            }
            else if(m==2||m==n-2)
            {
                printf("%d\n",n*(n-1)/2);
                continue;
            }
            else
            {
                printf("1\n");
                continue;
            }
        }
        double ans=c(m,n);
        if(ans>20.723265837) printf("-1\n");
        else
        {
            long int real_ans=0;
            real_ans=(long int)round(pow(exp(1),ans));
            printf("%ld\n",real_ans);
        }
    }
    
    
    return 0;
}
