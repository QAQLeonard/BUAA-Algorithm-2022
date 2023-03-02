#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

const ll p = 4179340454199820289ll;

ll fpow(ll x, int y) {
	ll ans = 1;
	while(y) {
		if(y & 1) ans = (__int128)ans * x % p;
		x = (__int128)x * x % p, y >>= 1;
	}
	return ans;
}

int t, k;
int a[maxn];

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &k);
		for(int i = 1; i <= 1e5; i++) a[i] = 0;
		int cnt = 0;
		ll now = fpow(3, k);
		while(cnt < 1e5) {
			ll x = now;
			int y = 0;
			for(int i = 1; i <= 1e5; i *= 10) {
				if(!x) break;
				y += i * (x % 10), x /= 10;
				if(y > 1e5) break;
				if(y && !a[y]) a[y] = k, cnt++;
			}
			now = (__int128)now * 3 % p, k++;
		}
		for(int i = 1; i <= 1e5; i++) printf("%d ", a[i]);
		puts("");
	}
}
