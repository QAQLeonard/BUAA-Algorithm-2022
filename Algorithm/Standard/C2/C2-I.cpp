#include<bits/stdc++.h>
#define maxn 1000005
using namespace std;

inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while(ch > '9' || ch < '0') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch -'0';
		ch = getchar();
	}
	return x * f;
}

vector<int> app[maxn];
int a[maxn], n, q;

int main() {
	srand(time(0));
	n = read();
	for(int i = 1; i <= n; i++) a[i] = read(), app[a[i]].push_back(i);
	q = read();
	for(int i = 1; i <= q; i++) {
		int l = read(), r = read(), k = read(), ok = (r - l + 1 + k - 1) / k;
		int ans = -1;
		for(int t = 1; t <= 60; t++) {
			int x = a[rand() % (r - l + 1) + l];
			if(lower_bound(app[x].begin(), app[x].end(), r + 1) - upper_bound(app[x].begin(), app[x].end(), l - 1) >= ok)
				ans = x;
		}
		printf("%d\n", ans);
	}
}
