#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cstring>
#include<set>
#include<ctime>
#include<map>
#include<assert.h>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pi;
const int N = 20005;
const int M = 1000005;
const ll inf = 1ll << 60;
int getint(){
    char c;bool flag=0;int num=0;
    while((c=getchar())<'0'||c>'9')if(c=='-')flag=1;
    while(c>='0'&&c<='9'){num=num*10+c-48;c=getchar();}
    return flag ? -num : num;
}
const int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int cnt, fir[N], tar[M], nxt[M], w[M];
ll dis[N]; bool vis[N];
int Hash(int a[][3]) {
    int h = 0;
    for(int i = 0; i < 3; i ++)
        for(int j = 0; j < 3; j ++)
            h = h * 3 + a[i][j];
    return h;
}
void reHash(int h, int a[][3]) {
    for(int i = 2; i >= 0; i --)
        for(int j = 2; j >= 0; j --)
            a[i][j] = h % 3, h /= 3;
}
void rotate(int x[][3], int y[][3], int si, int sj) {
    for(int i = 0; i < 3; i ++)
        for(int j = 0; j < 3; j ++)
            y[i][j] = x[i][j];
    // si, sj         si, sj + 1
    // si + 1, sj     si + 1, sj + 1

    y[si][sj + 1] = x[si][sj];
    y[si + 1][sj + 1] = x[si][sj + 1];
    y[si + 1][sj] = x[si + 1][sj + 1];
    y[si][sj] = x[si + 1][sj];
}
void link(int a, int b, int c) {
    tar[++ cnt] = b, w[cnt] = c;
    nxt[cnt] = fir[a], fir[a] = cnt;
}
bool inarea(int x, int y) {
    return x >= 0 && x < 3 && y >= 0 && y < 3;
}

priority_queue<pi, vector<pi>, greater<pi> > q;
void dij(int x) {
    for(int i = 0; i < 19683; i ++)
        dis[i] = inf;
    q.push(make_pair(dis[x] = 0, x));
    while(! q.empty()) {
        x = q.top().second, q.pop();
        if(vis[x]) continue ; 
        vis[x] = 1;

        for(int i = fir[x]; i; i = nxt[i])
            if(dis[tar[i]] > dis[x] + w[i]) {
                dis[tar[i]] = dis[x] + w[i];
                q.push(make_pair(dis[tar[i]], tar[i]));
            }
    }
}
int main() {
    int x[3][3], y[3][3], color[3][3];
    int a = getint(), b = getint(), c = getint();

    int n = getint(), m = getint();
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
            color[i][j] = getint();
    
    for(int i = 0; i < 3; i ++)
        for(int j = 0; j < 3; j ++)
            x[i][j] = getint();
    
    int st = Hash(x), Ed = 19683;
    for(int s = 0; s < Ed; s ++) {
        reHash(s, x);
        
        // Ðý×ª
        rotate(x, y, 0, 0), link(s, Hash(y), a);
        rotate(x, y, 0, 1), link(s, Hash(y), a);
        rotate(x, y, 1, 0), link(s, Hash(y), a);
        rotate(x, y, 1, 1), link(s, Hash(y), a);

        // ¶Ô»»
        for(int i = 0; i < 3; i ++)
            for(int j = 0; j < 3; j ++)
                for(int k = 0; k < 3; k ++)
                    if(inarea(i + d[k][0], j + d[k][1])) {
                        swap(x[i][j], x[i + d[k][0]][j + d[k][1]]);
                        link(s, Hash(x), b);
                        swap(x[i][j], x[i + d[k][0]][j + d[k][1]]);
                    }
        
        // Ô¤ÖÆ
        for(int i = 0; i + n - 1 < 3; i ++)
            for(int j = 0; j + m - 1 < 3; j ++) {
                for(int di = 0; di < n; di ++)
                    for(int dj = 0; dj < m; dj ++) {
                        y[di][dj] = x[i + di][j + dj];
                        x[i + di][j + dj] = color[di][dj];
                    }
                link(s, Hash(x), c);

                for(int di = 0; di < n; di ++)
                    for(int dj = 0; dj < m; dj ++)
                        x[i + di][j + dj] = y[di][dj];
            }
    }

    dij(st);

    for(int i = 0; i < 3; i ++)
        for(int j = 0; j < 3; j ++)
            x[i][j] = getint();
    //cout << dis[Hash(x)] << '\n';
    printf("%lld\n", dis[Hash(x)]);

    return 0;
}
