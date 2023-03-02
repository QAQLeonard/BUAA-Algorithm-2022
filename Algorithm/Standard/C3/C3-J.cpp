#include <bits/stdc++.h>
#define maxn 20

using namespace std;

int t, n, m;
unsigned f[1 << maxn], g[1 << maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		if(n < m) swap(n, m);
		for(int i = 0;i < (1 << m);i++) f[i] = g[i] = 0;
		f[0] = 1;
		for(int i = 0;i < n;i++) for(int j = 0;j < m;j++){
			for(int s = 0;s < (1 << m);s++){
				int ss = (s | (1 << j)) ^ (1 << j);
				g[ss] += f[s];
				if((j == 0 || !(s & (1 << (j - 1)))) && !(s & (1 << j))) g[ss | (1 << j)] += f[s];
			}
			for(int s = 0;s < (1 << m);s++) f[s] = g[s], g[s] = 0;
		}
		unsigned ans = 0;
		for(int i = 0;i < (1 << m);i++) ans += f[i];
		printf("%u\n", ans);
	}
}
