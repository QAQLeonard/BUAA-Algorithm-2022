#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cstring>
#include<set>
#include<ctime>
#include<assert.h>
using namespace std;
typedef long long ll;
typedef pair<int, ll> pi;
const int N = 55;
const int inf = 0x3f3f3f3f;
const int mod = 998244253;
int getint(){
    char c;bool flag=0;int num=0;
    while((c=getchar())<'0'||c>'9')if(c=='-')flag=1;
    while(c>='0'&&c<='9'){num=num*10+c-48;c=getchar();}
    return flag ? -num : num;
}
void add(int &a, int b) {
    a += b; if(a >= mod) a -= mod;
}
void sub(int &a, int b) {
    a -= b; if(a < 0) a += mod;
}
int dp[N][N][N * N];
int main(){

    int n = getint(), k = getint();
    int mid = (n + 1) >> 1, len = n >> 1;
    int Max = (n & 1) * mid + (mid + 1 + n) * len;
    dp[1][0][n] = n;
    dp[0][1][2 * n] = n * (n - 1);
    for(int i = 1; i < n; i ++) {
        int val = n - i;
        for(int full = 0; full <= i; full ++) {
            int half = i - full; //half = (2 * i - full * 2) / 2
            int empty = n - full - 2 * half;
            if(empty < 0) continue ;
            for(int sum = 0; sum <= Max; sum ++)if(dp[full][half][sum]) { 
                if(full + 1 <= n && sum + val <= Max) {
                    //两个i放成一个新的full
                    add(dp[full + 1][half][sum + val], 
                    1ll * dp[full][half][sum] * empty % mod);
                    //一个放half，一个放empty，生成一个full
                    add(dp[full + 1][half][sum+val], 
                    1ll * dp[full][half][sum] * empty % mod * half * 2 % mod);
                }
                //两个i都放在half，生成两个full，减少一个half
                if(full + 2 <= n && half)
                    add(dp[full + 2][half - 1][sum],
                    1ll * dp[full][half][sum]
                    *(1ll * half * half % mod) % mod);
                //两个分别放在不同的empty中，增加一个half
                if(half + 1 <= n && sum + 2 * val <= Max)
                    add(dp[full][half + 1][sum + 2 * val],
                    1ll * dp[full][half][sum]*
                    (1ll * empty * (empty - 1) % mod) % mod);
            }
        }
    }

    int ans = 0;
    for(int i = 0; i <= k; i ++)
        add(ans, dp[n][0][i]);
    printf("%d\n", ans);
}
