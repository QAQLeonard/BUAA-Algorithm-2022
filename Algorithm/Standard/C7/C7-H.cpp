#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, m;
vector<pair<int, int> > v[maxn];
int d[maxn][4];
bool vis[maxn][4];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= n;i++) v[i].clear();
		while(m--){
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			v[x].push_back({y, z}), v[y].push_back({x, z});
		}
		priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
		for(int i = 1;i <= n;i++) for(int j = 0;j < 4;j++) d[i][j] = 0x3f3f3f3f, vis[i][j] = false; 
		d[1][0] = 0, q.push(make_tuple(0, 1, 0));
		while(!q.empty()){
			int x = get<1>(q.top()), y = get<2>(q.top());q.pop();
			if(vis[x][y]) continue;
			vis[x][y] = true;
			for(auto it : v[x]){
				int to = it.first, co = it.second;
				if(d[to][y] > d[x][y] + co){
					d[to][y] = d[x][y] + co;
					q.push(make_tuple(d[to][y], to, y));
				}
				if(!(y & 1) && d[to][y | 1] > d[x][y]){
					d[to][y | 1] = d[x][y];
					q.push(make_tuple(d[to][y | 1], to, y | 1));
				}
				if(!(y & 2) && d[to][y | 2] > d[x][y] + co * 2){
					d[to][y | 2] = d[x][y] + co * 2;
					q.push(make_tuple(d[to][y | 2], to, y | 2));
				}
				if(!(y & 3) && d[to][y | 3] > d[x][y] + co){
					d[to][y | 3] = d[x][y] + co;
					q.push(make_tuple(d[to][y | 3], to, y | 3));
				}
			}
		}
		for(int i = 2;i <= n;i++) printf("%d ", d[i][3]), assert(d[i][3] < 0x3f3f3f3f);puts("");
	}
}
