#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, m;
vector<int> v[maxn];
int d[maxn];

int dfs(int i){
	if(d[i] != -1) return d[i];
	d[i] = 0;
	for(auto to : v[i]){
		d[i] = max(d[i], dfs(to));
	}
	return ++d[i];
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= n;i++) v[i].clear(), d[i] = -1;
		while(m--){
			int x, y;
			scanf("%d%d", &x, &y);
			v[x].push_back(y);
		}
		int ans = 0; 
		for(int i = 1;i <= n;i++) ans = max(ans, dfs(i));
		puts(ans == n ? "yy" : "nn");
	}
} 
