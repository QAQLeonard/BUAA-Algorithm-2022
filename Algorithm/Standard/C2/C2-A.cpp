#include<bits/stdc++.h>
#define maxn 1005
using ll = long long;
using namespace std;
int t, n, x[maxn], y[maxn];

int main() {
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		for(int i = 1; i <= n; i++) scanf("%d", x + i), scanf("%d", y + i);
		int ans = 200000;
		for(int i = 1; i <= n; i++) for(int j = 1; j < i; j++) ans = min(ans, max(abs(x[i] - x[j]), abs(y[i] - y[j])));
		printf("%d\n", ans);
	}
}
