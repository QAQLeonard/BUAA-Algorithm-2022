#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define eps 1e-14
#define maxn 100005
#define ls (tot << 1)
#define rs (tot << 1 | 1)
#define PII pair<int, int>
#define fi first
#define se second
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;
const double pi = acosl(-1.0L);
const int mod = 998244353;
inline ll read(){
    ll x = 0, f = 1;char ch = getchar();
    while(ch > '9' || ch < '0'){if(ch == '-') f = -1;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch -'0';ch = getchar();}
    return x * f;
}



ll n, A, B, C;


void solve(){
	ll ans = 0;
	
	n = read(), A = read(), B = read(), C = read();
	if(A > B) swap(A, B);if(A > C) swap(A, C);if(B > C) swap(B, C);
	ll sum = n * (A + B + C);
	for(int i = 0; i <= n; i++){
		ll mn = 1ll * A * i + 1ll * B * (n - i);
		if(mn * 3 >= sum || B == C){
			if(abs(ans * 3 - sum) > abs(mn * 3 - sum)) ans = mn;
		}else{
			ll delta = (C - B) * 3, nd = sum - mn * 3;
			ll down = nd / delta, up = down + 1;
			if(down >= n - i) down = up = n - i;
			mn = 1ll * A * i + 1ll * B * (n - i - down) + 1ll * C * down;
			if(abs(ans * 3 - sum) > abs(mn * 3 - sum)) ans = mn;
			mn = 1ll * A * i + 1ll * B * (n - i - up) + 1ll * C * up;
			if(abs(ans * 3 - sum) > abs(mn * 3 - sum)) ans = mn;
		}
	}
	printf("%lld\n", ans);
}

int main(){

	int t = read();
	while(t--){
		solve();
	}
	
   return 0;
}
