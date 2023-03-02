#include <bits/stdc++.h>
#define maxn 100086
using namespace std;
int t, n, m;
vector<pair<int, int> > v[maxn];
vector<tuple<int, int, int> > ans;

void dfs(int i, int fa){
	int x = i;
	for(auto it : v[i]){
		int to = it.first, co = it.second;
		if(to == fa) continue;
		ans.push_back(make_tuple(x, to, co));
		ans.push_back(make_tuple(x, ++m, 0));
		x = m;
		dfs(to, i);
	}
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) v[i].clear();
		for(int i = 1;i < n;i++){
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			v[x].push_back({y, z}), v[y].push_back({x, z});
		}
		m = n, ans.clear();
		dfs(1, 0);
		assert(m <= n * 2 && ans.size() + 1 == m); 
		printf("%d\n", m);
		for(auto it : ans) printf("%d %d %d\n", get<0>(it), get<1>(it), get<2>(it));
	}
}
