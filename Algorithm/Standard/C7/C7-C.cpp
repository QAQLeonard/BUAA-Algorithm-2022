#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define eps 1e-14
#define maxn 1000005
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


int n, a[maxn];
priority_queue<int> q;
priority_queue<int, vector<int>, greater<int>> p;

void solve(){
	while(!q.empty())q.pop();
	while(!p.empty())p.pop();
	n = read();
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		q.push(a[i]);
		if(i & 1){
			while(q.size() > p.size()) p.push(q.top()), q.pop();
			while(q.size() < p.size()) q.push(p.top()), p.pop();
			printf("%d ", q.top());
		}
	}
	puts("");
}

int main(){

	int t = read();
	while(t--){
		solve();
	}
	
   return 0;
}
