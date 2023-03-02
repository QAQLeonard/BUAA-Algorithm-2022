#include <bits/stdc++.h>

using namespace std;

int t, a, b, k;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &a, &b, &k);
		long long x = 1;
		if(b > 1){
			for(int i = 1;i <= k && x <= a;i++) x *= b;
		}
		if(a == x) puts("n^k\\log n");
		else if(a > x) puts("n^{\\log_ba}");
		else puts("n^k");
	}
}
