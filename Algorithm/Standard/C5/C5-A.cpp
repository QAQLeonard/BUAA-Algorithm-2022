#include <bits/stdc++.h>
#define maxn 305

using namespace std;

int t, n, m;
int d[maxn][maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) d[i][j] = i == j ? 0 : 1e9;
		while(m--){
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			d[x][y] = d[y][x] = z;
		}
		for(int k = 1;k <= n;k++) for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
		int M = 0, k = 0;
		for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) M = max(M, d[i][j]);
		for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) if(d[i][j] == M) k++;
		printf("%d %d\n", M, k);
		for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) if(d[i][j] == M) printf("%d %d\n", i, j);
	}
}
