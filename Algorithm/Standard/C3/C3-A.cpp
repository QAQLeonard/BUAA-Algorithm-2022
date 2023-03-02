#include<bits/stdc++.h>
#define maxn 100005
typedef long long ll;
using namespace std;
inline ll read(){
    ll x = 0, f = 1;char ch = getchar();
    while(ch > '9' || ch < '0'){if(ch == '-') f = -1;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch -'0';ch = getchar();}
    return x * f;
}
ll dp[maxn];
int main(){
	int n = read();
	for(int i = 1; i <= n; i++) dp[i] = read();
	for(int i = 2; i <= n; i++){
		for(int j = 1; j < i; j++) dp[i] = max(dp[i], dp[j] + dp[i - j]);
	}
	printf("%lld\n", dp[n]);
	return 0;
}
