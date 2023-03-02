#include <stdio.h>
#include <limits.h>
#include <math.h>

typedef struct POINT
{
    int x;
    int y;
}point;

point p[1005];

int max(point a,point b)
{
    if(abs(a.x-b.x)>abs(a.y-b.y)) return abs(a.x-b.x);
    else return abs(a.y-b.y);
}

int main()
{
    int time=0,n=0;
    scanf("%d",&time);
    int ans=0;
    for(int t=0;t<time;t++)
    {
        ans=INT_MAX;
        scanf("%d",&n);
        int tmp_x,tmp_y;
        for(int i=0;i<n;i++)
        {
            scanf("%d %d",&p[i].x,&p[i].y);
        }
        //printf("!!!!!!!%d",max(p[0],p[1]));
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int temp=max(p[i],p[j]);
                if (temp<ans)
                {
                    ans=temp;
                }
            }
        }
        printf("%d\n",ans);
    }
}