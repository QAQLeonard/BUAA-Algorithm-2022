#include<bits/stdc++.h>
#define maxn 1000005
using ll = long long;
using namespace std;
const int mod = 998244353;

inline ll read() {
	ll x = 0, f = 1;
	char ch = getchar();
	while(ch > '9' || ch < '0') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch -'0';
		ch = getchar();
	}
	return x * f;
}

int t, tot;
int f[maxn];

int main() {
	f[0] = 1;
	for(int i = 1; i <= 1000000; i++) {
		f[i] = f[i - 1];
		if(i > 1) f[i] = (f[i] + f[i - 2]) % mod;
		if(i > 2) f[i] = (f[i] + 4ll * f[i - 3]) % mod;
		if(i > 3) f[i] = (f[i] + 2ll * f[i - 4]) % mod;
	}
	t = read();
	while(t--) printf("%d\n", f[read()]);
}
