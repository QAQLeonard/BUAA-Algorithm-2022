#include <stdio.h>
#include <string.h>
#define maxn 205

int n, m;
int a[maxn][maxn];
int tag[maxn][maxn], g[maxn][maxn];
int f[maxn][maxn];

int solve(){
	if(tag[1][1]) return 0;
	f[1][1] = 1;
	int i, j;
	for(i = 1;i <= n;i++){
		for(j = 1;j <= m;j++){
			if(tag[i][j]) continue;
			f[i][j] |= f[i - 1][j] | f[i][j - 1];
		}
	}
	return f[n][m];
}

int main(){
	int t, ans, i, j, x;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		memset(tag, 0, sizeof(tag));
		ans = 0;
		for(i = 1;i <= n;i++){
			for(j = 1;j <= m;j++){
				scanf("%d", &a[i][j]);
			}
		}
		for(x = 1 << 29;x;x >>= 1){
			memset(f, 0, sizeof(f));
			memset(g, 0, sizeof(g));
			for(i = 1;i <= n;i++){
				for(j = 1;j <= m;j++){
					if(tag[i][j]) continue;
					if(!(a[i][j] & x)){
						g[i][j] = tag[i][j] = 1;
					}
				}
			}
			if(solve()){
				ans += x;
			}else{
				for(i = 1;i <= n;i++){
					for(j = 1;j <= m;j++){
						if(g[i][j]) tag[i][j] = 0;
					}
				}
			}
		}
		printf("%d\n", ans);
	}
}
