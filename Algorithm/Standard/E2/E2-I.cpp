#include <bits/stdc++.h>
#define maxn 10000086

using namespace std;

unsigned seed;

unsigned Rand(){
	seed ^= seed << 13;
	seed ^= seed >> 7;
	seed ^= seed << 17;
	return seed;
}

int t, n, k;
unsigned a[maxn];

unsigned ans;
int dep[maxn];
int q[maxn], l, r;

void dfs(int i){
	if(i > n) return;
	int L = l, R = r;
	while(l <= r && a[q[r]] <= a[i]) r--;
	int x = q[++r];
	q[r] = i;
	if(dep[i] - dep[q[l]] == k) l++;
	ans += a[q[l]] ^ i;
	if(i == 1){
		dep[n - 999] = dep[i] + 1;
		dfs(n - 999);
	}else if(i == n){
		dep[2] = dep[i] + 1, dfs(2);
		dep[3] = dep[i] + 1, dfs(3);
	}else if(i > n - 1000){
		dep[i + 1] = dep[i] + 1;
		dfs(i + 1);
	}else{
		if((i << 1) <= n - 1000){
			dep[i << 1] = dep[i] + 1;
			dfs(i << 1);
		}
		if((i << 1 | 1) <= n - 1000){
			dep[i << 1 | 1] = dep[i] + 1;
			dfs(i << 1 | 1);
		}
	}
	q[r] = x;
	l = L, r = R;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%u", &n, &k, &seed);
		for(int i = 1;i <= n;i++) a[i] = Rand();
		ans = 0, l = 1, r = 0, dfs(1);
		printf("%u\n", ans);
	}
} 
