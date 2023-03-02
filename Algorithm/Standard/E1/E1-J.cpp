#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

unsigned c[maxn];

void add(int x, unsigned y) {
	for(; x < maxn; x += x & -x) c[x] += y;
}

unsigned query(int x) {
	unsigned sum = 0;
	for(; x; x -= x & -x) sum += c[x];
	return sum;
}

int t, n;
int a[maxn], b[maxn];
unsigned f[maxn];

void solve(int l, int r) {
	if(l == r) {
		f[l]++;
		return;
	}
	int mid = l + r >> 1;
	solve(l, mid);
	vector<pair<int, int> > v;
	for(int i = l; i <= r; i++) v.push_back({a[i], -i});
	sort(v.begin(), v.end());
	for(auto it : v) {
		int i = -it.second;
		if(i <= mid) add(b[i], f[i]);
		else f[i] += query(b[i] - 1);
	}
	for(auto it : v) {
		int i = -it.second;
		if(i <= mid) add(b[i], -f[i]);
	}
	solve(mid + 1, r);
}

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		vector<int> v;
		for(int i = 1; i <= n; i++) scanf("%d", &b[i]), v.push_back(b[i]);
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		for(int i = 1; i <= n; i++) b[i] = lower_bound(v.begin(), v.end(), b[i]) - v.begin() + 1;
		for(int i = 1; i <= n; i++) f[i] = 0;
		solve(1, n);
		for(int i = 1; i <= n; i++) printf("%u ", f[i]);
		puts("");
	}
}
