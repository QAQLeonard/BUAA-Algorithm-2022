#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cstring>
#include<set>
#include<assert.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
const int N = 1005;
const int M = 10005;
const int inf = 0x3f3f3f3f;
int getint(){
    char c;bool flag=0;int num=0;
    while((c=getchar())<'0'||c>'9')if(c=='-')flag=1;
    while(c>='0'&&c<='9'){num=num*10+c-48;c=getchar();}
    return flag ? -num : num;
}
int a[N], sum[N], f[N][M];
vector<int> last;
void dfs(int n, int d){
    if(n < 1) return ;
    else if(f[n][d] == f[n - 1][d] + a[n]){
        last.push_back(n);
        dfs(n - 1, d);
    }
    else if(f[n][d] == f[n - 1][d + a[n]])
        dfs(n - 1, d + a[n]);
    else dfs(n - 1, abs(d - a[n]));
}
int main(){
    int n = getint();
    assert(n <= 1000);
    for(int i = 1; i <= n; i ++)
        sum[i] = sum[i - 1] + (a[i] = getint());
    assert(sum[n] <= 10000);

    memset(f, 0x3f, sizeof(f));
    f[0][0] = 0;
    for(int i = 1; i <= n; i ++)
        for(int j = 0; j <= sum[i - 1]; j ++){
            f[i][j] = min(f[i][j], f[i - 1][j] + a[i]);
            f[i][j + a[i]] = min(f[i][j + a[i]], f[i - 1][j]);
            f[i][abs(j - a[i])] = min(f[i][abs(j - a[i])], f[i - 1][j]);
        }
    
    cout << f[n][0] << endl;
    
    dfs(n, 0);
    for(auto v : last)
        printf("%d ", v);
}
