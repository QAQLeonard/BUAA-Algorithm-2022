#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, m;
int a[maxn];
pair<int, int> b[maxn], c[maxn];
bool vis[maxn];

int id(int x, int y){
	return (x - 1) * m + y;
}

const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= n;i++) for(int j = 1;j <= m;j++) scanf("%d", &a[id(i, j)]);
		for(int i = 1;i <= n;i++) for(int j = 1;j <= m;j++){
			int x;
			scanf("%d", &x);
			b[x] = {i, j};
		}
		for(int i = 1;i <= n;i++) for(int j = 1;j <= m;j++){
			c[id(i, j)] = {i - b[a[id(i, j)]].first, j - b[a[id(i, j)]].second};
		}
		for(int i = 1;i <= n * m;i++) vis[i] = false;
		int ans = 0;
		for(int i = 1;i <= n;i++) for(int j = 1;j <= m;j++) if(!vis[id(i, j)]){
			int sum = 0;
			queue<pair<int, int> > q;
			vis[id(i, j)] = true, q.push({i, j});
			while(!q.empty()){
				int x = q.front().first, y = q.front().second;q.pop();
				sum++;
				for(int k = 0;k < 4;k++){
					int xx = x + dx[k], yy = y + dy[k];
					if(xx >= 1 && xx <= n && yy >= 1 && yy <= m){
						if(c[id(x, y)] == c[id(xx, yy)] && !vis[id(xx, yy)]) vis[id(xx, yy)] = true, q.push({xx, yy});
					}
				}
			}
			ans = max(ans, sum);
		}
		printf("%d\n", ans);
	}
}
