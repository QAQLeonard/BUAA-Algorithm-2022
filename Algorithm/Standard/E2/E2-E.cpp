#include <bits/stdc++.h>
#define inf 1e18
#define maxn 20005
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const ll mod = 998244353;
const double eps = 1e-4;
inline ll read(){
    ll x = 0, f = 1;char ch = getchar();
    while(ch > '9' || ch < '0'){if(ch == '-') f = -1;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch -'0';ch = getchar();}
    return x * f;
}

int n;
char s[maxn];

char pan[5] = {' ', 'A', 'B', 'C'};

void solve(int n, int now, int to){
    if(n == 1){
        if(to == now % 3 + 1) {
            if(s[n] == 'r') printf("move 1 from %c to %c\n", pan[now], pan[to]);
            else printf("move 1 from %c to %c\n", pan[now], pan[6 - now - to]), printf("move 1 from %c to %c\n", pan[6 - now - to], pan[to]);
        }
        else{
            if(s[n] == 'l') printf("move 1 from %c to %c\n", pan[now], pan[to]);
            else printf("move 1 from %c to %c\n", pan[now], pan[6 - now - to]), printf("move 1 from %c to %c\n", pan[6 - now - to], pan[to]);
        }
        return ;
    }
    if(to == now % 3 + 1) {
        if(s[n] == 'r') solve(n - 1, now, 6 - now - to), printf("move %d from %c to %c\n", n, pan[now], pan[to]), solve(n - 1, 6 - now - to, to);
        else {
            solve(n - 1, now, to);
            printf("move %d from %c to %c\n", n, pan[now], pan[6 - now - to]);
            solve(n - 1, to, now);
            printf("move %d from %c to %c\n", n,  pan[6 - now - to], pan[to]);
            solve(n - 1, now, to);
        }
    }
    else{
        if(s[n] == 'l') solve(n - 1, now, 6 - now - to),printf("move %d from %c to %c\n", n, pan[now], pan[to]), solve(n - 1, 6 - now - to, to);
        else {
            solve(n - 1, now, to);
            printf("move %d from %c to %c\n", n, pan[now], pan[6 - now - to]);
            solve(n - 1, to, now);
            printf("move %d from %c to %c\n", n, pan[6 - now - to], pan[to]);
            solve(n - 1, now, to);
        }
    }
}

int main(){

    while(scanf("%d%s", &n, s + 1) != EOF){
        solve(n, 1, 3);
        puts("");
    }
    return 0;
}
