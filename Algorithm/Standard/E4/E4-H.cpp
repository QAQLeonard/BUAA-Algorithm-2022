#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, m;
vector<int> v[maxn];
int fa[maxn], siz[maxn];

int find(int x){
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void merge(int x, int y){
	x = find(x), y = find(y);
	if(x == y) return;
	if(siz[x] > siz[y]) swap(x, y);
	fa[x] = y, siz[y] += siz[x];
}

bool vis[maxn];

void cal(int i, int j){
	for(auto to : v[i]) vis[to] = j;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= n;i++) v[i].clear(), fa[i] = i, siz[i] = 1;
		while(m--){
			int x, y;
			scanf("%d%d", &x, &y);
			v[x].push_back(y), v[y].push_back(x);
		}
		int x = 1;
		for(int i = 2;i <= n;i++) if(v[i].size() < v[x].size()) x = i;
		cal(x, 1);
		for(int i = 1;i <= n;i++) if(!vis[i]) merge(x, i);
		cal(x, 0);
		for(auto to : v[x]){
			cal(to, 1);
			for(int i = 1;i <= n;i++) if(!vis[i]) merge(to, i);
			cal(to, 0);
		}
		for(int i = 1;i <= n;i++) printf("%d ", siz[find(i)]);puts("");
	}
}
