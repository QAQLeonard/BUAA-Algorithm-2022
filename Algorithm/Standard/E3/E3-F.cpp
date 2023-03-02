#include<bits/stdc++.h>
#define N 2000

using namespace std;
vector<int>son[N];
int fa[N];
bool vis[N];
int ans[N];
void solve(int x)
{
	if(ans[x])
	{
		return;
	}
	ans[x]=1;
	for(int i=0;i<son[x].size();i++)
	{
		solve(son[x][i]);
		ans[x]+=ans[son[x][i]];
	}
}
int main()
{
	int t,n,k,x;
	int tmp;
	scanf("%d",&t);
	while(t--)
	{
		tmp=0;
		scanf("%d%d",&n,&k);
		for(int i=2;i<=n;i++)
		{
			scanf("%d",&x);
			fa[i]=x;
			son[x].push_back(i);
		}
		for(int i=n;i>=1;i--)
		{
			solve(i);
		}
		for(int i=1;i<=n;i++)
		{
			if(ans[i]%k==0)
			{
				tmp++;
			}
		}
		if(n%k==0&&tmp==n/k)
		{
			printf("YE5\n");
		}
		else
		{
			printf("N0\n");
		}
		for(int i=1;i<=n;i++)
		{
			son[i].clear();
		}
		memset(ans,0,sizeof(ans));
	}
}
