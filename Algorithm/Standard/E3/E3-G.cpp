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
inline int read(){
    int x = 0, f = 1;char ch = getchar();
    while(ch > '9' || ch < '0'){if(ch == '-') f = -1;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch -'0';ch = getchar();}
    return x * f;
}

int n, m, k;
bool vis[maxn];
int dp[maxn][2];
set<int> s; 

void solve(){
	n = read(), m = read(), k = read();
	for(int i = 1; i <= m; i++) vis[read()] = 1;
	dp[1][0] = k - 1, dp[1][1] = !vis[1];
	for(int i = 2; i <= n; i++){
		dp[i][0] = (1ll * dp[i - 1][0] * (k - 2) + 1ll * dp[i - 1][1] * (k - 1)) % mod;
		dp[i][1] = dp[i - 1][0];
		if(vis[i]) dp[i][1] = 0;
	}
	printf("%d", (dp[n][0] + dp[n][1]) % mod);
}

int main(){
    int t = 1, cnt = 1;
	while(t--){
		solve();
	}
	
   return 0;
}
