#include<stdio.h>
#include<math.h>
int main()
{
    int t=0;
    long long int z,k;
    int ans;
    scanf("%d",&t);
    for(int time=0;time<t;time++)
    {
        ans=0;
        scanf("%d %d",&z,&k);
        if(k>2) ans=0;
        else if(k==1) ans=z-1;
        else//k=2
        {
            for(long long int x=1;x<z;x++)
            {
                long long int y=round(sqrtl(z*z-x*x));
                if(y*y+x*x==z*z)
                //if(round(sqrt(z*z-x*x))*round(sqrt(z*z-x*x))==z*z-x*x)
                {
                    //printf("%d %ddnmd\n",x,y);
                    ans++;
                    
                }
            }
        }
        printf("%d\n",ans);
    }
}