#include <bits/stdc++.h>
#define maxn 10

using namespace std;

int t, n, m;
int ans;
vector<pair<int, int> > v;
int tag[maxn][maxn];
int in1[maxn], out1[maxn], in0[maxn], out0[maxn];

void dfs(int i) {
	if(i == v.size()) {
		ans++;
		return;
	}
	int x = v[i].first, y = v[i].second;
	if(tag[x][y] != 1 && !(out1[x] & in1[y])) {
		out0[x] ^= 1 << y;
		in0[y] ^= 1 << x;
		dfs(i + 1);
		out0[x] ^= 1 << y;
		in0[y] ^= 1 << x;
	}
	if(tag[x][y] != 0 && !(out0[x] & out1[y]) && !(in1[x] & in0[y])) {
		out1[x] ^= 1 << y;
		in1[y] ^= 1 << x;
		dfs(i + 1);
		out1[x] ^= 1 << y;
		in1[y] ^= 1 << x;
	}
}

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) tag[i][j] = -1;
		while(m--) {
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			tag[x - 1][y - 1] = z;
		}
		v.clear();
		for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) if(i ^ j) v.push_back({i, j});
		ans = 0, dfs(0);
		printf("%d\n", ans);
	}
}
