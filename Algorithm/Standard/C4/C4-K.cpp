#include<bits/stdc++.h>
using namespace std;
const int N = 2000;
char s[N];
long long a[N];
struct fgo{
	int x;
	int y;
}f[N];
bool cmp(long long x,long long y)
{
	return x>y;
}
int main()
{
	int t=1,n;
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&f[i].x,&f[i].y);
		}
		long long ans=0;
		int ansi=1;
		for(int i=n;i>=1;i--)
		{
			long long tmp=0;
			for(int j=0;j<n;j++)
			{
				a[j]=(long long)f[j].x-(long long)f[j].y*(i-1);
			}
			sort(a,a+n,cmp);
			for(int j=0;j<i;j++)
			{
				tmp+=a[j];
			}
			if(ans<=tmp)
			{
				ans=tmp;
				ansi=i;	
			}
		}
		printf("%lld\n",ans);
		printf("%d",ansi);
		
	}
}
