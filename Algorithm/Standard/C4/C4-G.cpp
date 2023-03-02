#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, m;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		sort(a + 1, a + 1 + n);
		int ans = 0, l = 1, r = n;
		while(l <= r){
			if(l == r || a[l] + a[r] <= m) l++, r--;
			else r--;
			ans++;
		}
		printf("%d\n", ans);
	} 
} 
