#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

const int p = 1e9 + 7;

int n, q;
int a[maxn];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		a[x]++;
	}
	for(int i = 1; i <= 1000; i++) a[i] += a[i - 1];
	scanf("%d", &q);
	while(q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		int ans = 0;
		for(int i = 1; i <= 1000; i++) {
			int x = a[i] - a[i - 1];
			int L = (i + l - 1) / l, R = i / 2;
			if(L > R) continue;
			int sum1 = a[R] - (L ? a[L - 1] : 0);
			L = i * 2, R = i * r;
			if(L > 1000) continue;
			R = min(R, 1000);
			int sum2 = a[R] - a[L - 1];
			ans = (ans + 1ll * x * sum1 % p * sum2) % p;
		}
		printf("%d\n", ans);
	}
}
