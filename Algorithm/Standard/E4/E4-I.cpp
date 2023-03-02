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
typedef pair<int, int> pi;
const int N = 100005;
const int M = 1000005;
const int inf = 0x3f3f3f3f;
int getint(){
    char c;bool flag=0;int num=0;
    while((c=getchar())<'0'||c>'9')if(c=='-')flag=1;
    while(c>='0'&&c<='9'){num=num*10+c-48;c=getchar();}
    return flag ? -num : num;
}
int cnt, fir[N], tar[M], nxt[M];
int vis[N], U[M], V[M];
void link(int a, int b) {
    tar[++ cnt] = b, nxt[cnt] = fir[a], fir[a] = cnt;
}
void dfs(int x) {
    for(int i = fir[x]; i; i = nxt[i]) {
        if(vis[tar[i]] == vis[x])
            continue ;
        vis[tar[i]] = vis[x], dfs(tar[i]);
    }

}
int main(){
    int n = getint(), m = getint();
    int group = 1, last = 0;
    vis[1] = group;
    for(int i = 1; i <= m; i ++) {
        int x = getint(), y = getint();
        link(x, y), U[i] = x, V[i] = y;
        if(vis[x] == group)
            dfs(x);
        if(vis[n] == group) {
            vis[1] = ++ group;
            for(int j = i; j >= last; j --)
                fir[U[j]] = 0;
            last = i, link(x, y);
            if(x == 1) vis[y] = group;
        }
    }
    cout << group << endl;
}
