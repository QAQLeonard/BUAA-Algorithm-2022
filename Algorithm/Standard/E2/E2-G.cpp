#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cstring>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
const int N = 3000005;
const int inf = 0x3f3f3f3f;
int getint(){
    char c;bool flag=0;int num=0;
    while((c=getchar())<'0'||c>'9')if(c=='-')flag=1;
    while(c>='0'&&c<='9'){num=num*10+c-48;c=getchar();}
    return flag ? -num : num;
}
int pri[N], num[N];
int getzero(int n, int x){
    int cnt = 0;
    while(n)
        cnt += n / x, n /= x;
    return cnt;
}
int getpri(int n){
    int h = sqrt(n + 0.5), cnt = 0;
    for(int i = 2; i <= h; i ++){
        if(n % i) continue ;
        pri[++ cnt] = i, num[cnt] = 0;
        while(n % i == 0)
            n /= i, num[cnt] ++;
    }
    if(n > 1) pri[++ cnt] = n, num[cnt] = 1;
    return cnt;
}
int main(){
    int T = getint();
    while(T --){
        int n = getint(), m = getint(), k = getint();
        int cnt = getpri(k), ans = inf;
        for(int i = 1; i <= cnt; i ++){
            int zero = getzero(n, pri[i]);
            zero -= getzero(m, pri[i]);
            zero -= getzero(n - m, pri[i]);
            ans = min(ans, zero / num[i]);
        }
        cout << ans << endl;
    }
}
