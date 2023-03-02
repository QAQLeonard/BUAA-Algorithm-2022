#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, m;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		vector<pair<int, int> > v[2];
		while(m--){
			int x, y;
			scanf("%d%d", &x, &y);
			v[x < y].push_back({x, y}); 
		}
		if(v[0].size() < v[1].size()) swap(v[0], v[1]);
		printf("%d\n", v[0].size());
		for(auto it : v[0]) printf("%d %d\n", it.first, it.second);
	}
}
