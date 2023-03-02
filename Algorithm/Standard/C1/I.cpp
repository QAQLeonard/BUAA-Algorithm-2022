#include<bits/stdc++.h>
using namespace std;
int solve(int x)
{
	int res=0;
	while(x>0)
	{
		x>>=1;
		res++;
	}
	return res;
}
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(n%4==0)
		{
			printf("%d\n",n-1);
		}
		else if(n%4==3)
		{
			printf("%d\n",n);
		}
		else if(n%4==1)
		{
			printf("%d\n",n);
		}
		else if(n%4==2)
		{
			if(solve(n+2)>solve(n))
			{
				printf("%d\n",n+3);
			}
			else
			{
				printf("%d\n",n+2);
			}
		}
	}
}
