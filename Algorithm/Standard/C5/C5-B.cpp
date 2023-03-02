#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

inline int read(){
    int x = 0, f = 1;char ch = getchar();
    while(ch > '9' || ch < '0'){if(ch == '-') f = -1;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch -'0';ch = getchar();}
    return x * f;
}

int x[3], y[3];

void solve(){
	for(int i = 0; i < 3; i++){
		x[i] = read(), y[i] = read();
	}
	for(int i = 1; i < 3; i++) y[i] -= y[0], x[i] -= x[0];
	ll ans = abs(1ll * y[2] * x[1] - 1ll * y[1] * x[2]);
	printf("%lld.%d\n", ans / 2, ans & 1 ? 5 : 0);
	assert(ans != 0);
}

int main(){
	int t = read();
	while(t--){
		solve(); 
	}
   return 0;
}
