#include<iostream>
#include<cstring>
using namespace std;
long long dp[200001];
long long v[300001],w[300001];
long long i,j,m,n;
int main(){
	scanf("%lld%lld",&n,&m);

		dp[0]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld %lld",&v[i],&w[i]);
		}
		for(i=1;i<=n;i++)
		{
			for(j=m;j>=w[i];j--)
			{
				if(dp[j]<dp[j-w[i]]+v[i] )
					dp[j]=dp[j-w[i]]+v[i];			
			}
		}
		printf("%lld\n",dp[m]);
	
	return 0;
}
