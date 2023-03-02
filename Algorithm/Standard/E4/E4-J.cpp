#include <bits/stdc++.h>
#define maxn 505

using namespace std;

int t;
int n, m;
int a[maxn][maxn];
int d[maxn][maxn];
vector<int> v[maxn];
int fa[maxn];

void dfs(int i, int x){
	fa[i] = x;
	for(auto to : v[i]) dfs(to, x);
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) a[i][j] = d[i][j] = i == j ? 0 : 1e9;
		while(m--){
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			a[x][y] = a[y][x] = d[x][y] = d[y][x] = z;
		}
		for(int k = 1;k <= n;k++) for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++) v[j].clear();
			for(int j = 1;j <= n;j++) if(i ^ j){
				for(int k = 1;k <= n;k++) if(k ^ j) if(d[i][k] + a[k][j] == d[i][j]){
					v[k].push_back(j);
					break;
				}
			}
			for(auto to : v[i]) dfs(to, to);
			int ans = 1e9;
			for(int j = 1;j <= n;j++) if(i ^ j){
				if(fa[j] ^ j) ans = min(ans, a[i][j] + d[i][j]);
			}
			for(int j = 1;j <= n;j++) if(i ^ j) for(int k = j + 1;k <= n;k++) if(i ^ k){
				if(fa[j] ^ fa[k]) ans = min(1ll * ans, 1ll * a[j][k] + d[i][j] + d[i][k]);
			}
			printf("%d ", ans);
		}
		puts("");
	}
}
