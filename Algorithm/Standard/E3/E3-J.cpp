#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t, n, m, k;
map<int, int> mp;
int cnt;

void dfs(int i, int j){
	if(i & (i << 1)) return;
	if(j == m){
		mp[i] = ++cnt;
		return;
	}
	dfs(i, j + 1), dfs(i | (1 << j), j + 1);
}

int a[maxn][30][2];
unsigned f[maxn], g[maxn];
int b[1005][1005];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &n, &m, &k);
		bool tag = false, flag = false;
		if(n < m) swap(n, m), tag = true;
		for(int i = 0;i < n;i++) for(int j = 0;j < m;j++) b[i][j] = -1;
		while(k--){
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			if(tag) swap(x, y);
			x--, y--;
			if(b[x][y] == -1) b[x][y] = z;
			else if(b[x][y] != z) flag = true;
		}
		if(flag){
			puts("0");
			continue; 
		}
		mp.clear();
		cnt = 0, dfs(0, 0);
		for(auto it : mp){
			int S = it.first, x = it.second;
			for(int i = 0;i < m;i++){
				a[x][i][0] = mp[S & ~(1 << i)];
				if((i == 0 || !(S & (1 << (i - 1)))) && !(S & (1 << i))){
					a[x][i][1] = mp[(S | (1 << i)) & ~(1 << (i + 1))];
				}else{
					a[x][i][1] = 0;
				}
			}
		}
		for(int i = 1;i <= cnt;i++) f[i] = 0;
		f[mp[0]] = 1;
		for(int i = 0;i < n;i++) for(int j = 0;j < m;j++){
			for(int k = 1;k <= cnt;k++){
				if(b[i][j] != 1) g[a[k][j][0]] += f[k];
				if(b[i][j] != 0 && a[k][j][1]) g[a[k][j][1]] += f[k];
			}
			for(int k = 1;k <= cnt;k++) f[k] = g[k], g[k] = 0;
		}
		unsigned ans = 0;
		for(int i = 1;i <= cnt;i++) ans += f[i];
		printf("%u\n", ans);
	}
}
