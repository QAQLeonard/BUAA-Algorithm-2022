#include<stdio.h>
#include<math.h>

long long int a[200000];

#define eps 1e9+6

long long int temp1[200000];
long long int temp2[200000];

int main()
{
    int data_num=0;
	scanf("%d",&data_num);
    long long int m=1000000006;

    int n=0;
    a[0]=1;
	
    for(int i=0;i<data_num;i++)
    {
        scanf("%d",&n);
        temp1[0]=1;
        temp2[n+1]=1;
        for(int j=1;j<=n;j++)
        {
            scanf("%lld",&a[j]);
        }
        
        long long int ans=1;
        
        for(int j=1;j<=n;j++)
        {
            temp1[j]=(temp1[j-1]*a[j])%m;
        }

        for(int j=n;j>=1;j--)
        {
            temp2[j]=(temp2[j+1]*a[j])%m;
        }

        for(int i=1;i<=n;i++)
        {           
            ans=1;
            ans*=((temp1[i-1]%m)*(temp2[i+1]%m))%m;
            printf("%lld ",ans);
        }
        printf("\n");
    }
    return 0;
}
