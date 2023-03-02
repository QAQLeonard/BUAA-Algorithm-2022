#include<stdio.h>
#include<math.h>

#define eps 1e-8


int n,m;
int a[40000];
int b[40000];
int x=0,y=0;
long long int sum=0;


int main()
{
	int calculate_num=0;
	
	scanf("%d",&n);
	for(int i=0;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	scanf("%d",&m);
	for(int i=0;i<=m;i++)
	{
		scanf("%d",&b[i]);
	}	
	
	scanf("%d",&calculate_num);

	for(int i=0;i<calculate_num;i++)
	{
		sum=0;
		scanf("%d %d",&x,&y);
		long long int temp1=0;
		long long int temp2=0;
		for(int j=n;j>=0;j--)
		{
			temp1=(a[j]+x*temp1)%10007;
		}
		for(int j=m;j>=0;j--)
		{
			temp2=(b[j]+y*temp2)%10007;
		}
		sum=((temp1%10007)*(temp2%10007))%10007;
		printf("%lld\n",sum);
	}

	return 0;	
}
