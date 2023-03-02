#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cstring>
#include<set>
using namespace std;
typedef long long ll;
const int N = 1000005;
int getint(){
    char c;bool flag=0;int num=0;
    while((c=getchar())<'0'||c>'9')if(c=='-')flag=1;
    while(c>='0'&&c<='9'){num=num*10+c-48;c=getchar();}
    return flag ? -num : num;
}
int f[N], fa[N], layer[N], ans[N], sum[N], sz[N], a[N];
vector<int> son[N];
vector<int> layer_point[N];
void dfs(int x){
    sz[x] = 1;
    int m = son[x].size();
    for(int i = 0; i < m; i ++){
        dfs(son[x][i]);
        sz[x] += sz[son[x][i]];
    }
    ans[x] = sum[f[x]] + sz[x] - 1;
    sum[f[x]] += sz[x];
}
int main(){

	int n = getint();

    for(int i = 1; i <= n; i ++)
        f[i] = getint();

    for(int i = 1; i <= n; i ++){
        fa[i] = layer[f[i] - 1];
        layer[f[i]] = i;
        layer_point[f[i]].push_back(i);
        son[fa[i]].push_back(i);
    }
    dfs(0);

    for(int i = 1, j = 0; i <= n; i ++){
        int k = (j += layer_point[i].size());
        for(auto x : layer_point[i])
            a[x] = k --;
    }
    for(int i = 1; i <= n; i ++)
        printf("%d%c", a[i], i == n ? 10 : 32);
    
    for(int i = 1; i <= n; i ++)
        printf("%d%c", n - ans[i], i == n ? 10 : 32);
    
    exit(0);
}
