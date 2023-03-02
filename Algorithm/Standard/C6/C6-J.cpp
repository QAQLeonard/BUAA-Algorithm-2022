#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,k;
const int N = 5010;
vector<tuple<ll,ll,ll>> tmp;
long double dp[N];
long double calc(int l,int r) {
	return 1.0L*(get<1>(tmp[l-1])+get<1>(tmp[r-1]))*(get<0>(tmp[r-1])-get<0>(tmp[l-1]))/2-get<2>(tmp[r-1]);
}
int main() {

	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d",&n);
		for(int i = 1; i <= n; i++) dp[i] = 0;
		tmp.clear();
		for(int i=0; i<n; i++) {
			ll x,w,c;
			scanf("%lld %lld %lld",&x,&c,&w);
			tmp.push_back(make_tuple(x,c,w));
		}
		sort(tmp.begin(),tmp.end());
		for(int i=1; i<=n; i++) {
			dp[i]=-get<2>(tmp[i-1]);
		}
		for(int i=1; i<=n; i++) {
			for(int j=1; j<i; j++) {
				dp[i]=max(dp[i],dp[j]+ calc(j,i));
			}
		}
		long double tmpa=0;
		for(int i=1; i<=n; i++) {
			tmpa=max(tmpa,dp[i]);
		}
		printf("%.1Lf\n",tmpa);
	}
}
