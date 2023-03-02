#include <bits/stdc++.h>
#define maxn 20000086

using namespace std;

unsigned seed;

int Rand() {
	seed ^= seed << 13;
	seed ^= seed >> 7;
	seed ^= seed << 17;
	return seed & ((1 << 24) - 1);
}

int t, n, a[maxn];
int num[maxn];

int main() {
	scanf("%d", &t);
	while(t--) {
		memset(num, 0, sizeof(num));
		scanf("%d%u", &n, &seed);
		for(int i = 1; i <= n; i++) a[i] = Rand(), num[a[i]]++;
		unsigned ans = 0;
		int cnt = 0;
		for(int i = 0; i <= (1 << 24) - 1; i++) {
			while(num[i]--) cnt++, ans += i ^ cnt;
		}
		printf("%u\n", ans);
	}
}
