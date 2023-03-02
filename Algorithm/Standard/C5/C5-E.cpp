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
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
const int N = 100005;
int getint(){
    char c;bool flag=0;int num=0;
    while((c=getchar())<'0'||c>'9')if(c=='-')flag=1;
    while(c>='0'&&c<='9'){num=num*10+c-48;c=getchar();}
    return flag ? -num : num;
}
map<pi, int> point;
ll sqr(int x) {
    return 1ll * x * x;
}
ll dis(int x1, int y1, int x2, int y2) {
    return sqr(x1 - x2) + sqr(y1 - y2);
}
int main(){

    int n = getint(), q = getint();

    for(int i = 1; i <= n; i ++) {
        int x = getint(), y = getint();

        if(point.count(make_pair(x, y)))
            point[make_pair(x, y)] ++;
        else 
            point[make_pair(x, y)] = 1;
    }

    while(q --) {
        int x = getint(), y = getint(), r = getint(), ans = 0;

        
        for(int i = x - r; i <= x + r; i ++)
            for(int j = y - r; j <= y + r; j ++)
                if(dis(i, j, x, y) <= sqr(r) && point.count(make_pair(i, j))) {

                    ans += point[make_pair(i, j)];
                }
        printf("%d\n", ans);
    }
}
