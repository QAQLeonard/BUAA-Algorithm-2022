#include <bits/stdc++.h>
#define maxn 2086

using namespace std;

int t, n, m;
vector<pair<int, int> > v[maxn];
int d[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= n;i++) v[i].clear(), d[i] = 1e9;
		while(m--){
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			v[x].push_back({y, z});
		}
		d[1] = 0;
		bool tag = false;
		for(int j = 1;j <= n;j++){
			for(int i = 1;i <= n;i++){
				for(auto it : v[i]){
					int to = it.first, co = it.second;
					if(d[to] > d[i] + co && j == n) tag = true;
					d[to] = min(d[to], d[i] + co);
				}
			}
		}
		if(tag) puts("boo how");
		else{
			for(int i = 1;i <= n;i++) printf("%d ", d[i]);puts("");
		}
	}
} 
