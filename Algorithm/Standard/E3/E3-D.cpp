#include <bits/stdc++.h>
#define maxn 5086

using namespace std;

typedef long long ll;

int t, n, m;
int a[maxn];
ll f[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= m;i++) scanf("%d", &a[i]);
		for(int i = 1;i <= n;i++) f[i] = -1e18;
		f[0] = 0;
		for(int i = 1;i <= n;i++){
			for(int j = n;j >= 0;j--){
				f[j] = -1e18;
				for(int l = 1;l <= m && j - l >= 0;l++) f[j] = max(f[j], f[j - l] + a[l]);
			}
			if(i >= (n + m - 1) / m) printf("%lld ", f[n]);
		}
		puts("");
	}
}
