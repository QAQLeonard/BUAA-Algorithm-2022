#include<iostream>
#define maxn 1010
typedef long long LL;
using namespace std;
LL e[maxn][maxn], w[maxn][maxn], p[maxn], q[maxn], n;
void OBST()
{
	for(LL i=1;i<=n+1;i++)
		e[i][i-1] = w[i][i-1] = q[i-1];
	for(LL k=1;k<=n;k++)
	{
		for(LL i=1;i<=n-k+1;i++)
		{
			LL j = i+k-1;
			e[i][j] = 0x7ffffff;
			w[i][j] = w[i][j-1] + p[j] +q[j];
			for(LL r = i;r<=j;r++)
			{
				LL t = e[i][r-1] + e[r+1][j] + w[i][j];
				if(t < e[i][j])	e[i][j] = t;
			}
		}
	}
}
int main(){
	scanf("%lld",&n);
	for(LL i = 1;i<=n;i++)	scanf("%lld",&p[i]);
	for(LL i = 0;i<=n;i++) scanf("%lld",&q[i]);
	OBST();
	printf("%lld\n",e[1][n]);
	return 0;
}
