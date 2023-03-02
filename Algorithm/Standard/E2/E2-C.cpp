#include <bits/stdc++.h>

using namespace std;

int t, n, m;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		int ans = 1;
		for(int i = 1;i <= (n + 1) / 2;i++) ans *= n - i + 1, ans /= i;
		if(ans < m){
			puts("-1");
			continue;
		}
		for(int i = 0;i < (1 << n) && m;i++) if(__builtin_popcount(i) == (n + 1) / 2){
			m--;
			printf("%d ", (n + 1) / 2);
			for(int j = 0;j < n;j++) if(i & (1 << j)) printf("%d ", j + 1);puts(""); 
		}
	}
}
