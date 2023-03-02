#include <bits/stdc++.h>
#define maxn 1086

using namespace std;

typedef long long ll;

int t, n, m;
int a[maxn][maxn];
ll f[maxn][maxn]; 

int main(){
	memset(f, -0x3f, sizeof(f)), f[0][1] = 0;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= n;i++) for(int j = 1;j <= m;j++) scanf("%d", &a[i][j]);
		for(int i = 1;i <= n;i++) for(int j = 1;j <= m;j++){
			f[i][j] = max(f[i - 1][j], f[i][j - 1]) + a[i][j];
		}
		printf("%lld\n", f[n][m]);
	}
} 
