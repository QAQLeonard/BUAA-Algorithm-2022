#include<bits/stdc++.h>
#define maxn 3000005
using ll = long long;
using namespace std;

inline int read(){
    int x = 0, f = 1;char ch = getchar();
    while(ch > '9' || ch < '0'){if(ch == '-') f = -1;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch -'0';ch = getchar();}
    return x * f;
}

map<int, int> mp;

int a[maxn], n, q;
ll ans[maxn], bit[maxn];
void add(int x, int v){for(int i = x; i <= n; i += i & -i) bit[i] += v;}
ll getb(int x){ll ans = 0;for(int i = x; i; i -= i & -i) ans += bit[i];return ans;}
vector<pair<int, int>> v[maxn];

int main(){
	n = read(), q = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	for(int i = 1; i <= q; i++){
		int l = read(), r = read();
		assert(1 <= l && l <= r && r <= n);
		v[r].push_back({l, i});
	}
	for(int i = 1; i <= n; i++){
		if(mp.count(a[i])){
			int x = mp[a[i]];
			add(x, i - x);
		}
		mp[a[i]] = i;
		for(auto x: v[i]){
			ans[x.second] = getb(i) - getb(x.first - 1);
		}
	}
	for(int i = 1; i <= q; i++) printf("%lld\n", ans[i]);
}
