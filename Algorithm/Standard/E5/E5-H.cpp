#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 5;
const LL mod = 998244353;

LL x[maxn], POW[maxn], ans[maxn];

int main() {
	POW[0] = 1;
	for(int i=1; i<maxn; i++) POW[i] = (POW[i-1] * 2) % mod;

	int T, n;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i=1; i<=n; i++) scanf("%lld", &x[i]);
		sort(x+1, x+1+n);
		ans[n-1] = POW[x[n]-x[n-1]];
		for(int i=n-2; i>=1; i--) ans[i] = (POW[x[i+1]-x[i]] * (1 + ans[i+1])) % mod;
		int res = 0;
		for(int i=1; i<=n-1; i++) res = (res + ans[i]) % mod;
		printf("%lld\n", res);
	}

	return 0;
}
