#include <bits/stdc++.h>
#define maxn 10000086

using namespace std;

unsigned seed;

unsigned Rand() {
	seed ^= seed << 13;
	seed ^= seed >> 7;
	seed ^= seed << 17;
	return seed;
}

int t, n, k;
int fa[maxn];
unsigned a[maxn];
int q[maxn];

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d%u", &n, &k, &seed);
		for(int i = 1; i <= n; i++) fa[i] = i - 1;
		for(int i = 1; i <= n; i++) a[i] = Rand();
		unsigned ans = 0;
		int l = 1, r = 0;
		for(int i = 1; i <= n; i++) {
			while(l <= r && a[i] >= a[q[r]]) r--;
			q[++r] = i;
			if(i - k == q[l]) l++;
			ans += a[q[l]] ^ i;
		}
		printf("%u\n", ans);
	}
}
