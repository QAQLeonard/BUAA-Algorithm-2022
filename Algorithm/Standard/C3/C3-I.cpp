#include<bits/stdc++.h>
using namespace std;
#define ll long long

multiset<ll> s;
const int N = 1e5+10;
ll a[N];
ll b[N];
ll dp[N];
int main(){
    int t;
    scanf("%d",&t);
    while(t--) {
        s.clear();
        int n, m, k;
        scanf("%d %d", &n, &k);
        for (int i = 1; i <= n; i++) {
            scanf("%lld", a + i);
            dp[i]=-2e9;
        }
        for (int i = 1; i <= n; i++) {
            scanf("%lld", b + i);
        }
        dp[k]=0;
        scanf("%d", &m);
        for (int i = 1; i <= n; i++) {
            s.insert(dp[i]);
        }
        for (int i = 1; i <= m; i++) {
            int c;
            scanf("%d", &c);
            auto itt = s.find(dp[c]);
            s.erase(itt);
            auto it = s.end();
            it--;
            dp[c] = max(dp[c] + a[c], (*it) + b[c]);
            s.insert(dp[c]);
        }
        auto it = s.end();
        it--;
        printf("%lld\n", *it);
    }
}
