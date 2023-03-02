#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pi;
const int N = 100005;
const int M = 2000005;
const ll inf = 1ll << 60;
int getint(){
    char c;bool flag=0;int num=0;
    while((c=getchar())<'0'||c>'9')if(c=='-')flag=1;
    while(c>='0'&&c<='9'){num=num*10+c-48;c=getchar();}
    return flag ? -num : num;
}
int n, m, T, cnt, fir[N], tar[M], nxt[M], w[M], age[M], A[M];
ll dis[N]; bool vis[N];
priority_queue<pi, vector<pi>, greater<pi> > q;
void link(int a, int b, int c, int A) {
    tar[++ cnt] = b, w[cnt] = c, age[cnt] = A;
    nxt[cnt] = fir[a], fir[a] = cnt;
}
bool dij(int x, int ed, int mx) {
    for(int i = 1; i <= n; i ++)
        dis[i] = inf, vis[i] = 0;
    q.push(make_pair(dis[x] = 0, x));
    while(! q.empty()) {
        x = q.top().second, q.pop();
        if(vis[x]) continue ;

        vis[x] = 1;
        for(int i = fir[x]; i; i = nxt[i])
            if(age[i] > mx && dis[tar[i]] > dis[x] + w[i]) {
                dis[tar[i]] = dis[x] + w[i];
                q.push(make_pair(dis[tar[i]], tar[i]));
            }
    }
    return dis[ed] >= T;
}
int main(){

    n = getint(), m = getint(), T = getint();
    for(int i = 1; i <= m; i ++) {
        int x = getint(), y = getint();
        int len = getint(), age = getint();
        link(x, y, len, A[i] = age);
    }
    sort(A + 1, A + m + 1);
    if(dij(1, n, -1)) {
        printf("O v O %lld\n", dis[n]);
        return 0;
    }

    int l = 1, r = m;
    while(l < r) {
        int mid = (l + r) >> 1;
        if(dij(1, n, A[mid]))
            r = mid;
        else l = mid + 1;
    }
    cout << A[l] << endl;
}
