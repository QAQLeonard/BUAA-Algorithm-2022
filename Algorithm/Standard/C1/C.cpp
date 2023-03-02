#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

const int p = 1e9 + 6;

int t, n;
int a[maxn], f[maxn], g[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		f[0] = 1;for(int i = 1;i <= n;i++) f[i] = 1ll * f[i - 1] * a[i] % p;
		g[n + 1] = 1;for(int i = n;i;i--) g[i] = 1ll * g[i + 1] * a[i] % p;
		for(int i = 1;i <= n;i++) printf("%d ", 1ll * f[i - 1] * g[i + 1] % p);puts("");
	}
}
