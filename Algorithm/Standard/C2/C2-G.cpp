#include<bits/stdc++.h>
#define maxn 505
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

int t, n, mp[maxn][maxn], col[maxn][maxn], cnt[maxn * maxn], now;
char s[maxn];

int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

void dfs(int x, int y) {
	if(col[x][y]) return ;
	col[x][y] = now;
	cnt[now]++;
	for(int i = 0; i < 4; i++) {
		int xx = x + dx[i], yy = y + dy[i];
		if(xx < 1 || xx > n || yy < 1 || yy > n) continue;
		if(mp[xx][yy] == 0) continue;
		if(col[xx][yy]) continue;
		dfs(xx, yy);
	}
}

int main() {
	t = read();
	while(t--) {
		n = read();
		for(int i = 1; i <= n; i++) {
			scanf("%s", s + 1);
			for(int j = 1; j <= n; j++) mp[i][j] = s[j] - '0', cnt[(i - 1) * n + j] = col[i][j] = 0;
		}
		for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) if(mp[i][j] == 1 && !col[i][j])
					now++, dfs(i, j);
		vector<int> ans;
		for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) if(!mp[i][j]) {
					set<int> s;
					int tot = 0;
					for(int k = 0; k < 4; k++) {
						int xx = i + dx[k], yy = j + dy[k];
						if(xx < 1 || xx > n || yy < 1 || yy > n) continue;
						if(mp[xx][yy] == 0) continue;
						s.insert(col[xx][yy]);
					}
					for(auto x: s) tot += cnt[x];
					ans.push_back(tot);
				}
		sort(ans.begin(), ans.end());
		printf("%d\n", ans.size());
		for(auto x: ans) printf("%d ", x);
		puts("");
	}
}
