#include<stdio.h>
#define ll long long int
#define M 1000100

ll MOD=998244353;
ll result[M]= {1, 1, 2, 9, 21, 48};
ll sum[M]= {1, 2, 4, 13, 34, 82};
int main() {
	int t, n, i, j;
	scanf("%d",&t);
	for(i=6; i<M; i++) {
		result[i] = (result[i-1] + result[i-2] + 4*result[i-3] + 2*result[i-4] +2*sum[i-3])%MOD;
		sum[i] = (sum[i-1] + result[i])%MOD;
	}
	for(i=0; i<t; i++) {
		scanf("%d",&n);
		printf("%lld\n",result[n]);
	}
	return 0;
}
