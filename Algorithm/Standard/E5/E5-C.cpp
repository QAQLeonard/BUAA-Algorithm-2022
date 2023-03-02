#include<bits/stdc++.h>
using namespace std;
const int N = 500;
char s[N];
int a[N],p[N],b[N],q[N];
bool mat[N][N];
bool vis[N];
int girl[N];
int n;
bool find(int x)
{
	for(int i=1;i<=n;i++)
	{
		if(mat[x][i]&&!vis[i])
		{
			vis[i]=true;
			if(!girl[i]||find(girl[i]))
			{
				girl[i]=x;
				return true;
			}
		}
	}
	return false;
}
int main()
{

	int t=1;
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&p[i]);
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&b[i]);
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&q[i]);
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(b[j]>=p[i]&&a[i]>=q[j])
				{
					mat[i][j]=true;
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			memset(vis,0,sizeof(vis));
			if(find(i))
			{
				ans++;
			}
		}
		printf("%d",ans);
	}
}


