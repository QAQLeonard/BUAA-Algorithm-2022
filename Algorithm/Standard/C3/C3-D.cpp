#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

typedef long long ll;

int t, n;
int a[maxn];
ll f[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		f[1] = a[1];
		if(n >= 2) f[2] = max(a[1], a[2]);
		for(int i = 3;i <= n;i++){
			f[i] = max({f[i - 1], f[i - 2] + a[i], 1ll * a[i]});
		}
		printf("%lld\n", f[n]);
	}
} 
