#include<bits/stdc++.h>
using namespace std;
int a[600000][3];
char s[10];
int ans[3];
int tr(char s[])
{
	int res=0;
	int len=strlen(s);
	for(int i=0;i<len;i++)
	{
		res=res*27+s[i]-'a'+1;
	}
	return res;
}
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		memset(a,0,sizeof(a));
		memset(ans,0,sizeof(ans));
		scanf("%d",&n);
		for(int j=0;j<3;j++)
		{
			for(int i=0;i<n;i++)
			{
				scanf("%s",s);
				a[tr(s)][j]++;
			}
		}
		for(int i=0;i<27*27*27*27;i++)
		{
			if(a[i][0]&&a[i][1]&&a[i][2])
			{
				continue;
			}
			else if(a[i][0]&&a[i][1])
			{
				ans[0]++;
				ans[1]++;
			}
			else if(a[i][0]&&a[i][2])
			{
				ans[0]++;
				ans[2]++;
			}
			else if(a[i][1]&&a[i][2])
			{
				ans[1]++;
				ans[2]++;
			}
			else if(a[i][0])
			{
				ans[0]+=3;
			}
			else if(a[i][1])
			{
				ans[1]+=3;
			}
			else if(a[i][2])
			{
				ans[2]+=3;
			}
		}
		for(int i=0;i<3;i++)
		{
			printf("%d ",ans[i]);
		}
		puts("");
	}
}
